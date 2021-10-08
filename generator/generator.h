/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** contains all my headers
*/

#ifndef G_H_
#define G_H_

#include "include/my.h"

typedef struct spart
{
    int a;
    int b;
    struct spart *next;
} tpart;

typedef struct slc
{
    tpart *first;
} tlc;

typedef struct stab
{
    char x;
    int y;
} ttab;

typedef struct gen
{
    int rng;
    int width;
    int height;
    ttab **sq;
} gen;

gen *init_struct(void);
tlc *initialize(void);
void push_first(tlc *lc, int a, int b);
int lc_len(tlc *lc);
int	random_between(int minimun, int maximum);
int	*count_unvisited_sq(gen *lab, int i, int j);
int	select_rand_sq(gen *lab, int i, int j);
int	random_coord(gen *lab, tlc *lc, int *i, int *j);
void goback(tlc *lc, int *i, int *j);
void imperfect(gen *lab);
int	*washer(int *coord, int coord_len);
void exit_maze(gen *lab);
void rng_coord(gen *lab, tlc *lc, int *i, int *j);
int	**fillxs(gen *lab, int **wall_tab);
int	**create_xtab(gen *lab);
int	countx(gen *lab);
void display_tab(gen *lab);
int	intlen(int *tab);
int check_it(char* str1, char*str2);
char p_i(char* str);


#endif