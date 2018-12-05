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

static coord_t add_elem(uint_t x, uint_t y)
{
    coord_t *i = malloc(sizeof(*i));

    i->x = x;
    i->y = y;
    return *i;
}

static uint_t find_longest_line(char **m)
{
    uint_t col = 0;

    for (uint_t tmp = 0, line = 0; m[line]; tmp = 0, line++) {
        for (; m[line][tmp] && m[line][tmp] != '\n'; tmp++);
        col = (col < tmp) ? tmp : col;
    }
    return col;
}

map_t *fill_map(char **map)
{
    map_t *m = gib(sizeof(map_t));
    uint_t box_i = 0;
    uint_t pad_i = 0;

    m->m = map;
    for (uint_t x = 0; m->m[m->max.y] && m->m[m->max.y][x]; m->max.y++, x = 0)
        switch (m->m[m->max.y][x]) {
            case 'X': m->boxen[box_i++] = add_elem(x, m->max.y);
                m->boxnum++;
                break;
            case 'P': m->play = add_elem(x, m->max.y);
                break;
            case 'O': m->pads[pad_i++] = add_elem(x, m->max.y);
                break;
            default: break;
        }
    m->boxen[box_i] = add_elem(UINT_MAX, UINT_MAX);
    m->pads[pad_i] = add_elem(UINT_MAX, UINT_MAX);
    m->max.x = find_longest_line(m->m);
    return m;
}

void print_map(win_t *w, map_t *m)
{
    for (uint_t i = 0; m->m[i]; i++) {
        mvprintw((w->max.y - m->max.y) / 2, (w->max.x - m->max.x) / 2, m->m[i]);
    }
}

void destroy_map(map_t *m)
{
    destroy_double_array(m->m);
    free(m->boxen);
    free(m->pads);
}
