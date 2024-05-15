/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-corewar-leo.gregori
** File description:
** ld.c
*/
#include "../corewar.h"
#include "../my.h"

void inst_ld(Global_t *s)
{
    int r3;

    s->reg.r3 = s->pc + 34 % IDX_MOD;
    my_printf("(%d)\n", s->reg.r3);
}
