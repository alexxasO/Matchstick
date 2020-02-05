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
    int correct = 0;

    do {
        my_putstr("Line: ");
        readsize = read(0, buf, READ_SIZE);
        if (readsize == 0)
            return 1;
        buf[readsize] = '\0';
        info->line = my_getnbr(buf);
        if ((correct = check_and_display_lines(info, l_max, buf)) == 1)
            continue;
        my_putstr("Matches: ");
        readsize = read(0, buf, READ_SIZE);
        if (readsize == 0) {
            return 1;
        }
        buf[readsize] = '\0';
        info->nb = my_getnbr(buf);
        correct = check_and_display_matches(table, info, info->max, buf);
    } while (correct == 1);
    return 0;
}

int get_turn_info_pl(turn_info *info, int l_max, int *table, int m_max)
{
    char *buf = malloc(sizeof(char) * READ_SIZE + 1);

    info->max = m_max;
    my_putstr("Your turn:\n");
    if (choose_line(l_max, info, buf, table) == 0) {
        my_printf("Player removed %d match(es) from line %d\n",
                    info->nb, info->line);
        return 1;
    }
    return 0;
}