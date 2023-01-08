/*
** EPITECH PROJECT, 2022
** help.c
** File description:
** The help zone
*/

#include<unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "lib.h"
#include "struct2.h"

int help_menu(help_zone_t *help)
{
    write(1, "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW\n", 40);
    write(1, "o DESCRIPTION:                       o\n", 40);
    write(1, "o A game where you must shoot some   o\n", 40);
    write(1, "o Pidgey if you failed 3 times, the  o\n", 40);
    write(1, "o game is finished !                 o\n", 40);
    write(1, "o                                    o\n", 40);
    write(1, "o GAMEPLAY:                          o\n", 40);
    write(1, "o Click on the Pidgey to restart it  o\n", 40);
    write(1, "o before it crosses the screen.      o\n", 40);
    write(1, "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n", 40);
    return (0);
}
