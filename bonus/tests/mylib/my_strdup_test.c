/*
** EPITECH PROJECT, 2018
** mylib
** File description:
** strdup tests
*/

#include "my.h"
#include <criterion/criterion.h>

Test(my_strdup, not_empty)
{
    cr_expect_str_eq(my_strdup("123"), "123");
    cr_expect_str_eq(my_strdup("abs"), "abs");
    cr_expect_str_eq(my_strdup("m"), "m");
}

Test(my_strdup, empty)
{
    cr_expect_str_eq(my_strdup(""), "");
}
