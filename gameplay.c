/*
** EPITECH PROJECT, 2022
** gameplay.c
** File description:
** The gameplay
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window/Event.h>
#include "lib.h"
#include "struct.h"

void motion(all_resources_t *game)
{
    game->clock = sfClock_getElapsedTime(game->timer);
    float seconds = game->clock.microseconds / 1000000.0;
    game->pictures[7].rect.width = 50;
    game->pictures[7].rect.height = 50;
    game->pictures[8].rect.width = 50;
    game->pictures[8].rect.height = 50;
    if (seconds < 0.1) {
        game->pictures[7].rect.top = 125;
        game->pictures[7].rect.left = 10;
        game->pictures[8].rect.top = 60;
        game->pictures[8].rect.left = 10;
    } else if (seconds < 0.2) {
        game->pictures[7].rect.top = 125;
        game->pictures[7].rect.left = 75;
        game->pictures[8].rect.top = 60;
        game->pictures[8].rect.left = 75;
    } else {
        sfClock_restart(game->timer);
    }
}

void sprite_position(all_resources_t *game)
{
    game->clock = sfClock_getElapsedTime(game->timer);
    float seconds = game->clock.microseconds / 1000000.0;
    if (seconds < 0.1) {
        game->pictures[7].pos.x += 0.2;
        sfSprite_setPosition(game->pictures[7].sprite, game->pictures[7].pos);
        game->pictures[8].pos.x -= 0.2;
        sfSprite_setPosition(game->pictures[8].sprite, game->pictures[8].pos);
    } else if (seconds < 0.2) {
        game->pictures[7].pos.x += 0.3;
        sfSprite_setPosition(game->pictures[7].sprite, game->pictures[7].pos);
        game->pictures[8].pos.x -= 0.3;
        sfSprite_setPosition(game->pictures[8].sprite, game->pictures[8].pos);
    } else {
        sfClock_restart(game->timer);
    }
}

void event_click(all_resources_t *game)
{
    game->music->j;
    game->pictures->mouse = sfMouse_getPositionRenderWindow
    (game->window.window);
    if (game->pictures->mouse.x >= game->pictures[7].pos.x &&
    game->pictures->mouse.x <= game->pictures[7].pos.x + 100
    && game->pictures->mouse.y >= game->pictures[7].pos.y &&
    game->pictures->mouse.y <= game->pictures[7].pos.y + 100) {
        if (game->window.event.type == sfEvtMouseButtonPressed){
            random_pos(game);
        }
    }
    if (game->pictures->mouse.x >= game->pictures[8].pos.x &&
    game->pictures->mouse.x <= game->pictures[8].pos.x + 100
    && game->pictures->mouse.y >= game->pictures[8].pos.y &&
    game->pictures->mouse.y <= game->pictures[8].pos.y + 100) {
        if (game->window.event.type == sfEvtMouseButtonPressed){
            random_pos2(game);
        }
    }
}

void shoot(all_resources_t *game)
{
    game->music->i;
    float seconds = game->clock.microseconds / 1000000.0;
    motion(game);
    sprite_position(game);
    sfSprite_setTextureRect(game->pictures[7].sprite, game->pictures[7].rect);
    sfSprite_setTextureRect(game->pictures[8].sprite, game->pictures[8].rect);
    sfRenderWindow_drawSprite(game->window.window,
    game->pictures[7].sprite, NULL);
    sfRenderWindow_drawSprite(game->window.window,
    game->pictures[8].sprite, NULL);
    if (game->pictures[7].pos.x >= 1920) {
        random_pos(game);
        game->music->i += 1;
        if (game->music->i == 2)
            launcher(game);
    }
    if (game->pictures[8].pos.x <= 0) {
        random_pos2(game);
        game->music->i += 1;
        if (game->music->i == 2)
            launcher(game);
    }
    if (game->window.event.type == sfEvtMouseButtonPressed)
        event_click(game);
}

int game_screen(all_resources_t *game)
{
    game->timer = sfClock_create();
    game->clock = sfClock_getElapsedTime(game->timer);
    while (sfRenderWindow_isOpen(game->window.window)) {
        sfRenderWindow_clear(game->window.window, sfWhite);
        sfRenderWindow_setMouseCursorVisible(game->window.window, false);
        sfRenderWindow_drawSprite(game->window.window,
        game->pictures[4].sprite, NULL);
        sfRenderWindow_drawSprite(game->window.window,
        game->pictures[5].sprite, NULL);
        motion(game);
        cursor(game);
        event_management(game);
        shoot(game);
        sfRenderWindow_display(game->window.window);
    }
    return (0);
}
