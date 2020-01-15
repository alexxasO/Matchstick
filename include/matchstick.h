/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** matchstick.h
*/

#ifndef MATCHSTICK
#define MATCHSTICK

#define READ_SIZE 128

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

typedef struct
{
    int line;
    int nb;
} turn_info;

void print_map(int lines, int *table);
void apply_matchsticks(int *table, turn_info ti);
void get_turn_info_pl(turn_info *info);
void get_turn_info_ai(turn_info *info);
int *create_game_table(int line);
//DEBUG FUNCTIONS
void print_table_debug(int *game_table, int lines);

#endif