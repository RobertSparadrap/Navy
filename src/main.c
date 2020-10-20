/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Main function of the Navy.
*/

#include "../include/navy.h"

int help(int ac, char **av)
{
    if (ac == 1 || ac > 3) {
        my_printf("Number of arguments invalide\n");
        return (1);
    }
    if (av[1][1] == 'h') {
        my_printf("USAGE\n");
        my_printf("\t./navy [first_player_pid] navy_positions\n");
        my_printf("DESCRIPTION\n");
        my_printf("\tfirst_player_pid: \
        only for the 2nd player. pid of the first player.\n");
        my_printf("\tnavy_positions: \
        file representing the positions of the ships.\n");
    }
    return (0);
}

int main(int ac, char **av)
{
    if (help(ac, av))
        return (ERROR);
    if (error(av[1], 0) == -1 && ac == 2)
        return (ERROR);
    co(ac, av);
    return (0);
}
