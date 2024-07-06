#include "s21_tests.h"

START_TEST(strpbrk_1) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  ck_assert_pstr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_2) {
  char str1[] = "Hello, world!";
  char str2[] = "!";
  ck_assert_pstr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_3) {
  char str1[] = "";
  char str2[] = "He";
  ck_assert_pstr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_4) {
  char str1[] = "\0";
  char str2[] = "";
  ck_assert_pstr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_5) {
  char str1[] = "Hello, world!";
  char str2[] = "!";
  ck_assert_pstr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_6) {
  char str1[] = "147896321";
  char str2[] = "4";
  ck_assert_pstr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_7) {
  char str1[] = "";
  char str2[] = "777";
  ck_assert_pstr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

Suite *strpbrk_suite() {
  Suite *s = suite_create("STRPBRK");
  TCase *tc = tcase_create("strpbrk");
  tcase_add_test(tc, strpbrk_1);
  tcase_add_test(tc, strpbrk_2);
  tcase_add_test(tc, strpbrk_3);
  tcase_add_test(tc, strpbrk_4);
  tcase_add_test(tc, strpbrk_5);
  tcase_add_test(tc, strpbrk_6);
  tcase_add_test(tc, strpbrk_7);
  suite_add_tcase(s, tc);
  return s;
}
