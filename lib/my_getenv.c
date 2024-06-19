/*
** EPITECH PROJECT, 2024
** My_putnbr
** File description:
** Solo Stumper02
*/

#include "../include/mon.h"

extern char **environ;

char *my_getenv(const char *name)
{
    int i = 0;
    int len = my_strlen(name);
    char *env_entry;
    char *env_value;

    for (; (env_entry = environ[i]) != NULL;) {
        if (my_strncmp(env_entry, name, len) == 0 && env_entry[len] == '=') {
            env_value = &env_entry[len + 1];
            return env_value;
        }
        i++;
    }
    return NULL;
}
