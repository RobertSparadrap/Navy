/*
** EPITECH PROJECT, 2020
** map
** File description:
** navy
*/

#include "../include/navy.h"

char *my_split(char *str, const char del)
{
    static char *a = NULL;
    static char *to_free = NULL;
    if (str != NULL) {
        if (!to_free)
            free(to_free);
        a = malloc(my_strlen(str) + 1);
        to_free = a;
        my_strcpy(a, str);
    }
    char *ret = a;
    while (*a != del && *a != '\n' && *a != '\0')
        a++;
    *(a++) = '\0';
    return ret;
}

int put_boat(char **map, char *line)
{
    char *a = my_split(line, ':');
    char *b = my_split(NULL, ':');
    char *c = my_split(NULL, ':');
    map_line_t *map_line = malloc(sizeof(*map_line));
    map_line->a = *a;
    map_line->b1 = *b;
    map_line->b2 = *c;
    map_line->c = *(c + 1);
    map_line->c1 = *(b + 1);
    int dx = *b - *c;
    int dy = *(b + 1) - *(c + 1);
    if (dx * dy != 0)
        return -1;
    if (dx)
        hboat(map, map_line);
    if (dy)
        vboat(map, map_line);
    return 0;
}

char **map_init(char *name)
{
    char **map = malloc(sizeof(char *) * 8);
    for (int i = 0; i < 8; i++) {
        *(map + i) = malloc(8);
        for (int y = 0; y < 8; y++)
            map[i][y] = 0;
    }
    if (name) {
        int fd = open(name, O_RDONLY);
        char *line = get_next_line(fd);
        while (line) {
            put_boat(map, line);
            line = get_next_line(fd);
        }
    }
    return map;
}

void map_print(char **map)
{
    my_printf(" |A B C D E F G H\n");
    my_printf("-+---------------\n");
    for (int i = 0; i < 8; i++) {
        my_printf("%d|", i + 1);
        for (int y = 0; y < 8; y++)
            my_printf("%c ", map[i][y] == 0 ? '.' : map[i][y]);
        my_printf("\n");
    }
}

int map_close(char **map)
{
    for (int i = 0; i < 8; i++)
        free(map[i]);
    free(map);
}

