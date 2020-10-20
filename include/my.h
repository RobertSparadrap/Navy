/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** Print librairy
*/

#ifndef MY_H
#define MY_H

#include "navy.h"

typedef struct flag
{
    char c;
    int (*f)(va_list*);
} flag;

int my_printf(char *str, ...);
int my_put_nbr_abs(int nb);
int my_putnbr_base(int nbr, char const *base);
int my_putstr_wrap(va_list *arg);
int my_putchar_wrap(va_list *arg);
int my_putnbr_b_wrap(va_list *arg);
int my_putnbr_o_wrap(va_list *arg);
int my_putnbr_x_wrap(va_list *arg);
int my_putnbr_big_x_wrap(va_list *arg);
int my_put_nbr_wrap(va_list *arg);
int my_put_nbr_abs_wrap(va_list *arg);
int my_put_percent(va_list *arg);
int my_getnbr_char(char str);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcpy(char *dest, char const *src);

#endif
