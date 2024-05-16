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

typedef struct arena {
    char val;
    int id;
    int pos;
} arena_t;

typedef struct Global {
    pars_t pars;
    op_t op;
    int prog_number;
    arena_t *arena;
} Global_t;

typedef struct champion {
    int prog_number;
    int load_address;
    char *prog_name;
    char **prog_body;
    struct champion *next;
} champion_t;

typedef struct reg {
    int pos;
    int r[16];
    struct reg *next;
} reg_t;

int parsing_arguments(char **argv, Global_t *s);
void arguments_to_linked_list(char **argv, Global_t *s,
    champion_t *champ, reg_t *reg);
void inst_add(champion_t *current);
void inst_ld(Global_t *s);
void inst_live(champion_t *current);
void inst_st(champion_t *current);
void inst_sti(Global_t *s, int i);
void inst_sub(champion_t *current);
void arene_ncurse(Global_t *s, champion_t *champ, reg_t *reg);
void display_infos(Global_t *s, champion_t *champ, reg_t *reg);
#endif
