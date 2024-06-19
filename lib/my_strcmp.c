/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** my_strcmp
*/

#include "../include/mon.h"

int my_strcmp(char *str1, char *str2)
{
    int i = 0;

    if (str1 == NULL || str2 == NULL) {
        if (str1 == NULL && str2 == NULL) {
            return 0;
        }
        return (str1 == NULL) ? -1 : 1;
    }
    while (str1[i] == str2[i] && str1[i] != '\0') {
        i++;
    }
    return (str1[i] - str2[i]);
}
