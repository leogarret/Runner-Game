/*
** EPITECH PROJECT, 2018
** Léo Garret
** File description:
** init.c
*/

#include "../include/my.h"

menu_t init_menu(void)
{
    menu_t menu;

    menu.background = create_object("sprites/background/background_1.png",
    (sfVector2f){0, 0}, 0);
    menu.btn_play = create_object("sprites/btn_play.png",
    (sfVector2f){250, 890}, 0);
    menu.btn_quit = create_object("sprites/btn_quit.png",
    (sfVector2f){650, 885}, 0);
    return (menu);
}

void var_init_2(game_t *game, sfRenderWindow *window)
{
    game->txt_end = sfText_create();
    sfText_setString(game->txt_end, "Distance  parcourue\t:");
    sfText_setFont(game->txt_end, game->font);
    sfText_setCharacterSize(game->txt_end, 50);
    sfText_setPosition(game->txt_end, (sfVector2f){520, 330});
    game->txt_distance_end = sfText_create();
    sfText_setString(game->txt_distance_end, "0");
    sfText_setFont(game->txt_distance_end, game->font);
    sfText_setCharacterSize(game->txt_distance_end, 50);
    sfText_setPosition(game->txt_distance_end, (sfVector2f){1000, 330});
    game->txt_score_str = sfText_create();
    sfText_setString(game->txt_score_str, "Pieces recoltees\t:");
    sfText_setFont(game->txt_score_str, game->font);
    sfText_setCharacterSize(game->txt_score_str, 50);
    sfText_setPosition(game->txt_score_str, (sfVector2f){520, 430});
    game->txt_score_nbr = sfText_create();
    sfText_setString(game->txt_score_nbr, "0");
    sfText_setFont(game->txt_score_nbr, game->font);
    sfText_setCharacterSize(game->txt_score_nbr, 50);
    sfText_setPosition(game->txt_score_nbr, (sfVector2f){1000, 430});
}

void var_init(game_t *game, sfRenderWindow *window)
{
    game->clock = sfClock_create();
    game->second = 0;
    game->path = "map/map_1";
    game->go_array = game_object_array(window);
    game->map = open_map(game->path);
    game->number_of_coins = count_coins(game->map);
    game->coin_vectors = map_manager(game->map);
    game->coin = init_coin(game->coin_vectors, game->map);
    game->tab[0] = game->number_of_coins;
    game->tab[1] = last_vector(game->coin_vectors);
    game->txt_score = sfText_create();
    game->font = sfFont_createFromFile("fonts/AmericanCaptain.ttf");
    game->go_array[4].event = 0;
    game->go_array[4].on_ground = 0;
    game->score = 0;
    game->distance = 0;
    game->fuel = 100;
    game->fuel_random_y = 0;
}

game_t init_game(sfRenderWindow *window)
{
    game_t game;

    var_init(&game, window);
    var_init_2(&game, window);
    init_button(&game, window);
    sfText_setString(game.txt_score, "0");
    sfText_setFont(game.txt_score, game.font);
    sfText_setCharacterSize(game.txt_score, 50);
    sfText_setPosition(game.txt_score, (sfVector2f){1800, 25});
    game.txt_distance = sfText_create();
    sfText_setString(game.txt_distance, "0");
    sfText_setFont(game.txt_distance, game.font);
    sfText_setCharacterSize(game.txt_distance, 50);
    sfText_setPosition(game.txt_distance, (sfVector2f){100, 25});
    init(window, game.go_array);
    init_game_2(&game);
    return (game);
}

runner_t init_runner(void)
{
    runner_t runner;

    runner.window = create_window(WINDOW_TITLE, DISPLAY_WIDTH, DISPLAY_HEIGHT);
    runner.menu = init_menu();
    runner.game = init_game(runner.window);
    runner.game.end = create_object("sprites/endbg.png",
    (sfVector2f){500, 500}, 0);
    runner.scene = 0;
    runner.win = NULL;
    runner.pass = 0;
    runner.game.price = sfText_create();
    runner.game.vec_price = (sfVector2f){1185, 712};
    init_runner_2(&runner);
    runner.game.coin_price = create_object("sprites/coin.png",
    (sfVector2f){1150, 720}, 0);
    sfSprite_setScale(runner.game.coin_price.sprite, (sfVector2f){0.7, 0.7});
    init_obstacle(&runner);
    return (runner);
}