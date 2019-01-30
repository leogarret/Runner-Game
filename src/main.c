/*
** EPITECH PROJECT, 2018
** Léo Garret
** File description:
** main.c
*/

#include "../include/my.h"

void verif(runner_t *runner)
{
    if (runner->event.type == sfEvtClosed)
        sfRenderWindow_close(runner->window);
    if (runner->event.type == sfEvtMouseButtonPressed &&
        runner->scene == 0) {
        play(runner);
        btn_help(runner);
        quit(runner);
    }
    else if (runner->event.type == sfEvtMouseButtonPressed &&
        runner->scene == 2)
        btn_menu_help(runner);
}

void loop(void)
{
    runner_t runner = init_runner();

    runner.game.snd = sfMusic_createFromFile("sound/sf.ogg");
    init_scene(&runner.game.end);
    init_help(&runner);
    runner.game.game_scene = 0;
    while (sfRenderWindow_isOpen(runner.window)) {
        while (sfRenderWindow_pollEvent(runner.window, &runner.event))
            verif(&runner);
        if (runner.scene == 0)
            menu(&runner);
        else if (runner.scene == 1)
            game(&runner);
        else if (runner.scene == 2)
            help_scene(&runner);
    }
    sfMusic_stop(runner.game.snd);
    clear_data(runner.window, runner.game.go_array, runner.game.coin,
    runner.game.number_of_coins);
}

int main(int ac, char **av)
{
    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h') {
            help_arg();
            return (0);
        }
    }
    loop();
    return (0);
}