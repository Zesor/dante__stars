##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

SRC =	main.c					\
		fs_open_file.c			\
		init_list.c				\
		my_engine.c				\
		my_str_to_word_array.c	\

OBJ =   $(SRC:.c=.o)

CFLAGS	= -W -Wall -Wextra -Wno-unused -g3

CPPFLAGS	=	-I include/ -Ofast

NAME	=   solver

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -O3 -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS) $(CPPFLAGS) -g3

clean:
	$(RM) $(OBJ)
	$(RM) *.gc*

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all $(NAME) clean fclean re
