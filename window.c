/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** window manipulation
*/

#include "sokoban.h"
#include <sys/ioctl.h>

void set_colors(void)
{
    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_RED,     COLOR_BLACK);
        init_pair(2, COLOR_GREEN,   COLOR_BLACK);
        init_pair(3, COLOR_YELLOW,  COLOR_BLACK);
        init_pair(4, COLOR_BLUE,    COLOR_BLACK);
        init_pair(5, COLOR_CYAN,    COLOR_BLACK);
        init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(7, COLOR_WHITE,   COLOR_BLACK);
    }
}

win_t *init(void)
{
    win_t *w = gib(sizeof(*w));

    initscr();
    cbreak();
    noecho();
    nonl();
    curs_set(FALSE);
    intrflush(stdscr, FALSE);
    keypad(stdscr, TRUE);
    getmaxyx(stdscr, w->max.x, w->max.y);
    clear();
    return w;
}

void event(win_t *w, map_t *m, char **av)
{
    switch (getch()) {
        case ' ': main(2, av);
        case KEY_LEFT: go_left(w, m);
                        return;
        case KEY_DOWN: go_down(w, m);
                        return;
        case KEY_UP: go_up(w, m);
                        return;
        case KEY_RIGHT: go_right(w, m);
                        return;
        case 'q': endwin();
                  exit(0);
        default: return;
    }
}

void run_game(win_t *w, map_t *m, char **av)
{
    while (1) {
        reload_pads(m);
        getmaxyx(stdscr, w->max.x, w->max.y);
        if (!small_screen(w, m))
            print_map(w, m);
        refresh();
        event(w, m, av);
        if (check_stuck(m) == m->padnum){
            destroy_map(m);
            endwin();
            exit(1);
        } else if (check_solved(m) == m->padnum)
            break;
        usleep(1000);
    }
    destroy_map(m);
}
