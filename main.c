/*
** EPITECH PROJECT, 2020
** FINAL STUMPER
** File description:
** NO DESCRIPTION
*/

#include "./include/stumper.h"

void print_c(char *tab, char **order)
{
    char *cpy = malloc(sizeof(char) * my_strlen(tab) + 1);
    int nbr = 0;

    for (int t = 0; t <= my_strlen(tab) - 1; t++)
        cpy[t] = 5;
    for (int k = 0; order[k]; k++) {
        if (contains(order[k], '-') == FALSE) {
            nbr = my_getnbr(order[k]);
            cpy[nbr - 1] = tab[nbr - 1];
        } else {
            cpy = param_two(tab, order[k], cpy);
        }
    }

    for (int l = 0; l < my_strlen(cpy); l++)
        if (cpy[l] != 5)
            my_putchar(cpy[l]);
    my_putchar('\n');
}

void only_flag_c(int ac, char **av, char *buff)
{
    char **tab = my_strtok(buff, '\n');
    char **order = my_strtok(av[2], ',');

    ac = ac;
    for (int x = 0; tab[x]; x++)
        print_c(tab[x], order);
}

int minicut(int ac, char **av, char *buff)
{
    if (ac == 3 && check_args(av, 1, "-c")) {
        only_flag_c(ac, av, buff);
        return 0;
    }
    if (ac == 5 && (check_args(av, 1, "-d") || check_args(av, 1, "-f")) &&
        (check_args(av, 3, "-d") || check_args(av, 3, "-f"))) {
        flag_two(ac, av, buff);
        return 0;
    }
    if (ac == 3 && check_args(av, 1, "-f") && my_getnbr(av[2]) > 0) {
        my_putstr(buff);
        return 0;
    }
    return 84;
}

int main(int ac, char **av)
{
    char *buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
    int offset = 0;
    int len = 0;

    while ((len = read(0 , buff + offset , BUFFER_SIZE - offset)) > 0) {
        offset = offset + len;
    }
    buff[offset] = '\0';
    if (len < 0)
        return (84);
    return (minicut(ac, av, buff));
}
