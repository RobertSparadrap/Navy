/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** connection
*/

#include <unistd.h>
#include "../include/navy.h"

void connection_b(int i, siginfo_t *sig, void *s)
{
    if (i == SIGUSR1)
        my_printf("successfully connected\n\n");
}

int send(char *a, int pid)
{
    *(a + 2) = 0;
    int ping1, ping2;
    if (my_strlen(a) != 2)
        return -1;
    ping1 = *a - 'A' + 1;
    ping2 = *(a + 1) - '0';
    while (ping1-- > 0) {
        kill(pid, SIGUSR1);
        usleep(50);
    }
    if (ping2 < 1 || ping2 > 8)
        return -3;
    while (ping2-- > 0) {
        kill(pid, SIGUSR2);
        usleep(50);
    }
    kill(pid, SIGUSR1);
    return 0;
}

void print_game(char **map, char **map2, int i)
{
    if (i) {
        my_printf("my positions:\n");
        map_print(map);
        my_printf("\nenemy's positions:\n");
        map_print(map2);
    } else {
        my_printf("my positions:\n");
        map_print(map);
        my_printf("\nenemy's positions:\n");
        map_print(map2);
    }
}

int check_input(char *in)
{
    if (*in < 'A' || *in > 'H') {
        my_printf("wrong position\n");
        return 1;
    }
    if (*(in + 1) < '1' || *(in + 1) > '8') {
        my_printf("wrong position\n");
        return 1;
    }
    return 0;
}

int check(char **map, char *msg)
{
    char x = *msg - 'A';
    char y = *(msg + 1) - '1';
    if (map[y][x] == 'o')
        return 0;
    return (map[y][x] > 0);
}
