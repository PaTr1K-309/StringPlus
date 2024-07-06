#include "s21_tests.h"

START_TEST(strncat_test1) {
  char dest1[20] = "World never";
  char dest2[20] = "World never";
  char src[] = "stops";
  s21_size_t n = 1;

  strncat(dest1, src, n);
  s21_strncat(dest2, src, n);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_test2) {
  char dest1[20] = "World never";
  char dest2[20] = "World never";
  char src[] = "stops";
  s21_size_t n = 6;

  strncat(dest1, src, n);
  s21_strncat(dest2, src, n);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_test3) {
  char dest1[20] = "World never";
  char dest2[20] = "World never";
  char src[] = "stops";
  s21_size_t n = 0;

  strncat(dest1, src, n);
  s21_strncat(dest2, src, n);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_test4) {
  char dest1[20] = "";
  char dest2[20] = "";
  char src[] = "";
  s21_size_t n = 3;

  strncat(dest1, src, n);
  s21_strncat(dest2, src, n);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_test5) {
  char dest1[20] = "";
  char dest2[20] = "";
  char src[] = "PTest";
  s21_size_t n = 3;

  strncat(dest1, src, n);
  s21_strncat(dest2, src, n);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_test6) {
  char dest1[20] = "";
  char dest2[20] = "";
  char src[] = "PTest";
  s21_size_t n = 10;

  strncat(dest1, src, n);
  s21_strncat(dest2, src, n);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

Suite *strncat_suite() {
  Suite *s = suite_create("STRNCAT");
  TCase *tc = tcase_create("strncat");
  tcase_add_test(tc, strncat_test1);
  tcase_add_test(tc, strncat_test2);
  tcase_add_test(tc, strncat_test3);
  tcase_add_test(tc, strncat_test4);
  tcase_add_test(tc, strncat_test5);
  tcase_add_test(tc, strncat_test6);
  suite_add_tcase(s, tc);
  return s;
}
