/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** matches.c
*/

#include "matchstick.h"

static void check_and_display_matches(int *table, turn_info *info, int m_max)
{
    if (table[info->line - 1] < info->nb)
        my_putstr("Error: not enough matches on this line\n");
    if (info->nb <= 0)
        my_putstr("Error: you have to remove at least one match\n");
    if (info->nb > m_max)
        my_printf("Error: you cannot remove more than %d matches per turn\n", m_max);
}

static void check_and_display_lines(turn_info *info, int l_max)
{
    if (info->line > l_max || info->line <= 0)
        my_putstr("Error: this line is out of range\n");
}

int *create_game_table(int line)
{
    int *game_table = malloc(sizeof(int) * line);

    for (int i = 0; i < line; i++)
        game_table[i] = ((i + 1) * 2) - 1;
    return game_table;
}

void get_turn_info_pl(turn_info *info, int l_max, int *table, int m_max)
{
    char *buf = malloc(sizeof(char) * READ_SIZE + 1);
    int readsize = 0;

    my_putstr("Your turn:\n");
    do {
        my_putstr("Line: ");
        readsize = read(0, buf, READ_SIZE);
        buf[readsize] = '\0';
        info->line = my_getnbr(buf);
        check_and_display_lines(info, l_max);
    } while ((info->line > l_max || info->line <= 0));
    do {
        my_putstr("Matches: ");
        readsize = read(0, buf, READ_SIZE);
        buf[readsize] = '\0';
        info->nb = my_getnbr(buf);
        check_and_display_matches(table, info, m_max);
    } while (table[info->line - 1] < info->nb || info->nb <= 0 ||
            info->nb > m_max);
    my_printf("Player removed %d match(es) from line %d\n",
                info->nb, info->line);
}

void get_turn_info_ai(turn_info *info, int *table, int line_max, int matches_max)
{
    int line = (random() % line_max - 1) + 1;
    int nb = 0;

    my_putstr("AI's turn...\n");
    while (table[line - 1] == 0)
        line = (random() % line_max - 1) + 1;
    info->line = line;
    info->nb = (random() % MIN(table[line - 1], matches_max)) + 1;
    my_printf("AI removed %d match(es) from line %d\n", info->nb, info->line);
}

void apply_matchsticks(int *table, turn_info ti)
{
    if (!table[ti.line - 1])
        exit(84);
    table[ti.line - 1] += -(ti.nb);
}