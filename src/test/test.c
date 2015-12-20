#include <stdlib.h>
#include <check.h>
#include "pathfinder.h"

START_TEST (test_name)
{
    ck_assert_msg(1 == 0, "1 != 0");
}
END_TEST

Suite* test_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Pathway");

    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_name);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
  Suite *s;
  SRunner *sr;

  s = test_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_VERBOSE);

  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
