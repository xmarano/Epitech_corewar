/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-corewar-leo.gregori
** File description:
** arguments_to_linked_list.c
*/
#include "corewar.h"
#include "my.h"

//champion_t *add_champ(champion_t *champ, int numero, char *nom, char *fichier)
//{
//    Robot_t *nouveau_robot = malloc(sizeof(Robot_t));
//    if (nouveau_robot == NULL) {
//        // Gestion de l'erreur d'allocation de mémoire
//        return champ;
//    }
//    nouveau_robot->numero = numero;
//    nouveau_robot->nom = strdup(nom);
//    nouveau_robot->fichier = strdup(fichier);
//    nouveau_robot->suivant = NULL;
//
//    if (champ == NULL) {
//        return nouveau_robot;
//    }
//    // Trouver le dernier robot dans la liste
//    Robot_t *courant = champ;
//    while (courant->suivant != NULL) {
//        courant = courant->suivant;
//    }
//    // Ajouter le nouveau robot à la fin de la liste
//    courant->suivant = nouveau_robot;
//    return champ;
//}


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

void arguments_to_linked_list(char **argv, Global_t *s)
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
        prog_name = strdup(argv[i]);
        my_printf("%d | %d | %s\n", prog_number, load_address, prog_name);
        free(prog_name);
    }
}
