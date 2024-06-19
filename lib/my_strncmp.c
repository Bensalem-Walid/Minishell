/*
** EPITECH PROJECT, 2023
** my_strncmp
** File description:
** my_strncmp
*/

#include "../include/mon.h"

int my_strncmp(char *s1, const char *s2, int n)
{
    int i = 0;

    while (i < n && s1[i] == s2[i] && s1[i] != '\0') {
        i++;
    }
    if (i == n || (s1[i] == '\0' && s2[i] == '\0')) {
        return 0;
    }
    if (s1[i] - s2[i] > 0)
        return 1;
    if (s1[i] - s2[i] < 0)
        return -1;
    return 0;
}
