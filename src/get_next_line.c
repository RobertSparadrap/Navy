/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** get_next_line
*/

#include "../include/get_next_line.h"
#include "../include/navy.h"

char *mcpy(const char *a, char *b, int n)
{
    for (int i = 0; i < n; i++)
        *(b + i) = *(a + i);
    return b;
}

char *append_str(gnl_t gnl, buffer_t b)
{
    char *tmp = malloc(gnl.l_pos);
    if (gnl.l_pos > 0)
        mcpy(gnl.line, tmp, gnl.l_pos);
    free(gnl.line);
    char *line = malloc(gnl.l_pos + b.eol - b.pos + 1);
    if (gnl.l_pos > 0)
        mcpy(tmp, line, gnl.l_pos);
    mcpy(b.buff + b.pos, line + gnl.l_pos, b.eol - b.pos);
    free(tmp);
    return line;
}

int load(int fd, buffer_t * b)
{
    int size = read(fd, b->buff, READ_SIZE);
    b->eol = b->pos = 0;
    return size;
}

void analyse(gnl_t * gnl, buffer_t * b)
{
    gnl->line = append_str(*gnl, *b);
    gnl->l_pos += b->eol - b->pos;
    if (gnl->line[gnl->l_pos - 1] == '\n') {
        gnl->line[gnl->l_pos] = 0;
        gnl->p = 1;
    }
}

char *get_next_line(int fd)
{
    gnl_t gnl = {0};
    static buffer_t b = {0};
    static int r = 1, size;
    if (!b.buff)
        b.buff = malloc(READ_SIZE + 2);
    while (1) {
        if (r)
            size = load(fd, &b);
        if (!size) break;
        while (1)
            if (b.buff[b.eol] == 0 || b.eol == size || b.buff[b.eol++] == '\n')
                break;
        analyse(&gnl, &b);
        r = (b.eol == size);
        b.pos = b.eol;
        if (gnl.p) return gnl.line;
    }
    return gnl.line;
}
