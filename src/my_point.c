/*
** EPITECH PROJECT, 2021
** my_point
** File description:
** my_point
*/

#include "graph.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

static const sfVector2f RIGHT_POINTS[] = {
    { 191, 298 },
    { 289, 387 },
    { 242, 476 },
    { 251, 596 },
    { 410, 640 },
    { 553, 625 },
};

static const sfVector2f LEFT_POINTS[] = {
    { 1045, 180 },
    { 1069, 256 },
    { 1057, 338 },
    { 966, 453 },
    { 903, 541 },
    { 823, 618 },
    { 708, 652 },
    { 655, 625 },
};

void waves(enemies **bad)
{
    int count = 0;
    int i = (*bad)->start_enemies;

    for (; i < (*bad)->nbr_enemies; i++)
        if (!bad[i]->hp.pv)
            count++;
    if (count == 3 && i != 9 && i != 10) {
        (*bad)->nbr_enemies += 3;
        (*bad)->start_enemies += 3;
    } else if (count == 3 && i == 9) {
        (*bad)->nbr_enemies += 1;
        (*bad)->start_enemies += 1;
    }
}

enemies *create_boss(int x, int y, int type)
{
    enemies *bad = malloc(sizeof(enemies));
    sfVector2f size, pos;
    sfTexture *texture = sfTexture_createFromFile("image/serpent.png",
    NULL);

    bad->sprite = sfSprite_create();
    bad->hp.pv = 100, bad->hp.pv_base = 100;
    pos.x  = x - 10, pos.y = y;
    size.x = 2, size.y = 2;
    bad->stop = 0;
    bad->pts.pts_end = 0, bad->pts.pts_now = -1;
    bad->pos.x = pos.x;
    bad->pos.y = pos.y;
    bad->barre.barre = init_barre(bad->pos.x, bad->pos.y);
    bad->barre.base_x = 60;
    sfSprite_setPosition(bad->sprite, pos);
    sfSprite_setTexture(bad->sprite, texture, sfTrue);
    sfSprite_setScale(bad->sprite, size);
    init_rect(bad, type);
    return bad;
}

void init_bad_point(enemies **bad)
{
    int i = 0;
    for (; i < 5; i++) {
        bad[i] = create_enemies(91, 249, 1);
        bad[i]->type = 1;
        bad[i]->point = RIGHT_POINTS;
    }
    for (; i < 9; i++) {
        bad[i] = create_enemies(1074, 184, 2);
        bad[i]->type = 2;
        bad[i]->point = LEFT_POINTS;
    }
    bad[9] = create_boss(91, 249, 1);
    bad[9]->type = 1;
    bad[9]->point = RIGHT_POINTS;
    (*bad)->start_enemies = 0;
    (*bad)->nbr_enemies = 3;
}