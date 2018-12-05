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

void fill_attrs(map_t *m)
{
    uint_t box_i = 0;
    uint_t pad_i = 0;

    for (uint_t y = 0, x = 0; m->m[y] && m->m[y][x]; y++, x = 0)
        switch (m->m[y][x]) {
            case 'X': m->boxen[box_i++] = add_elem(x, y);
                m->boxnum++;
                break;
            case 'P': m->play = add_elem(x, y);
                break;
            case 'O': m->pads[pad_i++] = add_elem(x, y);
                break;
            default: break;
        }
    m->boxen[box_i] = add_elem(UINT_MAX, UINT_MAX);
    m->pads[pad_i] = add_elem(UINT_MAX, UINT_MAX);
}

map_t *set_map(char **map)
{
    map_t *m = gib(sizeof(map_t));

    m->m = map;
    fill_attrs(m);
    return m;
}

void print_map(map_t *m)
{

}

void destroy_map(map_t *m)
{
    destroy_double_array(m->m);
    free(m->boxen);
    free(m->pads);
}
