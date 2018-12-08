/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** window manipulation
*/

#include "sokoban.h"

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

int win_close(win_t *win)
{
    free(win);
    endwin();
    return 0;
}

void event(win_t *w, map_t *m, char **av)
{
    signal(SIGINT, sighandle);
    signal(SIGWINCH, sighandle);
    switch (getch()) {
        case ' ': main(2, av);
        case KEY_LEFT: go_left(w, m);
                       break;
        case KEY_DOWN: go_down(w, m);
                       break;
        case KEY_UP: go_up(w, m);
                     break;
        case KEY_RIGHT: go_right(w, m);
                        break;
        case 'q': win_close(w);
                  exit(0);
        default: break;
    }
}

void run_game(win_t *w, map_t *m, char **av)
{
    while (1) {
        clear();
        if (!small_screen(w, m))
            print_map(w, m);
        event(w, m, av);
        refresh();
        usleep(1000);
        if (check_solved(m))
            break;
    }
    destroy_map(m);
}
