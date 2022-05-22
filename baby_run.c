/*
** EPITECH PROJECT, 2021
** verif_tower.c
** File description:
** verif_tower.c
*/

#include "graph.h"
#include <math.h>

sfTexture *texture_attaque(int flag)
{
    sfTexture *texture;

    if (flag == 0)
        texture = sfTexture_createFromFile("image/ball.png", NULL);
    if (flag == 1)
        texture = sfTexture_createFromFile("image/ball.png", NULL);
    if (flag == 2)
        texture = sfTexture_createFromFile("image/fire_ball.png", NULL);
    if (flag == 3)
        texture = sfTexture_createFromFile("image/ice_pick.png", NULL);
    if (flag == 4)
        texture = sfTexture_createFromFile("image/thunder_ball.png", NULL);
    return texture;
}

int start_attack(enemies *bad, defense *tower)
{
    sfTexture *texture = texture_attaque(tower->flag);
    sfVector2f scale;

    scale.x = 0.35, scale.y = 0.35;
    tower->shoot.sprite = sfSprite_create();
    tower->shoot.flag = 1;
    tower->shoot.my_pos.x = tower->x - 10;
    tower->shoot.my_pos.y = tower->y - 50;
    tower->shoot.my_attack.x = bad->pos.x;
    tower->shoot.my_attack.y = bad->pos.y;
    if (tower->shoot.my_pos.x > bad->pos.x)
        tower->shoot.offset.x = -5;
    else
        tower->shoot.offset.x = 5;
    tower->shoot.offset.y = make_dy(tower->shoot.my_pos, \
    tower->shoot.my_attack, tower->shoot.offset.x);
    sfSprite_setPosition(tower->shoot.sprite, tower->shoot.my_pos);
    sfSprite_setTexture(tower->shoot.sprite, texture, sfTrue);
    sfSprite_setScale(tower->shoot.sprite, scale);
}

int verif_tower(enemies *bad, defense *tower)
{
    float rad = 70;

    if (pow((bad->pos.x - tower->x + 26.66666667), 2) +  \
    pow((bad->pos.y - tower->y + 26.66666667), 2)   \
    <= pow(2 * rad, 2))
        return 1;
    else
        return 0;
}

int tower_vs_bad(enemies *bad, defense *tower)
{
    for (int i = 0; i < tower->nbr; i++) {
        if (verif_tower(bad, &tower[i]) && !tower[i].shoot.flag) {
            start_attack(bad, &tower[i]);
        }
    }
    return 0;
}