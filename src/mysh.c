/*
** EPITECH PROJECT, 2024
** Shell Programming
** File description:
** minishell1
*/

#include "../include/mon.h"


static void verif_setenv(char **tableau, char **env)
{
    if (tableau[1] == NULL && tableau[2] == NULL) {
        env_command(env);
    }
    if (tableau[1] != NULL && tableau[2] != NULL) {
        set_env_variable(env, tableau[1], tableau[2]);
    }
    if (tableau[1] != NULL && tableau[2] == NULL)
        set_env_variable(env, tableau[1], NULL);
}

static int command_env(char **tableau, char **env)
{
    if (my_strcmp(tableau[0], "setenv") == 0) {
        if (tableau[1] != NULL && tableau[2] != NULL && tableau[3] != NULL) {
            mini_printf("setenv: Too many arguments.\n");
            return 84;
        }
        verif_setenv(tableau, env);
    }
    if (my_strcmp(tableau[0], "unsetenv") == 0) {
        if (tableau[1] != NULL)
            unset_env_variable(env, tableau[1]);
        else {
            mini_printf("unsetenv: Too few arguments.\n");
            return 84;
        }
    }
}

void commande_mysh(char **tableau, char **env)
{
    if (my_strcmp(tableau[0], "env") == 0)
        env_command(env);
    if (my_strcmp(tableau[0], "cd") == 0)
        cd_execute(tableau[1]);
    if (my_strcmp(tableau[0], "exit") == 0) {
        mini_printf("exit\n");
        exit(0);
    }
    if (my_strcmp(tableau[0], "setenv") == 0
    || my_strcmp(tableau[0], "unsetenv") == 0)
        command_env(tableau, env);
    if (my_strcmp(tableau[0], "exit") != 0 && my_strcmp(tableau[0], "cd") != 0
    && my_strcmp(tableau[0], "setenv") != 0 && my_strcmp(tableau[0],
    "unsetenv") != 0 && my_strcmp(tableau[0], "env") != 0){
        all_commande_linux(tableau, env);
    }
}

int main(int argc, char **argv, char **env)
{
    char *buffer = NULL;
    size_t size = 0;
    ssize_t read;

    while (1) {
        mini_printf("$> ");
        read = getline(&buffer, &size, stdin);
        if (read == -1) {
            mini_printf("\nexit\n");
            free(buffer);
            exit(84);
        }
        initialisation_token_split(env, buffer);
        free(buffer);
        buffer = NULL;
    }
    return 0;
}
