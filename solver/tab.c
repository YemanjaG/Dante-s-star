/*
** EPITECH PROJECT, 2019
** Dante_solver
** File description:
** Dante_solver
*/

#include "include/my.h"

void shorten_mktb(char* file, all *va)
{
    while (file[va->i] != '\n' && file[va->i] != '\0'){
        va->laby[va->j][va->k] = file[va->i];
        if (va->k == 0){
            va->laby[va->j][va->k] = 'X';
            va->i--;
        }
        va->k++;
        va->i++;
    }
    if (va->k == va->len + 1){
        va->laby[va->j][va->k] = 'X';
        va->k++;
    }
    va->laby[va->j][va->k] = '\0';
    va->i++;
    va->j++;
}

void make_tab(char *file, int lines, all *va)
{
    va->laby = malloc(sizeof(char *) * (lines + 1));
    while (file[va->i]){
        va->len = linelen(file + va->i);
        va->laby[va->j] = malloc(sizeof(char) * va->len + 2);
        if (va->j == 0 || va->j == lines + 2){
            va->laby[va->j] = "XXXXXXXXXXXX";
            va->j++;
            va->laby[va->j] = malloc(sizeof(char) * va->len + 2);
        }
        va->k = 0;
        shorten_mktb(file, va);
        if (va->j == lines + 1){
            va->laby[va->j] = "XXXXXXXXXXXX";
            va->j++;
            va->laby[va->j] = NULL;
        }
    }
    va->cols = va->len + 2;
    va->laby[1][1] = 's';
    va->laby[lines][va->cols - 1] = 'f';
}

char *file_reader(char *filename)
{
    struct stat	stats;
    char *file;
    int fd;
    int gotten;
    stat(filename, &stats);
    if ((fd = open(filename, O_RDONLY)) == -1)
        return NULL;
    if ((file = malloc(sizeof(char) * stats.st_size)) == NULL)
        return NULL;
    while ((gotten = read(fd, file, stats.st_size)) > 0)
        file[gotten] = '\0';
    return file;
}

int labyrinthe(char *filename, all *va)
{
    char *file;
    int lines = 0;
    if ((file = file_reader(filename)) == NULL)
        return 84;
    lines = line_count(file, va);
    va->rows = lines + 2;
    make_tab(file, lines, va);
    return 0;
}