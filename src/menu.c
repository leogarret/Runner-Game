/*
** EPITECH PROJECT, 2018
** Léo Garret
** File description:
** menu.c
*/

#include "../include/my.h"

void play(runner_t *runner)
{
    runner->game.m_vec = sfMouse_getPosition(runner->win);
    runner->game.s_vec = sfSprite_getPosition(runner->menu.btn_play.sprite);

    if (runner->game.m_vec.x >= runner->game.s_vec.x &&
        runner->game.m_vec.x <= (runner->game.s_vec.x + 288)) {
        if (runner->game.m_vec.y >= runner->game.s_vec.y &&
            runner->game.m_vec.y <= (runner->game.s_vec.y + 120)) {
            runner->scene = 1;
            sfMusic_play(runner->game.snd);
            sfMusic_setLoop(runner->game.snd, sfTrue);
        }
    }
}

void quit(runner_t *runner)
{
    runner->game.m_vec = sfMouse_getPosition(runner->win);
    runner->game.s_vec = sfSprite_getPosition(runner->menu.btn_quit.sprite);

    if (runner->game.m_vec.x >= runner->game.s_vec.x &&
        runner->game.m_vec.x <= (runner->game.s_vec.x + 288)) {
        if (runner->game.m_vec.y >= runner->game.s_vec.y &&
            runner->game.m_vec.y <= (runner->game.s_vec.y + 120)) {
            runner->scene = 1;
            sfRenderWindow_close(runner->window);
        }
    }
}

void menu(runner_t *runner)
{
    sfRenderWindow_drawSprite(runner->window,
    runner->menu.background.sprite, NULL);
    sfRenderWindow_drawSprite(runner->window,
    runner->menu.btn_play.sprite, NULL);
    sfRenderWindow_drawSprite(runner->window,
    runner->menu.btn_quit.sprite, NULL);
    sfRenderWindow_drawSprite(runner->window,
    runner->help.btn_howtoplay.sprite, NULL);
    sfRenderWindow_display(runner->window);
    sfRenderWindow_clear(runner->window, sfBlack);
}