/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <stdlib.h>
#include "solver.h"

static int my_solver(char **map)
{
    map = fs_open_file(map);
    if (map == NULL)
        return 84;
    map = error_handler(map);
    if (map == NULL)
        return 84;
    if (solver_solution(map) == 84)
        return 84;
    return 0;
}

int main(int ac, char **av)
{
    if (ac > 2 || ac < 2)
        return (84);

    return (my_solver(av));
}
