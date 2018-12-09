/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** checkers
*/

#include "sokoban.h"

void sokoban_err(char **d, char *s)
{
    write(2, s, my_strlen(s));
    destroy_double_array(d);
    endwin();
    exit(84);
}

static char **check_map(char **s)
{
    char dude = 0;
    int boxes = 0;

    for (uint_t r = 0, c = 0; s && s[r] && s[r][c]; r++, c = 0)
        for (; s[r][c]; c++)
            switch (s[r][c]) {
                case 'O': boxes--;
                        break;
                case 'X': boxes++;
                        break;
                case 'P': dude++;
                        break;
                case '\n': case '#': case ' ': break;
                default: sokoban_err(s, "Invalid map\n");
            }
    if (boxes) sokoban_err(s, "Incorrect number of boxes and pads\n");
    if (dude != 1) sokoban_err(s, "There needs to be exactly one player\n");
    return s;
}

char **get_buf(char const *path)
{
    FILE *f = (path) ? fopen(path, "r") : 0;
    uint_t ln = 0;
    char **s = 0;
    char *p = 0;
    size_t i = 0;

    if (!f)
        errb("Invalid path\n");
    for (size_t m = 0; getline(&p, &m, f) != -1; free(p), m = 0, ln++) ;
    fclose(f);
    f = fopen(path, "r");
    s = gib(ln + 3);
    for (size_t n = 0; getline(&p, &n, f) != -1; \
            p = 0, n = 0, i++)
        s[i] = my_strdup(p);
    s[i] = 0;
    fclose(f);
    return check_map(s);
}

uint_t check_solved(map_t *m)
{
    coord_t *boxes = get_coords(m->m, m->boxnum, 'X');
    uint_t match = 0;

    for (uint_t i = 0; i < m->boxnum; i++)
        for (uint_t j = 0; j < m->padnum; j++)
            if (boxes[i].x == m->pads[j].x && boxes[i].y == m->pads[j].y) {
                match++;
            }
    return match;
}

bool small_screen(win_t *w, map_t *m)
{
    char *msg = "Screen too small";

    if (m->max.x > w->max.x || m->max.y > w->max.y) {
        mvaddstr((w->max.y / 2), (w->max.x - my_strlen(msg)) / 2, msg);
        return false;
    }
    return true;
}
