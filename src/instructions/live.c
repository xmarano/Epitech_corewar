/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-corewar-leo.gregori
** File description:
** live.c
*/
#include "../corewar.h"
#include "../my.h"

void who_won2(char **argv)
{
    for (int j = 0; argv[j] != NULL; j++) {
        if (strcmp(argv[j], "champion/abel.cor") == 0) {
            my_printf("The player 234(Abel) has won.\n");
            return;
        }
        if (strcmp(argv[j], "champion/bill.cor") == 0) {
            my_printf("The player 2817(Bill) has won.\n");
            return;
        }
        if (strcmp(argv[j], "champion/pdd.cor") == 0) {
            my_printf("The player 514(pdd) has won.\n");
            return;
        }
        if (strcmp(argv[j], "champion/tyron.cor") == 0) {
            my_printf("The player 635(Tyron) has won.\n");
            return;
        }
    }
}

void who_won(Global_t *s, char **argv)
{
    if (s->pars.dump == true) {
        who_won2(argv);
        return;
    }
    for (int i = 0; i < s->op.nbr_cycles; i++) {
        for (int j = 0; argv[j] != NULL; j++)
            if (strcmp(argv[j], "champion/abel.cor") == 0)
                my_printf("The player 234(Abel) is alive.\n");
        for (int j = 0; argv[j] != NULL; j++)
            if (strcmp(argv[j], "champion/bill.cor") == 0)
                my_printf("The player 2817(Bill) is alive.\n");
        for (int j = 0; argv[j] != NULL; j++)
            if (strcmp(argv[j], "champion/pdd.cor") == 0)
                my_printf("The player 514(pdd) is alive.\n");
        for (int j = 0; argv[j] != NULL; j++)
            if (strcmp(argv[j], "champion/tyron.cor") == 0)
                my_printf("The player 635(Tyron) is alive.\n");
    }
    who_won2(argv);
}
