/*
** EPITECH PROJECT, 2019
** str to int
** File description:
** str to int
*/

int str_to_int(char* str)
{
    int val = 0;
    for (str; *str; str++){
        if (*str >= '0' && *str <= '9') {
            val *= 10;
            val += *str - '0';
        } else
            return (val);
    }
    return (val);
}