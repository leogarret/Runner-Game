##
## EPITECH PROJECT, 2018
## Made by Léo Garret
## File description:
## Makefile
##

SRC		=	src/main.c \
			src/game.c \
			src/functions.c \
			src/game_init.c \
			src/events_manager.c \
			src/graphics.c \
			src/player.c \
			src/map_manager.c \
			src/pieces.c \
			src/menu.c \
			src/function2.c \
			src/gameplay.c \
			src/fuel.c \
			src/scene.c \
			src/game_init_2.c \
			src/init.c \
			src/init_2.c \
			src/end.c \
			src/reset_game.c \
			src/obstacle.c \
			src/trap.c \
			src/help.c \
			src/norm.c

OBJ     =       $(SRC:.c=.o)

CC	=	gcc

WFLAGS	=	-W -Wall -Werror -Wextra -pedantic

CFLAGS	=	-I./include

NAME	=	my_runner

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(WFLAGS) $(OBJ) -o $(NAME) $(CFLAGS) -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system
clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
