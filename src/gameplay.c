/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** gameplay.c
*/

#include "matchstick.h"

static int choose_line(int l_max, turn_info *info, char *buf, int *table)
{
    int readsize = 0;

    do {
        my_putstr("Line: ");
        readsize = read(0, buf, READ_SIZE);
        buf[readsize] = '\0';
        info->line = my_getnbr(buf);
        check_and_display_lines(info, l_max, table);
    } while ((info->line > l_max || info->line <= 0));
    return 0;
}

int choose_matches(char *buf, turn_info *info, int *table, int m_max)
{
    int readsize = 0;

    do {
        my_putstr("Matches: ");
        readsize = read(0, buf, READ_SIZE);
        buf[readsize] = '\0';
        info->nb = my_getnbr(buf);
        check_and_display_matches(table, info, m_max);
    } while (table[info->line - 1] < info->nb || info->nb <= 0 ||
            info->nb > m_max);
}

void get_turn_info_pl(turn_info *info, int l_max, int *table, int m_max)
{
    char *buf = malloc(sizeof(char) * READ_SIZE + 1);
    int readsize = 0;

    my_putstr("Your turn:\n");
    choose_line(l_max, info, buf, table);
    choose_matches(buf, info, table, m_max);
    my_printf("Player removed %d match(es) from line %d\n",
                info->nb, info->line);
}