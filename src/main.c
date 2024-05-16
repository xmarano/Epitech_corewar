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

static void fill_arena2(Global_t *s, champion_t *current, int *a, int champion)
{
    for (int i = 0; current->prog_body[i] != NULL; i++) {
        for (int j = 0; current->prog_body[i][j] != '\0'; j++) {
            s->arena[(*a)].val = current->prog_body[i][j];
            s->arena[(*a)].id = champion;
            (*a)++;
        }
    }
}

static void fill_arena(Global_t *s, champion_t *champ, reg_t *reg)
{
    champion_t *current = champ;
    int a = 0;
    int champion = 1;

    current = current->next;
    reg = reg->next;
    while (current != NULL) {
        if (current->load_address == 6144) {
            a = (current->load_address / s->pars.nb_cor) * (champion - 1);
            reg->pos = a;
        } else {
            a = current->load_address;
            reg->pos = a;
        }
        fill_arena2(s, current, &a, champion);
        champion++;
        current = current->next;
        reg = reg->next;
    }
}

void init_arena(Global_t *s, champion_t *champ, reg_t *reg)
{
    int i = 0;

    s->arena = malloc(MEM_SIZE * sizeof(arena_t));
    for (int i = 0; i < MEM_SIZE; i++) {
        s->arena[i].val = '0';
        s->arena[i].pos = i;
    }
    fill_arena(s, champ, reg);
}

static void temp_disp_reg(reg_t *reg)
{
    reg_t *current = reg;
    int champion = 1;

    current = current->next;
    while (current != NULL) {
        my_printf("champion %d - pos : (%d)\n", champion, current->pos);
        for (int i = 0; i != 16; i++)
            my_printf("reg %d : (%d)\n", i, current->r[i]);
        champion++;
        my_printf("\n");
        current = current->next;
    }
}

int main(int argc, char **argv)
{
    Global_t s = {0};
    champion_t champ = {0};
    reg_t reg = {0};

    if (read_h(argc, argv) == 1)
        return 0;
    if (parsing_arguments(argv, &s) == 84)
        return 84;
    arguments_to_linked_list(argv, &s, &champ, &reg);
    init_arena(&s, &champ, &reg);
    temp_disp_reg(&reg);
    if (s.pars.dump == true)
        arene_ncurse(&s, &champ, &reg);
    free_linked_list(&champ, &s);
    return 0;
}
