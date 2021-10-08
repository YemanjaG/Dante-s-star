/*
** EPITECH PROJECT, 2019
** Dante_generator
** File description:
** Dante_generator
*/

#include "include/my.h"
#include "generator.h"

char p_i(char* str)
{
    char* perfect = "perfect";
    if (str == NULL)
        return 'i';
    if (strcmp(str, perfect) == 0)
        return 'p';
    else
        return 'e';
}

int check_it(char* str1, char*str2)
{
    int i = 0;
    while (str1[i] != '\0'){
        if (str1[i] < '0' || str1[i] > '9')
            return 84;
        i++;
    }
    i = 0;
    while (str2[i] != '\0'){
        if (str2[i] < '0' || str2[i] > '9')
            return 84;
        i++;
    }
    return 0;
}

int	intlen(int *tab)
{
    int	i = 0;
    int	j = 0;
    while (tab[i]){
        if (tab[i] != -1)
	        j++;
        i++;
    }
    return j;
}

void display_tab(gen *lab)
{
    int i = 0;
    int j = 0;
    while (lab->sq[i]){
        j = 0;
        while (j < lab->width){
            write(1, &lab->sq[i][j].x, 1);
            j++;
        }
        if (i != lab->height - 1)
            my_putstr("\n");
        i++;
    }
}