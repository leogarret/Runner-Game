/*
** EPITECH PROJECT, 2018
** Léo Garret
** File description:
** game_init.c
*/

#include "../include/my.h"

game_object_t *game_object_arr_2(sfRenderWindow *window, game_object_t *array)
{
    array[7] = create_object("sprites/bar.png", (sfVector2f){835, 50}, 0);
    array[8] = create_object("sprites/cbar.png", (sfVector2f){830, 45}, 0);
    array[9] = create_object("sprites/cico.png", (sfVector2f){1720, 30}, 0);
    array[10] = create_object("sprites/dist.png", (sfVector2f){30, 30}, 0);
    array[11] = create_object("sprites/tro.png", (sfVector2f){220, 30}, 0);
    array[12] = create_object("sprites/ficon.png", (sfVector2f){780, 20}, 0);
    array[13] = create_object("sprites/fuel.png", (sfVector2f){5500, 500}, 0);
    return (array);
}