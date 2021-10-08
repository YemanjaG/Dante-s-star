##
## EPITECH PROJECT, 2019
## MAKEFILE
## File description:
## MAKEFILE
##

all:
		make -C ./solver
		make -C ./generator/

clean:
		make clean -C ./solver
		make clean -C ./generator/

fclean:
		make fclean -C ./solver
		make fclean -C ./generator/

re:
		make re -C ./solver
		make re -C ./generator/

.PHONY:	all clean fclean re