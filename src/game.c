/*
** EPITECH PROJECT, 2018
** Léo Garret
** File description:
** hunter.c
*/

#include "../include/my.h"

void call_functions(runner_t *runner)
{
    sfSprite_setTextureRect(runner->game.go_array[4].sprite,
    runner->game.go_array[4].rect);
    parallax(&runner->game.go_array[0], &runner->game.go_array[1], 5);
    parallax(&runner->game.go_array[2], &runner->game.go_array[3], 6);
    parallax(&runner->game.go_array[5], &runner->game.go_array[6], 7);
    move_fuel(runner);
    collide_coin(runner);
    distance(runner);
    collide_fuel(runner);
    move_obstacle(runner);
    collide_obstacle(runner);
    move_trap(runner);
    collide_fuel_e(runner);
    draw(runner);
    sfRenderWindow_display(runner->window);
    sfRenderWindow_clear(runner->window, sfBlack);
}

void game(runner_t *runner)
{
    runner->game.time = sfClock_getElapsedTime(runner->game.clock);
    runner->game.second = runner->game.time.microseconds / 1000000.0;
    if (runner->game.second >= 0.08) {
        down_fuel_level(runner);
        move_rect(&runner->game.go_array[4]);
        sfClock_restart(runner->game.clock);
    }
    for (int i = 0; i < runner->game.number_of_coins; i++) {
        runner->game.coin[i].position.x -= 8;
        sfSprite_setPosition(runner->game.coin[i].sprite,
        runner->game.coin[i].position);
        sfRenderWindow_drawSprite(runner->window,
        runner->game.coin[i].sprite, NULL);
    }
    call_functions(runner);
    event_manager(runner);
}