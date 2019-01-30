/*
** EPITECH PROJECT, 2018
** Léo Garret
** File description:
** norm.c
*/

#include "../include/my.h"

void norm(runner_t *runner)
{
    if (runner->game.fuel > 100)
        runner->game.fuel = 100;
}