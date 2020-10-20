/*
** EPITECH PROJECT, 2019
** PSU_Navy
** File description:
** Header of the Navy.
*/

#ifndef NAVY_H_
#define NAVY_H_

#define _POSIX_C_SOURCE 200809L
#include <signal.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include "my.h"

#define ERROR 84

typedef struct map_line_s
{
    char a;
    char b1;
    char b2;
    char c;
    char c1;
    char c2;
}map_line_t;

typedef struct gnl_s
{
    char *line;
    int l_pos;
    int p;
}gnl_t;

typedef struct buffer_s
{
    char *buff;
    int pos;
    int eol;
}buffer_t;

void *global_data;

/// Main ///
int main(int ac, char **av);
int error(char *map, int i);
void co(int ac, char **av);
char *get_next_line(int fd);
void map_print(char **map);
char **map_init(char *name);
int map_close(char **map);

/// Game ///
void player_one(char **av);
void player_two(char **av);
int pid_f(void);
int game_loop(char **map, char **map2, int pid, char *f);
void receive(int signo, siginfo_t *sig, void *s);
void connection_a(int i, siginfo_t *sig, void *s);

/// Connection ///
void connection_b(int i, siginfo_t *sig, void *s);
int send(char *a, int pid);
void print_game(char **map, char **map2, int i);
int check_input(char *in);
int check(char **map, char *msg);

/// Utils ///
char *my_split(char *str, const char del);
void vboat(char **map, map_line_t *map_line);
void hboat(char **map, map_line_t *map_line);
void set(char **map, char *pos, int boom);
char *attack(char *f, int pid);
void co(int ac, char **av);

/// Lib ///
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr_char(char str);
int my_getnbr(char const *str);
char *my_strcpy(char *dest, char const *src);

#endif /* NAVY_H_ */
