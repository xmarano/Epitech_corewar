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
    s->reg.r3 = s->pc + 34 % IDX_MOD;
    my_printf("\x1b[38;5;208m" "  ├──ld: " "\x1b[0m");
    my_printf("Le registre 3 : (%d)\n", s->reg.r3);
}
