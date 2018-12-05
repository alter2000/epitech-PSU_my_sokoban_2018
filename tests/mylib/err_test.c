/*
** EPITECH PROJECT, 2018
** mylib
** File description:
** tests file for err.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string.h>
#include "my.h"

void redirect_stderr(void)
{
    cr_redirect_stderr();
}

Test(err, empty, .init = redirect_stderr, .exit_code = 0)
{
    err("");
    fflush(stderr);
    cr_expect_stderr_eq_str("err: no error string\n");
}

Test(errb, not_empty, .init = redirect_stderr, .exit_code = 84)
{
    errb("meh more text");
    fflush(stderr);
    cr_expect_stderr_eq_str("meh more text");
}

Test(errb, empty, .init = redirect_stderr, .exit_code = 0)
{
    errb(0);
    fflush(stderr);
    cr_expect_stderr_eq_str("errb: no error string\n");
}

Test(errc, empty, .init = redirect_stderr, .exit_code = 0)
{
    errc(0, 0);
    cr_expect_stderr_eq_str("errc: no error string or buffer\n");
}

Test(err, not_empty, .init = redirect_stderr, .exit_code = 0)
{
    err("lol idk");
    fflush(stderr);
    cr_expect_stderr_eq_str("lol idk");
    rewind(stderr);
}

Test(errc, not_empty, .init = redirect_stderr, .exit_code = 84)
{
    char *s = my_strdup("huh");

    errc(s, "meh more text");
    fflush(stderr);
}
