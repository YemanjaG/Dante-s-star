/*
** EPITECH PROJECT, 2019
** Dante_generator
** File description:
** Dante_generator
*/

#include "include/my.h"
#include "generator.h"

int	random_between(int minimun, int maximum)
{
    return (rand() % (maximum - minimun + 1) + minimun);
}

int	*count_unvisited_sq(gen *lab, int i, int j)
{
    int *coord;
    if ((coord = malloc(sizeof(int) * (4 + 1))) == NULL)
        return NULL;
    if (i > 0 && lab->sq[i - 2][j].y == 0)
        coord[0] = 1;
    else
        coord[0] = -1;
    coord[0] = (i > 0 && lab->sq[i - 2][j].y == 0) ? 1 : -1;
    coord[1] = (j < lab->width - 2 && lab->sq[i][j + 2].y == 0) ? 2 : -1;
    coord[2] = (i < lab->height - 2 && lab->sq[i + 2][j].y == 0) ? 3 : -1;
    coord[3] = (j > 0 && lab->sq[i][j - 2].y == 0) ? 4 : -1;
    return coord;
}

int	select_rand_sq(gen *lab, int i, int j)
{
    int *coord;
    int *epur_coord;
    int coord_len;
    int rng_array;
    int rng_nb;
    coord = count_unvisited_sq(lab, i, j);
    coord_len = intlen(coord);
    epur_coord = washer(coord, coord_len);
    if (coord_len == 0)
        return 0;
    rng_array = random_between(0, coord_len - 1);
    rng_nb = epur_coord[rng_array];
    return rng_nb;
}

int	random_coord(gen *lab, tlc *lc, int *i, int *j)
{
    lab->sq[*i][*j].y = 1;
    if ((lab->rng = select_rand_sq(lab, *i, *j)) == 0)
        return 1;
    rng_coord(lab, lc, i, j);
    return 0;
}