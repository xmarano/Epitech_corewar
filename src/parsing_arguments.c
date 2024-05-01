/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-corewar-leo.gregori
** File description:
** parsing_arguments.c
*/
#include "corewar.h"
#include "my.h"

int dump_argument(char **argv, Global_t *s, int i)
{
    if (my_strcmp("-dump", argv[i]) == 0) {
        if (argv[i + 1] != NULL && my_is_num(argv[i + 1]) == 0)
            s->pars.dump = true;
        else
            return 84;
    }
    return 0;
}

int n_argument(char **argv, Global_t *s, int i)
{
    if (my_strcmp("-n", argv[i]) == 0) {
        if (argv[i + 1] != NULL && my_is_num(argv[i + 1]) == 0)
            s->pars.n = true;
        else
            return 84;
    }
    return 0;
}

int a_argument(char **argv, Global_t *s, int i)
{
    if (my_strcmp("-a", argv[i]) == 0) {
        if (argv[i + 1] != NULL && (argv[i + 1][0]) != '-')
            s->pars.a = true;
        else
            return 84;
    }
    return 0;
}

int parsing_arguments(char **argv, Global_t *s)
{
    for (int i = 0; argv[i] != NULL; i++) {
        if (my_strcmp("./corewar", argv[i]) == 0)
            continue;
        if (dump_argument(argv, s, i) == 84)
            return 84;
        if (n_argument(argv, s, i) == 84)
            return 84;
        if (a_argument(argv, s, i) == 84)
            return 84;
    }
    return 0;
}
