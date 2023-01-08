/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** one-by-one, the characters of a string.
*/

#include "lib.h"

int my_putstr(char const *str)
{
    char x = 0;

    while (str[x] != '\0'){
        my_putchar(str[x]);
        x++;
    }
}
