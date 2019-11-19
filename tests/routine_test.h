#ifndef ROUTINE_TEST
#define ROUTINE_TEST

#include <check.h>
#include "routine.h"
#include <stdlib.h>

START_TEST (test_routine_getHomeDir_returns_non_null_with_default_env)
{
    char home_dir[124];
    get_home_dir(home_dir);
    ck_assert_int_gt(strlen(home_dir), 0);
}
END_TEST

#endif
