/*
** EPITECH PROJECT, 2019
** Dante_generator
** File description:
** Dante_generator
*/

#include "include/my.h"
#include "generator.h"

gen *init_struct(void)
{
    gen *lab = malloc(sizeof(gen));
    lab->height = 0;
    lab->width = 0;
    return lab;
}
