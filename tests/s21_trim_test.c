#include "s21_tests.h"

START_TEST(trim_test1) {
  char *str1 = "Hello World";
  char *str2 = "H";
  char *str3 = (char *)s21_trim(str1, str2);
  ck_assert_str_eq(str3, "ello World");
  free(str3);
}
END_TEST

START_TEST(trim_test2) {
  char *str1 = "codir";
  char *str2 = "cod";
  char *str3 = (char *)s21_trim(str1, str2);
  ck_assert_str_eq(str3, "ir");
  free(str3);
}
END_TEST

START_TEST(trim_test3) {
  char *str1 = "";
  char *str2 = "";
  char *str3 = (char *)s21_trim(str1, str2);
  ck_assert_str_eq(str3, "");
  free(str3);
}
END_TEST

START_TEST(trim_test4) {
  char *str = "empty";
  char *str2 = "empty";
  char *str3 = (char *)s21_trim(str, str2);
  ck_assert_str_eq(str3, "");
  free(str3);
}
END_TEST

START_TEST(trim_test5) {
  char *str = S21_NULL;
  char *str2 = S21_NULL;
  char *str3 = (char *)s21_trim(str, str2);
  ck_assert_ptr_eq(str3, S21_NULL);
  free(str3);
}
END_TEST

START_TEST(trim_test6) {
  char *str = "";
  char *str2 = S21_NULL;
  char *str3 = (char *)s21_trim(str, str2);
  ck_assert_ptr_eq(str3, S21_NULL);
  free(str3);
}
END_TEST

START_TEST(trim_test7) {
  char *str = S21_NULL;
  char *str2 = "          ";
  char *str3 = (char *)s21_trim(str, str2);
  ck_assert_ptr_eq(str3, S21_NULL);
  free(str3);
}
END_TEST

START_TEST(trim_test8) {
  char *str = "*Hello, beautiful World !**";
  char *str2 = "*H!";
  char *str3 = (char *)s21_trim(str, str2);
  ck_assert_str_eq(str3, "ello, beautiful World ");
  free(str3);
}
END_TEST

Suite *trim_suite() {
  Suite *s = suite_create("TRIM");
  TCase *tc = tcase_create("trim");
  tcase_add_test(tc, trim_test1);
  tcase_add_test(tc, trim_test2);
  tcase_add_test(tc, trim_test3);
  tcase_add_test(tc, trim_test4);
  tcase_add_test(tc, trim_test5);
  tcase_add_test(tc, trim_test6);
  tcase_add_test(tc, trim_test7);
  tcase_add_test(tc, trim_test8);
  suite_add_tcase(s, tc);
  return s;
}
