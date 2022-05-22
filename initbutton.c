/*
** EPITECH PROJECT, 2021
** init_button.c
** File description:
** init_button
*/

#include"graph.h"

void put_start(sfRenderWindow *windows)
{
    sfTexture *texture = sfTexture_createFromFile("image/bouton.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos;
    sfVector2f scale;

    scale.x = 0.5;
    scale.y = 0.5;
    pos.x = 500;
    pos.y = 480;
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, scale);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_drawSprite(windows, sprite, NULL);
}

void put_how(sfRenderWindow *windows)
{
    sfTexture *texture = sfTexture_createFromFile("image/how2.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos;
    sfVector2f scale;

    scale.x = 0.5;
    scale.y = 0.5;
    pos.x = 700;
    pos.y = 480;
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, scale);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_drawSprite(windows, sprite, NULL);
}

void put_exit(sfRenderWindow *windows)
{
    sfTexture *texture = sfTexture_createFromFile("image/exit.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos;
    sfVector2f scale;

    scale.x = 0.5;
    scale.y = 0.5;
    pos.x = 300;
    pos.y = 480;
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, scale);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_drawSprite(windows, sprite, NULL);
}