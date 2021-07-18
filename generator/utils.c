/*
** EPITECH PROJECT, 2021
** utils
** File description:
** Usefull funct for Dante
*/

#include <stdlib.h>
#include "dante.h"

bool pos_eq(position_t pos1, position_t pos2)
{
    return (pos1.x == pos2.x && pos1.y == pos2.y) ||
        (pos1.x == pos2.wall_x && pos1.y == pos2.wall_y);
}

position_t *malloc_pos(position_t pos)
{
    position_t *pos_m = malloc(sizeof(position_t));

    pos_m->x = pos.x;
    pos_m->y = pos.y;
    pos_m->wall_x = pos.wall_x;
    pos_m->wall_y = pos.wall_y;
    return pos_m;
}

