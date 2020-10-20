/*
** EPITECH PROJECT, 2020
** my_getnbr_char
** File description:
** getnbr_for_char
*/

#include "../../include/my.h"

int my_getnbr_char(char str)
{
    int ret = 0;

    if ((str >= '0' || str <= '9'))
        ret = str - 48;
    return ret;
}
