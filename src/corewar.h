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

typedef struct champion {
    int prog_number;
    char *load_address;
    char *prog_name;
    struct Champion *next;
} champion_t;

typedef struct Global {
    pars_t pars;
    op_t op;
    champion_t champ;
    int prog_number;
} Global_t;

int parsing_arguments(char **argv, Global_t *s);
void arguments_to_linked_list(char **argv, Global_t *s);
void live(int player_number, char *player_name);

#endif
