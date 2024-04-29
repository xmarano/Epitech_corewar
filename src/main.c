/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-corewar-leo.gregori
** File description:
** main.c
*/
#include "corewar.h"
#include "my.h"

char *read_h(void)
{
    char *buffer = NULL;
    long length;
    FILE *f = fopen("help.txt", "rb");

    if (f) {
        fseek(f, 0, SEEK_END);
        length = ftell(f);
        fseek(f, 0, SEEK_SET);
        buffer = malloc(length + 1);
        if (buffer) {
            fread(buffer, 1, length, f);
            buffer[length] = '\0';
        }
        fclose(f);
    }
    return buffer;
}

int main(int argc, char **argv)
{
    S_t s = {0};
    pars_t pars = {0};

    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        char *help_text = read_h();
        if (help_text) {
            printf("%s\n", help_text);
            free(help_text);
        }
    }
    return 0;
}
