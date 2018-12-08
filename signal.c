/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** signal handling and open/closing
*/

#include "sokoban.h"
#include <signal.h>

void sighandle(int sig)
{
    switch (sig) {
        case SIGINT: endwin();
            exit(0);
        case SIGWINCH:
            return;
        default: return;
    }
}
