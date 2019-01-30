/*
** EPITECH PROJECT, 2018
** Léo Garret
** File description:
** scene.c
*/

#include "../include/my.h"

void init_scene(game_object_t *scene)
{
    scene->sprite = sfSprite_create();
    scene->texture = sfTexture_createFromFile("sprites/endbg.png", NULL);
    sfSprite_setTexture(scene->sprite, scene->texture, sfTrue);
    sfSprite_setPosition(scene->sprite, (sfVector2f){320, 200});
}