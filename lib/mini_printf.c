/*
** EPITECH PROJECT, 2023
** mini
** File description:
** printf
*/

#include <stdarg.h>
#include <stdio.h>
#include "../include/mon.h"

int lettre(const char *format, va_list list, int i)
{
    int compteur = 0;

    if (format[i] == 'd' || format[i] == 'i' || format[i] == 's'
        || format[i] == 'c' || format[i] == '%') {
        if (format[i] == 'd' || format[i] == 'i')
            my_putnbr(va_arg(list, int));
        if (format[i] == 's')
            compteur = my_putstr(va_arg(list, char *));
        if (format[i] == 'c'){
            my_putchar(va_arg(list, int));
            compteur += 1;
        }
        if (format[i] == '%'){
            my_putchar('%');
            compteur += 1;
        }
    } else {
        my_putchar('%'), my_putchar(format[i]), compteur += 2;
    }
    return compteur;
}

int mini_printf(const char *format, ...)
{
    int i;
    va_list list;
    int compteur = 0;

    va_start(list, *format);
    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%'){
            i++;
            compteur += lettre(format, list, i);
        } else {
            my_putchar(format[i]);
            compteur += 1;
        }
    }
    va_end(list);
    return compteur;
}
