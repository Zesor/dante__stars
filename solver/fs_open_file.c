/*
** EPITECH PROJECT, 2020
** fs_open_file
** File description:
** fs_open_file
*/

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "solver.h"

char **fs_open_file(char **str)
{
    struct stat sb;
    char *buffer = NULL;
    char **array;
    int read_value = 0;
    int fd = 0;

    stat(str[1], &sb);
    buffer = malloc(sizeof(char) * (sb.st_size + 1));
    if (buffer == NULL)
        exit(1);
    fd = open(str[1], O_RDONLY);
    if (fd == -1)
        exit(1);
    read_value = read(fd, buffer, sb.st_size);
    buffer[read_value] = '\0';
    array = my_str_to_word_array(buffer, "\n");
    close(fd);
    free(buffer);
    return (array);
}

char *my_str_to_null(char *s, int c)
{
    if (!s)
        return (NULL);
    while (*s) {
        if (*s == c)
            break;
        s++;
    }
    return (s);
}

unsigned int array_len(char **array)
{
    char **ptr = NULL;

    ptr = array;
    while (*ptr)
        ptr++;
    return (ptr - array);
}

void free_array(char **maze)
{
    for (int i = 0; maze[i]; i++)
        free(maze[i]);
    free(maze);
    maze = NULL;
}