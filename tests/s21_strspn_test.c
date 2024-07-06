#include "s21_tests.h"

START_TEST(strspn_empty) {
  char str1[] = "";
  char str2[] = "";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(strspn_hello_world) {
  char str1[] = "Hello, World!";
  char str2[] = "Hello, World!";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(strspn_hello_1) {
  char str1[] = "Hello, World!";
  char str2[] = "Hello, ";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(strspn_hello_2) {
  char str1[] = "ello!, ";
  char str2[] = "World, Hello!";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(strspn_dots) {
  char str1[] = "......................................";
  char str2[] = "......................................";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(strspn_chars_equality) {
  char str1[] =
      "0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ^-`"
      "abcdefghijklmnopqrstuvwxyz";
  char str2[] =
      "abcdefghijklmnopqrstuvwxy0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ^-`"
      "z";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(strspn_chars_diff1) {
  char str1[] = "0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ^-`";
  char str2[] =
      "0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ^-`"
      "abcdefghijklmnopqrstuvwxyz";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(strspn_chars_diff2) {
  char str1[] =
      "0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ^-`"
      "abcdefghijklmnopqrstuvwxyz";
  char str2[] = "0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ^-`";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(strspn_nums_1) {
  char str1[] = "0123456789";
  char str2[] = "798";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(strspn_nums_2) {
  char str1[] = "3478652036";
  char str2[] = "9";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(strspn_nums_3) {
  char str1[] = "3478652036";
  char str2[] = "0";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

Suite *strspn_suite() {
  Suite *s = suite_create("STRSPN");
  TCase *tc = tcase_create("strspn");
  tcase_add_test(tc, strspn_empty);
  tcase_add_test(tc, strspn_hello_world);
  tcase_add_test(tc, strspn_hello_1);
  tcase_add_test(tc, strspn_hello_2);
  tcase_add_test(tc, strspn_dots);
  tcase_add_test(tc, strspn_chars_equality);
  tcase_add_test(tc, strspn_chars_diff1);
  tcase_add_test(tc, strspn_chars_diff2);
  tcase_add_test(tc, strspn_nums_1);
  tcase_add_test(tc, strspn_nums_2);
  tcase_add_test(tc, strspn_nums_3);
  suite_add_tcase(s, tc);
  return s;
}