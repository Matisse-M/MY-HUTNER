/*
** EPITECH PROJECT, 2022
** game_setup.c
** File description:
** setup the game's functions
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdbool.h>
#include <time.h>
#include "lib.h"
#include "struct.h"

void open_window(all_resources_t *game)
{
    game->window.mode.bitsPerPixel = 32;
    game->window.mode.width = 1920;
    game->window.mode.height = 1080;
    game->window.window = sfRenderWindow_create(game->window.mode,
    "MyHunter", sfResize | sfClose, NULL);
    game->music = malloc(sizeof(*(game->music)) * 2);
    game->music[0].song = sfMusic_createFromFile("src/audio.ogg");
}

void open_sprite1(all_resources_t *game)
{
    game->pictures = malloc(sizeof(*(game->pictures)) * 9);
    game->pictures[0].texture = sfTexture_createFromFile("src/waterfall.jpg",
    NULL);
    game->pictures[0].sprite = sfSprite_create();
    sfSprite_setTexture(game->pictures[0].sprite,
    game->pictures[0].texture, sfFalse);
    game->pictures[1].texture = sfTexture_createFromFile("src/title.png", NULL);
    game->pictures[1].sprite = sfSprite_create();
    game->pictures[1].pos = (sfVector2f) {50, 50};
    sfSprite_setPosition(game->pictures[1].sprite, game->pictures[1].pos);
    sfSprite_setTexture(game->pictures[1].sprite,
    game->pictures[1].texture, sfFalse);
    game->pictures[2].texture = sfTexture_createFromFile("src/fusil.png", NULL);
    game->pictures[2].sprite = sfSprite_create();
    game->pictures[2].pos = (sfVector2f) {0, 470};
    sfSprite_setPosition(game->pictures[2].sprite, game->pictures[2].pos);
    sfSprite_setTexture(game->pictures[2].sprite,
    game->pictures[2].texture, sfFalse);
}

void open_sprite2(all_resources_t *game)
{
    game->pictures[3].texture = sfTexture_createFromFile("src/start.png", NULL);
    game->pictures[3].sprite = sfSprite_create();
    game->pictures[3].pos = (sfVector2f) {1350, 520};
    sfSprite_setPosition(game->pictures[3].sprite, game->pictures[3].pos);
    sfSprite_setTexture(game->pictures[3].sprite,
    game->pictures[3].texture, sfFalse);
    game->pictures[4].texture = sfTexture_createFromFile("src/waterfall2.jpg",
    NULL);
    game->pictures[4].sprite = sfSprite_create();
    sfSprite_setTexture(game->pictures[4].sprite,
    game->pictures[4].texture, sfFalse);
    game->pictures[5].texture = sfTexture_createFromFile("src/cross.png", NULL);
    game->pictures[5].sprite = sfSprite_create();
    game->pictures[5].pos = (sfVector2f) {0, 0};
    sfSprite_setPosition(game->pictures[5].sprite, game->pictures[5].pos);
    sfSprite_setScale(game->pictures[5].sprite, (sfVector2f) {0.5f, 0.5f});
    sfSprite_setTexture(game->pictures[5].sprite,
    game->pictures[5].texture, sfFalse);
}

void random_pos(all_resources_t *game)
{
    int max_y = 900;
    int min = 1;

    srand(time(NULL));
    game->pictures[7].pos.x = 0;
    game->pictures[7].pos.y = rand() % (max_y - min + 1) + min;
    sfSprite_setPosition(game->pictures[7].sprite, game->pictures[7].pos);
}

void open_sprite3(all_resources_t *game)
{
    game->pictures[6].texture = sfTexture_createFromFile("src/pointeur.png", NULL);
    game->pictures[6].sprite = sfSprite_create();
    sfSprite_setScale(game->pictures[6].sprite, (sfVector2f) {0.5f, 0.5f});
    sfSprite_setTexture(game->pictures[6].sprite,
    game->pictures[6].texture, sfFalse);
    game->pictures[7].texture = sfTexture_createFromFile("src/Roucool.png", NULL);
    game->pictures[8].texture = sfTexture_createFromFile("src/Roucool.png", NULL);
    game->pictures[7].sprite = sfSprite_create();
    game->pictures[8].sprite = sfSprite_create();
    random_pos(game);
    random_pos2(game);
    sfSprite_setScale(game->pictures[7].sprite, (sfVector2f) {2.8f, 2.8f});
    sfSprite_setTexture(game->pictures[7].sprite,
    game->pictures[7].texture, sfFalse);
    sfSprite_setScale(game->pictures[8].sprite, (sfVector2f) {2.8f, 2.8f});
    sfSprite_setTexture(game->pictures[8].sprite,
    game->pictures[8].texture, sfFalse);
    game->timer = sfClock_create();
}
