#include "s21_tests.h"

START_TEST(strncmp_empty) {
  char str1[] = "";
  char str2[] = "";
  s21_size_t n = 0;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_hello_equality) {
  char str1[] = "Hello, World!";
  char str2[] = "Hello, World!";
  s21_size_t n = 13;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_hello_diff1) {
  char str1[] = "Hello, World!";
  char str2[] = ", World!";
  s21_size_t n = 5;
  int std_lib_res = strncmp(str1, str2, n);
  int our_res = s21_strncmp(str1, str2, n);
  if (std_lib_res < -1) std_lib_res = -1;
  if (std_lib_res > 1) std_lib_res = 1;
  if (our_res < -1) our_res = -1;
  if (our_res > 1) our_res = 1;
  ck_assert_int_eq(std_lib_res, our_res);
}
END_TEST

START_TEST(strncmp_hello_diff2) {
  char str1[] = "Hello, ";
  char str2[] = "Hello, World!";
  s21_size_t n = 4;
  int std_lib_res = strncmp(str1, str2, n);
  int our_res = s21_strncmp(str1, str2, n);
  if (std_lib_res < -1) std_lib_res = -1;
  if (std_lib_res > 1) std_lib_res = 1;
  if (our_res < -1) our_res = -1;
  if (our_res > 1) our_res = 1;
  ck_assert_int_eq(std_lib_res, our_res);
}
END_TEST

START_TEST(strncmp_hello_diff3) {
  char str1[] = "hELLO, wORLD";
  char str2[] = "Hello, World!";
  s21_size_t n = 11;
  int std_lib_res = strncmp(str1, str2, n);
  int our_res = s21_strncmp(str1, str2, n);
  if (std_lib_res < -1) std_lib_res = -1;
  if (std_lib_res > 1) std_lib_res = 1;
  if (our_res < -1) our_res = -1;
  if (our_res > 1) our_res = 1;
  ck_assert_int_eq(std_lib_res, our_res);
}
END_TEST

START_TEST(strncmp_dots_equality) {
  char str1[] = "......................................";
  char str2[] = "......................................";
  s21_size_t n = 35;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_chars_equality) {
  char str1[] =
      "0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ^-`"
      "abcdefghijklmnopqrstuvwxyz";
  char str2[] =
      "0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ^-`"
      "abcdefghijklmnopqrstuvwxyz";
  s21_size_t n = 30;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_dots_diff1) {
  char str1[] = "................,..............";
  char str2[] = "......................................";
  s21_size_t n = 30;
  int std_lib_res = strncmp(str1, str2, n);
  int our_res = s21_strncmp(str1, str2, n);
  if (std_lib_res < -1) std_lib_res = -1;
  if (std_lib_res > 1) std_lib_res = 1;
  if (our_res < -1) our_res = -1;
  if (our_res > 1) our_res = 1;
  ck_assert_int_eq(std_lib_res, our_res);
}
END_TEST

START_TEST(strncmp_dots_diff2) {
  char str1[] = "......................................";
  char str2[] = "........,.......................";
  s21_size_t n = 25;
  int std_lib_res = strncmp(str1, str2, n);
  int our_res = s21_strncmp(str1, str2, n);
  if (std_lib_res < -1) std_lib_res = -1;
  if (std_lib_res > 1) std_lib_res = 1;
  if (our_res < -1) our_res = -1;
  if (our_res > 1) our_res = 1;
  ck_assert_int_eq(std_lib_res, our_res);
}
END_TEST

START_TEST(strncmp_chars_diff1) {
  char str1[] = "0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ^-`";
  char str2[] =
      "0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ^-`"
      "abcdefghijklmnopqrstuvwxyz";
  s21_size_t n = 45;
  int std_lib_res = strncmp(str1, str2, n);
  int our_res = s21_strncmp(str1, str2, n);
  if (std_lib_res < -1) std_lib_res = -1;
  if (std_lib_res > 1) std_lib_res = 1;
  if (our_res < -1) our_res = -1;
  if (our_res > 1) our_res = 1;
  ck_assert_int_eq(std_lib_res, our_res);
}
END_TEST

START_TEST(strncmp_chars_diff2) {
  char str1[] =
      "0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ^-`"
      "abcdefghijklmnopqrstuvwxyz";
  char str2[] = "0123456789:;<=>?@aBCDEFGHIJKLMNOPQRSTUVWXYZ^-`";
  s21_size_t n = 45;
  int std_lib_res = strncmp(str1, str2, n);
  int our_res = s21_strncmp(str1, str2, n);
  if (std_lib_res < -1) std_lib_res = -1;
  if (std_lib_res > 1) std_lib_res = 1;
  if (our_res < -1) our_res = -1;
  if (our_res > 1) our_res = 1;
  ck_assert_int_eq(std_lib_res, our_res);
}
END_TEST

Suite *strncmp_suite() {
  Suite *s = suite_create("STRNCMP");
  TCase *tc = tcase_create("strncmp");
  tcase_add_test(tc, strncmp_empty);
  tcase_add_test(tc, strncmp_hello_equality);
  tcase_add_test(tc, strncmp_hello_diff1);
  tcase_add_test(tc, strncmp_hello_diff2);
  tcase_add_test(tc, strncmp_hello_diff3);
  tcase_add_test(tc, strncmp_dots_equality);
  tcase_add_test(tc, strncmp_chars_equality);
  tcase_add_test(tc, strncmp_dots_diff1);
  tcase_add_test(tc, strncmp_dots_diff2);
  tcase_add_test(tc, strncmp_chars_diff1);
  tcase_add_test(tc, strncmp_chars_diff2);
  suite_add_tcase(s, tc);
  return s;
}