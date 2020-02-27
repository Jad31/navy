/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** header
*/

#include "struct.h"
#include "macro.h"

#ifndef MY_H
#define MY_H

int navy(int , char **);
int usage(int argc, char **argv);
int error_handling(int);
char **create_map(void);
int navy(int, char **);
int file_error(int ac, char **av, info_t *info);
int check_file(char ***);
int player_connection(int, char **);
void load_maps(info_t *);
void game_loop(int, info_t *);
void print_turn(info_t *info);
char ***put_file_in_triple_array(char ***boat_pos, int fd);
void init_struct(info_t *info);
void load_boat(int argc, info_t *info);
void free_all(info_t *info);
int check_attack_input(char *);
void send_attack(int *binary, char);
char *receive_attack(void);
int attack(info_t *info, char *coord);

#endif
