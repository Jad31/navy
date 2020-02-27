/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** free_all
*/

#include <stdlib.h>
#include "lib.h"
#include "my.h"

void free_all(info_t *info)
{
    free_double_char(info->enemy_map);
    free_double_char(info->map);
    free_triple_array(info->boat_pos);
}
