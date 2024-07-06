#include "s21_tests.h"

START_TEST(strrchr_1) {
  char str[] = "Hello, world!";
  int ch = 'h';
  ck_assert_pstr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_2) {
  char str[] = "Hello, world!";
  int ch = '\0';
  ck_assert_pstr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_3) {
  char str[] = "Hello, world!";
  int ch = ',';
  ck_assert_pstr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_4) {
  char str[] = "Hello, world!";
  int ch = 33;
  ck_assert_pstr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_5) {
  char str[] = "Hello, world!";
  int ch = 'P';
  ck_assert_pstr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_6) {
  char str[] = "Hello, world!";
  int ch = 'w';
  ck_assert_pstr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_7) {
  char str[] = "Hello, world!";
  int ch = 'm';
  ck_assert_pstr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_8) {
  char str[] = "Hello, world!";
  int ch = '!';
  ck_assert_pstr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_9) {
  char str[] = "Hello, world!";
  int ch = '\n';
  ck_assert_pstr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_10) {
  char str[] = "Hello, world!";
  int ch = 'h';
  ck_assert_pstr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

Suite *strrchr_suite() {
  Suite *s = suite_create("STRRCHR");
  TCase *tc = tcase_create("strrchr");
  tcase_add_test(tc, strrchr_1);
  tcase_add_test(tc, strrchr_2);
  tcase_add_test(tc, strrchr_3);
  tcase_add_test(tc, strrchr_4);
  tcase_add_test(tc, strrchr_5);
  tcase_add_test(tc, strrchr_6);
  tcase_add_test(tc, strrchr_7);
  tcase_add_test(tc, strrchr_8);
  tcase_add_test(tc, strrchr_9);
  tcase_add_test(tc, strrchr_10);
  suite_add_tcase(s, tc);
  return s;
}
