/*
** EPITECH PROJECT, 2018
** Léo Garret
** File description:
** help.c
*/

#include "../include/my.h"

void init_help(runner_t *runner)
{
    runner->help.btn_howtoplay = create_object("sprites/htp.png",
    (sfVector2f){1400, 900}, 0);
    runner->help.game_rule = create_object("sprites/help.png",
    (sfVector2f){500, 200}, 0);
    runner->help.btn_home = create_object("sprites/home.png",
    (sfVector2f){1700, 900}, 0);
}

void btn_help(runner_t *runner)
{
    runner->game.m_vec = sfMouse_getPosition(runner->win);

    if (runner->game.m_vec.x >= runner->help.btn_howtoplay.position.x &&
        runner->game.m_vec.x <= (runner->help.btn_howtoplay.position.x + 400)) {
        if (runner->game.m_vec.y >= runner->help.btn_howtoplay.position.y &&
            runner->game.m_vec.y <=
            (runner->help.btn_howtoplay.position.y + 120)) {
            runner->scene = 2;
        }
    }
}

void btn_menu_help(runner_t *runner)
{
    runner->game.m_vec = sfMouse_getPosition(runner->win);

    if (runner->game.m_vec.x >= runner->help.btn_home.position.x &&
        runner->game.m_vec.x <= (runner->help.btn_home.position.x + 130)) {
        if (runner->game.m_vec.y >= runner->help.btn_home.position.y &&
            runner->game.m_vec.y <= (runner->help.btn_home.position.y + 120)) {
            runner->scene = 0;
        }
    }
}

void help_scene(runner_t *runner)
{
    sfRenderWindow_drawSprite(runner->window, runner->help.game_rule.sprite,
    NULL);
    sfRenderWindow_drawSprite(runner->window, runner->help.btn_home.sprite,
    NULL);
    sfRenderWindow_display(runner->window);
    sfRenderWindow_clear(runner->window, sfBlack);
}

void help_arg(void)
{
    my_putstr("JetRun by Leo Garret\n\n");
    my_putstr("USAGE\n");
    my_putstr("./my_runner\n\n");
    my_putstr("OPTIONS\n");
    my_putstr("-h print the usage and quit.\n\n");
    my_putstr("MAP\n");
    my_putstr("Edit map_1.txt in map folder for change map\n");
    my_putstr("The size of map is 27*100, the map_1.txt can be ");
    my_putstr("edit with 27 lines and 100 columns\n");
    my_putstr("Good game !\n");
}