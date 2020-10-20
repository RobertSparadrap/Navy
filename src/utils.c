/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** utils
*/

#include "../include/navy.h"

void hboat(char **map, map_line_t *map_line)
{
    map_line->b1 -= 'A';
    map_line->b2 -= 'A';
    map_line->c -= '0';
    for (int i = map_line->b1; i <= map_line->b2; i++)
        map[map_line->c - 1][i] = map_line->a;
}

void vboat(char **map, map_line_t *map_line)
{
    map_line->b1 -= 'A';
    map_line->c1 -= '0';
    map_line->c -= '0';
    for (int i = map_line->c1; i <= map_line->c; i++)
        map[i - 1][map_line->b1] = map_line->a;
}

void set(char **map, char *pos, int boom)
{
    char x = *pos - 'A';
    char y = *(pos + 1) - '1';
    map[y][x] = boom ? 'x' : 'o';
}

char *attack(char *f, int pid)
{
    size_t size = 3;
    do {
        my_printf("\nattack: \e[3m");
        getline(&f, &size, stdin);
        my_printf("\e[0m");
    }
    while (check_input(f));
    send(f, pid);
    return f;
}

void co(int ac, char **av)
{
    my_printf("my_pid: %d\n", getpid());
    if (ac == 2)
        player_one(av);
    else
        player_two(av);
}