/*
** EPITECH PROJECT, 2018
** Léo Garret
** File description:
** main.c
*/

#include "../include/my.h"

void init_obstacle(runner_t *runner)
{
    srand(time(0));
    runner->game.obstacle.sprite = sfSprite_create();
    runner->game.obstacle.texture =
    sfTexture_createFromFile("sprites/obstacle.png", NULL);
    sfSprite_setTexture(runner->game.obstacle.sprite,
    runner->game.obstacle.texture, sfFalse);
    runner->game.obstacle.position.y = DISPLAY_HEIGHT - 257;
    runner->game.obstacle.position.x = DISPLAY_WIDTH + rand()% 5000;
}

void move_obstacle(runner_t *runner)
{
    runner->game.obstacle.position.x -= 7;
    sfSprite_setPosition(runner->game.obstacle.sprite,
    runner->game.obstacle.position);
}

void random_obstacle(runner_t *runner)
{
    srand(time(0));
    runner->game.obstacle.position.y = DISPLAY_HEIGHT - 257;
    runner->game.obstacle.position.x += (500 + rand()%100);
    sfSprite_setPosition(runner->game.obstacle.sprite,
    runner->game.obstacle.position);
}

void obstacle_with_wall(runner_t *runner)
{
    srand(time(0));
    if (runner->game.obstacle.position.x <= -200) {
        runner->game.obstacle.position.x = 2000 + rand()%2000;
        sfSprite_setPosition(runner->game.obstacle.sprite,
        runner->game.obstacle.position);
    }
}

void collide_obstacle(runner_t *runner)
{
    srand(time(0));
    if (runner->game.go_array[4].position.x <
        (runner->game.obstacle.position.x + 130) &&
        (runner->game.go_array[4].position.x + 90) >
        runner->game.obstacle.position.x) {
        if (runner->game.go_array[4].position.y <
            (runner->game.obstacle.position.y + 130) &&
            (runner->game.go_array[4].position.y + 160) >
            runner->game.obstacle.position.y) {
                runner->game.game_scene = 1;
                runner->game.fuel = 0;
        }
    }
    obstacle_with_wall(runner);
}