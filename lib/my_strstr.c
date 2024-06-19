/*
** EPITECH PROJECT, 2023
** mini
** File description:
** printf
*/

#include "../include/mon.h"

const char *my_strstr(const char *haystack, const char *needle)
{
    const char *h;
    const char *n;

    if (*needle == '\0')
        return haystack;
    while (*haystack != '\0') {
        h = haystack;
        n = needle;
        while (*n != '\0' && *h == *n && *h != '\0') {
            h++;
            n++;
        }
        if (*n == '\0') {
            return haystack;
        haystack++;
    }
    return NULL;
    }
}
