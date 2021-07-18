/*
** EPITECH PROJECT, 2020
** str to tab
** File description:
** st
*/

#include <stdlib.h>
#include <string.h>
#include "solver.h"

void string_clean(char *str, const char c, char const *end_ptr)
{
    for (; str < end_ptr;) {
        str = my_str_to_null(str, c);
        *str++ = '\0';
    }
}

char *skip_space(char *str, char const *end_ptr)
{
    for (; !*str && str < end_ptr;)
        str++;
    return (str);
}

int word_count(char *str, char const *end_ptr)
{
    int nb_count = 0;

    str = skip_space(str, end_ptr);
    for (; str < end_ptr;) {
        if (*str)
            nb_count++;
        for (; *str;)
            str++;
        str = skip_space(str, end_ptr);
    }
    return (nb_count);
}

static int put_word_array(char **array, char *str, char const *end_ptr)
{
    for (; str < end_ptr;) {
        *array = strdup(str);
        if (*array == NULL)
            return (0);
        for (; *str;)
            str++;
        str = skip_space(str, end_ptr);
        array++;
    }
    *array = NULL;
    return (1);
}

char **my_str_to_word_array(char *str, const char *limit)
{
    char **array;
    char const *end_ptr;
    char *ptr = strdup(str);

    if (!ptr)
        return (NULL);
    end_ptr = ptr + strlen(ptr);
    for (; *limit;)
        string_clean(ptr, *limit++, end_ptr);
    array = malloc(sizeof(char *) * (word_count(ptr, end_ptr) + 1));
    if (!array)
        return (NULL);
    if (put_word_array(array, skip_space(ptr, end_ptr), end_ptr) == 0)
        return (NULL);
    free(ptr);
    return (array);
}
