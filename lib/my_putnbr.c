/*
** EPITECH PROJECT, 2024
** My_putnbr
** File description:
** Solo Stumper02
*/

#include "../include/mon.h"

void my_putnbr(int nb)
{
    if (nb < 0){
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb <= 9 && nb >= 0){
        my_putchar(nb + 48);
    }
    if (nb > 9){
        my_putnbr(nb / 10);
        my_putchar((nb % 10) + 48);
    }
}
