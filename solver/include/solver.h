/*
** EPITECH PROJECT, 2020
** MY_H
** File description:
** MY_H
*/

#ifndef MY_H
#define MY_H

typedef struct node_s
{
    unsigned int x;
    unsigned int y;
    struct node_s *back;
    struct node_s *next;
} node_t;

void free_array(char **maze);
int depth_search_direction(char **maze, node_t **node, unsigned int info[2]);
char **fs_open_file(char **str);
int print_map(char **map, unsigned int info[2]);
unsigned int array_len(char **array);
char *my_str_to_null(char *s, int c);
int solver_solution(char **map);
char **my_str_to_word_array(char *src, const char *delim);
char **error_handler(char **map);
node_t *create_node(void);
node_t *add_node(int x, int y, node_t *node);
node_t *pop_back_node(node_t *node);
node_t *clear_list(node_t *node);
int depth_search_solver(char **map, node_t *node, unsigned int info[2]);

#endif
