/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** player_connection.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include "struct.h"
#include "lib.h"
#include "my.h"

global_t global;

void handler(int sig, siginfo_t *siginfo, void *context)
{
    (void) sig;
    (void) context;
    global.var = siginfo->si_pid;
}

int connect_player_one(void)
{
    struct sigaction prepaSignal;
    pid_t pid = getpid();

    my_printf("my_pid:  %d\n", pid);
    my_putstr("Waiting for enemy connection...\n\n");
    sigemptyset(&prepaSignal.sa_mask);
    prepaSignal.sa_sigaction = &handler;
    prepaSignal.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &prepaSignal, NULL);
    pause();
    my_putstr("enemy connected\n\n");
    return (0);
}

int connect_player_two(char **argv, info_t *info)
{
    pid_t pid_2 = getpid();
    int status = 0;

    info->p1_pid = my_atoi(argv[1]);
    status = kill(info->p1_pid, SIGUSR1);
    usleep(4000);
    if (status != 0)
        return (84);
    my_printf("my_pid:  %d\n", pid_2);
    my_putstr("successfully connected\n\n");
    return (0);
}

int player_connection(int argc, char **argv, info_t *info)
{
    info->argc = argc;
    if (argc == 2) {
        connect_player_one();
        info->enemy_pid = global.var;
    }
    if (argc == 3) {
        connect_player_two(argv, info);
    }
    return (0);
}
