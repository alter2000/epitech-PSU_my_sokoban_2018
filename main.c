/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** sokoban main
*/

#include "sokoban.h"

static int gib_help(void)
{
    my_putstr("USAGE\n\t./my_sokoban map\nDESCRIPTION\n\tmap\t"
        "file representing the warehouse map, containing '#' for walls,\n\t\t"
        "'P' for the player, 'X' for boxes and 'O' for storage locations.");
    return 0;
}

int main(int ac, char **av)
{
    if (ac != 2)
        errb("Map file?\n");
    if (!my_strcmp(av[1], "-h"))
        return gib_help();
    win_t *win = init();
    map_t *m = fill_map(get_buf(av[1]));

    signal(SIGINT, sighandle);
    signal(SIGWINCH, sighandle);
    run_game(win, m, av);
    free(win);
    endwin();
    return 0;
}
