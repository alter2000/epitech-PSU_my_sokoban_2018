/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** checkers
*/

#include "sokoban.h"
#include <stdlib.h>
#include <sys/stat.h>

void sokoban_err(char **d, char *s)
{
    destroy_double_array(d);
    write(2, s, my_strlen(s));
    endwin();
    exit(84);
}

static char **check_map(char **s)
{
    bool dude = false;
    int boxes = 0;

    for (uint_t r = 0, c = 0; s && s[r] && s[r][c]; r++, c = 0)
        for (; s[r][c]; c++)
            switch (s[r][c]) {
                case 'O': boxes--;
                        break;
                case 'X': boxes++;
                        break;
                case 'P': dude = !dude;
                        break;
                case '\n': case '#': case ' ': break;
                default: sokoban_err(s, "Invalid map\n");
            }
    if (boxes) sokoban_err(s, "Incorrect number of boxes and pads\n");
    if (!dude) sokoban_err(s, "There needs to be exactly one player\n");
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
    for (size_t i = 0, n = 0; getline(s + i, &n, f) > 0; n = 0, i++);
    fclose(f);
    return check_map(s + 1);
}
