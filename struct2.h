/*
** EPITECH PROJECT, 2022
** struct2.h
** File description:
** structure for the -h window
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#ifndef __WINDOW_H_
    #define __WINDOW_H_

    typedef struct openh_window_s {
        sfRenderWindow *window;
        sfVideoMode mode;
        sfEvent event;
        sfText *text;
    } openh_window_t;

    typedef struct openh_music_s {
        sfMusic *song;
        sfTime skip;
    } openh_music_t;

    typedef struct help_zone_s {
        openh_window_t screen;
        openh_music_t song;
    } help_zone_t;

#endif
