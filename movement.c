/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** movement functions
*/

#include "sokoban.h"

char check(char *c, char *n)
{
    if (c && *c == 'X')
        if (n && (*n == 'O' || *n == ' '))
            return 2;
        else
            return 0;
    else if (c && (*c == ' ' || *c == 'O'))
        return 1;
    else
        return 0;
}

void go_left(win_t *w, map_t *m)
{
    char *cur = &m->m[m->p.y][m->p.x];
    char *c = (m->p.x > 1) ? &m->m[m->p.y][m->p.x - 1] : 0;
    char *n = (m->p.x > 2) ? &m->m[m->p.y][m->p.x - 2] : 0;

    if (check(c, n) == 1) {
        *cur = ' ';
        *c = 'P';
        m->p.x--;
    } else if (check(c, n) == 2) {
        *cur = ' ';
        *c = 'P';
        *n = 'X';
        m->p.x--;
    }
}

void go_down(win_t *w, map_t *m)
{
    char *cur = &m->m[m->p.y][m->p.x];
    char *c = (m->p.y < w->max.y) ? &m->m[m->p.y + 1][m->p.x] : 0;
    char *n = (m->p.y < w->max.y + 1) ? &m->m[m->p.y + 2][m->p.x] : 0;

    if (check(c, n) == 1) {
        *cur = ' ';
        *c = 'P';
        m->p.y++;
    } else if (check(c, n) == 2) {
        *cur = ' ';
        *c = 'P';
        *n = 'X';
        m->p.y++;
    }
}

void go_up(win_t *w, map_t *m)
{
    char *cur = &m->m[m->p.y][m->p.x];
    char *c = (m->p.y > 1) ? &m->m[m->p.y - 1][m->p.x] : 0;
    char *n = (m->p.y > 2) ? &m->m[m->p.y - 2][m->p.x] : 0;

    if (check(c, n) == 1) {
        *cur = ' ';
        *c = 'P';
        m->p.y--;
    } else if (check(c, n) == 2) {
        *cur = ' ';
        *c = 'P';
        *n = 'X';
        m->p.y--;
    }
}

void go_right(win_t *w, map_t *m)
{
    char *cur = &m->m[m->p.y][m->p.x];
    char *c = (m->p.x < w->max.x) ? &m->m[m->p.y][m->p.x + 1] : 0;
    char *n = (m->p.x < w->max.x + 1) ? &m->m[m->p.y][m->p.x + 2] : 0;

    if (check(c, n) == 1) {
        *cur = ' ';
        *c = 'P';
        m->p.x++;
    } else if (check(c, n) == 2) {
        *cur = ' ';
        *c = 'P';
        *n = 'X';
        m->p.x++;
    }
}
