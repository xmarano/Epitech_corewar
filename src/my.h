/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-corewar-leo.gregori
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H
    #include <unistd.h>
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include <signal.h>
    #include <sys/stat.h>
    #include <stdbool.h>
    #include <errno.h>
    #include <stdint.h>
    #include <ncurses.h>
    #include "/opt/homebrew/Cellar/sdl2/2.30.3/include/SDL2/SDL.h"
    #include "/opt/homebrew/Cellar/sdl2_mixer/2.8.0/include/SDL2/SDL_mixer.h"
    #include <time.h>
char *my_strchr(const char *s, int c);
char *my_strstr(char *source, char *search);
char *my_strrchr(const char *s, int c);
int my_put_nbr(int nb);
int my_atoi(char *str);
char my_putchar(char c);
int my_is_num(char *str);
int my_strlen(char const *str);
int my_putstr(char const *str);
int my_put_nbr_recursive(int nb);
char *my_strdup(char const *src);
char **str_to_word_array(char *str);
int my_printf(const char *format, ...);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strncpy(char *dest, char const *src, int n);
#endif
