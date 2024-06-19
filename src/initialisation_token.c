/*
** EPITECH PROJECT, 2024
** Shell Programming
** File description:
** minishell1
*/

#include "../include/mon.h"

void initialisation_token(char *commands[],
    int command_count, char **env)
{
    char *tableau[1000];
    int compteur;
    char *token;

    for (int i = 0; i < command_count; i++) {
        compteur = 0;
        token = strtok(commands[i], " \n\t");
        while (token != NULL && compteur < 999) {
            tableau[compteur] = token;
            compteur++;
            token = strtok(NULL, " \n\t");
        }
        tableau[compteur] = NULL;
        commande_mysh(tableau, env);
    }
}

void initialisation_token_split(char **env, char *buffer)
{
    char *token;
    char *after_point;
    char *commands[100];
    int command_count = 0;

    token = strtok_r(buffer, ";", &after_point);
    while (token != NULL && command_count < 100) {
        if (my_strlen(token) > 0) {
            commands[command_count] = token;
            command_count++;
        }
        token = strtok_r(NULL, ";", &after_point);
    }
    initialisation_token(commands, command_count, env);
}
