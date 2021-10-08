/*
** EPITECH PROJECT, 2019
** int to str
** File description:
** int to str
*/

#include <stdlib.h>

char *int_to_str(long long nb)
{
    int len = 0;
    char* str;
    int	tmp = nb;
    for (len; tmp > 0; len++)
        tmp /= 10;
    str = malloc(sizeof(*str) * (len + 1));
    str[len] = '\0';
    for (len; len--; nb /= 10)
        str[len] = nb % 10 + '0';
    return (str);
}