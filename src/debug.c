/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** debug.c
*/

void print_table_debug(int *game_table, int lines)
{
    for (int i = 0; i < lines; i++)
        printf("game_table[%d] = %d\n", i, game_table[i]);
}