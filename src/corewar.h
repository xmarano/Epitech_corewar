/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-corewar-leo.gregori
** File description:
** corewar.h
*/
#include "my.h"
#include "op.h"
#ifndef COREWAR_H
    #define COREWAR_H

typedef struct pars {
    bool dump;
    int nb_cor;
} pars_t;

typedef struct Global {
    pars_t pars;
    op_t op;
    int prog_number;
} Global_t;

typedef struct champion {
    int prog_number;
    int load_address;
    char *prog_name;
    struct champion *next;
} champion_t;

int parsing_arguments(char **argv, Global_t *s);
void arguments_to_linked_list(char **argv, Global_t *s, champion_t *champ);
void live(int player_number, char *player_name);

#endif
