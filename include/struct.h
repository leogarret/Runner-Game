/*
** EPITECH PROJECT, 2018
** Léo Garret
** File description:
** include
*/

#include <SFML/Graphics.h>
#include <SFML/Audio/Music.h>

typedef struct game_object_s
{
    int type;
    int rectMax;
    float velocity;
    sfSprite *sprite;
    sfTexture *texture;
    sfTexture *texture_second;
    sfTexture *texture_third;
    sfVector2f position;
    sfIntRect rect;
    int event;
    int on_ground;
    int texture_change;
} game_object_t;

typedef struct menu_s {
    game_object_t background;
    game_object_t btn_play;
    game_object_t btn_quit;
}menu_t;

typedef struct game_s {
    sfClock *clock;
    float second;
    sfTime time;
    char *path;
    sfEvent event;
    game_object_t *go_array;
    char *map;
    int number_of_coins;
    sfVector2f *coin_vectors;
    game_object_t *coin;
    int tab[2];
    int score;
    sfText *txt_score;
    sfFont *font;
    sfText *txt_distance;
    int distance;
    int temp_distance;
    float fuel;
    int fuel_random_y;
    int game_scene;
    game_object_t end;
    sfText *txt_end;
    sfText *txt_distance_end;
    sfText *txt_score_str;
    sfText *txt_score_nbr;
    sfText *btn_replay;
    sfVector2f vec_replay;
    sfVector2f vec_menu;
    sfVector2i m_vec;
    sfVector2f s_vec;
    sfText *btn_resume;
    sfVector2f vec_resume;
    sfText *btn_menu;
    game_object_t obstacle;
    game_object_t fuel_e;
    sfText *price;
    game_object_t coin_price;
    sfVector2f vec_price;
    sfMusic *snd;
}game_t;

typedef struct help_s {
    game_object_t btn_howtoplay;
    game_object_t game_rule;
    game_object_t btn_home;
}help_t;

typedef struct runner_s {
    menu_t menu;
    game_t game;
    help_t help;
    sfRenderWindow *window;
    int scene;
    sfEvent event;
    sfWindow *win;
    unsigned int hight_score;
    int pass;
}runner_t;