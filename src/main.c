/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** main.c
*/

#include "matchstick.h"

void print_reg_line(int pos, int col_max)
{
    int sticks = (pos * 2 - 1);
    int spaces = (col_max - sticks) / 2;
    //TODO print les spaces puis sticks puis space encore
    my_putchar('*');
    for (int i = 0; i < spaces; i++)
        my_putchar(' ');
    for (int i = 0; i < sticks; i++)
        my_putchar('|');
    for (int i = 0; i < spaces; i++)
        my_putchar(' ');
    my_putchar('*');
    my_putchar('\n');
}

void print_border(int col_max) {
    for (int i = 0; i < col_max + 2; i++) {
        my_putchar('*');
    }
    my_putchar('\n');
}

void print_map(int lines)
{
    int col_max = (lines * 2) - 1;

    for (int i = 0; i <= lines + 1; i++) {
        if (i <= 0 || i >= lines + 1) {
            print_border(col_max);
            continue;
        }
        print_reg_line(i, col_max);
    }
}

int matchstick(int lines, int max)
{
    print_map(lines);
    return 0;
}

int main(int ac, char **av)
{
    int max = 0;
    int lines = 0;
    
    if (ac != 3)
        return 84;
    lines = my_getnbr(av[1]);
    max = my_getnbr(av[2]);
    matchstick(lines, max);
    return 0;
}