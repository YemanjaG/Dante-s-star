/*
** EPITECH PROJECT, 2019
** Dante_solver
** File description:
** Dante_solver
*/

#include "include/my.h"

int	line_count(char *str, all *va)
{
    int	i = 0;
    int	j = 0;
    while (str[i]){
        if (str[i] == '\n')
            j++;
        i++;
    }
    return j;
}

int	linelen(char *str)
{
    int	i = 0;
    while (str[i] != '\n'){
        if (str[i] == '\0')
            return (i);
        i++;
    }
    return i;
}

all *init_struct(int ac, char** av)
{
	all *va = malloc(sizeof(all));
	va->cols = 0;
	va->rows = 0;
	va->start_col = 0;
	va->start_row = 0;
	va->i = 0;
	va->j = 0;
	va->k = 0;
	va->len = 0;
	return va;
}

void print_maze(all *va)
{
	for (int i = 0; i < va->rows; i++) {
		for (int j = 0; j < va->cols; j++)
			printf("%d", va->num_tab[i][j]);
		printf("\n");
	}
}

void real_print(all *va)
{
	for (int i = 1; i != va->rows - 1; i++){
		for (int j = 0; va->maze[i][j] != '\0'; j++){
			if (j != 0 && i != va->rows - 1 && j != va->cols - 1){
				my_putchar(va->maze[i][j]);
			}
			if (j == va->cols - 1){
				my_putchar('\n');
			}
		}
	}

}