/*
** EPITECH PROJECT, 2018
** Léo Garret
** File description:
** trap.c
*/

#include "../include/my.h"

void move_trap(runner_t *runner)
{
    runner->game.fuel_e.position.x -= 8;
    sfSprite_setPosition(runner->game.fuel_e.sprite,
    runner->game.fuel_e.position);
}

void trap_with_wall(runner_t *runner)
{
    srand(time(0));
    if (runner->game.fuel_e.position.x <= -200) {
        runner->game.fuel_e.position.x = 2000 + rand()%2000;
        sfSprite_setPosition(runner->game.fuel_e.sprite,
        runner->game.fuel_e.position);
    }
}

void collide_fuel_e(runner_t *runner)
{
    srand(time(0));
    if (runner->game.go_array[4].position.x <
        (runner->game.fuel_e.position.x + 50) &&
        (runner->game.go_array[4].position.x + 90) >
        runner->game.fuel_e.position.x) {
        if (runner->game.go_array[4].position.y <
            (runner->game.fuel_e.position.y + 62) &&
            (runner->game.go_array[4].position.y + 160) >
            runner->game.fuel_e.position.y) {
                runner->game.fuel_e.position.x = 2000 + rand()%2000;
                while ((runner->game.fuel_e.position.y =
                rand() % 600) < 100);
                sfSprite_setPosition(runner->game.fuel_e.sprite,
                runner->game.fuel_e.position);
                runner->game.fuel = 0;
        }
    }
    trap_with_wall(runner);
}