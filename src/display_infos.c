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

void display_infos_bottom(void)
{
    printw("|");
    for (int i = 0; i < 95; i++)
        printw("_");
    printw("|\n");
}

void display_infos(Global_t *s, champion_t *champ)
{
    champion_t *current = champ;
    int champion = 1;

    display_infos_top();
    current = current->next;
    while (current != NULL) {
        printw("|\t\t");
        attron(COLOR_PAIR(champion) | A_BOLD);
        printw("Champion n°%d: ", current->prog_number);
        printw("%s\t\t\t", current->prog_name);
        if (current->load_address == 6144)
            printw("current : %d", ((MEM_SIZE / s->pars.nb_cor) * (champion - 1)));
        else
            printw("current : %d", current->load_address);
        attroff(COLOR_PAIR(champion) | A_BOLD);
        printw("\t\t\t\t|\n");
        current = current->next;
        champion++;
    }
    display_infos_bottom();
}
