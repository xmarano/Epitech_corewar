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

void test_instructions(champion_t *current)
{
    my_printf("\x1b[38;5;208m" "  ├──add: " "\x1b[0m");
    add(current);
    my_printf("\x1b[38;5;208m" "  ├──ld: " "\x1b[0m");
    ld(current);
    my_printf("\x1b[38;5;208m" "  ├──live: " "\x1b[0m");
    live(current);
    my_printf("\x1b[38;5;208m" "  ├──st: " "\x1b[0m");
    st(current);
    my_printf("\x1b[38;5;208m" "  └──sub: " "\x1b[0m");
    sub(current);
}

void disp_list(champion_t *champ)
{
    champion_t *current = champ;

    current = current->next;
    while (current != NULL) {
        my_printf("\x1b[38;5;21m" "champ %s:\n" "\x1b[0m", current->prog_name);
        my_printf("├──Prog_number: %d\n", current->prog_number);
        my_printf("├──Load_address: %d\n", current->load_address);
        my_printf("├──Prog_name: %s\n", current->prog_name);
        my_printf("└──Prog_body: %s\n", current->prog_body);
        test_instructions(current);
        current = current->next;
    }
}

void free_linked_list(champion_t *champ)
{
    champion_t *current = champ;
    champion_t *temp;

    current = current->next;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp->prog_name);
        free(temp->prog_body);
        free(temp);
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
    arguments_to_linked_list(argv, &s, &champ);
    disp_list(&champ);
    free_linked_list(&champ);
    return 0;
}
