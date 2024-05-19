/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-corewar-leo.gregori
** File description:
** parsing_arguments.c
*/
#include "corewar.h"
#include "my.h"

int dump_argument(char **argv, Global_t *s, int *i)
{
    if (my_strcmp("-dump", argv[(*i)]) == 0) {
        if (argv[(*i) + 1] != NULL && my_is_num(argv[(*i) + 1]) == 0) {
            s->pars.dump = true;
            s->op.nbr_cycles = my_atoi(argv[(*i) + 1]);
            (*i) = (*i) + 2;
        } else
            return 84;
    }
    return 0;
}

int n_argument(char **argv, Global_t *s, int *i)
{
    if (my_strcmp("-n", argv[(*i)]) == 0) {
        if (argv[(*i) + 1] != NULL && my_is_num(argv[(*i) + 1]) == 0)
            (*i) = (*i) + 2;
        else
            return 84;
    }
    return 0;
}

int a_argument(char **argv, Global_t *s, int *i)
{
    if (my_strcmp("-a", argv[(*i)]) == 0) {
        if (argv[(*i) + 1] != NULL && my_is_num(argv[(*i) + 1]) == 0)
            (*i) = (*i) + 2;
        else
            return 84;
    }
    return 0;
}

static int open_core_file(char *filename)
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    file = fopen(filename, "r");
    if (file == NULL)
        return 84;
    read = getline(&line, &len, file);
    if (read == -1)
        return 84;
    free(line);
    fclose(file);
    return 0;
}

static int is_cor_file(char *filename)
{
    size_t len = my_strlen(filename);
    char *extension = ".cor";
    size_t ext_len = my_strlen(extension);

    if (len < ext_len)
        return 1;
    if (my_strcmp(filename + len - ext_len, extension) == 0)
        return 0;
    else
        return 1;
}

int cor_argument(char **argv, Global_t *s, int *i)
{
    if (is_cor_file(argv[(*i)]) == 0) {
        if (open_core_file(argv[(*i)]) == 84)
            return 84;
        s->pars.nb_cor++;
    } else
        return 84;
    return 0;
}

int parsing_arguments(char **argv, Global_t *s)
{
    for (int i = 0; argv[i] != NULL; i++) {
        if (my_strcmp("./corewar", argv[i]) == 0)
            i++;
        if (dump_argument(argv, s, &i) == 84)
            return 84;
        if (n_argument(argv, s, &i) == 84)
            return 84;
        if (a_argument(argv, s, &i) == 84)
            return 84;
        if (cor_argument(argv, s, &i) == 84)
            return 84;
    }
    if (s->pars.nb_cor == 1 || s->pars.nb_cor > 4)
        return 84;
    return 0;
}
