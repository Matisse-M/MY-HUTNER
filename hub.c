/*
** EPITECH PROJECT, 2022
** hub.c
** File description:
** Many functions with no sense together
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window/Event.h>
#include <time.h>
#include "lib.h"
#include "struct.h"

void change_scene(all_resources_t *game)
{
    if (game->pictures->mouse.x >= 1440 && game->pictures->mouse.x <= 1720
    && game->pictures->mouse.y >= 645 && game->pictures->mouse.y <= 750) {
        if (game->window.event.type == sfEvtMouseButtonPressed) {
            game_screen(game);
        }
    }
    if (game->pictures->mouse.x >= 0 && game->pictures->mouse.x <= 102
    && game->pictures->mouse.y >= 0 && game->pictures->mouse.y <= 102) {
        if (game->window.event.type == sfEvtMouseButtonPressed) {
            launcher(game);
        }
    }
}

void cursor (all_resources_t *game)
{
    game->pictures->mouse.x = sfMouse_getPositionRenderWindow
    (game->window.window).x - 103;
    game->pictures->mouse.y = sfMouse_getPositionRenderWindow
    (game->window.window).y - 103;
    game->pictures[6].pos = (sfVector2f) {game->pictures->mouse.x,
    game->pictures->mouse.y};
    sfSprite_setPosition(game->pictures[6].sprite, game->pictures[6].pos);
    sfRenderWindow_drawSprite(game->window.window,
    game->pictures[6].sprite, NULL);
}

void destroy(all_resources_t *game)
{
    sfSprite_destroy(game->pictures[0].sprite);
    sfSprite_destroy(game->pictures[1].sprite);
    sfSprite_destroy(game->pictures[2].sprite);
    sfSprite_destroy(game->pictures[3].sprite);
    sfSprite_destroy(game->pictures[4].sprite);
    sfSprite_destroy(game->pictures[5].sprite);
    sfSprite_destroy(game->pictures[6].sprite);
    sfSprite_destroy(game->pictures[7].sprite);
    sfSprite_destroy(game->pictures[8].sprite);
    sfMusic_destroy(game->music[0].song);
    sfClock_destroy(game->timer);
}

void random_pos2(all_resources_t *game)
{
    int max_y = 900;
    int min = 1;

    srand(time(NULL));
    game->pictures[8].pos.x = 1920;
    game->pictures[8].pos.y = rand() % (max_y - min + 1) + min;
    sfSprite_setPosition(game->pictures[8].sprite, game->pictures[8].pos);
}