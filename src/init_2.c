/*
** EPITECH PROJECT, 2018
** Léo Garret
** File description:
** init_2.c
*/

#include "../include/my.h"

void init_button(game_t *game, sfRenderWindow *window)
{
    game->btn_replay = sfText_create();
    game->vec_replay = (sfVector2f){520, 650};
    sfText_setString(game->btn_replay, "Rejouer");
    sfText_setFont(game->btn_replay, game->font);
    sfText_setCharacterSize(game->btn_replay, 50);
    sfText_setPosition(game->btn_replay, game->vec_replay);
    game->btn_menu = sfText_create();
    game->vec_menu = (sfVector2f){820, 650};
    sfText_setString(game->btn_menu, "Menu");
    sfText_setFont(game->btn_menu, game->font);
    sfText_setCharacterSize(game->btn_menu, 50);
    sfText_setPosition(game->btn_menu, game->vec_menu);
    game->btn_resume = sfText_create();
    game->vec_resume = (sfVector2f){1100, 650};
    sfText_setString(game->btn_resume, "Continuer");
    sfText_setFont(game->btn_resume, game->font);
    sfText_setCharacterSize(game->btn_resume, 50);
    sfText_setPosition(game->btn_resume, game->vec_resume);
}

void init_runner_2(runner_t *runner)
{
    sfText_setString(runner->game.price, "0");
    sfText_setFont(runner->game.price, runner->game.font);
    sfText_setCharacterSize(runner->game.price, 30);
    sfText_setPosition(runner->game.price, runner->game.vec_price);
}

void init_game_2(game_t *game)
{
    game->go_array[4].texture_second =
    sfTexture_createFromFile("sprites/jet_pack.png", NULL);
    game->go_array[4].texture_third =
    sfTexture_createFromFile("sprites/jet_pack_no_fire.png", NULL);
    game->fuel_e = create_object("sprites/fuee.png",
    (sfVector2f){5000, 200}, 0);
    game->go_array[4].texture_change = 0;
}