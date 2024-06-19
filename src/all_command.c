/*
** EPITECH PROJECT, 2024
** Shell Programming
** File description:
** minishell1
*/

#include "../include/mon.h"

char *check_command_in_dir(const char *dir, const char *cmd)
{
    struct stat st;
    char *fullpath = malloc(my_strlen(dir) + my_strlen(cmd) + 2);

    if (!fullpath) {
        return NULL;
    }
    my_strcpy(fullpath, dir);
    my_strcat(fullpath, "/");
    my_strcat(fullpath, cmd);
    if (stat(fullpath, &st) == 0 && (st.st_mode & S_IXUSR)) {
        return fullpath;
    } else {
        free(fullpath);
        return NULL;
    }
}

char *find_command_in_path(const char *cmd)
{
    char *path = my_getenv("PATH");
    char *pathcopy;
    char *dir;
    char *result = NULL;

    if (!path)
        return NULL;
    pathcopy = my_strdup(path);
    if (!pathcopy)
        return NULL;
    for (dir = strtok(pathcopy, ":"); dir != NULL; dir = strtok(NULL, ":")) {
        result = check_command_in_dir(dir, cmd);
        if (result)
            break;
    }
    free(pathcopy);
    return result;
}

char *verif(char **tableau)
{
    struct stat st;

    if (tableau != NULL && tableau[0] != NULL &&
        (tableau[0][0] == '/' || my_strncmp(tableau[0], "./", 2) == 0 ||
        my_strncmp(tableau[0], "../", 3) == 0 ||
        my_strchr(tableau[0], '/') != NULL)) {
        if (stat(tableau[0], &st) == 0 && (st.st_mode & S_IXUSR)) {
            return my_strdup(tableau[0]);
        } else {
            return NULL;
        }
    }
    return NULL;
}

int pipe_found_pid(bool found_something, char
    *command_path, char **tableau, char **env)
{
    if (!found_something)
        pid_normal(command_path, tableau, env);
}

static void verification_pipe_redirection(bool *found_something,
    char **tableau, char **env, char *command_path)
{
    for (int i = 0; tableau[i] != NULL; i++) {
        if (my_strchr(tableau[i], '|') != NULL) {
            *found_something = true;
            befor_after_pipe(command_path, tableau, env);
            return;
        }
    }
    for (int i = 0; tableau[i] != NULL; i++) {
        if (my_strchr(tableau[i], '>') != NULL
        || my_strstr(tableau[i], ">>") != NULL) {
            *found_something = true;
            initialisation_redirection(command_path, tableau, env);
            return;
        }
    }
}

int all_commande_linux(char **tableau, char **env)
{
    char *command_path;
    bool found_something = false;

    command_path = verif(tableau);
    if (command_path == NULL) {
        command_path = find_command_in_path(tableau[0]);
        if (command_path == NULL) {
            mini_printf("%s: Command not found.\n", tableau[0]);
            return 1;
        }
    }
    verification_pipe_redirection(&found_something,
    tableau, env, command_path);
    pipe_found_pid(found_something, command_path, tableau, env);
    return 0;
}
