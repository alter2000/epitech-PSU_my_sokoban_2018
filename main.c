/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** sokoban main
*/

#include "sokoban.h"

int main(int ac, char **av)
{
    if (ac != 2)
        errb("Map file?\n");

    win_t *win = init();
    run_game(win, av[1]);
    return win_close(win);
}
