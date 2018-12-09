movement.c:    char *c = (m->p.y < (w->max.x + 1)) ? &m->m[m->p.y + 1][m->p.x] : 0;
movement.c:    char *n = (m->p.y < (w->max.x + 2)) ? &m->m[m->p.y + 2][m->p.x] : 0;
movement.c:    char *c = (m->p.x < w->max.y) ? &m->m[m->p.y][m->p.x + 1] : 0;
movement.c:    char *n = (m->p.x < (w->max.y + 2)) ? &m->m[m->p.y][m->p.x + 2] : 0;
check.c:    if (m->max.x >= w->max.x || m->max.y >= w->max.y) {
check.c:        mvaddstr((w->max.y / 2), (w->max.x - my_strlen(msg)) / 2, msg);
window.c:    getmaxyx(stdscr, w->max.x, w->max.y);
window.c:        getmaxyx(stdscr, w->max.y, w->max.x);
