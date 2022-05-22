#ifndef JAM_H_
#define JAM_H_

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Window/Event.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/System/Vector2.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Window/Types.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Export.h>
#include <SFML/Audio/Types.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio.h>

sfMusic *musique;
sfVideoMode mode = {800, 600, 30};
sfRenderWindow *window;
sfEvent event;
sfRectangleShape *rec;
sfVector2f vec = {1, 1};
sfVector2f size = {50, 50};
sfTexture *salon_t;
sfSprite *salon_s;
sfTexture *background_t;
sfSprite *background_s;
sfTexture *vaisseau_t;
sfSprite *vaisseau_s;
sfVector2f vec1 = {-230, 100};
sfVector2f size1 = {20, 20};
sfTexture *vaisseau2_t;
sfSprite *vaisseau2_s;
sfVector2f vec2 = {-496, 233};
sfVector2f size2 = {20, 20};
sfTexture *vaisseau3_t;
sfSprite *vaisseau3_s;
sfVector2f vec3 = {-56, 366};
sfVector2f size3 = {20, 20};
sfTexture *vaisseau4_t;
sfSprite *vaisseau4_s;
sfVector2f vec4 = {-689, 490};
sfVector2f size4 = {20, 20};
sfVector2i mouse;
sfTexture *starw_vaisseau_t;
sfSprite *starw_vaisseau_s;
sfVector2f vecstar1 = {-20, 200};
sfVector2f sizestar1 = {20, 20};

sfTexture *coeur3_t;
sfSprite *coeur3_s;
sfVector2f vectcoeur3 = {0, 9};
sfVector2f sizecoeur3 = {20, 20};

sfTexture *coeur2_t;
sfSprite *coeur2_s;
sfVector2f vectcoeur2 = {0, 9};
sfVector2f sizecoeur2 = {20, 20};

sfTexture *coeur1_t;
sfSprite *coeur1_s;
sfVector2f vectcoeur1 = {0, 9};
sfVector2f sizecoeur1 = {20, 20};


sfTexture *game_over_t;
sfSprite *game_over_s;
sfClock *clock_png;
sfClock *clockcoeur_png;
int v = 1;
int jpg = 737;
int coeurjpg = 0;
int score = 0;
int life = 3;
sfIntRect rect_jpg = {0, 0, 67, 66};
sfIntRect rectcoeur_jpg = {0, 0, 313, 59};
void open_window(sfRenderWindow *window);
int game = 0;

#endif
