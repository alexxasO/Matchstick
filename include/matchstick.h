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
#include <time.h>
#include "my.h"

typedef struct
{
    int line;
    int nb;
} turn_info;

void print_map(int lines, int *table);
void apply_matchsticks(int *table, turn_info ti);
void get_turn_info_pl(turn_info *info, int l_max, int *table, int m_max);
void get_turn_info_ai(turn_info *info, int *table, int line_max, int matches_max);
int *create_game_table(int line);
int is_map_empty(int *table, int lines);
int check_and_display_matches(int *table, turn_info *info, int m_max);
int check_and_display_lines(turn_info *info, int l_max);

//DEBUG FUNCTIONS

void print_table_debug(int *game_table, int lines);

#endif