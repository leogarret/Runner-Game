/*
** EPITECH PROJECT, 2018
** Léo Garret
** File description:
** end.c
*/

#include "../include/my.h"

void btn_replay(runner_t *runner)
{
    runner->game.m_vec = sfMouse_getPosition(runner->win);

    if (runner->game.m_vec.x >= runner->game.vec_replay.x &&
        runner->game.m_vec.x <= (runner->game.vec_replay.x + 150)) {
        if (runner->game.m_vec.y >= runner->game.vec_replay.y &&
            runner->game.m_vec.y <= (runner->game.vec_replay.y + 100)) {
            reset(runner);
        }
    }
}

void btn_menu(runner_t *runner)
{
    runner->game.m_vec = sfMouse_getPosition(runner->win);

    if (runner->game.m_vec.x >= runner->game.vec_menu.x &&
        runner->game.m_vec.x <= (runner->game.vec_menu.x + 150)) {
        if (runner->game.m_vec.y >= runner->game.vec_menu.y &&
            runner->game.m_vec.y <= (runner->game.vec_menu.y + 100)) {
            runner->game.game_scene = 0;
            runner->scene = 0;
            reset(runner);
        }
    }
}

void btn_resume(runner_t *runner)
{
    runner->game.m_vec = sfMouse_getPosition(runner->win);
    srand(time(0));
    if (runner->game.m_vec.x >= runner->game.vec_resume.x &&
        runner->game.m_vec.x <= (runner->game.vec_resume.x + 150)) {
        if (runner->game.m_vec.y >= runner->game.vec_resume.y &&
            runner->game.m_vec.y <= (runner->game.vec_resume.y + 100)) {
            runner->game.game_scene = 0;
            runner->game.fuel = 100;
            runner->pass = 0;
            runner->game.obstacle.position.x = 2000 + rand()%2000;
            runner->game.score -= (runner->game.distance * 6);
            sfText_setString(runner->game.txt_score,
            my_gettxt(runner->game.score));
            sfRenderWindow_drawText(runner->window,
            runner->game.txt_score, NULL);
        }
    }
}