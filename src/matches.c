/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** matches.c
*/

#include "matchstick.h"

int check_and_display_matches(int *table, turn_info *info, int m_max)
{
    // if (info->nb == NULL)
    //     return 84;
    if (table[info->line - 1] < info->nb)
        my_putstr("Error: not enough matches on this line\n");
    if (info->nb <= 0)
        my_putstr("Error: you have to remove at least one match\n");
    if (info->nb > m_max)
        my_printf("Error: you cannot remove more than %d matches per turn\n",
                    m_max);
    return 0;
}

int check_and_display_lines(turn_info *info, int l_max)
{
    // if (info->nb == NULL) {
    //     return 84;
    // }
    if (info->line > l_max || info->line <= 0)
        my_putstr("Error: this line is out of range\n");
    return 0;
}

int *create_game_table(int line)
{
    int *game_table = malloc(sizeof(int) * line);

    for (int i = 0; i < line; i++)
        game_table[i] = ((i + 1) * 2) - 1;
    return game_table;
}

void get_turn_info_ai(turn_info *info, int *table, int line_max, int m_max)
{
    int line = (random() % line_max - 1) + 1;

    my_putstr("AI's turn...\n");
    while (table[line - 1] == 0)
        line = (random() % line_max - 1) + 1;
    info->line = line;
    info->nb = (random() % MIN(table[line - 1], m_max)) + 1;
    my_printf("AI removed %d match(es) from line %d\n", info->nb, info->line);
}