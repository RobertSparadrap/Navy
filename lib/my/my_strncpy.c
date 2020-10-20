/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** my_strncpy
*/

#include "../../include/my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (src[i] != '\0') {
        if (i < n)
            dest[i] = src[i];
        i++;
    }
    if (i < n)
        dest[i] = '\0';
    return (dest);
}
