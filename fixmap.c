/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** map fixing functions
*/

#include "sokoban.h"

map_t *mkmap(char **map)
{
    map_t *m = gib(sizeof(*m));

    m->m = map;
    m->boxen = gib((sizeof(*m->boxen) + 1) * m->boxnum);
    m->pads = gib((sizeof(*m->pads) + 1) * m->padnum);
    return m;
}

void print_map(win_t *w, map_t *m)
{
    for (uint_t i = 0; m->m[i] && *m->m[i]; i++) {
        /* for (uint_t j = 0; m->m[i][j] && m->m[i][j] != '\n'; j++) */
        mvaddstr(i, 0, m->m[i]);
    }
}

void destroy_map(map_t *m)
{
    destroy_double_array(m->m);
    free(m->boxen);
    free(m->pads);
}

coord_t *get_coords(char **m, uint_t num, char elem)
{
    coord_t *coord = gib(sizeof(coord_t) * (1 + num));

    for (uint_t i = 0, j = 0, k = 0; m && m[i] && m[i][j]; i++, j = 0) 
        for (; m[i][j]; j++)
            if (m[i][j] == elem)
                coord[k++] = add_elem(j, i);
    return coord;
}
