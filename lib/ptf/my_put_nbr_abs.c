/*
** EPITECH PROJECT, 2019
** my_put_nbr_abs
** File description:
** my_putnbr
*/

#include "../../include/my.h"

int my_put_nbr_abs(int nb)
{
    if (nb < 0)
        nb = -nb;
    if (nb < 10)
        my_putchar(nb % 10 + '0');
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + '0');
    }
    return (nb);
}
