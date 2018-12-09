/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** movement functions
*/

#include "sokoban.h"

void go_left(win_t *w, map_t *m)
{
    char *cur = &m->m[m->p.y][m->p.x];
    char *c = (m->p.x > 1) ? &m->m[m->p.y][m->p.x - 1] : 0;
    char *n = (m->p.x > 2) ? &m->m[m->p.y][m->p.x - 2] : 0;

    switch (check_cells(c, n)) {
        case 1: *cur = ' ';
                *c = 'P';
                m->p.x--;
                return;
        case 2: *cur = ' ';
                *c = 'P';
                *n = 'X';
                m->p.x--;
                return;
        default: return;
    }
}

void go_down(win_t *w, map_t *m)
{
    char *cur = &m->m[m->p.y][m->p.x];
    char *c = (m->p.y < w->max.x) ? &m->m[m->p.y + 1][m->p.x] : 0;
    char *n = (m->p.y < w->max.x + 1) ? &m->m[m->p.y + 2][m->p.x] : 0;

    switch (check_cells(c, n)) {
        case 1: *cur = ' ';
                *c = 'P';
                m->p.y++;
                return;
        case 2: *cur = ' ';
                *c = 'P';
                *n = 'X';
                m->p.y++;
                return;
        default: return;
    }
}

void go_up(win_t *w, map_t *m)
{
    char *cur = &m->m[m->p.y][m->p.x];
    char *c = (m->p.y > 1) ? &m->m[m->p.y - 1][m->p.x] : 0;
    char *n = (m->p.y > 2) ? &m->m[m->p.y - 2][m->p.x] : 0;

    switch (check_cells(c, n)) {
        case 1: *cur = ' ';
                *c = 'P';
                m->p.y--;
                return;
        case 2: *cur = ' ';
                *c = 'P';
                *n = 'X';
                m->p.y--;
                return;
        default: return;
    }
}

void go_right(win_t *w, map_t *m)
{
    char *cur = &m->m[m->p.y][m->p.x];
    char *c = (m->p.x < w->max.y) ? &m->m[m->p.y][m->p.x + 1] : 0;
    char *n = (m->p.x < w->max.y + 1) ? &m->m[m->p.y][m->p.x + 2] : 0;

    switch (check_cells(c, n)) {
        case 1: *cur = ' ';
                *c = 'P';
                m->p.x++;
                return;
        case 2: *cur = ' ';
                *c = 'P';
                *n = 'X';
                m->p.x++;
                return;
        default: return;
    }
}
