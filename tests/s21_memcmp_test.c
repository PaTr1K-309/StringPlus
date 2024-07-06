#include "s21_tests.h"

START_TEST(memcmp_empty) {
  char str1[] = "";
  char str2[] = "";
  s21_size_t n = 0;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_hello_world) {
  char str1[] = "Hello, World!";
  char str2[] = "Hello, World!";
  s21_size_t n = 5;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_hello_1) {
  char str1[] = "Hello, World!";
  char str2[] = "Hello, ";
  s21_size_t n = 8;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_hello_2) {
  char str1[] = "ello!, ";
  char str2[] = "World, Hello!";
  s21_size_t n = 8;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_dots) {
  char str1[] = "......................................";
  char str2[] = "......................................";
  s21_size_t n = 18;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_chars_equality) {
  char str1[] =
      "0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ^-`"
      "abcdefghijklmnopqrstuvwxyz";
  char str2[] =
      "abcdefghijklmnopqrstuvwxy0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ^-`"
      "z";
  s21_size_t n = 18;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_chars_diff1) {
  char str1[] = "0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ^-`";
  char str2[] =
      "0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ^-`"
      "abcdefghijklmnopqrstuvwxyz";
  s21_size_t n = 18;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_chars_diff2) {
  char str1[] =
      "0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ^-`"
      "abcdefghijklmnopqrstuvwxyz";
  char str2[] = "0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ^-`";
  s21_size_t n = 28;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_nums_1) {
  char str1[] = "0123456789";
  char str2[] = "798";
  s21_size_t n = 3;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_nums_2) {
  char str1[] = "3478652036";
  char str2[] = "9";
  s21_size_t n = 1;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_nums_3) {
  char str1[] = "3478652036";
  char str2[] = "0";
  s21_size_t n = 1;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

Suite *memcmp_suite() {
  Suite *s = suite_create("MEMCMP");
  TCase *tc = tcase_create("memcmp");
  tcase_add_test(tc, memcmp_empty);
  tcase_add_test(tc, memcmp_hello_world);
  tcase_add_test(tc, memcmp_hello_1);
  tcase_add_test(tc, memcmp_hello_2);
  tcase_add_test(tc, memcmp_dots);
  tcase_add_test(tc, memcmp_chars_equality);
  tcase_add_test(tc, memcmp_chars_diff1);
  tcase_add_test(tc, memcmp_chars_diff2);
  tcase_add_test(tc, memcmp_nums_1);
  tcase_add_test(tc, memcmp_nums_2);
  tcase_add_test(tc, memcmp_nums_3);
  suite_add_tcase(s, tc);
  return s;
}