/*
** EPITECH PROJECT, 2020
** main
** File description:
** main.c
*/

#include "graph.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

void all_free(defense *tower, enemies **bad)
{
    for (int i = 0; i < 100; i++) {
        sfSprite_destroy(tower[i].my_square);
        if (tower[i].shoot.flag)
            sfSprite_destroy(tower[i].shoot.sprite);
    }
    sfRectangleShape_destroy(tower->my_qg.Qg.barre);
    free(tower->location);
    free(tower);
    for (int i = 0; i < (*bad)->nbr_enemies; i++) {
        sfSprite_destroy(bad[i]->sprite);
        sfRectangleShape_destroy(bad[i]->barre.barre);
        free(bad[i]);
    }
    free(bad);
}

void windows_sprite(sfRenderWindow *windows)
{
    sfSprite *sprite = sfSprite_create();
    sfSprite *base = init_base();
    sfSprite *tower = sfSprite_create();
    sfVector2f scale;
    sfTexture *text = sfTexture_createFromFile("image/castle-defender.png"
    , NULL);
    sfTexture *texture = sfTexture_createFromFile("image/plx2.png", NULL);
    sfVector2f pos, origine, sec_pos;

    scale.x = 0.5, scale.y = 0.5;
    pos.x = 0, pos.y = 0;
    sec_pos.x = 730, sec_pos.y = 20;
    sfSprite_setPosition(sprite, pos);
    sfSprite_setPosition(tower, sec_pos);
    sfSprite_setTexture(tower, texture, sfTrue);
    sfSprite_setTexture(sprite, text, sfTrue);
    sfSprite_setScale(tower, scale);
    sfRenderWindow_drawSprite(windows, sprite, NULL);
    sfRenderWindow_drawSprite(windows, tower, NULL);
    sfRenderWindow_drawSprite(windows, base, NULL);
}

int test_circle(sfRenderWindow *windows, defense *tower)
{
    if (!tower->flag)
        return 0;
    tower->location = malloc(sizeof(sfVector2f) * 8);
    tower->location[0].x = 294, tower->location[0].y = 239;
    tower->location[1].x = 159, tower->location[1].y = 405;
    tower->location[2].x = 350, tower->location[2].y = 522;
    tower->location[3].x = 538, tower->location[3].y = 583;
    tower->location[4].x = 830, tower->location[4].y = 490;
    tower->location[5].x = 977, tower->location[5].y = 261;
    tower->location[6].x = 944, tower->location[6].y = 656;
    tower->location[7].x = 703, tower->location[7].y = 579;
    for (int i = 0; i < 8; i++)
        make_circle(tower->location[i].x, tower->location[i].y, windows);
    return 0;
}

int main(void)
{
    sfRenderWindow *windows = create_window(1200, 700);
    defense *tower = init_tower();
    sfEvent event;
    enemies **bad = malloc(sizeof(enemies) * 10);
    init_bad_point(bad);

    game(windows, tower, &event, bad);
    return 0;
}