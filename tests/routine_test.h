#ifndef ROUTINE_TEST
#define ROUTINE_TEST

#include <check.h>
#include "routine.h"
#include <stdlib.h>

START_TEST (test_routine_get_home_dir_returns_non_null_with_default_env)
{
    char home_dir[124];
    get_home_dir(home_dir);
    ck_assert_int_gt(strlen(home_dir), 0);
}
END_TEST

START_TEST (test_routine_get_home_dir_returns_HOME_env_var) {
    char home_dir[124];
    const char expected[2][124] = {"/home/not_kuberlog", "/home/kuberlog"};

    //Ensure that when ENV changes, get_home_dir() also changes
    for(int i = 0; i < 2; i++) {
        setenv("HOME", expected[i], 1);
        get_home_dir(home_dir);
        ck_assert_str_eq(home_dir, expected[i]);
    }
}
END_TEST

#endif
