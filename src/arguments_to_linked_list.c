/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-corewar-leo.gregori
** File description:
** arguments_to_linked_list.c
*/
#include "corewar.h"
#include "my.h"

champion_t *add_champion(champion_t *champ, int prog_number,
    int load_address, char *file)
{
    champion_t *new = malloc(sizeof(champion_t));
    champion_t *current;

    if (new == NULL)
        return champ;
    new->prog_number = prog_number;
    new->load_address = load_address;
    new->prog_name = my_strdup(file);
    new->next = NULL;
    if (champ == NULL)
        return new;
    current = champ;
    while (current->next != NULL)
        current = current->next;
    current->next = new;
    return champ;
}

int init_prog_number(char **argv, Global_t *s, int *i)
{
    int nb = 0;

    if (my_strcmp("-n", argv[(*i)]) == 0) {
        nb = my_atoi(argv[(*i) + 1]);
        (*i) = (*i) + 2;
    } else {
        s->prog_number++;
        nb = s->prog_number;
    }
    return nb;
}

int init_load_address(char **argv, Global_t *s, int *i)
{
    int nb = 0;

    if (my_strcmp("-a", argv[(*i)]) == 0) {
        nb = my_atoi(argv[(*i) + 1]);
        (*i) = (*i) + 2;
    } else
        nb = MEM_SIZE;
    return nb;
}

void arguments_to_linked_list(char **argv, Global_t *s, champion_t *champ)
{
    int prog_number = 0;
    int load_address = 0;
    char *prog_name;

    for (int i = 0; argv[i] != NULL; i++) {
        if (my_strcmp("./corewar", argv[i]) == 0)
            i++;
        if (my_strcmp("-dump", argv[i]) == 0)
            i = i + 2;
        prog_number = init_prog_number(argv, s, &i);
        load_address = init_load_address(argv, s, &i);
        prog_name = my_strdup(argv[i]);
        champ = add_champion(champ, prog_number, load_address, prog_name);
        free(prog_name);
    }
}
