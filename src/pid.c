/*
** EPITECH PROJECT, 2024
** Shell Programming
** File description:
** minishell2
*/

#include "../include/mon.h"

static void gestion_erreur(char **tableau)
{
    if (errno == ENOEXEC) {
        mini_printf("%s: Exec format error.", tableau[0]);
        mini_printf(" Wrong Architecture.\n", tableau[0]);
    } else {
        mini_printf("%s: Permission denied.\n", tableau[0]);
    }
}

int pid_normal(char *command_path, char **tableau, char **env)
{
    int status;
    int segfault_code;
    pid_t pid;

    pid = fork();
    if (pid == 0) {
        if (command_path == NULL || tableau[0] == NULL || env == NULL)
            exit(84);
        execve(command_path, tableau, env);
        gestion_erreur(tableau);
        free(command_path), exit(84);
    } else {
        waitpid(pid, &status, 0);
        segfault_code = segfault(status, command_path);
        if (segfault_code) {
            return segfault_code;
        }
    }
    return 0;
}

static void close_and_wait(pid_t pid1, pid_t pid2, int tube[2])
{
    close(tube[0]), close(tube[1]);
    waitpid(pid1, NULL, 0), waitpid(pid2, NULL, 0);
}

int pipe_fonction(pipeparams_t *params)
{
    int tube[2];
    pid_t pid1;
    pid_t pid2;

    if (pipe(tube) < 0)
        exit(84);
    pid1 = fork();
    if (pid1 == 0) {
        dup2(tube[1], STDOUT_FILENO), close(tube[0]), close(tube[1]);
        execve(params->command_path, params->before_pipe, params->env);
    }
    pid2 = fork();
    if (pid2 < 0)
        return 84;
    if (pid2 == 0) {
        dup2(tube[0], STDIN_FILENO), close(tube[0]), close(tube[1]);
        execve(params->command_path_pipe, params->after_pipe, params->env);
    }
    close_and_wait(pid1, pid2, tube);
    return 0;
}

static char **extract_commands_before_pipe(char **tableau)
{
    int i;
    char **before_pipe = malloc((sizeof(char *)) * (my_strlen(*tableau) + 1));
    int before_compteur = 0;

    for (i = 0; tableau[i] != NULL && my_strcmp(tableau[i], "|") != 0; i++) {
        before_pipe[before_compteur] = tableau[i];
        before_compteur++;
    }
    before_pipe[before_compteur] = NULL;
    return before_pipe;
}

static char **extract_commands_after_pipe(char **tableau)
{
    int tableau_length = 0;
    int after_compteur = 0;
    bool is_pipe_found = false;
    char **after_pipe;

    for (int i = 0; tableau[i] != NULL; i++)
        tableau_length += strlen(tableau[i]);
    after_pipe = malloc((tableau_length + 1) * sizeof(char *));
    for (int i = 0; tableau[i] != NULL; i++) {
        if (my_strcmp(tableau[i], "|") == 0) {
            is_pipe_found = true;
            continue;
        }
        if (is_pipe_found == true) {
            after_pipe[after_compteur] = tableau[i];
            after_compteur++;
        }
    }
    after_pipe[after_compteur] = NULL;
    return after_pipe;
}

static char *find_command_path_for_pipe(char **command)
{
    char *command_path = verif(command);

    if (command_path == NULL) {
        command_path = find_command_in_path(command[0]);
        if (command_path == NULL) {
            mini_printf("%s: Command not found.\n", command[0]);
            return NULL;
        }
    }
    return command_path;
}

int befor_after_pipe(char *command_path, char **tableau, char **env)
{
    char **before_pipe = extract_commands_before_pipe(tableau);
    char **after_pipe = extract_commands_after_pipe(tableau);
    char *command_path_pipe = find_command_path_for_pipe(after_pipe);
    pipeparams_t params;

    params.command_path = command_path;
    params.before_pipe = before_pipe;
    params.after_pipe = after_pipe;
    params.command_path_pipe = command_path_pipe;
    params.env = env;
    pipe_fonction(&params);
    free(before_pipe);
    free(after_pipe);
    return 0;
}
