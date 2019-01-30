/*
** EPITECH PROJECT, 2018
** Léo Garret
** File description:
** hunter.c
*/

#include "../include/my.h"

void distance(runner_t *runner)
{
    sfSprite_setScale(runner->game.go_array[7].sprite,
    (sfVector2f){runner->game.fuel / 100,
    sfSprite_getScale(runner->game.go_array[7].sprite).y});
    runner->game.temp_distance += 4;
    if (runner->game.temp_distance >= 100 && runner->game.game_scene == 0) {
        runner->game.distance += 1;
        sfText_setString(runner->game.txt_distance,
        (char *)my_gettxt(runner->game.distance));
        runner->game.temp_distance = 0;
    }
}