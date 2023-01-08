/*
** EPITECH PROJECT, 2022
** lib.h
** File description:
** the prototypes of all the functions exposed by your libmy.a
*/

#ifndef LIB_H_
    #define LIB_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include "struct.h"
    #include "struct2.h"

void setup(all_resources_t *game);
void clicking(all_resources_t *game);
void event_management(all_resources_t *game);
int launcher(all_resources_t *game);
int help_menu(help_zone_t *help);
void event_management(all_resources_t *game);
void change_scene(all_resources_t *game);
int game_screen(all_resources_t *game);
void event_click(all_resources_t *game);
void cursor(all_resources_t *game);
void destroy(all_resources_t *game);
int my_putstr(char const *str);
void my_putchar(int c);
void open_window(all_resources_t *game);
void open_sprite1(all_resources_t *game);
void open_sprite2(all_resources_t *game);
void open_sprite3(all_resources_t *game);
void random_pos(all_resources_t *game);
void random_pos2(all_resources_t *game);


#endif
