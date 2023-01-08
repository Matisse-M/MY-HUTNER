/*
** EPITECH PROJECT, 2022
** struct.h
** File description:
** structure for all the project
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#ifndef __STRUCT_H_
    #define __STRUCT_H_

    typedef struct window_s {
        sfRenderWindow *window;
        sfVideoMode mode;
        sfEvent event;
    } window_t;

    typedef struct pictures_s {
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f pos;
        sfVector2i mouse;
        sfIntRect rect;
    } pictures_t;

    typedef struct music_s {
        sfMusic *song;
        sfTime skip;
        int i;
        int j;
    } music_t;

    typedef struct all_resources_s {
        window_t window;
        pictures_t *pictures;
        music_t *music;
        sfClock *timer;
        sfTime clock;
    } all_resources_t;

#endif
