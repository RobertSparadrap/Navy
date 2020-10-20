/*
** EPITECH PROJECT, 2019
** wrap_nbr
** File description:
** warp
*/

#include "../../include/my.h"

int my_put_nbr_wrap(va_list *arg)
{
    my_put_nbr(va_arg(*arg, int));
}

int my_put_nbr_abs_wrap(va_list *arg)
{
    my_put_nbr_abs(va_arg(*arg, int));
}
