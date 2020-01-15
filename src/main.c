/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** main.c
*/

#include "matchstick.h"

int matchstick(int lines, int max)
{
    int *game_table = create_game_table(lines);
    int playing = 1;
    int turn = 1;
    turn_info ti;

    print_map(lines, game_table);
    while (playing) {
        if (turn == 1)
            get_turn_info_pl(&ti);
        else
            get_turn_info_ai(&ti);
        apply_matchsticks(game_table, ti);
        print_table_debug(game_table, lines);
        print_map(lines, game_table);
        //test si tout est vide et return 2 si pdt tour du joueur (1 sinon)
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
    lines = my_getnbr(av[1]);
    max = my_getnbr(av[2]);
    matchstick(lines, max);
    return 0;
}