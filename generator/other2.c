/*
** EPITECH PROJECT, 2019
** Dante_generator
** File description:
** Dante_generator
*/

#include "include/my.h"
#include "generator.h"

int	countx(gen *lab)
{
    int i = 0;
    int j = 0;
    int nb_wall = 0;
    while (lab->sq[i]){
        j = 0;
        while (j < lab->width){
	        if (lab->sq[i][j].x == 'X')
	            ++nb_wall;
	        j++;
	    }
        i++;
    }
    return nb_wall;
}

int	**create_xtab(gen *lab)
{
    int **wall_tab;
    int i = 0;
    if ((wall_tab = malloc(sizeof(int *) * (countx(lab) + 1))) == NULL)
        return NULL;
    while (i < countx(lab)) {
        if ((wall_tab[i] = malloc(sizeof(int) * 3)) == NULL)
	        return (NULL);
        i++;
    }
    wall_tab[i] = '\0';
    return wall_tab;
}

int	**fillxs(gen *lab, int **wall_tab)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (lab->sq[i]){
        j = 0;
        while (j < lab->width){
            if (lab->sq[i][j].x == 'X'){
                wall_tab[k][0] = i;
                wall_tab[k][1] = j;
                k++;
            }
            j++;
        }
        i++;
    }
    wall_tab[k] = '\0';
    return wall_tab;
}

void imperfect(gen *lab)
{
    int **wall_tab;
    int breakit;
    int i = 0;
    int rng_wall;
    int nb_wall;
    srand(time(NULL));
    wall_tab = create_xtab(lab);
    wall_tab = fillxs(lab, wall_tab);
    nb_wall = countx(lab);
    breakit = nb_wall * 45 / 100;
    while (i < breakit){
        rng_wall = rand() % (nb_wall);
        lab->sq[wall_tab[rng_wall][0]][wall_tab[rng_wall][1]].x = '*';
        i++;
    }
}