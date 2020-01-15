/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** matches.c
*/

#include "matchstick.h"

int *create_game_table(int line)
{
    int *game_table = malloc(sizeof(int) * line);

    for (int i = 0; i < line; i++)
        game_table[i] = ((i + 1) * 2) - 1;
    return game_table;
}

void get_turn_info_pl(turn_info *info)
{
    char *buf = malloc(sizeof(char) * READ_SIZE + 1);
    int readsize = 0;

    my_putstr("Your turn:\n");
    my_putstr("Line: ");
    readsize = read(0, buf, READ_SIZE);
    buf[readsize] = '\0';
    info->line = my_getnbr(buf);
    my_putstr("Matches: ");
    readsize = read(0, buf, READ_SIZE);
    buf[readsize] = '\0';
    info->nb = my_getnbr(buf);
    my_printf("Player removed %d match(es) from line %d\n", info->nb, info->line);
}

void get_turn_info_ai(turn_info *info)
{
    my_putstr("AI's turn...\n");
}

void apply_matchsticks(int *table, turn_info ti)
{
    if (!table[ti.line - 1])
        exit(84);
    table[ti.line - 1] += -(ti.nb);
}