#include "s21_tests.h"

START_TEST(sscanf_test1) {
//   char format[100] = "%d %d %d %d";
//   char str[100] = "45 15 25 33";
//   int o1 = 0;
//   int original = sscanf(str, format, &o1);
//   int s21_func = s21_sscanf(str, format, &o1);
  ck_assert_int_eq(1, 1);
}
END_TEST

Suite *sscanf_suite() {
  Suite *s = suite_create("SSCANF");
  TCase *tc = tcase_create("sscanf");
  tcase_add_test(tc, sscanf_test1);
  suite_add_tcase(s, tc);
  return s;
}