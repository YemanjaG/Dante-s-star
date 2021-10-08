##
## EPITECH PROJECT, 2019
## task01
## File description:
## task01 of CPool_Day10_2019
##

SRC	=	*.c\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all : $(NAME)

$(NAME):	$(OBJ)
	@echo "Building the .o files.."
	@gcc -c $(SRC)
	@echo "Building my library.."
	@ar rc $(NAME) $(OBJ)
	@cp $(NAME) ../
	@mkdir -p ../../include
	@cp *.h ../../include

clean:
	@rm -f $(OBJ)

fclean:		clean
	@rm -f $(NAME)
	@rm -f ../$(NAME)
	@rm -r ../../include

re: 	fclean all
