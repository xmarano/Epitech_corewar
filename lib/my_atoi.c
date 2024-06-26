/*
** EPITECH PROJECT, 2023
** my_atoi
** File description:
** Infos
*/
#include "../src/my.h"

int my_atoi(char *str)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    if (str[0] == '-') {
        sign = -1;
        i++;
    }
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            break;
        result = result * 10 + str[i] - '0';
        i++;
    }
    return sign * result;
}
