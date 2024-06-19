/*
** EPITECH PROJECT, 2024
** Mon.h
** File description:
** Solo Stumper02
*/

#ifndef MON_H_
    #define MON_H_

    #include <stdarg.h>
    #include <stddef.h>
    #include <signal.h>
    #include <stddef.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <limits.h>
    #include <unistd.h>
    #include <sys/wait.h>
    #include <sys/stat.h>
    #include <errno.h>
    #include <stdbool.h>
    #include <fcntl.h>
    #include <stdint.h>
    #include <string.h>

    #define MAX_ENV_VARS 1000
    #define PATH_MAX 1024

struct globalvariables {
    char lastDir[PATH_MAX];
};

typedef struct {
    char *command_path;
    char **before_pipe;
    char **after_pipe;
    char *command_path_pipe;
    char **env;
} pipeparams_t;

typedef struct {
    char **filename;
    bool *verif;
} redirectioninfo_t;

extern struct globalvariables global_vars;

//Fonction Lib
void my_putchar(char c);
char *my_strdup(const char *s);
int my_strncmp(char *s1, const char *s2, int n);
void my_putnbr(int nb);
const char *my_strstr(const char *haystack, const char *needle);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcpy(char *dest, char const *src);
int my_putstr(char const *str);
char *my_strcat(char *dest, char const *src);
int my_strlen(char const *str);
int lettre(const char *format, va_list list, int i);
int mini_printf(const char *format, ...);
int my_strcmp(char *str1, char *str2);
char *my_getenv(const char *name);
char *my_strchr(char *s, int c);

//Fonction src/
int cd_execute(char *token);
int cd_execute_two(char *token);
int all_commande_linux(char **tableau, char **env);
int segfault(int status, char *command_path);
void pid_error(pid_t pid, char *command_path);
void add_env_variable(char **env, const char *name, const char *value);
void update_env_variable(char *env_var, const char *name, const char *value);
int while_env(char **env, const char *name);
int unset_env_variable(char **env, const char *name);
void display_env(char **env);
void add_env_variable(char **env, const char *name, const char *value);
int set_env_variable(char **env, const char *name, const char *value);
int while_env(char **env, const char *name);
void update_env_variable(char *env_var, const char *name, const char *value);
void display_env(char **env);
char *find_command_in_path(const char *cmd);
int pid_normal(char *command_path, char **tableau, char **env);
void initialisation_token(char *commands[],
    int command_count, char **env);
void initialisation_token_split(char **env, char *buffer);
int befor_after_pipe(char *command_path, char **tableau, char **env);
int create_file(char *filename);
int initialisation_redirection(char *command_path, char **tableau, char **env);
void env_command(char **env);
char *verif(char **tableau);
void commande_mysh(char **tableau, char **env);

#endif
