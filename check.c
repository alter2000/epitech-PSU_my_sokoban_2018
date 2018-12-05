/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** checkers
*/

#include "sokoban.h"
#include <stdlib.h>
#include <sys/stat.h>

char **check_map(char **s)
{
    bool player = false;
    int boxes = 0;

    while (s && *s && **s)
        switch (**s) {
            case 'O': boxes--;
                break;
            case 'X': boxes++;
                break;
            case 'P': player = (player) ? errm(s, "Two base states?\n") : true;
                break;
            case '\n': case '#': case ' ': (*s)++;
                break;
            default: errm(s, "Invalid map\n");
        }
    if (boxes)
        errm(s, "Incorrect number of boxes and pads\n");
    return s;
}

char **get_buf(char const *path)
{
    FILE *f = (path) ? fopen(path, "r") : 0;
    uint_t ln = 0;
    char **s = 0;
    char *p = 0;

    if (!f)
        errb("Invalid path\n");
    for (size_t m = 0; getline(&p, &m, f) != -1; p = 0, m = 0, ln++);
    fclose(f);
    f = fopen(path, "r");
    s = gib(ln);
    for (size_t i = 0, n = 0; getline(&s[i++], &n, f) > 0; n = 0);
    fclose(f);
    return check_map(s);
}
