#include "s21_tests.h"

START_TEST(sprintf_test1) {
  for (int i = 0; i < 150; i++) {
    ck_assert_str_eq(strerror(i), s21_strerror(i));
  }
}
END_TEST

Suite *strerror_suite() {
  Suite *s = suite_create("STERROR");
  TCase *tc = tcase_create("sterror");
  tcase_add_test(tc, sprintf_test1);
  suite_add_tcase(s, tc);
  return s;
}
