/*
** EPITECH PROJECT, 2022
** game.c
** File description:
** The Game
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window/Event.h>
#include "lib.h"
#include "struct.h"
#include "struct2.h"

void event_management(all_resources_t *game)
{
    while (sfRenderWindow_pollEvent(game->window.window,
    &game->window.event)) {
        if (game->window.event.type == sfEvtClosed ) {
            sfRenderWindow_close(game->window.window);
        }
        if (game->window.event.type == sfEvtMouseButtonPressed) {
            game->pictures->mouse = sfMouse_getPositionRenderWindow
            (game->window.window);
            change_scene(game);
        }
    }
}

int launcher(all_resources_t *game)
{
    sfMusic_play(game->music[0].song);
    sfMusic_setLoop(game->music[0].song, true);
    sfRenderWindow_setMouseCursorVisible(game->window.window, true);
    while (sfRenderWindow_isOpen(game->window.window)) {
        sfRenderWindow_clear(game->window.window, sfWhite);
        sfRenderWindow_drawSprite(game->window.window,
        game->pictures[0].sprite, NULL);
        sfRenderWindow_drawSprite(game->window.window,
        game->pictures[1].sprite, NULL);
        sfRenderWindow_drawSprite(game->window.window,
        game->pictures[2].sprite, NULL);
        sfRenderWindow_drawSprite(game->window.window,
        game->pictures[3].sprite, NULL);
        sfRenderWindow_display(game->window.window);
        event_management(game);
    }
    return (0);
}

void setup(all_resources_t *game)
{
    open_window(game);
    open_sprite1(game);
    open_sprite2(game);
    open_sprite3(game);
}


int main(int ac, char **av)
{
    all_resources_t game;
    help_zone_t help;

    if (ac == 1) {
        setup(&game);
        launcher(&game);
        destroy(&game);
        return (0);
    } else if (av[1][0] == '-' && av[1][1] == 'h') {
        help_menu(&help);
        return (0);
    } else {
        return (84);
    }
}
