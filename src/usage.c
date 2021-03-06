/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** usage.c
*/

#include "lib.h"

int usage(int argc, char **argv)
{
    if (argc == 2 && my_strcmp("-h", argv[1]) == 0) {
        my_putstr("USAGE\n");
        my_putstr("      ./navy [first_player_pid] navy_positions\n");
        my_putstr("Description\n");
        my_putstr("     first_player_pid:  only for the 2nd player. pid pf");
        my_putstr(" the first player\n");
        my_putstr("     navy_positions:  file containing the positions of the");
        my_putstr(" ships.\n");
        return (1);
    }
    return (0);
}
