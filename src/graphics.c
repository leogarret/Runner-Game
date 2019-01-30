/*
** EPITECH PROJECT, 2018
** Léo Garret
** File description:
** graphics.c
*/

#include "../include/my.h"

void call(runner_t *runner)
{
    btn_replay(runner);
    btn_menu(runner);
    if ((runner->game.score - (runner->game.distance * 6)) >= 0) {
        btn_resume(runner);
    }
}

void draw_end(runner_t *runner)
{
    sfRenderWindow_drawSprite(runner->window, runner->game.end.sprite, NULL);
    sfRenderWindow_drawText(runner->window, runner->game.txt_end, NULL);
    sfText_setString(runner->game.txt_distance_end,
    my_gettxt(runner->game.distance));
    sfRenderWindow_drawText(runner->window,
    runner->game.txt_distance_end, NULL);
    sfRenderWindow_drawText(runner->window, runner->game.txt_score_str, NULL);
    sfText_setString(runner->game.txt_score_nbr, my_gettxt(runner->game.score));
    sfRenderWindow_drawText(runner->window, runner->game.txt_score_nbr, NULL);
    sfRenderWindow_drawText(runner->window, runner->game.btn_replay, NULL);
    sfRenderWindow_drawText(runner->window, runner->game.btn_menu, NULL);
    sfRenderWindow_drawText(runner->window, runner->game.btn_resume, NULL);
    sfRenderWindow_drawText(runner->window, runner->game.price, NULL);
    sfRenderWindow_drawSprite(runner->window,
    runner->game.coin_price.sprite, NULL);
    sfText_setString(runner->game.price, my_gettxt(runner->game.distance * 6));
    if (runner->event.type == sfEvtMouseButtonPressed)
        call(runner);
}

void draw(runner_t *runner)
{
    for (int i = 0; i <= 12; i++) {
        sfRenderWindow_drawSprite(runner->window,
        runner->game.go_array[i].sprite, NULL);
    }
    for (int i = 0; i < runner->game.number_of_coins; i++) {
        sfRenderWindow_drawSprite(runner->window,
        runner->game.coin[i].sprite, NULL);
    }
    sfRenderWindow_drawSprite(runner->window,
    runner->game.obstacle.sprite, NULL);
    if (runner->game.game_scene == 1)
        draw_end(runner);
    else {
        sfRenderWindow_drawSprite(runner->window,
        runner->game.go_array[13].sprite, NULL);
        sfRenderWindow_drawSprite(runner->window,
        runner->game.fuel_e.sprite, NULL);
    }
    sfRenderWindow_drawText(runner->window, runner->game.txt_score, NULL);
    sfRenderWindow_drawText(runner->window, runner->game.txt_distance, NULL);
}

void clear_data(sfRenderWindow* window, game_object_t *go_array,
game_object_t *coin, int number_of_coins)
{
    for (int i = 0; i <= 12; i++)
        sfSprite_destroy(go_array[i].sprite);
    for (int i = 0; i < number_of_coins; i++)
        sfSprite_destroy(coin[i].sprite);
    sfRenderWindow_destroy(window);
}