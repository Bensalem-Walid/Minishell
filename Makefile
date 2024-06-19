##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for 101 pong
##

SRC	=	src/mysh.c \
		src/env.c \
		src/pid.c \
		src/cd.c \
		src/env_two.c \
		src/setenv.c \
		src/all_command.c \
		src/segfault.c \
		src/pid_error.c \
		src/redirection.c \
		src/initialisation_token.c \
		lib/mini_printf.c \
		lib/my_putchar.c \
		lib/my_putnbr.c \
		lib/my_putstr.c \
		lib/my_strlen.c \
		lib/my_strcmp.c \
		lib/my_strcat.c \
		lib/my_strcpy.c \
		lib/my_strdup.c \
		lib/my_getenv.c \
		lib/my_strncmp.c \
		lib/my_strncpy.c \
		lib/my_str_chr.c \
		lib/my_strstr.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

NB = 0
SRC_COUNT = $(words $(SRC))

CFLAGS = -w

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

%.o: %.c
	@$(eval NB=$(shell echo $$(($(NB)+1))))
	@gcc -c -o $@ $^ $(CFLAGS) && python3 build/build.py $< $(NB) $(SRC_COUNT)

clean:
	rm -f $(OBJ)
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re: fclean all
