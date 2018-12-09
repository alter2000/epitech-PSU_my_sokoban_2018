/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** more checks for game state
*/

#include "sokoban.h"
#include <signal.h>
#include <sys/ioctl.h>

void sighandle(int sig)
{
    switch (sig) {
        case SIGINT: endwin();
            exit(0);
        case SIGSEGV: endwin();
            exit(84);
        case SIGWINCH: endwin();
            refresh();
            clear();
            return;
        default: return;
    }
}

bool disgusting_neighbor_condition(map_t *m, uint_t y, uint_t x)
{
    return (m->m[y][x] == 'X' && \
    (((m->m[y - 1][x] == '#' && m->m[y][x - 1] == '#') || \
    (m->m[y - 1][x] == 'X' && m->m[y][x - 1] == 'X') || \
    (m->m[y - 1][x] == '#' && m->m[y][x - 1] == 'X') || \
    (m->m[y - 1][x] == 'X' && m->m[y][x - 1] == '#')) || \
    ((m->m[y - 1][x] == '#' && m->m[y][x + 1] == '#') || \
    (m->m[y - 1][x] == 'X' && m->m[y][x + 1] == 'X') || \
    (m->m[y - 1][x] == '#' && m->m[y][x + 1] == 'X') || \
    (m->m[y - 1][x] == 'X' && m->m[y][x + 1] == '#')) || \
    ((m->m[y + 1][x] == '#' && m->m[y][x + 1] == '#') || \
    (m->m[y + 1][x] == 'X' && m->m[y][x + 1] == 'X') || \
    (m->m[y + 1][x] == '#' && m->m[y][x + 1] == 'X') || \
    (m->m[y + 1][x] == 'X' && m->m[y][x + 1] == '#')) || \
    ((m->m[y + 1][x] == '#' && m->m[y][x - 1] == '#') || \
    (m->m[y + 1][x] == 'X' && m->m[y][x - 1] == 'X') || \
    (m->m[y + 1][x] == '#' && m->m[y][x - 1] == 'X') || \
    (m->m[y + 1][x] == 'X' && m->m[y][x - 1] == '#'))));
}

uint_t check_stuck(map_t *m)
{
    uint_t stuck = 0;

    for (uint_t i = 1, j = 1; m->m[i + 1] && *m->m[i + 1]; i++, j = 1)
        for (; m->m[i + 1][j + 1]; j++)
            if (disgusting_neighbor_condition(m, i, j))
                stuck++;
    return stuck;
}

char check_cells(char *c, char *n)
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
