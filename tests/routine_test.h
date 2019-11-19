#ifndef ROUTINE_TEST
#define ROUTINE_TEST

#include <check.h>
#include "routine.h"
#include <stdlib.h>
#include <unistd.h>

// This is to ensure that the correct env var is being used.
// HOME should be set in almost every environment. Will throw error if not set.
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

START_TEST (test_load_routine_file)
{
    int path_max = 256;
    char test_home_dir[path_max];
    char routine[256];

    getcwd(test_home_dir, path_max);
    strcat(test_home_dir, "/tests/data");
    setenv("HOME", test_home_dir, 1);

    read_file("test_load_routine_file", routine);

    ck_assert_str_eq(routine, "abc\ndef\nghi\n");

}
END_TEST

#endif
