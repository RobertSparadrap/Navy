/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** solo_stumper
*/

#include "../../include/my.h"

int my_strlen(char const *str)
{
    int r = 0;

    while (str[r] != '\0')
        r++;
    return (r);
}
