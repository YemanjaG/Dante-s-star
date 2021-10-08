/*
** EPITECH PROJECT, 2019
** Dante_solver
** File description:
** Dante_solver
*/

#include "include/my.h"

int main(int ac, char** av)
{
	if (ac != 2)
		return 84;
	all *va = init_struct(ac, av);
	if (labyrinthe(av[1], va) != 0)
		return 84;
	va->start_col = 1;
	va->start_row = 1;
	va->maze = va->laby;
	init_num_maze(va);
	if (pathmaker(va->start_row, va->start_col, va) == 0){
		printf("No path found\n");
		return 84;
	} else {
		add_path(va);
		real_print(va);
	}
	return 0;
}