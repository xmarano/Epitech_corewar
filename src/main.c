/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-corewar-leo.gregori
** File description:
** main.c
*/
#include "corewar.h"
#include <stdint.h>
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

int main(int argc, char **argv)
{
    S_t s = {0};
    pars_t pars = {0};

    if (read_h(argc, argv) == 1)
        return 0;
    my_printf("test\n");
    return 0;
}
