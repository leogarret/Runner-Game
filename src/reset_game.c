/*
** EPITECH PROJECT, 2018
** Léo Garret
** File description:
** end.c
*/

#include "../include/my.h"

void reset(runner_t *runner)
{
    runner->game.fuel = 100;
    runner->game.score = 0;
    runner->game.distance = 0;
    runner->game.game_scene = 0;
    runner->pass = 0;
    runner->game.obstacle.position.x += 3000;
    sfText_setString(runner->game.txt_score, "0");
}