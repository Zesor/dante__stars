##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile of Generator for Dante
##

SRC =	main.c	\
		vector_basic.c	\
		vector_more.c	\
		dante_more.c	\
		utils.c

OBJ =   $(SRC:.c=.o)


CFLAGS	= -W -Wall -Wextra -Wno-unused -g3

CPPFLAGS	=	-I include/ -Ofast

NAME	=   generator


all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -O3 -o $(NAME) $(MAIN_OBJ) $(OBJ) $(LDFLAGS) $(CFLAGS) $(CPPFLAGS) -g3

clean:
	$(RM) $(OBJ)
	$(RM) *.gc*

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all $(NAME) clean fclean re