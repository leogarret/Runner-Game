/*
** EPITECH PROJECT, 2018
** Léo Garret
** File description:
** game_init.c
*/

#include "../include/my.h"

sfRenderWindow *create_window(char *title, int width, int height)
{
    sfVideoMode video_mode = {width, height, 32};
    sfRenderWindow *window;

    window = sfRenderWindow_create(video_mode, title, sfClose, NULL);
    return (window);
}

game_object_t create_object(const char *path_to_spritesheet,
sfVector2f pos, int rectMax)
{
    game_object_t game_object;
    sfIntRect rect;

    game_object.rectMax = rectMax;
    game_object.texture = sfTexture_createFromFile(path_to_spritesheet, NULL);
    game_object.sprite = sfSprite_create();
    sfSprite_setTexture(game_object.sprite, game_object.texture, sfTrue);
    game_object.position = pos;
    sfSprite_setPosition(game_object.sprite, game_object.position);
    game_object.rect = rect;
    return (game_object);
}

void init(sfRenderWindow* window, game_object_t *go_array)
{
    init_jetpack_rect(&go_array[4]);
    sfSprite_setScale(go_array[4].sprite, (sfVector2f){0.3, 0.3});
    sfRenderWindow_setVerticalSyncEnabled(window, sfTrue);
    sfRenderWindow_setFramerateLimit(window, 60);
}

void init_jetpack_rect(game_object_t *jetpack)
{
    jetpack->rect.top = 0;
    jetpack->rect.left = 0;
    jetpack->rect.width = 381;
    jetpack->rect.height = 563;
}

game_object_t *game_object_array(sfRenderWindow *window)
{
    game_object_t *array = malloc(sizeof(game_object_t) * 14);

    array[4] = create_object(PLAYER_RUN,
    (sfVector2f){200, DISPLAY_HEIGHT - 285}, 2667);
    array[2] = create_object(BG_LAYER_1, (sfVector2f){0, 0}, 1);
    array[3] = create_object(BG_LAYER_1,
    (sfVector2f){sfRenderWindow_getSize(window).x, 0}, 1);
    array[0] = create_object(BG_1, (sfVector2f){0, 0}, 1);
    array[1] = create_object(BG_1,
    (sfVector2f){sfRenderWindow_getSize(window).x, 0}, 1);
    array[5] = create_object(PLATEFORM,
    (sfVector2f){0, sfRenderWindow_getSize(window).y - 120}, 1);
    array[6] = create_object(PLATEFORM, (sfVector2f){sfRenderWindow_getSize(
    window).x, sfRenderWindow_getSize(window).y - 120}, 1);
    game_object_arr_2(window, array);
    return (array);
}