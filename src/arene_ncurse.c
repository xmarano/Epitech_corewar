/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-corewar-leo.gregori
** File description:
** arene_ncurse.c
*/
#include "corewar.h"
#include "my.h"

void set_color(void)
{
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(5, COLOR_WHITE, COLOR_RED);
    init_pair(6, COLOR_WHITE, COLOR_CYAN);
    init_pair(7, COLOR_WHITE, COLOR_GREEN);
    init_pair(8, COLOR_WHITE, COLOR_MAGENTA);
}

static void display_arena_colors(Global_t *s, int temp, int i, char *str)
{
    if (temp != s->arena[i].id && temp == 0) {
        attron(COLOR_PAIR(s->arena[i].id + 4) | A_BOLD | A_BLINK);
        printw("%c%c", str[0], str[1]);
        attroff(COLOR_PAIR(s->arena[i].id + 4) | A_BOLD | A_BLINK);
        printw("%c", str[2]);
    } else {
        attron(COLOR_PAIR(s->arena[i].id) | A_BOLD);
        printw("%s", str);
        attroff(COLOR_PAIR(s->arena[i].id) | A_BOLD);
    }
}

static void instruction(Global_t *s, char byte[3], int i)
{
    if (my_strcmp(byte, "0B") == 0)
        inst_sti(s, i);
}

void check_instruction(Global_t *s, char *str, int i)
{
    char byte[3];

    byte[0] = str[0];
    byte[1] = str[1];
    byte[2] = '\0';
}

void display_arena(Global_t *s)
{
    char str[4];
    int a = 0;
    int temp = 0;

    for (int i = 0; i < MEM_SIZE; i++) {
        str[0] = s->arena[i].val;
        i++;
        str[1] = s->arena[i].val;
        str[2] = ' ';
        str[3] = '\0';
        check_instruction(s, str, i);
        display_arena_colors(s, temp, i, str);
        if ((a + 1) % 64 == 0) {
            printw("\n");
            a = 0;
            continue;
        }
        temp = s->arena[i].id;
        a++;
    }
}

void arene_ncurse(Global_t *s, champion_t *champ, reg_t *reg)
{
    int key;

    initscr();
    noecho();
    curs_set(0);
    start_color();
    set_color();
    while (1) {
        clear();
        display_arena(s);
        display_infos(s, champ, reg);
        refresh();
        key = getch();
        if (key == 'q' || s->nbr_cycles_count == s->op.nbr_cycles)
            break;
        if (key == ' ')
            s->nbr_cycles_count++;
    }
    endwin();
}
