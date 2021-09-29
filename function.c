/*
** EPITECH PROJECT, 2020
** FINAL STUMPER
** File description:
** NO DESCRIPTION
*/

#include "./include/stumper.h"

int contains(char *str, char delim)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == delim)
            return TRUE;
    return FALSE;
}

void param_three(char *order, char **tab, char delim)
{
    char **yolo = my_strtok(order, '-');
    int one = my_getnbr(yolo[0]);
    int two = 0;

    my_putchar(delim);
    if (yolo[1] != NULL) {
        two = my_getnbr(yolo[1]);

        for (; one <= two; one++) {
            if (one != my_getnbr(yolo[0]))
                my_putchar(delim);
            my_putstr(tab[one - 1]);
        }
    } else {
        for (; one <= count_tab(tab); one++) {
            if (one != my_getnbr(yolo[0]))
                my_putchar(delim);
            my_putstr(tab[one - 1]);
        }
    }
}

void print_y(char **tabs, char *order, char delim)
{
    char **orders = my_strtok(order, ',');
    int nbr = 0;

    for (int k = 0; orders[k]; k++) {
        if (contains(orders[k], '-') == FALSE) {
            nbr = my_getnbr(orders[k]);
            if (k > 0)
                my_putchar(delim);
            my_putstr(tabs[nbr - 1]);
        } else {
            param_three(orders[k], tabs, delim);
        }
    }
    my_putchar('\n');
}

void flag_two(int ac, char **av, char *buff)
{
    char **tab = my_strtok(buff, '\n');
    char ** tabs = NULL;
    char delim;
    char *order = NULL;

    ac = ac;
    if (check_args(av, 1, "-d")) {
        delim = av[2][0];
        order = av[4];
    } else {
        delim = av[4][0];
        order = av[2];
    }
    for (int x = 0; tab[x]; x++) {
        tabs = my_strtok(tab[x], delim);
        print_y(tabs, order, delim);
    }
}

char *param_two(char *tab, char *order, char *cpy)
{
    char **yolo = my_strtok(order, '-');
    int one = my_getnbr(yolo[0]);
    int two = 0;

    if (yolo[1] != NULL) {
        two = my_getnbr(yolo[1]);

        for (; one <= two; one++)
            cpy[one - 1] = tab[one - 1];
    } else {
        for (; one <= my_strlen(tab); one++)
            cpy[one - 1] = tab[one - 1];
    }
    return cpy;
}
