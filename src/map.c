/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** map.c
*/

#include "matchstick.h"

static void print_reg_line(int pos, int col_max, int *table)
{
    int sticks = (pos * 2 - 1);
    int spaces = (col_max - sticks) / 2;
    int removed = sticks - table[pos - 1];
    my_putchar('*');
    for (int i = 0; i < spaces; i++)
        my_putchar(' ');
    for (int i = 0; i < sticks - removed; i++)
        my_putchar('|');
    for (int i = 0; i < spaces + removed; i++)
        my_putchar(' ');
    my_putchar('*');
    my_putchar('\n');
}

static void print_border(int col_max) {
    for (int i = 0; i < col_max + 2; i++) {
        my_putchar('*');
    }
    my_putchar('\n');
}

void print_map(int lines, int *table)
{
    int col_max = (lines * 2) - 1;

    for (int i = 0; i <= lines + 1; i++) {
        if (i <= 0 || i >= lines + 1) {
            print_border(col_max);
            continue;
        }
        print_reg_line(i, col_max, table);
    }
}