/*
** EPITECH PROJECT, 2024
** Shell Programming
** File description:
** minishell1
*/

#include "../include/mon.h"

void pid_error(pid_t pid, char *command_path)
{
    if (pid == -1) {
        perror("fork");
        free(command_path);
        exit(84);
    }
}
