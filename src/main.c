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
    char *buffer = NULL;
    char ch;
    long length = 0;
    FILE *f = fopen("help.txt", "rb");
    buffer = malloc(1);

    while ((ch = fgetc(f)) != EOF) {
        buffer[length++] = ch;
        buffer = realloc(buffer, length + 1);
    }
    buffer[length] = '\0';
    fclose(f);
    my_printf("%s\n", buffer);
    free(buffer);
    return 1;
}

int main(int argc, char **argv)
{
    S_t s = {0};
    pars_t pars = {0};

    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        if (read_h(argc, argv) == 1)
            return 0;
    }
    return 0;
}
