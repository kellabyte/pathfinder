#include <stdlib.h>
#include <check.h>
#include "../lib/libart/src/art.h"
#include "pathfinder.h"

START_TEST (test_pf_create)
{
    pathfinder* context = NULL;
    int rc = pf_create(context);
    ck_assert_msg(rc == 0, "rc != 0");
}
END_TEST

START_TEST (test_pf_free)
{
    pathfinder* context = NULL;
    int rc = pf_create(context);
    ck_assert_msg(rc == 0, "rc != 0");
    
    pf_free(context);
}
END_TEST

START_TEST (test_pf_find)
{
    pathfinder* context = NULL;
    int rc = pf_create(context);
    ck_assert_msg(rc == 0, "rc != 0");
    
    int* expected = malloc(sizeof(int));
    int* actual = malloc(sizeof(int));
    expected = 42;
    
    unsigned char* key = calloc(3, sizeof(unsigned char));
    key = "foo";
    
    rc = pf_set(context, key, 3, expected);
    rc = pf_find(context, key, 3, actual);
    ck_assert_msg(rc == 0, "rc != 0");
    
    pf_free(context);
}
END_TEST

Suite* test_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Pathfinder");

    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_pf_create);
    tcase_add_test(tc_core, test_pf_free);
    tcase_add_test(tc_core, test_pf_find);
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
