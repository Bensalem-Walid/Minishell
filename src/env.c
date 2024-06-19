/*
** EPITECH PROJECT, 2024
** Shell Programming
** File description:
** minishell1
*/

#include "../include/mon.h"

void display_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++){
        mini_printf("%s\n", env[i]);
    }
}

void env_command(char **env)
{
    display_env(env);
}

void update_env_variable(char *env_var, const char *name, const char *value)
{
    char *name_start;
    char *equal_sign;

    if (env_var != NULL) {
        name_start = my_strstr(env_var, name);
        if (name_start != NULL) {
            equal_sign = my_strchr(name_start, '=');
        }
        if (name_start != NULL && equal_sign != NULL) {
            equal_sign++;
            my_strcpy(equal_sign, value);
        }
    }
}
