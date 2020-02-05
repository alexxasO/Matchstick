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

int matchstick(int lines, int max, int *turn)
{
    int *game_table = create_game_table(lines);
    int playing = 1;
    turn_info ti;

    print_map(lines, game_table);
    while (playing) {
        if (*turn == 1)
            playing = get_turn_info_pl(&ti, lines, game_table, max);
        else
            get_turn_info_ai(&ti, game_table, lines, max);
        if  (playing == 0)
            return 0;
        apply_matchsticks(game_table, ti);
        if (is_map_empty(game_table, lines)) {
            print_map_empty(lines, game_table);
            playing = 0;
        } else
            print_map(lines, game_table);
        *turn = -(*turn);
    }
    return 0;
}

int main(int ac, char **av)
{
    int max = 0;
    int lines = 0;
    int turn = 1;

    if (ac != 3)
        return 84;
    srandom(time(NULL));
    lines = my_getnbr(av[1]);
    max = my_getnbr(av[2]);
    if (matchstick(lines, max, &turn))
        return 0;
    if (turn == -1) {
        my_putstr("You lost, too bad...\n");
        return 1;
    }
    if (turn == 1) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return 2;
    }
    return 84;
}