/*
** EPITECH PROJECT, 2022
** my_putchar.c
** File description:
** Function to display
*/

#include <unistd.h>

void my_putchar(int c)
{
    write(1, &c, 1);
}
