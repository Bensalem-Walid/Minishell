/*
** EPITECH PROJECT, 2024
** My_putstr
** File description:
** Solo Stumper02
*/

#include "../include/mon.h"

int my_putstr(char const *str)
{
    int a = 0;

    while (str[a] != '\0') {
        my_putchar(str[a]);
        a += 1;
    }
    return (a);
}
