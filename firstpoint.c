/*
** EPITECH PROJECT, 2021
** base.c
** File description:
** base
*/

#include "graph.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

sfSprite *init_base(void)
{
    sfSprite *base = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("image/base.png", NULL);
    sfVector2f scale;
    sfVector2f pos;
    sfVector2f origin;

    pos.x = 500, pos.y = 465;
    origin.x = 10, origin.y = 200;
    scale.x = 0.5, scale.y = 0.5;
    sfSprite_setPosition(base, pos);
    sfSprite_setTexture(base, texture, sfTrue);
    sfSprite_setScale(base, scale);

    return base;
}

sfRectangleShape *final_rectangle(void)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfVector2f pos, size;

    pos.x = 655, pos.y = 528;
    size.x = 10, size.y = 100;
    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setFillColor(rect, sfBlue);
    return rect;
}

void init_qg(defense *tower)
{
    tower->my_qg.Qg.barre = final_rectangle();
    tower->my_qg.Qg.base_x = 100;
    tower->my_qg.life.pv = 300;
    tower->my_qg.life.pv_base = 300;
}

void move_offset(enemies *bad, defense *tower)
{
    set_offset(bad, tower);
    if (bad->rect.left == 49 * 2)
        bad->rect.left = 0;
    else
        bad->rect.left += 49.666666666;
    sfSprite_setPosition(bad->sprite, bad->pos);
    sfSprite_setTextureRect(bad->sprite, bad->rect);
    sfRectangleShape_setPosition(bad->barre.barre, bad->pos);
}
