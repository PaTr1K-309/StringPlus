#include "s21_tests.h"

START_TEST(to_lower_test1) {
  char str1[16] = "DON'T\0ALL";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "don't");
  free(str2);
}
END_TEST

START_TEST(to_lower_test2) {
  char str1[12] = "HELLO WORLD";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "hello world");
  free(str2);
}
END_TEST

START_TEST(to_lower_test3) {
  char *str1 = S21_NULL;
  char *str2 = s21_to_lower(str1);
  ck_assert_ptr_eq(str2, S21_NULL);
  free(str2);
}
END_TEST

START_TEST(to_lower_test4) {
  char str1[16] = "notlowet";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "notlowet");
  free(str2);
}
END_TEST

START_TEST(to_lower_test5) {
  char str1[10] = "\0A\0";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "");
  free(str2);
}
END_TEST

START_TEST(to_lower_test6) {
  char str1[19] = "I'M CODER";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "i'm coder");
  free(str2);
}
END_TEST

START_TEST(to_lower_test7) {
  char str1[1] = "";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "");
  free(str2);
}
END_TEST

Suite *to_lower_suite() {
  Suite *s = suite_create("TO_LOWER");
  TCase *tc = tcase_create("to_lower");
  tcase_add_test(tc, to_lower_test1);
  tcase_add_test(tc, to_lower_test2);
  tcase_add_test(tc, to_lower_test3);
  tcase_add_test(tc, to_lower_test4);
  tcase_add_test(tc, to_lower_test5);
  tcase_add_test(tc, to_lower_test6);
  tcase_add_test(tc, to_lower_test7);
  suite_add_tcase(s, tc);
  return s;
}
