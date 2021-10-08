/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** contains all my headers
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define READ_SIZE 4

enum terrain
{
	empty,
	wall,
	finish,
	path
};

typedef struct t_all
{
    char** maze;
    char** laby;
    int** num_tab;
    int rows;
    int cols;
    int start_row;
    int start_col;
    int i;
    int j;
    int k;
    int len;
} all;

int my_compute_power_rec(int nb, int p);
int my_put_nbr(int nb);
char my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strdup(char const *src);
int str_to_int(char* str);
char *int_to_str(long long nb);
all *init_struct(int ac, char** av);
int pathmaker(int row, int col, all *va);
void add_path(all *va);
void print_maze(all *va);
void init_num_maze(all *va);
void num_maze_mem(all *va);
void make_tab(char *file, int lines, all *va);
int	linelen(char *str);
int	line_count(char *str, all *va);
char *file_reader(char *filename);
int labyrinthe(char *filename, all *va);
void real_print(all *va);
void print_maze(all *va);


#endif
