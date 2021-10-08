/*
** EPITECH PROJECT, 2019
** Dante_generator
** File description:
** Dante_generator
*/

#include "include/my.h"
#include "generator.h"

int	create_tab(gen *lab)
{
    int i = 0;
    ttab **sq;
    if ((sq = malloc(sizeof(ttab) * (lab->height + 1))) == NULL)
        return 84;
    while (i < lab->height){
        if ((sq[i] = malloc(sizeof(ttab) * (lab->width + 1))) == NULL)
	        return 84;
        i++;
    }
    lab->sq = sq;
    return 0;
}

void filler(gen *lab)
{
    int	i = 0;
    int	j = 0;
    char c = '*';
    while (i < lab->height){
        j = 0;
        while (j < lab->width){
	        if (i % 2 == 0)
	            lab->sq[i][j].x = (j % 2 == 0) ? c : 'X';
	        else
	            lab->sq[i][j].x = 'X';
	        lab->sq[i][j].y = 0;
	        j++;
	    }
        lab->sq[i][j].x = '\0';
        i++;
    }
    lab->sq[i] = '\0';
}

void perfect(gen *lab)
{
    int i = 0;
    int j = 0;
    int c = 0;
    tlc *lc;
    lc = initialize();
    lc->first->a = 0;
    lc->first->b = 0;
    srand(time(NULL));
    while (lc_len(lc) > 3 || c < 3){
        while (random_coord(lab, lc, &i, &j) != 1);
            goback(lc, &i, &j);
        c++;
    }
    exit_maze(lab);
}

int main(int ac, char** av)
{
    char c = p_i(av[3]);
    if (check_it(av[1], av[2]) != 0)
        return 84;
    gen *lab = init_struct();
    lab->width = atoi(av[1]);
    lab->height = atoi(av[2]);
    if (create_tab(lab) != 0)
        return 84;
    filler(lab);
    perfect(lab);
    if (c == 'p'){
        display_tab(lab);
        return 0;
    }
    imperfect(lab);
    display_tab(lab);
    return 0;
}