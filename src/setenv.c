/*
** EPITECH PROJECT, 2024
** Shell Programming
** File description:
** minishell1
*/

#include "../include/mon.h"

void add_env_variable(char **env, const char *name, const char *value)
{
    int i;
    char *new_var;

    for (i = 0; env[i] != NULL; i++) {
    }
    if (i < MAX_ENV_VARS - 1) {
        new_var = malloc(my_strlen(name) + my_strlen(value) + 2);
        if (new_var == NULL) {
            mini_printf("Error: Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
        my_strcpy(new_var, name);
        my_strcat(new_var, "=");
        my_strcat(new_var, value);
        env[i] = new_var;
        env[i + 1] = NULL;
    } else {
        mini_printf("Error: Too many environment variables.\n");
        exit(EXIT_FAILURE);
    }
}

void update_or_add_env_variable(char **env, const char *name
    , const char *value)
{
    int i = 0;

    while (env[i] != NULL) {
        if (my_strstr(env[i], name) == env[i]) {
            update_env_variable(env[i], name, value);
            return;
        }
        i++;
    }
    add_env_variable(env, name, value);
}

static int part_one_gestion(const char *name)
{
    if (!(name[0] >= 'a' && name[0] <= 'z') &&
        !(name[0] >= 'A' && name[0] <= 'Z')) {
        mini_printf("setenv: Variable name must begin with a letter.\n");
        return 1;
    }
    if (my_strchr(name, ':') != NULL) {
        mini_printf("setenv: Variable name must not contain a colon.\n");
        return 1;
    }
    return 0;
}

int gestion_error_setenv(char **env, const char *name, const char *value)
{
    if (part_one_gestion(name) != 0)
        return 1;
    if (!(name[0] >= 'a' && name[0] <= 'z') &&
        !(name[0] >= 'A' && name[0] <= 'Z')) {
        mini_printf("setenv: Variable name must be alphanumeric.\n");
        return 1;
    }
    for (int i = 0; name[i] != '\0'; i++) {
        if (!((name[i] >= 'a' && name[i] <= 'z') || (name[i] >=
        'A' && name[i] <= 'Z') || (name[i] >= '0' && name[i] <= '9'))) {
            mini_printf("setenv: Variable name must");
            mini_printf(" contain alphanumeric characters.\n");
            return 1;
        }
    }
    return 0;
}

int set_env_variable(char **env, const char *name, const char *value)
{
    gestion_error_setenv(env, name, value);
    if (value != NULL) {
        update_or_add_env_variable(env, name, value);
    } else {
        unset_env_variable(env, name);
        add_env_variable(env, name, "");
    }
    return 0;
}
