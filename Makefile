##
## EPITECH PROJECT, 2022
## Makefile myls
## File description:
##  Makefile for the myls *EPITECH*
##

SRC	=	my_putchar.c	\
		my_putstr.c	\
		game_setup.c	\
		help.c	\
		hub.c	\
		game.c	\
		gameplay.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

LIB_COMP	=	-I ./include

CSFML_COMP	=	-lcsfml-window -lcsfml-graphics -lcsfml-audio -lcsfml-system

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIB_COMP) $(CSFML_COMP)

clean:
	@rm -f $(OBJ)
	@find -name "#*#" -delete -o -name "*~" -delete

fclean: clean
	@rm -f $(NAME)

re: fclean all
