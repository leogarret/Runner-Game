/*
** EPITECH PROJECT, 2018
** Léo Garret
** File description:
** include
*/

#ifndef __LIST__
#define __LIST__

#include "struct.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio/Music.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifndef IMG_NAME
#define IMG_NAME
#define PLAYER_RUN "sprites/jet_pack2.png"
#define BG_LAYER_1 "sprites/background/layer_1.png"
#define BG_1 "sprites/background/background_1.png"
#define PLATEFORM "sprites/Platforms/tall_platform.png"
#endif

#define ERROR_MESSAGE "Un problème est survenue"
#define DISPLAY_WIDTH 1920
#define BUFF_SIZE 10000
#define DISPLAY_HEIGHT 1080
#define WINDOW_TITLE "JetRun - Leo Garret 2018"

void my_putchar(char c);
void my_putstr(char *str);
int my_getnbr(char *str);
char *my_gettxt(int nbr);
int my_strlen(char const *str);
void my_swap(char *a, char *b);
char *str_cat(char *tab, const char *str);
void help_arg(void);
void menu(runner_t *runner);
void game(runner_t *runner);
void play(runner_t *runner);
sfRenderWindow *create_window(char *title, int width, int height);
void event_manager(runner_t *runner);
game_object_t create_object(const char *path_to_spritesheet,
sfVector2f pos, int rectMax);
void parallax(game_object_t *bg1, game_object_t *bg2, int speed);
void draw(runner_t *runner);
void clear_data(sfRenderWindow* window, game_object_t *go_array,
game_object_t *coin, int number_of_coins);
void init(sfRenderWindow* window, game_object_t *go_array);
void init_jetpack_rect(game_object_t *jetpack);
void move_rect(game_object_t *game_object);
game_object_t *game_object_array(sfRenderWindow *window);
void player_movement(runner_t *runner);
void change_texture(game_object_t *player, const char *path);
void fire_is_on(game_object_t *player);
sfVector2f *map_manager(char *map);
game_object_t *coin(sfVector2f *fuel_vectors, char *map);
char *open_map(char *file);
game_object_t *init_coin(sfVector2f *fuel_vectors, char *map);
int count_coins(char *map);
void collide_coin(runner_t *runner);
int last_vector(sfVector2f *vectors);
void distance(runner_t *runner);
void gravity(game_object_t *player, float velocity, float max_vel);
void fire_is_on(game_object_t *player);
void ground_collision(game_object_t *player);
void change_texture(game_object_t *player, const char *path);
void down_fuel_level(runner_t *runner);
void move_fuel(runner_t *runner);
void collide_fuel(runner_t *runner);
void draw_scene(runner_t *runner);
void init_scene(game_object_t *scene);
game_object_t *game_object_arr_2(sfRenderWindow *window, game_object_t *array);
menu_t init_menu(void);
void var_init(game_t *game, sfRenderWindow *window);
game_t init_game(sfRenderWindow *window);
runner_t init_runner(void);
void init_button(game_t *game, sfRenderWindow *window);
void btn_replay(runner_t *runner);
void reset(runner_t *runner);
void btn_menu(runner_t *runner);
void init_obstacle(runner_t *runner);
void random_obstacle(runner_t *runner);
void move_obstacle(runner_t *runner);
void collide_obstacle(runner_t *runner);
void move_trap(runner_t *runner);
void collide_fuel_e(runner_t *runner);
void init_help(runner_t *runner);
void btn_help(runner_t *runner);
void help_scene(runner_t *runner);
void btn_menu_help(runner_t *runner);
void btn_resume(runner_t *runner);
void init_runner_2(runner_t *runner);
void init_game_2(game_t *game);
void quit(runner_t *runner);
void norm(runner_t *runner);

#endif /* __LIST */