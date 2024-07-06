#include "s21_tests.h"

START_TEST(strcmp_empty) {
  char str1[] = "";
  char str2[] = "";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

START_TEST(strcmp_hello_equality) {
  char str1[] = "Hello, World!";
  char str2[] = "Hello, World!";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

START_TEST(strcmp_hello_diff1) {
  char str1[] = "Hello, World!";
  char str2[] = "Hello, ";
  int std_lib_res = strcmp(str1, str2);
  int our_res = s21_strcmp(str1, str2);
  if (std_lib_res < -1) std_lib_res = -1;
  if (std_lib_res > 1) std_lib_res = 1;
  if (our_res < -1) our_res = -1;
  if (our_res > 1) our_res = 1;
  ck_assert_int_eq(std_lib_res, our_res);
}
END_TEST

START_TEST(strcmp_hello_diff2) {
  char str1[] = "Hello, ";
  char str2[] = "Hello, World!";
  int std_lib_res = strcmp(str1, str2);
  int our_res = s21_strcmp(str1, str2);
  if (std_lib_res < -1) std_lib_res = -1;
  if (std_lib_res > 1) std_lib_res = 1;
  if (our_res < -1) our_res = -1;
  if (our_res > 1) our_res = 1;
  ck_assert_int_eq(std_lib_res, our_res);
}
END_TEST

START_TEST(strcmp_hello_diff3) {
  char str1[] = "hELLO, wORLD";
  char str2[] = "Hello, World!";
  int std_lib_res = strcmp(str1, str2);
  int our_res = s21_strcmp(str1, str2);
  if (std_lib_res < -1) std_lib_res = -1;
  if (std_lib_res > 1) std_lib_res = 1;
  if (our_res < -1) our_res = -1;
  if (our_res > 1) our_res = 1;
  ck_assert_int_eq(std_lib_res, our_res);
}
END_TEST

START_TEST(strcmp_dots_equality) {
  char str1[] = "......................................";
  char str2[] = "......................................";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

START_TEST(strcmp_chars_equality) {
  char str1[] =
      "0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ^-`"
      "abcdefghijklmnopqrstuvwxyz";
  char str2[] =
      "0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ^-`"
      "abcdefghijklmnopqrstuvwxyz";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

START_TEST(strcmp_dots_diff1) {
  char str1[] = "...............................";
  char str2[] = "......................................";
  int std_lib_res = strcmp(str1, str2);
  int our_res = s21_strcmp(str1, str2);
  if (std_lib_res < -1) std_lib_res = -1;
  if (std_lib_res > 1) std_lib_res = 1;
  if (our_res < -1) our_res = -1;
  if (our_res > 1) our_res = 1;
  ck_assert_int_eq(std_lib_res, our_res);
}
END_TEST

START_TEST(strcmp_dots_diff2) {
  char str1[] = "......................................";
  char str2[] = "...............................";
  int std_lib_res = strcmp(str1, str2);
  int our_res = s21_strcmp(str1, str2);
  if (std_lib_res < -1) std_lib_res = -1;
  if (std_lib_res > 1) std_lib_res = 1;
  if (our_res < -1) our_res = -1;
  if (our_res > 1) our_res = 1;
  ck_assert_int_eq(std_lib_res, our_res);
}
END_TEST

START_TEST(strcmp_chars_diff1) {
  char str1[] = "0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ^-`";
  char str2[] =
      "0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ^-`"
      "abcdefghijklmnopqrstuvwxyz";
  int std_lib_res = strcmp(str1, str2);
  int our_res = s21_strcmp(str1, str2);
  if (std_lib_res < -1) std_lib_res = -1;
  if (std_lib_res > 1) std_lib_res = 1;
  if (our_res < -1) our_res = -1;
  if (our_res > 1) our_res = 1;
  ck_assert_int_eq(std_lib_res, our_res);
}
END_TEST

START_TEST(strcmp_chars_diff2) {
  char str1[] =
      "0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ^-`"
      "abcdefghijklmnopqrstuvwxyz";
  char str2[] = "0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ^-`";
  int std_lib_res = strcmp(str1, str2);
  int our_res = s21_strcmp(str1, str2);
  if (std_lib_res < -1) std_lib_res = -1;
  if (std_lib_res > 1) std_lib_res = 1;
  if (our_res < -1) our_res = -1;
  if (our_res > 1) our_res = 1;
  ck_assert_int_eq(std_lib_res, our_res);
}
END_TEST

Suite *strcmp_suite() {
  Suite *s = suite_create("STRCMP");
  TCase *tc = tcase_create("strcmp");
  tcase_add_test(tc, strcmp_empty);
  tcase_add_test(tc, strcmp_hello_equality);
  tcase_add_test(tc, strcmp_hello_diff1);
  tcase_add_test(tc, strcmp_hello_diff2);
  tcase_add_test(tc, strcmp_hello_diff3);
  tcase_add_test(tc, strcmp_dots_equality);
  tcase_add_test(tc, strcmp_chars_equality);
  tcase_add_test(tc, strcmp_dots_diff1);
  tcase_add_test(tc, strcmp_dots_diff2);
  tcase_add_test(tc, strcmp_chars_diff1);
  tcase_add_test(tc, strcmp_chars_diff2);
  suite_add_tcase(s, tc);
  return s;
}