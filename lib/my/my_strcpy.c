/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** my_strcpy
*/

#include "../../include/my.h"

char *my_strcpy(char *dest, char const *src)
{
    int r = 0;

    while (src[r] != '\0') {
        dest[r] = src[r];
        r++;
    }
    dest[r] = '\0';
    return (dest);
}