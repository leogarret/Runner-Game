/*
** EPITECH PROJECT, 2018
** Léo Garret
** File description:
** init_fuel.c
*/

#include "../include/my.h"

game_object_t *init_coin(sfVector2f *coin_vectors, char *map)
{
    game_object_t *coin_list;

    if (!(malloc(sizeof(game_object_t) * count_coins(map))))
        return (NULL);
    for (int i = 0; i < count_coins(map); i++)
        coin_list = coin(coin_vectors, map);
    return (coin_list);
}

int last_vector(sfVector2f *vectors)
{
    int i = 0;

    for (; vectors[i].x; i++) {
        if (!vectors[i + 1].x)
            return (vectors[i].x);
    }
    return (0);
}

void collide_verif(runner_t *runner, int i)
{
    if (runner->game.go_array[4].position.x <
        (runner->game.coin[i].position.x + 32) &&
        (runner->game.go_array[4].position.x + 90) >
        runner->game.coin[i].position.x) {
        if (runner->game.go_array[4].position.y <
            (runner->game.coin[i].position.y + 32) &&
            (runner->game.go_array[4].position.y + 160) >
            runner->game.coin[i].position.y) {
                runner->game.coin[i].position.x += 4000;
                runner->game.score += 1;
                sfText_setString(runner->game.txt_score,
                my_gettxt(runner->game.score));
                sfSprite_setPosition(runner->game.coin[i].sprite,
                runner->game.coin[i].position);
        }
    }
}

void collide_coin(runner_t *runner)
{
    for (int i = 0; i < runner->game.number_of_coins &&
        runner->game.game_scene == 0; i++) {
        collide_verif(runner, i);
        if (runner->game.coin[i].position.x <= -32) {
            runner->game.coin[i].position.x += 4000;
            sfSprite_setPosition(runner->game.coin[i].sprite,
            runner->game.coin[i].position);
        }
    }
}