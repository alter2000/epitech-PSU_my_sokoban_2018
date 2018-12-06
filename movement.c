/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** movement functions
*/

#include "sokoban.h"

void go_left(win_t *w, map_t *m)
{
    printw("-------- PLAYER MAP DATA left---------");
    printw("player in: %u; %u\n", m->play.y, m->play.x);
    printw("max coords: %u; %u\n", m->max.y, m->max.x);
    printw("box number: %u\n", m->boxnum);
    printw("-------- END PLAYER MAP DATA -------------");
    printw("window cursor in: %u; %u\n", w->cur.x, w->cur.y);
}

void go_down(win_t *w, map_t *m)
{
    printw("-------- PLAYER MAP DATA down---------");
    printw("player in: %u; %u\n", m->play.y, m->play.x);
    printw("max coords: %u; %u\n", m->max.y, m->max.x);
    printw("box number: %u\n", m->boxnum);
    printw("-------- END PLAYER MAP DATA -------------");
    printw("window cursor in: %u; %u\n", w->cur.x, w->cur.y);
}

void go_up(win_t *w, map_t *m)
{
    printw("-------- PLAYER MAP DATA up-----------");
    printw("player in: %u; %u\n", m->play.y, m->play.x);
    printw("max coords: %u; %u\n", m->max.y, m->max.x);
    printw("box number: %u\n", m->boxnum);
    printw("-------- END PLAYER MAP DATA -------------");
    printw("window cursor in: %u; %u\n", w->cur.x, w->cur.y);
}

void go_right(win_t *w, map_t *m)
{
    printw("-------- PLAYER MAP DATA right--------");
    printw("player in: %u; %u\n", m->play.y, m->play.x);
    printw("max coords: %u; %u\n", m->max.y, m->max.x);
    printw("box number: %u\n", m->boxnum);
    printw("-------- END PLAYER MAP DATA -------------");
    printw("window cursor in: %u; %u\n", w->cur.x, w->cur.y);
}
