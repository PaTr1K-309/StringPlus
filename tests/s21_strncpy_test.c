#include "s21_tests.h"

START_TEST(strcpy_test1) {
  char str_1[50] = "ddd\n\0\0";
  char str_2[50] = " aaaa\n\0";
  s21_size_t n = 3;
  ck_assert_str_eq(strncpy(str_1, str_2, n), s21_strncpy(str_1, str_2, n));
}
END_TEST

START_TEST(strcpy_test2) {
  char str_1[50] = "\n\t";
  char str_2[50] = "\056";
  s21_size_t n = 2;
  ck_assert_str_eq(strncpy(str_1, str_2, n), s21_strncpy(str_1, str_2, n));
}
END_TEST

START_TEST(strcpy_test3) {
  char str_1[50] = "Hello";
  char str_2[50] = "\t\n World!";
  s21_size_t n = 3;
  ck_assert_str_eq(strncpy(str_1, str_2, n), s21_strncpy(str_1, str_2, n));
}
END_TEST

START_TEST(strcpy_test4) {
  char str_1[50] = "0";
  char str_2[50] = "0\n\n6\t/t8";
  s21_size_t n = 2;
  ck_assert_str_eq(strncpy(str_1, str_2, n), s21_strncpy(str_1, str_2, n));
}
END_TEST

START_TEST(strcpy_test5) {
  char str_1[50] = "\t/n\n\0/0 ";
  char str_2[50] = " \t/n\n\0/0";
  s21_size_t n = 3;
  ck_assert_str_eq(strncpy(str_1, str_2, n), s21_strncpy(str_1, str_2, n));
}
END_TEST

START_TEST(strcpy_test6) {
  char str_1[255] = "QWERTY";
  char str_2[255] = "E";
  char str_3[255] = "E";
  char str_4[255] = "QWERTYUIO";
  s21_size_t n = 1;
  ck_assert_str_eq(strncpy(str_1, str_2, n), s21_strncpy(str_1, str_2, n));
  ck_assert_str_eq(strncpy(str_3, str_4, n), s21_strncpy(str_3, str_4, n));
}
END_TEST

Suite *strncpy_suite() {
  Suite *s = suite_create("STRNCPY");
  TCase *tc = tcase_create("strncpy");
  tcase_add_test(tc, strcpy_test1);
  tcase_add_test(tc, strcpy_test2);
  tcase_add_test(tc, strcpy_test3);
  tcase_add_test(tc, strcpy_test4);
  tcase_add_test(tc, strcpy_test5);
  tcase_add_test(tc, strcpy_test6);
  suite_add_tcase(s, tc);
  return s;
}
