##
## EPITECH PROJECT, 2021
## delivery
## File description:
## Makefile
##


all:
	(cd generator && make)
	(cd solver && make)

clean:
	(cd generator && make fclean)
	(cd solver && make fclean)

fclean:	clean

re:	fclean all

.PHONY:	all clean fclean re