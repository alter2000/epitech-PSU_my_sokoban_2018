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
    char **raw = get_buf(av[1]);

    win_t * win = init();
    run_game(win);
    return win_close(win);
}
