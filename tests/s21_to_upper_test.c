#include "s21_tests.h"

START_TEST(s21_to_upper_test1) {
  char str1[16] = "don't\0all";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "DON'T");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_test2) {
  char str1[12] = "hello world";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "HELLO WORLD");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_test3) {
  char *str1 = S21_NULL;
  char *str2 = s21_to_upper(str1);
  ck_assert_ptr_eq(str2, S21_NULL);
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_test4) {
  char str1[16] = "NOTUPPER";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "NOTUPPER");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_test5) {
  char str1[10] = "\0A\0";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_test6) {
  char str1[19] = "i'm coder";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "I'M CODER");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_test7) {
  char str1[1] = "";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "");
  free(str2);
}
END_TEST

Suite *to_upper_suite() {
  Suite *s = suite_create("TO_UPPER");
  TCase *tc = tcase_create("to_upper");
  tcase_add_test(tc, s21_to_upper_test1);
  tcase_add_test(tc, s21_to_upper_test2);
  tcase_add_test(tc, s21_to_upper_test3);
  tcase_add_test(tc, s21_to_upper_test4);
  tcase_add_test(tc, s21_to_upper_test5);
  tcase_add_test(tc, s21_to_upper_test6);
  tcase_add_test(tc, s21_to_upper_test7);
  suite_add_tcase(s, tc);
  return s;
}
