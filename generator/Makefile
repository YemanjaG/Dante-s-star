##
## EPITECH PROJECT, 2019
## MAKEFILE
## File description:
## MAKEFILE
##

SRC	=	*.c\

NAME	=	generator

all: $(NAME)

$(NAME):
	@$(MAKE) -C ./lib/my
	@gcc -g $(SRC) -o $(NAME) -L./lib -lmy

clean:
	@$(MAKE) -C ./lib/my clean

fclean:		clean
	@rm -f $(NAME)
	@$(MAKE) -C ./lib/my fclean

re:	fclean all
