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
    char *buffer = NULL;
    long length = 0;
    FILE *f = fopen("help.txt", "rb");

    if (argc == 2 && strcmp(argv[1], "-h") == 0)
        length = 1;
    if (length == 0)
        return 0;
    fseek(f, 0, SEEK_END);
    length = ftell(f);
    fseek(f, 0, SEEK_SET);
    buffer = malloc(length + 1);
    fread(buffer, 1, length, f);
    buffer[length] = '\0';
    fclose(f);
    printf("%s\n", buffer);
    free(buffer);
    return 1;
}

int main(int argc, char **argv)
{
    S_t s = {0};
    pars_t pars = {0};

    if (read_h(argc, argv) == 1)
        return 0;
    return 0;
}
