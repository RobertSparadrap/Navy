/*
** EPITECH PROJECT, 2020
** error
** File description:
** navy
*/

#include "../include/navy.h"

int error2(char *buffer)
{
    int navy1 = my_getnbr_char(buffer[0]);
    int navy2 = my_getnbr_char(buffer[8]);
    int navy3 = my_getnbr_char(buffer[16]);
    int navy4 = my_getnbr_char(buffer[24]);
    if (navy1 != 2 || navy2 != 3 || navy3 != 4 || navy4 != 5)
        return 1;
    return 0;
}

int error(char *map, int i)
{
    int j = 0;
    char buffer[40];
    int fd = open(map, O_RDONLY);
    read(fd, buffer, 40);
    int size = my_getnbr_char(buffer[i]);
    int min = my_getnbr_char(buffer[i + 3]);
    int max = my_getnbr_char(buffer[i + 6]) + 1;
    int c = buffer[i + 2];
    int c1 = buffer[i + 5] + 1;
    if (error2(buffer))
        return -1;
    if (max - min == size && c == c1 - 1)
        j = 1;
    else if (c1 - c == size && min == max - 1)
        j = 1;
    if (!j)
        return -1;
    if (i != 24)
        error(map, i + 8);
}
