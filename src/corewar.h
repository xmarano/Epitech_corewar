/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-corewar-leo.gregori
** File description:
** corewar.h
*/
#include "my.h"
#include "op.h"
#include <stdint.h>
#ifndef COREWAR_H
    #define COREWAR_H

typedef struct pars {
    bool dump;
    bool n;
    bool a;
} pars_t;

typedef struct Global {
    pars_t pars;
} Global_t;

int parsing_arguments(char **argv, Global_t *s);
void live(int player_number, char *player_name);

#endif
