/*
** EPITECH PROJECT, 2020
** list
** File description:
** list
*/

#include <stdlib.h>
#include "solver.h"

node_t *clear_list(node_t *node)
{
    while (node->next != NULL)
        node = pop_back_node(node);

    return (node);
}

node_t *create_node(void)
{
    node_t *node = malloc(sizeof(node_t));

    node->x = 0;
    node->y = 0;
    node->next = NULL;
    node->back = NULL;
    return (node);
}

node_t *add_node(int x, int y, node_t *node)
{
    while (node->next != NULL)
        node = node->next;
    node->next = malloc(sizeof(node_t));
    node->next->x = x;
    node->next->y = y;
    node->next->back = node;
    node->next->next = NULL;
    return (node);
}

node_t *pop_back_node(node_t *node)
{
    while (node->next != NULL)
        node = node->next;
    node = node->back;
    node->next = NULL;
    return (node);
}