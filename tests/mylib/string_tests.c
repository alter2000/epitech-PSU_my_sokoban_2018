/*
** EPITECH PROJECT, 2018
** mylib
** File description:
** strlen tests
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_stdout(void)
{
    cr_redirect_stdout();
}

Test(strlen, idk)
{
    cr_expect(my_strlen("123") == 3);
    cr_expect(my_strlen("abs") == 3);
    cr_expect(my_strlen("m") == 1);
    cr_expect(my_strlen("") == 0);
}

Test(putchar, idk, .init = redirect_stdout)
{
    my_putchar('a');
    fflush(stdout);
    cr_expect_stdout_eq_str("a");
}

Test(putstr, idk, .init = redirect_stdout)
{
    my_putstr("lol idk again");
    fflush(stdout);
    cr_expect_stdout_eq_str("lol idk again");
}

Test(show_word_array, idk, .init = redirect_stdout)
{
    char const **arr = malloc(sizeof(char *) * 4);

    arr[0] = "line one";
    arr[1] = "line two";
    arr[2] = "line three";
    arr[3] = 0;
    my_show_word_array(arr);
    fflush(stdout);
    cr_expect_stdout_eq_str("line one\nline two\nline three\n");
}
