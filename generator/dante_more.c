/*
** EPITECH PROJECT, 2021
** dante_more
** File description:
** More of dante
*/

#include <stdlib.h>
#include "dante.h"

void open_cell(dante_t *dante, position_t cell_pos)
{
    dante->current_cell = cell_pos;
    dante->map[cell_pos.y][cell_pos.x] = true;
    dante->map[cell_pos.wall_y][cell_pos.wall_x] = true;
    my_vector_add(&dante->history, malloc_pos(cell_pos));
}

bool can_cell_be_visited(dante_t *dante, position_t pos)
{
    position_t *pos_checker;

    if (pos.x < 0 || pos.x >= dante->width)
        return false;
    if (pos.y < 0 || pos.y >= dante->height)
        return false;
    for (int i = dante->history.size - 1; i >= 0; i--) {
        pos_checker = my_vector_get(&dante->history, i);
        if (pos_eq(pos, *pos_checker)) {
            return false;
        }
    }
    return true;
}

vector_t get_valid_adj_cells(dante_t *dante, position_t from)
{
    position_t top = (position_t) { from.x, from.y - 2, from.x, from.y - 1};
    position_t bottom = (position_t) { from.x, from.y + 2, from.x, from.y + 1 };
    position_t left = (position_t) { from.x - 2, from.y, from.x - 1, from.y };
    position_t right = (position_t) { from.x + 2, from.y, from.x + 1, from.y };
    vector_t result;

    my_vector_init(&result);
    if (can_cell_be_visited(dante, top))
        my_vector_add(&result, malloc_pos(top));
    if (can_cell_be_visited(dante, bottom))
        my_vector_add(&result, malloc_pos(bottom));
    if (can_cell_be_visited(dante, left))
        my_vector_add(&result, malloc_pos(left));
    if (can_cell_be_visited(dante, right))
        my_vector_add(&result, malloc_pos(right));
    return result;
}

void recursive_magic_gen(dante_t *dante, int from)
{
    vector_t vec_curr;
    position_t *pif_pos;
    int le_pif = 0;

    for (int i = from; i >= 0; i--) {
        dante->current_cell = *((position_t *)
            my_vector_get(&dante->history, i));
        vec_curr = get_valid_adj_cells(dante, dante->current_cell);
        if (vec_curr.size > 0) {
            le_pif = rand() % vec_curr.size;
            pif_pos = my_vector_get(&vec_curr, le_pif);
            open_cell(dante, *pif_pos);
            my_vector_free(&vec_curr);
            return;
        }
        my_vector_free(&vec_curr);
    }
}

void generate(dante_t *dante)
{
    vector_t vec_curr;
    position_t *pif_pos;
    int le_pif = 0;

    open_cell(dante, (position_t) { 0, 0, 0, 0 });
    do {
        vec_curr = get_valid_adj_cells(dante, dante->current_cell);
        if (vec_curr.size > 0) {
            le_pif = rand() % vec_curr.size;
            pif_pos = my_vector_get(&vec_curr, le_pif);
            open_cell(dante, *pif_pos);
            my_vector_free(&vec_curr);
        } else {
            recursive_magic_gen(dante, dante->history.size - 1);
        }
    } while (!pos_eq(dante->current_cell, (position_t) { 0, 0, 0, 0 }));
    finish_dante(dante);
}