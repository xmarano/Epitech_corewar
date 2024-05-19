/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-corewar-leo.gregori
** File description:
** display_infos.c
*/
#include "corewar.h"
#include "my.h"

void display_infos_top(void)
{
    for (int i = 0; i < 95; i++) {
        if (i == 0)
            printw(" ");
        printw("_");
    }
    printw("\n");
    printw("|");
    for (int i = 0; i < 95; i++)
        printw(" ");
    printw("|\n");
}

void display_infos_bottom(Global_t *s)
{
    printw("|");
    for (int i = 0; i < 95; i++)
        printw("_");
    printw("|");
    attron(COLOR_PAIR(s->nbr_cycles_count % 10) | A_BOLD);
    printw("\tCYCLE : %d/%d\t(press [SPACE] for next cycle)\n",
    s->nbr_cycles_count, s->op.nbr_cycles);
    attroff(COLOR_PAIR(s->nbr_cycles_count % 10) | A_BOLD);
}

void display_infos(Global_t *s, champion_t *champ, reg_t *reg)
{
    champion_t *current = champ;
    int cham = 1;

    display_infos_top();
    reg = reg->next;
    current = current->next;
    while (current != NULL) {
        printw("|\t\t");
        attron(COLOR_PAIR(cham) | A_BOLD);
        printw("Champion n°%d: ", current->prog_number);
        printw("%s\t\t\t", current->prog_name);
        printw("current: %d", reg->pos);
        attroff(COLOR_PAIR(cham) | A_BOLD);
        printw("\t\t\t\t|\n");
        reg = reg->next;
        current = current->next;
        cham++;
    }
    display_infos_bottom(s);
}
