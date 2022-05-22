#include "../include/jam.h"

void my_sprite_pos_three(void)
{
    if (life == 0) {
        game = 2;
    }
    if (game == 2) {
        sfRenderWindow_drawSprite(window, game_over_s, NULL);
        if (event.type == sfEvtMouseButtonPressed) {
            if (mouse.x >= 16 && mouse.y >= 417 && mouse.x <= 262  && mouse.y <= 454) {
                game = 1;
                life = 3;
                vecstar1.x = -200;
            }
            if (mouse.x >= 548 && mouse.y >= 416 && mouse.x <= 786  && mouse.y <= 451)
                sfRenderWindow_close(window);
        }
    }
}

void my_sprite_pos_two(void)
{
    if (life == 3) {
        sfRenderWindow_drawSprite(window, coeur3_s, NULL);
    }
    if (life == 2) {
        sfRenderWindow_drawSprite(window, coeur2_s, NULL);
    }
    if (life == 1) {
        sfRenderWindow_drawSprite(window, coeur1_s, NULL);
    }
    // sfRenderWindow_drawSprite(window, coeur3_s, NULL);
    sfSprite_setPosition(starw_vaisseau_s, vecstar1);
    vecstar1.x += 5 + (score / 2);
    if (vecstar1.x > 900) {
        vecstar1.x = -200;
        life--;
    }
    if ((vecstar1.x <= mouse.x && vecstar1.x + 134 >= mouse.x) &&
        (vecstar1.y <= mouse.y && vecstar1.y + 133 >= mouse.y) &&
        sfMouse_isButtonPressed(sfMouseLeft) == sfTrue){
        vecstar1.x = -200;
        vecstar1.y = rand() % (600 - 66);
        score++;
    }
}

void my_sprite_pos(void)
{
    sfSprite_setPosition(vaisseau4_s, vec4);
    vec4.x += 10;
    if (vec4.x > 900)
        vec4.x = -298;
    sfSprite_setPosition(vaisseau3_s, vec3);
    vec3.x += 10;
    if (vec3.x > 900)
        vec3.x = -120;
    sfSprite_setPosition(vaisseau2_s, vec2);
    vec2.x += 10;
    if (vec2.x > 900)
        vec2.x = -679;
    sfSprite_setPosition(vaisseau_s, vec1);
    vec1.x += 10;
    if (vec1.x > 900)
        vec1.x = -405;
}

void my_all_sprite_pos(void)
{
    if(game == 1) 
        my_sprite_pos_two();
    my_sprite_pos_three();
    my_sprite_pos();
}

void my_draw(void)
{
    sfRenderWindow_drawSprite(window, starw_vaisseau_s, NULL);
    sfRenderWindow_drawSprite(window, background_s, NULL);
    sfRenderWindow_drawSprite(window, starw_vaisseau_s, NULL);
    if (game == 0) {
        sfRenderWindow_drawSprite(window, salon_s, NULL);
        sfRenderWindow_drawSprite(window, vaisseau_s, NULL);
        sfRenderWindow_drawSprite(window, vaisseau2_s, NULL);
        sfRenderWindow_drawSprite(window, vaisseau3_s, NULL);
        sfRenderWindow_drawSprite(window, vaisseau4_s, NULL);
    }
}

void my_music(void)
{
    musique = sfMusic_createFromFile( "./song/starwars.ogg");
    sfMusic_play(musique);
}

void my_salon(void)
{
    game_over_t = sfTexture_createFromFile("./images/gameover.png", NULL);
    game_over_s = sfSprite_create();
    sfSprite_setTexture(game_over_s, game_over_t, 0);
    salon_t = sfTexture_createFromFile("./images/accueil.png", NULL);
    salon_s = sfSprite_create();
    sfSprite_setTexture(salon_s, salon_t, 0);
    background_t = sfTexture_createFromFile("./images/starsbackground.png", NULL);
    background_s = sfSprite_create();
    sfSprite_setTexture(background_s, background_t, 0); 
}

void my_vaisseau(void)
{
    coeur3_t = sfTexture_createFromFile("./images/coeur3.png", NULL);
    coeur3_s = sfSprite_create();
    sfSprite_setPosition(coeur3_s, vectcoeur3);
    sfSprite_setTexture(coeur3_s, coeur3_t, 0);

    coeur2_t = sfTexture_createFromFile("./images/coeur2.png", NULL);
    coeur2_s = sfSprite_create();
    sfSprite_setTexture(coeur2_s, coeur2_t, 0);

    coeur1_t = sfTexture_createFromFile("./images/coeur1.png", NULL);
    coeur1_s = sfSprite_create();
    sfSprite_setTexture(coeur1_s, coeur1_t, 0);

    starw_vaisseau_t = sfTexture_createFromFile("./images/starwvaisseau.png", NULL);
    starw_vaisseau_s = sfSprite_create();
    sfSprite_setPosition(starw_vaisseau_s, vec1);
    sfSprite_setTexture(starw_vaisseau_s, starw_vaisseau_t, 0);
    vaisseau_t = sfTexture_createFromFile("./images/vaisseauspace.png", NULL);
    vaisseau_s = sfSprite_create();
    sfSprite_setPosition(vaisseau_s, vec1);
    sfSprite_setTexture(vaisseau_s, vaisseau_t, 0);
    vaisseau2_t = sfTexture_createFromFile("./images/vaisseauspace2.png", NULL);
    vaisseau2_s = sfSprite_create();
    sfSprite_setPosition(vaisseau2_s, vec2);
    sfSprite_setTexture(vaisseau2_s, vaisseau2_t, 0);
    vaisseau3_t = sfTexture_createFromFile("./images/vaisseauspace3.png", NULL);
    vaisseau3_s = sfSprite_create();
    sfSprite_setPosition(vaisseau3_s, vec3);
    sfSprite_setTexture(vaisseau3_s, vaisseau3_t, 0);
    vaisseau4_t = sfTexture_createFromFile("./images/vaisseauspace4.png", NULL);
    vaisseau4_s = sfSprite_create();
    sfSprite_setPosition(vaisseau4_s, vec4);
    sfSprite_setTexture(vaisseau4_s, vaisseau4_t, 0);
}

int main(void)
{
    window  = sfRenderWindow_create(mode, "Jam", sfResize | sfClose, NULL);
    my_vaisseau();
    my_salon();
    //my_music();
    clock_png = sfClock_create();
    while (sfRenderWindow_isOpen(window)) {
        //sfIntRect rect_jpg = {jpg, 0, 67, 66};
        //if (sfTime_asSeconds(sfClock_getElapsedTime(clock_png)) >= 0.080) {
            //jpg = jpg - 67;
            //sfSprite_setTextureRect(starw_vaisseau_s, rect_jpg);
            //if (jpg <= 0) {
            //    jpg = 737;
            //    sfClock_restart(clock_png);
            //}
        //}
        sfIntRect rectcoeur_jpg = {0, coeurjpg, 313, 59};
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtMouseButtonPressed) {
                if (mouse.x >= 180 && mouse.y >= 380 && mouse.x <= 610  && mouse.y <= 450 ) {
                    game = 1;
                    life = 3;
                }
            }
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        mouse = sfMouse_getPositionRenderWindow(window);
        my_draw();
        sfRenderWindow_setFramerateLimit(window, 30);
        my_all_sprite_pos();
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    sfMusic_destroy(musique);
    return 0;
}
