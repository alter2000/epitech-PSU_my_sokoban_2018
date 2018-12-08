/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** sokoban header
*/

#ifndef SOKOBAN_H
#define SOKOBAN_H

#include <stdio.h>
#include <curses.h>
#include <limits.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "my.h"

typedef struct {
    uint_t x;
    uint_t y;
} coord_t;

typedef struct {
    coord_t cur;
    coord_t max;
} win_t;

typedef struct {
    coord_t p;
    coord_t old;
    coord_t *pads;
    uint_t boxnum;
    uint_t padnum;
    coord_t max;
    char **m;
} map_t;

// check.c
void sokoban_err(char **d, char *s);
char **get_buf(char const *path);
bool check_solved(map_t *m);
bool small_screen(win_t *w, map_t *m);

// handle_map.c
map_t *mkmap(char **map);
void print_map(win_t *w, map_t *m);
void destroy_map(map_t *m);
coord_t *get_coords(char **m, uint_t num, char elem);
coord_t add_elem(uint_t x, uint_t y);

// map.c
map_t *fill_map(char **map);
void reload_pads(map_t *m);

// more_check.c
void sighandle(int sig);
bool disgusting_neighbor_condition(char **c, uint_t y, uint_t x);
int check_stuck(map_t *m);
char check(char *c, char *n);

// movement.c
void go_left(win_t *w, map_t *m);
void go_down(win_t *w, map_t *m);
void go_up(win_t *w, map_t *m);
void go_right(win_t *w, map_t *m);

// window.c
void set_colors(void);
win_t *init(void);
void event(win_t *w, map_t *m, char **av);
void run_game(win_t *w, map_t *m, char **av);

int main(int ac, char **av);

#endif
