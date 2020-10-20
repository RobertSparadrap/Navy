/*
** EPITECH PROJECT, 2020
** co
** File description:
** navy
*/

#include <unistd.h>
#include "../include/navy.h"

void *global_data = NULL;

int finish(char **map)
{
    int destroy = 0;
    for (int i = 0; i != 8; i++)
        for (int j = 0; j != 8; j++)
            if (map[i][j] == 'x')
                destroy++;
    if (destroy == 14)
        return 1;
    return 0;
}

int game_loop(char **map, char **map2, int pid, char *f)
{
    int boom;
    char *msg = malloc(3);
    if (!f)
        f = malloc(3);
    while (1) {
        usleep(1000);
        if (global_data) {
            my_strncpy(msg, global_data, 2);
            free(global_data);
            global_data = NULL;
            if (*msg < 'J') {
                boom = check(map, msg);
                set(map, msg, boom);
                print_game(map, map2, 0);
                my_printf("%s: %s\n", msg, boom ? "hit" : "missed");
                *msg = 'J';
                *(msg + 1) = boom + '1';
                *(msg + 2) = 0;
                send(msg, pid);
                f = attack(f, pid);
                if (finish(map)) {
                    my_printf("Player 1 win\n");
                    return 1;
                }
                if (finish(map2)) {
                    my_printf("You win\n");
                    return 1;
                }
//                print_game(map, map2, 0);
            } else {
                my_printf("%s: %s\n\n", f,
                        *(msg + 1) - '1' ? "hit" : "missed");
                set(map2, f, *(msg + 1) - '1');
                print_game(map, map2, 0);
                if (finish(map)) {
                    my_printf("Player 2 win\n");
                    return 1;
                }
                if (finish(map2)) {
                    my_printf("You win\n");
                    return 1;
                }
            }
        }
    }
}

int pid_f(void)
{
    int pid;
    if (global_data) {
        pid = *((int *) global_data);
        global_data = NULL;
    }
    return pid;
}

void player_one(char **av)
{
    size_t size = 3;
    char **map = map_init(av[1]);
    char **map2 = map_init(NULL);
    char *f = malloc(size--);
    struct sigaction signal1 = {0};
    struct sigaction signal2 = {0};
    signal1.sa_sigaction = connection_a;
    signal1.sa_flags = SA_SIGINFO;
    my_printf("waiting for enemy connection...\n\n");
    sigaction(SIGUSR2, &signal1, NULL);
    pause();
    int pid = pid_f();
    signal2.sa_sigaction = receive;
    sigaction(SIGUSR1, &signal2, NULL);
    sigaction(SIGUSR2, &signal2, NULL);
    my_printf("enemy connected\n\n");
    print_game(map, map2, 1);
    f = attack(f, pid);
    if (game_loop(map, map2, pid, f))
        return;
}

void player_two(char **av)
{
    struct sigaction signal1 = {0};
    struct sigaction signal2 = {0};
    char **map = map_init(av[2]);
    char **map2 = map_init(NULL);
    signal1.sa_sigaction = connection_b;
    signal1.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &signal1, NULL);
    int pid = my_getnbr(av[1]);

    if (kill(pid, SIGUSR2) == -1)
        return;
    pause();
    signal2.sa_sigaction = receive;
    sigaction(SIGUSR1, &signal2, NULL);
    sigaction(SIGUSR2, &signal2, NULL);
    print_game(map, map2, 0);
    my_printf("\nwaiting for enemy's attack...\n");
    if (game_loop(map, map2, pid, NULL))
        return;
}
