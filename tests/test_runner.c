#include <check.h>
#include <stdlib.h>
#include "routine_test.h"

Suite* suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Routine");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_routine_get_home_dir_returns_non_null_with_default_env);
    tcase_add_test(tc_core, test_routine_get_home_dir_returns_HOME_env_var);
    tcase_add_test(tc_core, test_load_routine_file);
    tcase_add_test(tc_core, test_list_files_exclude_dirs);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
