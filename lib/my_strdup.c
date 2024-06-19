/*
** EPITECH PROJECT, 2024
** My_strlen.c
** File description:
** Solo Stumper 02
*/

#include "../include/mon.h"

char *my_strdup(const char *s)
{
    char *new_str = malloc(my_strlen(s) + 1);

    if (new_str == NULL) {
        return NULL;
    }
    my_strcpy(new_str, s);
    return new_str;
}
