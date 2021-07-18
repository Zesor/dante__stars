/*
** EPITECH PROJECT, 2021
** main
** File description:
** Main of Generator for Dante
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dante.h"

void finish_dante(dante_t *dante)
{
    dante->map[dante->height - 1][dante->width - 1] = true;
    if (dante->perfect == true) {
        if ((rand() % 2) == 1)
            dante->map[dante->height - 2][dante->width - 1] = true;
        else
            dante->map[dante->height - 1][dante->width - 2] = true;
    } else {
        dante->map[dante->height - 2][dante->width - 1] = true;
        dante->map[dante->height - 1][dante->width - 2] = true;
    }
}

void destroy_maze(dante_t *dante)
{
    position_t *current;

    for (int i = 0; i != dante->history.size ; i++) {
        current = my_vector_get(&dante->history, i);
        free(current);
    }
    my_vector_free(&dante->history);

    for (int i = 0; i != dante->height; i++)
        free(dante->map[i]);
    free(dante->map);
    free(dante);
}

void print_maze(dante_t *dante)
{
    for (int i = 0; i != dante->height; i++) {
        for (int k = 0; k != dante->width; k++) {
            if (dante->map[i][k])
                printf("*");
            else
                printf("X");
        }
        if (i != (dante->height - 1))
            printf("\n");
    }
}

void init_maze(dante_t *dante)
{
    dante->map = malloc(sizeof(char *) * (dante->height));
    for (int i = 0; i != dante->height; i++) {
        dante->map[i] = malloc(sizeof(char) * (dante->width));
        for (int k = 0; k != dante->width; k++)
            dante->map[i][k] = false;
    }
    my_vector_init(&dante->history);
}

int main(int ac, char **av)
{
    dante_t *dante;
    int x = 0;
    int y = 0;

    if (ac < 3)
        return 84;
    x = atoi(av[1]);
    y = atoi(av[2]);
    if (x < 2 || y < 2)
        return 84;
    dante = malloc(sizeof(dante_t));
    dante->width = x;
    dante->height = y;
    dante->perfect = (ac > 3);
    init_maze(dante);
    srand(time(0));
    generate(dante);
    print_maze(dante);
    destroy_maze(dante);
}