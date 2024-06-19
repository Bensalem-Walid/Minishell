/*
** EPITECH PROJECT, 2024
** My_strlen.c
** File description:
** Solo Stumper 02
*/

#include "../include/mon.h"

int my_strlen(char const *str)
{
    int i;

    if (str == NULL)
        return 0;
    for (i = 0; str[i] != '\0'; i++);
    return i;
}
