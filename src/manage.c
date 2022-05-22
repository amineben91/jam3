/*
** EPITECH PROJECT, 2021
** manag_loop.c
** File description:
** manage
*/


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