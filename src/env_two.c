/*
** EPITECH PROJECT, 2024
** Shell Programming
** File description:
** minishell1
*/

#include "../include/mon.h"

void while_env_two(char **env, int index)
{
    while (env[index] != NULL) {
        env[index] = env[index + 1];
        index++;
    }
}

int while_env(char **env, const char *name)
{
    int i = 0;

    while (env[i] != NULL) {
        if (my_strstr(env[i], name) == env[i]) {
            free(env[i]);
            while_env_two(env, i);
            return 1;
        }
        i++;
    }
    return 0;
}

int unset_env_variable(char **env, const char *name)
{
    int found = 0;

    for (int i = 0; env[i] != NULL; i++) {
        if (my_strstr(env[i], name) == env[i]) {
            found = 1;
            while_env_two(env, i);
            return 0;
        }
    }
    if (!found) {
        mini_printf("unsetenv: Variable not found.\n");
        return 1;
    }
    return 0;
}
