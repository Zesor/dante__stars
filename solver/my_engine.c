/*
** EPITECH PROJECT, 2020
** my_engine
** File description:
** my_engine
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "solver.h"

int print_maze(char **maze, unsigned int info[2])
{
    char *solved_maze = malloc(sizeof(char) * (info[0] * info[1] + info[0]));
    int count = 0;
    int i = 0;

    while (maze[i]) {
        for (int j = 0; maze[i][j]; j++) {
            solved_maze[count] = maze[i][j];
            count += 1;
        }
        if (maze[i + 1] == NULL)
            solved_maze[count] = '\0';
        else
            solved_maze[count] = '\n';
        count += 1;
        i += 1;
    }
    printf("%s", solved_maze);
    free(solved_maze);
    free_array(maze);
    return (0);
}

int solver_solution(char **maze)
{
    unsigned int info[2] = { array_len(maze), strlen(maze[0]) };
    node_t *head = create_node();
    unsigned int i = 0;

    if (depth_search_solver(maze, head, info) == 1)
        return (84);
    while (i < info[0]) {
        for (unsigned int j = 0; j < info[1]; j++)
            if (maze[i][j] == '!')
                maze[i][j] = '*';
        i += 1;
    }
    print_maze(maze, info);
    clear_list(head);
    free(head);
    return (0);
}

char **error_handler(char **maze)
{
    int rows = array_len(maze);
    int condition_check = 0;
    int lenght = strlen(maze[0]);
    int i = 0;

    if (rows == 0)
        return (NULL);
    while (maze[i] != NULL) {
        if (strlen(maze[i]) != lenght)
            return (NULL);
        for (int j = 0; j < lenght; j++)
            condition_check = ((maze[i][j] != '*' && maze[i][j] != 'X')
            ? 1 : condition_check);
        i += 1;
    }
    if (condition_check == 1)
        return (NULL);
    if (maze[0][0] != '*' || maze[rows - 1][lenght - 1] != '*')
        exit(84);
    return (maze);
}

int depth_search_direction(char **maze, node_t **node, unsigned int info[2])
{
    if ((*node)->y + 1 < info[1] && maze[(*node)->x][(*node)->y + 1] == '*') {
        *node = add_node((*node)->x, (*node)->y + 1, *node);
        return (0);
    }
    if ((*node)->x + 1 < info[0] &&
                maze[(*node)->x + 1][(*node)->y] == '*') {
        *node = add_node((*node)->x + 1, (*node)->y, *node);
        return (0);
    }
    if ((*node)->y > 0 && maze[(*node)->x][(*node)->y - 1] == '*') {
        *node = add_node((*node)->x, (*node)->y - 1, *node);
        return (0);
    }
    if ((*node)->x > 0 && maze[(*node)->x - 1][(*node)->y] == '*') {
        *node = add_node((*node)->x - 1, (*node)->y, *node);
        return (0);
    }
    maze[(*node)->x][(*node)->y] = '!';
    return (1);
}

int depth_search_solver(char **maze, node_t *node, unsigned int info[2])
{
    int value = 0;

    for (; value == 0;) {
        maze[node->x][node->y] = 'o';
        if (node->x == info[0] - 1 && node->y == info[1] - 1)
            return (0);
        else if (depth_search_direction(maze, &node, info) == 1) {
            if (node->x == 0 && node->y == 0)
                return (1);
            node = pop_back_node(node);
        }
        if (node->x == info[0] - 1 && node->y == info[1] - 1) {
            maze[node->x][node->y] = 'o';
            return (0);
        }
    }
    return (0);
}