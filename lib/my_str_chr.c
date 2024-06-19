/*
** EPITECH PROJECT, 2023
** my_strcpy
** File description:
** my_strcpy
*/

#include "../include/mon.h"

char *my_strchr(char *s, int c)
{
    int i;

    i = 0;
    while (s[i]) {
        if (s[i] == c)
            return (s + i);
        i = i + 1;
    }
    return (NULL);
}
