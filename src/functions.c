/*
** EPITECH PROJECT, 2018
** Léo Garret
** File description:
** functions.c
*/

#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}

int my_getnbr(char *str)
{
    int result = 0;
    int neg = (*str == '-') ? 1 && str++ : 0;

    for (; *str; str++)
        result = (result * 10) + (*str - 48);
    return (neg ? -result : result);
}

int my_strlen(char const *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}

void my_swap(char *a, char *b)
{
    char temp = *a;

    *a = *b;
    *b = temp;
}