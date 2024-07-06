#include "s21_tests.h"

START_TEST(strchr_1) {
  char str[] = "Hello, world!";
  int ch = 'h';
  ck_assert_pstr_eq(strchr(str, ch), s21_strchr(str, ch));
}
END_TEST

START_TEST(strchr_2) {
  char str[] = "Hello, world!";
  int ch = '\0';
  ck_assert_pstr_eq(strchr(str, ch), s21_strchr(str, ch));
}
END_TEST

START_TEST(strchr_3) {
  char str[] = "Hello, world!";
  int ch = ',';
  ck_assert_pstr_eq(strchr(str, ch), s21_strchr(str, ch));
}
END_TEST

START_TEST(strchr_4) {
  char str[] = "Hello, world!";
  int ch = 33;
  ck_assert_pstr_eq(strchr(str, ch), s21_strchr(str, ch));
}
END_TEST

START_TEST(strchr_5) {
  char str[] = "Hello, world!";
  int ch = 'P';
  ck_assert_pstr_eq(strchr(str, ch), s21_strchr(str, ch));
}
END_TEST

START_TEST(strchr_6) {
  char str[] = "Hello, world!";
  int ch = 'w';
  ck_assert_pstr_eq(strchr(str, ch), s21_strchr(str, ch));
}
END_TEST

START_TEST(strchr_7) {
  char str[] = "Hello, world!";
  int ch = 'm';
  ck_assert_pstr_eq(strchr(str, ch), s21_strchr(str, ch));
}
END_TEST

START_TEST(strchr_8) {
  char str[] = "Hello, world!";
  int ch = '!';
  ck_assert_pstr_eq(strchr(str, ch), s21_strchr(str, ch));
}
END_TEST

START_TEST(strchr_9) {
  char str[] = "Hello, world!";
  int ch = '\n';
  ck_assert_pstr_eq(strchr(str, ch), s21_strchr(str, ch));
}
END_TEST

START_TEST(strchr_10) {
  char str[] = "Hello, world!";
  int ch = 'h';
  ck_assert_pstr_eq(strchr(str, ch), s21_strchr(str, ch));
}
END_TEST

Suite *strchr_suite() {
  Suite *s = suite_create("STRCHR");
  TCase *tc = tcase_create("strchr");
  tcase_add_test(tc, strchr_1);
  tcase_add_test(tc, strchr_2);
  tcase_add_test(tc, strchr_3);
  tcase_add_test(tc, strchr_4);
  tcase_add_test(tc, strchr_5);
  tcase_add_test(tc, strchr_6);
  tcase_add_test(tc, strchr_7);
  tcase_add_test(tc, strchr_8);
  tcase_add_test(tc, strchr_9);
  tcase_add_test(tc, strchr_10);
  suite_add_tcase(s, tc);
  return s;
}
