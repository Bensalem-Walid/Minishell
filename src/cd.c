/*
** EPITECH PROJECT, 2024
** Shell Programming
** File description:
** minishell1
*/

#include "../include/mon.h"

struct globalvariables global_vars;

int cd_change_directory(char *path)
{
    char temp[PATH_MAX];

    if (getcwd(temp, sizeof(temp)) == NULL) {
        perror("Error getting current directory");
        return 1;
    }
    if (chdir(path) != 0) {
        mini_printf("%s: Not a directory.\n", path);
        return 1;
    }
    my_strncpy(global_vars.lastDir, temp, sizeof(global_vars.lastDir) - 1);
    global_vars.lastDir[sizeof(global_vars.lastDir) - 1] = '\0';
    return 0;
}

int cd_check_directory(char *path)
{
    struct stat sb;

    if (stat(path, &sb) == -1) {
        mini_printf("%s: No such file or directory.\n", path);
        return 1;
    }
    if (!S_ISDIR(sb.st_mode)) {
        mini_printf("%s: Not a directory.\n", path);
        return 1;
    }
    return 0;
}

int cd_execute_two(char *token)
{
    char *home = my_getenv("HOME");

    if (token == NULL || my_strcmp(token, "~") == 0) {
        if (home == NULL) {
            mini_printf("cd: HOME not set.\n");
            return 1;
        }
        return cd_change_directory(home);
    }
    if (my_strcmp(token, "-") == 0) {
        if (global_vars.lastDir[0] == '\0') {
            mini_printf(": No such file or directory.\n");
            return 1;
        }
        mini_printf("%s\n", global_vars.lastDir);
        return cd_change_directory(global_vars.lastDir);
    } else {
        return cd_change_directory(token);
    }
}

int cd_execute(char *token)
{
    if (token == NULL || my_strcmp(token, "cd") == 0) {
        return cd_execute_two(NULL);
    } else {
        return cd_execute_two(token);
    }
}
