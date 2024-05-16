/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-corewar-leo.gregori
** File description:
** sti.c
*/
#include "../corewar.h"
#include "../my.h"

void inst_sti(Global_t *s, int i)
{
    s->arena[i + 1000].val = 'L';
    s->arena[i + 1000].id = s->arena[i].id;
}
