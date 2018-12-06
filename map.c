/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** writing and reading functions
*/

#include "sokoban.h"
#include <sys/stat.h>
#include <stdio.h>
#include <limits.h>

coord_t add_elem(uint_t x, uint_t y)
{
    coord_t *i = malloc(sizeof(*i));

    i->x = x;
    i->y = y;
    return *i;
}

static uint_t find_longest_line(char **m)
{
    uint_t col = 0;

    for (uint_t tmp = 0, line = 0; m[line] && *m[line]; tmp = 0, line++) {
        for (; m[line] && *m[line] && \
                m[line][tmp] && m[line][tmp] != '\n'; tmp++);
        if (m[line] && *m[line])
            col = (col < tmp) ? tmp : col;
    }
    return col;
}

map_t *fill_map(char **map)
{
    map_t *m = gib(sizeof(*m));

    m->m = map;
    for (uint_t x = 0; m->m[m->max.y] && m->m[m->max.y][x]; m->max.y++, x = 0)
        for (; m->m[m->max.y][x]; x++)
            switch (m->m[m->max.y][x]) {
                case 'X': m->boxnum++;
                        break;
                case 'P': m->play = add_elem(x, m->max.y);
                        break;
                case 'O': m->padnum++;
                        break;
                default: break;
            }
    m->boxen = get_coords(m->m, m->boxnum, 'X');
    m->pads = get_coords(m->m, m->padnum, 'O');
    m->max.x = find_longest_line(m->m);
    return m;
}
