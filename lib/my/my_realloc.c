/*
** EPITECH PROJECT, 2018
** CPool_Day07_2018
** File description:
** reallocate memory
*/

#include "my.h"

char *my_realloc(char *s, int extra)
{
    char *newstr = 0;
    int oldsize = my_strlen(s);
    int newsize = 1 + oldsize + extra;

    while (!newstr)
        newstr = malloc(sizeof(char) * (newsize + 2));
    newstr = my_strncpy(newstr, s, oldsize);
    free(s);
    return newstr;
}
