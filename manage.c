/*
** EPITECH PROJECT, 2021
** manag_loop.c
** File description:
** manage
*/

#include "graph.h"
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int loop_event(sfRenderWindow *windows, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(windows, event)) {
            manage_event(event, windows);
            if (event->type == sfEvtKeyPressed) {
                return 0;
            }
            if (event->type == sfEvtClosed)
            sfRenderWindow_close(windows);
        }
    return 1;
}

void manage_enemies(enemies **bad, sfRenderWindow *windows, defense *tower)
{
    for (int i = (*bad)->start_enemies; i < (*bad)->nbr_enemies; i++) {
        if (!bad[i]->hp.pv) {
            bad[i]->pos.x = -100, bad[i]->pos.y = -100;
        } else {
            sfRenderWindow_drawSprite(windows, bad[i]->sprite, NULL);
            sfRenderWindow_drawRectangleShape(windows, \
            bad[i]->barre.barre, NULL);
            if (bad[i]->color)
                sfSprite_setColor(bad[i]->sprite, sfWhite);
        }
        sfRenderWindow_drawRectangleShape(windows, \
            tower->my_qg.Qg.barre, NULL);
    }
}

void manage_sprite(sfRenderWindow *windows, enemies **bad, defense *tower)
{
    for (int i = 0; i < tower->nbr; i++) {
        sfRenderWindow_drawSprite(windows, tower[i].my_square, NULL);
        if (tower[i].shoot.flag) {
            sfRenderWindow_drawSprite(windows, tower[i].shoot.sprite, NULL);
            if (tower[i].shoot.flag == -1)
                tower[i].shoot.flag = 0;
        }
    } move_path(bad, tower);
    manage_enemies(bad, windows, tower);
}