/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** unit tests for my_is*
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

Test(my_isdigit, all)
{
    cr_expect(my_isdigit(0) == 0);
    cr_expect(my_isdigit(4) == 0);
    cr_expect(my_isdigit('0') == 1);
    cr_expect(my_isdigit('a') == 0);
    cr_expect(my_isdigit('A') == 0);
    cr_expect(my_isdigit('.') == 0);
    cr_expect(my_isdigit('\v') == 0);
}

Test(my_isupper, all)
{
    cr_expect(my_isupper(0) == 0);
    cr_expect(my_isupper(4) == 0);
    cr_expect(my_isupper('0') == 0);
    cr_expect(my_isupper('a') == 0);
    cr_expect(my_isupper('A') == 1);
    cr_expect(my_isupper('.') == 0);
    cr_expect(my_isupper('\v') == 0);
}

Test(my_islower, all)
{
    cr_expect(my_islower(0) == 0);
    cr_expect(my_islower(4) == 0);
    cr_expect(my_islower('0') == 0);
    cr_expect(my_islower('a') == 1);
    cr_expect(my_islower('A') == 0);
    cr_expect(my_islower('.') == 0);
    cr_expect(my_islower('\v') == 0);
}

Test(my_isalpha, all)
{
    cr_expect(my_isalpha(0) == 0);
    cr_expect(my_isalpha(4) == 0);
    cr_expect(my_isalpha('0') == 0);
    cr_expect(my_isalpha('a') == 1);
    cr_expect(my_isalpha('A') == 1);
    cr_expect(my_isalpha('.') == 0);
    cr_expect(my_isalpha('\v') == 0);
}

Test(my_isspace, all)
{
    cr_expect(my_isspace(0) == 0);
    cr_expect(my_isspace(4) == 0);
    cr_expect(my_isspace('0') == 0);
    cr_expect(my_isspace('a') == 0);
    cr_expect(my_isspace('A') == 0);
    cr_expect(my_isspace('.') == 0);
    cr_expect(my_isspace('\v') == 1);
}

Test(my_isprintable, all)
{
    cr_expect(my_isprintable(0) == 0);
    cr_expect(my_isprintable(4) == 0);
    cr_expect(my_isprintable('0') == 1);
    cr_expect(my_isprintable('a') == 1);
    cr_expect(my_isprintable('A') == 1);
    cr_expect(my_isprintable('.') == 1);
    cr_expect(my_isprintable('\v') == 1);
    cr_expect(my_isprintable(32) == 1);
}
