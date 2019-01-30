/*
** EPITECH PROJECT, 2018
** Léo Garret
** File description:
** event_manager.c
*/

#include "../include/my.h"

int count_coins(char *map)
{
    int count = 0;

    for (int i = 0; map[i]; i++) {
        if (map[i] == '%')
            count++;
    }
    return (count);
}

sfVector2f *map_manager(char *map)
{
    sfVector2f *vectors;
    int vector_position = 0;
    int x = 0;
    int y = 0;

    if (!(vectors = malloc(sizeof(sfVector2f) * count_coins(map))))
        return (NULL);
    for (int i = 0; map[i]; i++, x += 32) {
        if (map[i] == '\n') {
            y += 32;
            x = 0;
        }
        if (map[i] == '%')
            vectors[vector_position++] = (sfVector2f){x, y};
    }
    return (vectors);
}

game_object_t *coin(sfVector2f *coin_vectors, char *map)
{
    static int position = 0;
    static game_object_t *array;
    game_object_t coin = create_object("sprites/coin.png",
    coin_vectors[position], 1);

    if (position == 0)
        if (!(array = malloc(sizeof(game_object_t) * count_coins(map))))
            return (NULL);
    array[position] = coin;
    position++;
    return (array);
}

char *open_map(char *file)
{
    char *buffer;
    int fd = open(file, O_RDONLY);
    int fileSize;

    if (!(buffer = malloc(sizeof(char) * BUFF_SIZE)))
        return (NULL);
    if (fd == -1) {
        write(2, "No such file or directory\n", 27);
        return (NULL);
    }
    fileSize = read(fd, buffer, BUFF_SIZE);
    if (fileSize < 0)
        return (NULL);
    return (buffer);
}