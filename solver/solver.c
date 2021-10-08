/*
** EPITECH PROJECT, 2019
** Dante_solver
** File description:
** Dante_solver
*/

#include "include/my.h"

void add_path(all *va)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < va->rows; i++) {
		for (j = 0; j < va->cols; j++) {
			if (va->maze[i][j] != 's' && va->num_tab[i][j] == path)
				va->maze[i][j] = 'o';
			if (va->maze[i][j] == 's' || va->maze[i][j] == 'f')
				va->maze[i][j] = 'o';
		}
	}
}

int pathmaker(int row, int col, all *va)
{
	int* current = &va->num_tab[row][col];
	if (*current == finish)
		return 1;
	if (*current == empty) {
		*current = wall;
		if (pathmaker(row, col - 1, va) != 0){
			*current = path;
			return 1;
		}
		if (pathmaker(row, col + 1, va) != 0){
			*current = path;
			return 1;
		}
		if (pathmaker(row + 1, col, va) != 0){
			*current = path;
			return 1;
		}
		if (pathmaker(row - 1, col, va) != 0){
			*current = path;
			return 1;
		}
	}
	return 0;
}

void num_maze_mem(all *va)
{
	va->num_tab = malloc(va->rows * sizeof(int*));
	int i = 0;
	for (i = 0; i < va->rows; i++){
		va->num_tab[i] = malloc(va->cols * sizeof(int*));
	}
}

void init_num_maze(all *va)
{
	num_maze_mem(va);
	int i = 0;
	int j = 0;
	for (i = 0; i < va->rows; i++) {
		for (j = 0; j < va->cols; j++) {
			if (va->maze[i][j] == 'X') {
				va->num_tab[i][j] = wall;
			}
			else if (va->maze[i][j] == 'f') {
				va->num_tab[i][j] = finish;
			}
			else {
				va->num_tab[i][j] = empty;
			}
		}
	}
}
