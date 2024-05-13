/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-corewar-leo.gregori
** File description:
** sub.c
*/
#include "../corewar.h"
#include "../my.h"

void inst_sub(champion_t *current)
{
    my_printf("\x1b[38;5;208m" "  ├──sub: " "\x1b[0m");
    my_printf("Le joueur %d(%s) est vivant.\n",
    current->prog_number, current->prog_name);
}
