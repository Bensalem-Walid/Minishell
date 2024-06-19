/*
** EPITECH PROJECT, 2024
** Shell Programming
** File description:
** minishell1
*/

#include "../include/mon.h"

static bool verif_tableau(char **tableau, redirectioninfo_t *redir_info, int i)
{
    if (tableau[i + 1] != NULL) {
        *(redir_info->filename) = tableau[i + 1];
        *(redir_info->verif) = (my_strcmp(tableau[i], ">>") == 0);
        return true;
    }
    return false;
}

bool get_redirection_info(char **tableau, redirectioninfo_t *redir_info)
{
    int i;

    for (i = 0; tableau[i] != NULL; i++) {
        if (my_strcmp(tableau[i], ">") == 0
        || my_strcmp(tableau[i], ">>") == 0) {
            return verif_tableau(tableau, redir_info, i);
        }
    }
    return false;
}

void setup_command_args(char **tableau, char **args)
{
    int arg_count = 0;

    for (int i = 0; tableau[i] != NULL && my_strcmp(tableau[i], ">")
    != 0 && my_strcmp(tableau[i], ">>") != 0; i++) {
        args[arg_count] = tableau[i];
        arg_count++;
    }
    args[arg_count] = NULL;
}

void execute_command_with_redirection(char *command_path, char **args,
    redirectioninfo_t *redir_info, char **env)
{
    int file;

    if (*(redir_info->filename) != NULL) {
        if (*(redir_info->verif)) {
            file = open(*(redir_info->filename), O_WRONLY | O_CREAT
            | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
        } else {
            file = open(*(redir_info->filename), O_WRONLY | O_CREAT
            | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
        }
        if (file == -1) {
            exit(84);
        }
        dup2(file, STDOUT_FILENO);
        close(file);
    }
    if (execve(command_path, args, env) == -1) {
        exit(84);
    }
}

int fork_execute(char *command_path, char **args,
    redirectioninfo_t *redir_info, char **env)
{
    pid_t pid;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        free(args);
        exit(EXIT_FAILURE);
    }
    if (pid == 0) {
        execute_command_with_redirection(command_path, args, redir_info, env);
    } else {
        wait(NULL);
    }
}

int initialisation_redirection(char *command_path, char **tableau, char **env)
{
    char *filename = NULL;
    bool verif = false;
    char **args = malloc(1000 * sizeof(char *));
    redirectioninfo_t redir_info;

    if (!args)
        exit(84);
    redir_info.filename = &filename;
    redir_info.verif = &verif;
    if (!get_redirection_info(tableau, &redir_info)) {
        free(args);
        return 1;
    }
    setup_command_args(tableau, args);
    fork_execute(command_path, args, &redir_info, env);
    free(args);
    return 0;
}
