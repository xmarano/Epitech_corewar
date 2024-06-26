/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-corewar-leo.gregori
** File description:
** main.c
*/
#include "corewar.h"
#include "my.h"

int read_h(int argc, char **argv)
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int verif = 0;

    if (argc == 2 && my_strcmp(argv[1], "-h") == 0)
        verif = 1;
    if (verif == 0)
        return 0;
    file = fopen("help.txt", "r");
    read = getline(&line, &len, file);
    while (read != -1) {
        read = getline(&line, &len, file);
        my_printf("%s", line);
    }
    my_printf("\n");
    free(line);
    fclose(file);
    return 1;
}

void test_instructions(champion_t *current, Global_t *s, int i)
{
    if (my_strcmp(current->prog_body[i], "01") == 0)
        inst_live(current);
    if (my_strcmp(current->prog_body[i], "02") == 0)
        inst_ld(s);
    if (my_strcmp(current->prog_body[i], "03") == 0)
        inst_st(current);
    if (my_strcmp(current->prog_body[i], "04") == 0)
        inst_add(current);
    if (my_strcmp(current->prog_body[i], "05") == 0)
        inst_sub(current);
    if (my_strcmp(current->prog_body[i], "0B") == 0)
        inst_sti(current);
    s->pc++;
}

void disp_list(champion_t *champ, Global_t *s)
{
    champion_t *current = champ;

    current = current->next;
    while (current != NULL) {
        my_printf("\x1b[38;5;21m" "champ %s:\n" "\x1b[0m", current->prog_name);
        my_printf("├──Prog_number: %d\n", current->prog_number);
        my_printf("├──Load_address: %d\n", current->load_address);
        my_printf("├──Prog_name: %s\n", current->prog_name);
        my_printf("└──Prog_body:");
        for (int i = 0; current->prog_body[i] != NULL; i++)
            my_printf(" %s", current->prog_body[i]);
        my_printf("\n");
        for (int i = 0; current->prog_body[i] != NULL; i++)
            test_instructions(current, s, i);
        current = current->next;
    }
}

void free_linked_list(champion_t *champ, Global_t *s)
{
    champion_t *current = champ;
    champion_t *temp;

    current = current->next;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp->prog_name);
        for (int i = 0; temp->prog_body[i] != NULL; i++)
            free(temp->prog_body[i]);
        free(temp->prog_body);
        free(temp);
    }
    free(s->arena);
}

static void init_arena(Global_t *s)
{
    int i = 0;

    s->arena = malloc(MEM_SIZE * sizeof(arena_t));
    for (int i = 0; i < MEM_SIZE; i++) {
        s->arena[i].val = '0';
        s->arena[i].id = i;
    }
}

int main(int argc, char **argv)
{
    Global_t s = {0};
    champion_t champ = {0};

    if (read_h(argc, argv) == 1)
        return 0;
    if (parsing_arguments(argv, &s) == 84)
        return 84;
    init_arena(&s);
    arguments_to_linked_list(argv, &s, &champ);
    for (int i = 0; i < s.op.nbr_cycles; i++)
        disp_list(&champ, &s);
    free_linked_list(&champ, &s);
    return 0;
}
