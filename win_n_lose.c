/*
** EPITECH PROJECT, 2021
** win_n_lose.c
** File description:
** win_n_lose
*/

#include "graph.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int game(sfRenderWindow *windows, defense *tower, sfEvent *event, \
enemies **bad)
{

    if (hub() == 3)
        return 0;
    while (sfRenderWindow_isOpen(windows)) {
        sfRenderWindow_clear(windows, sfBlack);
        if (!loop_event(windows, event, tower))
                return 0;
        if (tower->player.lose == 1)
            you_lose(windows);
        else if (tower->player.win == 1)
            you_win(windows);
        else {
            windows_sprite(windows);
            if (tower->flag == 'p')
                continue;
            manage_sprite(windows, bad, tower);
            test_circle(windows, tower);
        }
        sfRenderWindow_display(windows);
    } sfRenderWindow_destroy(windows);
    all_free(tower, bad);
}

void you_lose(sfRenderWindow *windows)
{
    sfTexture *texture = sfTexture_createFromFile("image/game_over_1.jpg", \
    NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos;
    sfVector2f scale;

    scale.x = 1.8;
    scale.y = 1.5;
    pos.x = 0;
    pos.y = 0;
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, scale);
    sfRenderWindow_drawSprite(windows, sprite, NULL);
}

void you_win(sfRenderWindow *windows)
{
    sfTexture *texture = sfTexture_createFromFile("image/you_win_2.jpg", \
    NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos;

    pos.x = 0;
    pos.y = 0;
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(windows, sprite, NULL);
}