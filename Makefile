##
## EPITECH PROJECT, 2020
## issam ch 
## File description:
## makefile
##

SRC	=	src/my_jam.c	\

OBJ	=	*.o

INCLUDE	=	include/

NAME	=	my_jam

all:	
	gcc -c -I $(INCLUDE) $(SRC)
	gcc -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -I./

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(OBJ)
	rm -f *~
	rm -f *#
	rm -f src/*~
	rm -f src/*#

re: fclean all

.PHONY:	re clean fclean all
