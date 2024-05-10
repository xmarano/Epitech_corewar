/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-corewar-leo.gregori
** File description:
** live.c
*/
#include "../corewar.h"
#include "../my.h"

void live(champion_t *current)
{
    my_printf("Le joueur %d(%s) est vivant.\n",
    current->prog_number, current->prog_name);
}
