/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** main.c
*/

#include "matchstick.h"

void apply_matchsticks(int *table, turn_info ti)
{
    if (!table[ti.line - 1])
        exit(84);
    table[ti.line - 1] += -(ti.nb);
}

int matchstick(int lines, int max)
{
    int *game_table = create_game_table(lines);
    int playing = 1;
    int turn = 1;
    turn_info ti;

    print_map(lines, game_table);
    while (playing) {
        if (turn == 1)
            get_turn_info_pl(&ti, lines, game_table, max);
        else
            get_turn_info_ai(&ti, game_table, lines, max);
        apply_matchsticks(game_table, ti);
        print_map(lines, game_table);
        if (is_map_empty(game_table, lines)) {
            playing = 0;
        }
        turn = -turn;
    }
    return 0;
}

int main(int ac, char **av)
{
    int max = 0;
    int lines = 0;

    if (ac != 3)
        return 84;
    srandom(time(NULL));
    lines = my_getnbr(av[1]);
    max = my_getnbr(av[2]);
    matchstick(lines, max);
    return 0;
}