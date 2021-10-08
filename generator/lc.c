/*
** EPITECH PROJECT, 2019
** Dante_generator
** File description:
** Dante_generator
*/

#include "include/my.h"
#include "generator.h"

tlc *initialize(void)
{
    tlc *lc;
    tpart *element;
    if ((lc = malloc(sizeof(*lc))) == NULL)
        return NULL;
    if ((element = malloc(sizeof(*element))) == NULL)
        return NULL;
    element->next = NULL;
    lc->first = element;
    return lc;
}

void push_first(tlc *lc, int a, int b)
{
    tpart *new_bloc;
    if ((new_bloc = malloc(sizeof(*new_bloc))) == NULL)
        exit(84);
    new_bloc->a = a;
    new_bloc->b = b;
    new_bloc->next = lc->first;
    lc->first = new_bloc;
}

int lc_len(tlc *lc)
{
    tpart *current;
    int i = 0;
    current = lc->first;
    while (current != NULL){
        current = current->next;
        i++;
    }
    return i;
}