/*
** EPITECH PROJECT, 2021
** dante
** File description:
** Dante Header
*/

#ifndef DANTE_H_
#define DANTE_H_

#include <stdbool.h>
#include "vector.h"

typedef struct position_s
{
    int x;
    int y;
    int wall_x;
    int wall_y;
} position_t;

typedef struct dante_s
{
    char **map;
    bool perfect;
    int width;
    int height;
    position_t current_cell;
    vector_t history;
} dante_t;

bool pos_eq(position_t pos1, position_t pos2);
position_t *malloc_pos(position_t pos);
void generate(dante_t *dante);
void finish_dante(dante_t *dante);

#endif /* !DANTE_H_ */
