#include "s21_tests.h"

START_TEST(strlen_empty) {
  char str[] = "";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_hello_world) {
  char str[] = "Hello, World!";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_chars) {
  char str[] =
      "0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ^-`"
      "abcdefghijklmnopqrstuvwxyz";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_null_term) {
  char str[] = "Hello, \0World!";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_dots) {
  char str[] = "......................................";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

Suite *strlen_suite() {
  Suite *s = suite_create("STRLEN");
  TCase *tc = tcase_create("strlen");
  tcase_add_test(tc, strlen_empty);
  tcase_add_test(tc, strlen_hello_world);
  tcase_add_test(tc, strlen_chars);
  tcase_add_test(tc, strlen_null_term);
  tcase_add_test(tc, strlen_dots);
  suite_add_tcase(s, tc);
  return s;
}