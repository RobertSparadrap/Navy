/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** utils_connection
*/

#include "../include/navy.h"

void connection_a(int i, siginfo_t *sig, void *s)
{
    int win = sig->si_pid;
    global_data = &win;
    kill(win, SIGUSR1);
}

void receive(int signo, siginfo_t *sig, void *s)
{
    static char a = 0, b = 0;
    if (signo == SIGUSR1 && !b)
        a++;
    if (signo == SIGUSR1 && b) {
        char *res = malloc(3);
        *res = a + 'A' - 1;
        *(res + 1) = b + '0';
        *(res + 2) = 0;
        global_data = (void *) res;
        a = 0;
        b = 0;
    }
    if (signo == SIGUSR2)
        b++;
}