/*
** EPITECH PROJECT, 2021
** hub.c
** File description:
** hub
*/

#include"graph.h"

void init_hub_windows(sfRenderWindow *windows)
{
    sfTexture *texture = sfTexture_createFromFile("image/hub.jpg", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos;
    sfVector2f scale;

    scale.x = 0.3125;
    scale.y = 0.324074074;
    pos.x = 0;
    pos.y = 0;
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, scale);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_drawSprite(windows, sprite, NULL);
}

int touch_button(sfEvent *event, sfRenderWindow *windows, int ans)
{
    int x, y;

    while (sfRenderWindow_pollEvent(windows, event)) {
        if (event->type == sfEvtKeyPressed)
            return 1;
        if (event->type == sfEvtMouseButtonReleased) {
            x = event->mouseButton.x;
            y = event->mouseButton.y;
          if (x >= 499 && x <= 672 && y >= 477 && y <= 537)
                return 1;
            if (x >= 696 && x <= 866 && y >= 473 && y <= 540)
                 return 2;
     if (x >= 299 && x <= 472 && y >= 480 && y <= 547)
                return 3;
        }        break;
     if (event->type == sfEvtClosed) {
            sfRenderWindow_close(windows);
            return 3;
        }
    }
    return ans;
}

void how_rule(sfRenderWindow *windows)
{
    sfTexture *texture = sfTexture_createFromFile("image/rules.jpg", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos;
    sfVector2f scale;

    scale.x = 1;
    scale.y = 1;
    pos.x = 0;
    pos.y = 0;
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, scale);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_drawSprite(windows, sprite, NULL);
}

int hub(void)
{
    sfMusic *music;
    sfRenderWindow *windows = create_window(1200, 700);
    sfEvent event;
    int ans = 0;

    music = sfMusic_createFromFile("./music/dragon.flac");
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);

    while (sfRenderWindow_isOpen(windows)) {
        sfRenderWindow_clear(windows, sfBlack);
        if (!ans)
            init_hub_windows(windows);
        else if (ans == 2)
            how_rule(windows);
        put_exit(windows);
        put_how(windows);
        put_start(windows);
        ans = touch_button(&event, windows, ans);
        if (ans && ans != 2)
            break;
        sfRenderWindow_display(windows);
    }
    sfRenderWindow_destroy(windows);
    return ans;
}
