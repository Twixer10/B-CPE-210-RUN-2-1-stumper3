/*
** EPITECH PROJECT, 2021
** 
** File description:
** 
*/

#include <unistd.h>
#include <stdlib.h>
#include "./my.h"

int contains(char *str, char delim);
void print_y(char **tabs, char *order, char delim);
void flag_two(int ac, char **av, char *buff);
char *param_two(char *tab, char *order, char *cpy);
void print_c(char *tab, char **order);
void only_flag_c(int ac, char **av, char *buff);
int minicut(int ac, char **av, char *buff);
int count_tab(char **tab);
