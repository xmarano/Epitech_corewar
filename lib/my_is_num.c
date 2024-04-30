/*
** EPITECH PROJECT, 2024
** my_is_num
** File description:
** Infos
*/
#include "../src/my.h"

int my_is_num(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return 1;
    return 0;
}
