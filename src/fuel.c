/*
** EPITECH PROJECT, 2018
** Léo Garret
** File description:
** main.c
*/

#include "../include/my.h"

char *get_score(char *buffer)
{
    char *hight_score = malloc(sizeof(char) * 6);

    for (int i = 0; buffer[i]; i++)
        hight_score[i] = buffer[i];
    return (hight_score);
}

void down_fuel_level(runner_t *runner)
{
    static int fd = 0;
    char *txt_hight_score;
    int tmp = 0;
    int size = 1;

    if (runner->game.fuel > 0 && runner->game.go_array[4].event == 1)
        runner->game.fuel -= 0.7;
    if (runner->game.fuel <= 0 && !runner->pass) {
        runner->pass = 1;
        runner->game.game_scene = 1;
    }
}

void move_fuel(runner_t *runner)
{
    runner->game.go_array[13].position.x -= 8;
    sfSprite_setPosition(runner->game.go_array[13].sprite,
    runner->game.go_array[13].position);
}

void collide_with_wall(runner_t *runner)
{
    if (runner->game.go_array[13].position.x <= -50) {
        runner->game.go_array[13].position.x += 4000;
        sfSprite_setPosition(runner->game.go_array[13].sprite,
        runner->game.go_array[13].position);
    }
}

void collide_fuel(runner_t *runner)
{
    srand(time(0));
    if (runner->game.go_array[4].position.x <
        (runner->game.go_array[13].position.x + 50) &&
        (runner->game.go_array[4].position.x + 90) >
        runner->game.go_array[13].position.x) {
        if (runner->game.go_array[4].position.y <
            (runner->game.go_array[13].position.y + 62) &&
            (runner->game.go_array[4].position.y + 160) >
            runner->game.go_array[13].position.y) {
                runner->game.go_array[13].position.x += 5000;
                while ((runner->game.go_array[13].position.y =
                rand() % 600) < 100);
                sfSprite_setPosition(runner->game.go_array[13].sprite,
                runner->game.go_array[13].position);
                runner->game.fuel += 40;
                norm(runner);
        }
    }
    collide_with_wall(runner);
}