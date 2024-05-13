/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-corewar-leo.gregori
** File description:
** arene_ncurse.c
*/
#include "corewar.h"
#include "my.h"

void arene_ncurse(Global_t *s)
{
    int key;
    int j = 0;

    initscr();
    noecho();
    while (1) {
        clear();
        for (int i = 0; s->arena[i] != '\0'; i++) {
            mvprintw(0, i,"%c", s->arena[i]);
        }
        refresh();
        key = getch();
        if (key == 'q')
            break;
    }
    endwin();
}
