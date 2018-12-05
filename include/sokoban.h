/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** sokoban header
*/

#ifndef SOKOBAN_H
#define SOKOBAN_H

#include <curses.h>
#include "my.h"

typedef struct {
    uint_t x;
    uint_t y;
    char b;
} coord_t;

typedef struct {
    coord_t cur;
    coord_t max;
} win_t;

typedef struct {
    coord_t play;
    coord_t *boxen;
    coord_t *pads;
    uint_t boxnum;
    coord_t max;
    char **m;
} map_t;

void set_colors(void);
win_t *init(void);
int win_close(win_t *);
void run_game(win_t *);

map_t *mkmap(size_t const, size_t const);
map_t *set_map(char **);

char **check_map(char **);
char **get_buf(char const *);

#endif
