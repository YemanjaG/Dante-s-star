/*
** EPITECH PROJECT, 2019
** Dante_generator
** File description:
** Dante_generator
*/

#include "include/my.h"
#include "generator.h"

void goback(tlc *lc, int *i, int *j)
{
    tpart *free_it;
    if (lc->first != NULL){
        free_it = lc->first;
        *i = lc->first->a;
        *j = lc->first->b;
        lc->first = lc->first->next;
        free(free_it);
    }
}

int	*washer(int *coord, int coord_len)
{
    int *clean_coord;
    int a = 0;
    int b = 0;
    if ((clean_coord = malloc(sizeof(int) * (coord_len + 1))) == NULL)
        return NULL;
    while (coord[a]){
        if (coord[a] != -1){
	        clean_coord[b] = coord[a];
	        b++;
	    }
        a++;
    }
    clean_coord[b] = '\0';
    return clean_coord;
}

void exit_maze(gen *lab)
{
    if (lab->sq[lab->height - 1][lab->width - 1].x != '*'){
        lab->sq[lab->height - 1][lab->width - 1].x = '*';
        if (lab->width != 1){
	        if (lab->sq[lab->height - 1][lab->width - 2].x != '*')
	            lab->sq[lab->height - 2][lab->width - 1].x = '*';
	        else
	            lab->sq[lab->height - 1][lab->width - 2].x = '*';
	    }
    }
}

void rng_coord(gen *lab, tlc *lc, int *i, int *j)
{
    if (lab->rng == 1){
        push_first(lc, *i, *j);
        lab->sq[*i - 1][*j].x = '*';
        *i = *i - 2;
    }
    else if (lab->rng == 2){
        push_first(lc, *i, *j);
        lab->sq[*i][*j + 1].x = '*';
        *j = *j + 2;
    }
    else if (lab->rng == 3){
        push_first(lc, *i, *j);
        lab->sq[*i + 1][*j].x = '*';
        *i = *i + 2;
    }
    else{
        push_first(lc, *i, *j);
        lab->sq[*i][*j - 1].x = '*';
        *j = *j - 2;
    }
}
