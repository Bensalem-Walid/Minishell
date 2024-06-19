/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** my_strcat
*/

#include "../include/mon.h"

char *my_strcat(char *dest, char const *src)
{
    int len = my_strlen(dest);
    int i;

    if (dest == NULL || src == NULL) {
        return NULL;
    }
    for (i = 0; src[i] != '\0'; i++) {
        dest[len + i] = src[i];
    }
    dest[len + i] = '\0';
    return dest;
}
