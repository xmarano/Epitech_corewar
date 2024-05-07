/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-corewar-leo.gregori
** File description:
** arguments_to_linked_list.c
*/
#include "corewar.h"
#include "my.h"

champion_t *add_champion(champion_t *champ, int prog_number,
    int load_address, char *prog_name)
{
    champion_t *new = malloc(sizeof(champion_t));
    champion_t *current;

    if (new == NULL)
        return champ;
    new->prog_number = prog_number;
    new->load_address = load_address;
    new->prog_name = my_strdup(prog_name);
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

char *init_prog_name(const char *filename)
{
    FILE *file = fopen(filename, "rb");
    uint8_t byte;
    char *str = malloc(1000 * sizeof(char));
    int white_space = 0;
    int i = 0;

    for (int a = 0; a < 4; a++)
        fread(&byte, sizeof(uint8_t), 1, file);
    for (; white_space == 0; i++) {
        fread(&byte, sizeof(uint8_t), 1, file);
        if (byte == 0)
            break;
        str[i] = byte;
    }
    fclose(file);
    return str;
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
        prog_name = init_prog_name(argv[i]);
        champ = add_champion(champ, prog_number, load_address, prog_name);
        free(prog_name);
    }
}
