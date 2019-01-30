/*
** EPITECH PROJECT, 2018
** Léo Garret
** File description:
** functions.c
*/

#include "../include/my.h"

char *my_revstr(char *str)
{
    int nb_str = my_strlen(str) - 1;
    int temp = my_strlen(str) - 1;

    for (int i = 0; i <= (temp / 2); i++, nb_str--)
        my_swap(&str[i], &str[nb_str]);
    return (str);
}

char *my_gettxt(int nbr)
{
    char *str;
    int i = 0;

    str = malloc(sizeof(char) * 5);
    for (int c = 0; c <= 4; c++)
        str[c] = '\0';
    for (; nbr > 9; i++) {
        str[i] = (nbr % 10) + 48;
        nbr = nbr / 10;
    }
    str[i] = nbr + 48;
    str = my_revstr(str);
    return (str);
}

char *str_cat(char *tab, const char *str)
{
    int tab_size = 0;

    for (; tab[tab_size]; tab_size++);
    for (int i = 0; str[i]; i++)
        tab[tab_size++] = str[i];
    tab[tab_size++] = '\0';
    return (tab);
}