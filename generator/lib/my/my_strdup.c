/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** allocates memory and copies a string
*/

#include <stdio.h>
#include <stdlib.h>

char *my_strcpy(char *dest, char const *src);

char *my_strdup(char const *src)
{
    char *dest = malloc(sizeof(char) * 18);
    dest = my_strcpy(dest, src);
    return dest;
}
