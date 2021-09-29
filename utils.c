/*
** EPITECH PROJECT, 2021
** UTILS
** File description:
** utils.c
*/

#include "./include/stumper.h"

int count_tab(char **tab)
{
    int i = 0;

    for (; tab[i]; i++);
    return i;
}
