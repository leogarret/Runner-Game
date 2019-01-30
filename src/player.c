/*
** EPITECH PROJECT, 2018
** Léo Garret
** File description:
** player.c
*/

#include "../include/my.h"

void player_movement(runner_t *runner)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace) && runner->game.fuel > 0)
        runner->game.go_array[4].event = 1;
    else
        runner->game.go_array[4].event = 0;
}

void gravity(game_object_t *player, float velocity, float max_vel)
{
    int positive = (velocity > 0) ? 1 : 0;

    if (player->event == 1 && player->velocity >= max_vel && !positive)
        player->velocity += velocity;
    else if (player->event == 0 && player->velocity <= max_vel && positive)
        player->velocity += velocity;
    if (player->position.y <= 0)
        player->velocity = 0.5;
}

void fire_is_on(game_object_t *player)
{
    if (player->event == 0 && player->texture_change == 1) {
        sfSprite_setTexture(player->sprite, player->texture_third, sfTrue);
        player->texture_change = 0;
    } else if (player->event == 1 && player->texture_change == 0) {
        sfSprite_setTexture(player->sprite, player->texture_second, sfTrue);
        player->texture_change = 1;
    }
}

void ground_collision(game_object_t *player)
{
    if (player->position.y >= DISPLAY_HEIGHT - 285) {
        if (player->on_ground == 0)
            sfSprite_setTexture(player->sprite, player->texture, sfTrue);
        player->on_ground = 1;
        player->velocity = -0.5;
    } else if (player->event == 1) {
        if (player->on_ground == 1)
            sfSprite_setTexture(player->sprite, player->texture_second, sfTrue);
        player->on_ground = 0;
    }
}

void change_texture(game_object_t *player, const char *path)
{
    sfTexture_destroy(player->texture);
    player->texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
}