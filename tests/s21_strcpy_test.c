#include "s21_tests.h"

START_TEST(strcpy_test1) {
  char str_1[50] = " \n\0\0";
  char str_2[50] = " a\n\0";
  ck_assert_str_eq(strcpy(str_1, str_2), s21_strcpy(str_1, str_2));
}
END_TEST

START_TEST(strcpy_test2) {
  char str_1[50] = "\n\t";
  char str_2[50] = "\056";
  ck_assert_str_eq(strcpy(str_1, str_2), s21_strcpy(str_1, str_2));
}
END_TEST

START_TEST(strcpy_test3) {
  char str_1[50] = "Hello";
  char str_2[50] = "\t\n World!";
  ck_assert_str_eq(strcpy(str_1, str_2), s21_strcpy(str_1, str_2));
}
END_TEST

START_TEST(strcpy_test4) {
  char str_1[50] = "0";
  char str_2[50] = "0\n\n6\t/t8";
  ck_assert_str_eq(strcpy(str_1, str_2), s21_strcpy(str_1, str_2));
}
END_TEST

START_TEST(strcpy_test5) {
  char str_1[50] = "\t/n\n\0/0 ";
  char str_2[50] = " \t/n\n\0/0";
  ck_assert_str_eq(strcpy(str_1, str_2), s21_strcpy(str_1, str_2));
}
END_TEST

START_TEST(strcpy_test6) {
  char s1[255] = "QWERTY";
  char s2[255] = "E";
  char s3[255] = "E";
  char s4[255] = "QWERTYUIO";
  ck_assert_pstr_eq(strcpy(s1, s2), s21_strcpy(s3, s2));
  ck_assert_pstr_eq(strcpy(s2, s4), s21_strcpy(s2, s4));
}
END_TEST

Suite *strcpy_suite() {
  Suite *s = suite_create("STRCPY");
  TCase *tc = tcase_create("strcpy");
  tcase_add_test(tc, strcpy_test1);
  tcase_add_test(tc, strcpy_test2);
  tcase_add_test(tc, strcpy_test3);
  tcase_add_test(tc, strcpy_test4);
  tcase_add_test(tc, strcpy_test5);
  tcase_add_test(tc, strcpy_test6);
  suite_add_tcase(s, tc);
  return s;
}
