/*
** EPITECH PROJECT, 2018
** CPool_evalexpr_2018
** File description:
** get numbers from string
*/

#include "my.h"

int my_atoi(char const *s)
{
    int nbr = 0;

    for (;*s >= '0' && *s <= '9'; s++)
        nbr = nbr * 10 + (*s - '0');
    return nbr;
}

long long int my_atoll(char const *s)
{
    long long int nbr = 0;

    for (;*s >= '0' && *s <= '9'; s++)
        nbr = nbr * 10 + (*s - '0');
    return nbr;
}

long long int getnbr_rec(char const *ch, long long int i)
{
    if (i < LLONG_MIN + 10)
        return LLONG_MIN;
    if (i > LLONG_MAX - 10)
        return LLONG_MAX;
    if (*ch && *(ch + 1) \
        && (*ch == '-' && my_isdigit(*(ch + 1))))
        return -getnbr_rec((ch + 1), i * 10);
    if (*ch && my_isdigit(*ch))
        return getnbr_rec((ch + 1), i * 10  + (*ch - '0'));
    return i;
}

long long int my_getnbr(char const *str)
{
    if (!str)
        return 0;
    return getnbr_rec(str, 0LL);
}
