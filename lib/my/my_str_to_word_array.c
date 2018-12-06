/*
** EPITECH PROJECT, 2018
** muhlib
** File description:
** change string to word array
*/

#include <stdlib.h>
#include "my.h"

static int count_letters(char const *str)
{
    unsigned int letters = 0;

    for (int i = 0; str[i] && \
            (my_isdigit(str[i]) || my_isalpha(str[i])); i++)
        letters++;
    return letters;
}

static int count_words(char const *str)
{
    int words = 0;
    int i = 0;

    while (1) {
        if (str[i] == '\0') {
            break;
        }
        if ((!my_isalpha(str[i]) && !my_isdigit(str[i])) &&
            (my_isalpha(str[i - 1]) && !my_isdigit(str[i - 1]))) {
                words++;
        }
        i++;
    }
    return words;
}

char **my_str_to_word_array(char const *str)
{
    int words = count_words(str);
    char **arr = malloc(sizeof(char *) * (words + 10));
    int letters = count_letters(str);
    int word = 0;
    int i = 0;

    while (!arr)
        arr = malloc(sizeof(char *) * (words + 10));
    for (int j = 0; str[j]; j++, i++) {
        arr[i] = 0;
        while (!arr[i])
            arr[i] = malloc(letters * sizeof(char));
        while (!my_isalpha(str[j]) && !my_isdigit(str[j]))
            j++;
        while (my_isalpha(str[j]) || my_isdigit(str[j]))
            arr[i][word++] = str[j++];
        word = 0;
    }
    arr[i] = 0;
    return arr;
}

int my_show_word_array(char const *tab[])
{
    uint_t i = 0;

    for (; tab[i] && *tab[i]; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return i;
}

void destroy_double_array(char **m)
{
    while (*m) free(*m++);
    free(m);
}
