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

typedef struct S {
    bool dump;
    bool n;
    bool a;
} S_t;

typedef struct pars {
    int test;
} pars_t;

int parsing_arguments(char **argv, S_t *s);
void live(int player_number, char *player_name);

#endif
