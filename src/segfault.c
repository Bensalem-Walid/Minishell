/*
** EPITECH PROJECT, 2024
** Shell Programming
** File description:
** minishell1
*/

#include "../include/mon.h"

int segfault_two(int status, char *command_path)
{
    if (WCOREDUMP(status)) {
        mini_printf("Segmentation fault (core dumped)\n");
    } else {
        mini_printf("Segmentation fault\n");
    }
    if (command_path != NULL) {
        free(command_path);
    }
    return 139;
}

int segfault(int status, char *command_path)
{
    int signal;

    if (WIFSIGNALED(status)) {
        signal = WTERMSIG(status);
        if (signal == SIGSEGV) {
            return segfault_two(status, command_path);
        }
    }
    return 0;
}
