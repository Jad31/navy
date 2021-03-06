/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** put_file_in_triple_array
*/

#include <stdlib.h>
#include "my.h"
#include "lib.h"

char ***put_file_in_triple_array(char ***boat_pos, int fd)
{
    char *str = NULL;
    int j = 0;

    boat_pos = malloc(sizeof(char **) * 5);
    for (; (str = get_next_line(fd)) != NULL; j++) {
        if (double_check(str) != 0)
            return (NULL);
        if (j <= 4) {
            boat_pos[j] = my_str_to_word_array(str, boat_pos[j], ':');
            free(str);
        }
    }
    if (j != 4)
        return (NULL);
    boat_pos[j] = NULL;
    return (boat_pos);
}
