/*
** EPITECH PROJECT, 2018
** Léo Garret
** File description:
** event_manager.c
*/

#include "../include/my.h"

void event_manager(runner_t *runner)
{
    fire_is_on(&runner->game.go_array[4]);
    while (sfRenderWindow_pollEvent(runner->window, &runner->event)) {
        if (runner->event.type == sfEvtClosed)
            sfRenderWindow_close(runner->window);
        player_movement(runner);
        gravity(&runner->game.go_array[4], -0.5, -8);
    }
    gravity(&runner->game.go_array[4], 0.5, 8);
    ground_collision(&runner->game.go_array[4]);
    runner->game.go_array[4].position.y += runner->game.go_array[4].velocity;
    sfSprite_setPosition(runner->game.go_array[4].sprite,
    runner->game.go_array[4].position);
}

void parallax(game_object_t *bg1, game_object_t *bg2, int speed)
{
    bg1->position.x -= speed;
    bg2->position.x -= speed;
    sfSprite_setPosition(bg1->sprite, bg1->position);
    sfSprite_setPosition(bg2->sprite, bg2->position);
    if (bg1->position.x <= -DISPLAY_WIDTH)
        bg1->position.x = DISPLAY_WIDTH;
    else if (bg2->position.x <= -DISPLAY_WIDTH)
        bg2->position.x = DISPLAY_WIDTH;
}

void move_rect(game_object_t *game_object)
{
    if (game_object->rect.left < game_object->rectMax)
        game_object->rect.left += game_object->rect.width;
    else
        game_object->rect.left = 0;
}