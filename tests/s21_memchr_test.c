#include "s21_tests.h"

START_TEST(memchr_1) {
  char str[] = "Hello, world!";
  int c = ' ';
  s21_size_t len = strlen(str);
  s21_size_t s21_len = s21_strlen(str);
  ck_assert_pstr_eq(memchr(str, c, len), s21_memchr(str, c, s21_len));
}
END_TEST

START_TEST(memchr_2) {
  char str[] = "Hello, world!";
  int c = 104;
  s21_size_t len = strlen(str);
  s21_size_t s21_len = s21_strlen(str);
  ck_assert_pstr_eq(memchr(str, c, len), s21_memchr(str, c, s21_len));
}
END_TEST

START_TEST(memchr_3) {
  char str[] = "Hello, world!";
  int c = '1';
  s21_size_t len = strlen(str);
  s21_size_t s21_len = s21_strlen(str);
  ck_assert_pstr_eq(memchr(str, c, len), s21_memchr(str, c, s21_len));
}
END_TEST

START_TEST(memchr_4) {
  char str[] = "Hello, world!";
  int c = 65;
  s21_size_t len = strlen(str);
  s21_size_t s21_len = s21_strlen(str);
  ck_assert_pstr_eq(memchr(str, c, len), s21_memchr(str, c, s21_len));
}
END_TEST

START_TEST(memchr_5) {
  char str[] = "Hello, world!";
  int c = 'l';
  s21_size_t len = strlen(str);
  s21_size_t s21_len = s21_strlen(str);
  ck_assert_pstr_eq(memchr(str, c, len), s21_memchr(str, c, s21_len));
}
END_TEST

START_TEST(memchr_6) {
  char str[] = "Hello, world!";
  int c = '\0';
  s21_size_t len = strlen(str);
  s21_size_t s21_len = s21_strlen(str);
  ck_assert_pstr_eq(memchr(str, c, len), s21_memchr(str, c, s21_len));
}
END_TEST

START_TEST(memchr_7) {
  char str[] = "00000000008000000000";
  int c = '8';
  s21_size_t len = strlen(str);
  s21_size_t s21_len = s21_strlen(str);
  ck_assert_pstr_eq(memchr(str, c, len), s21_memchr(str, c, s21_len));
}
END_TEST

START_TEST(memchr_8) {
  char str[] = "k\n\0";
  int c = '\\';
  s21_size_t len = strlen(str);
  s21_size_t s21_len = s21_strlen(str);
  ck_assert_pstr_eq(memchr(str, c, len), s21_memchr(str, c, s21_len));
}
END_TEST

START_TEST(memchr_9) {
  char str[] = "Hello, world!";
  int c = '\n';
  s21_size_t len = strlen(str);
  s21_size_t s21_len = s21_strlen(str);
  ck_assert_pstr_eq(memchr(str, c, len), s21_memchr(str, c, s21_len));
}
END_TEST

START_TEST(memchr_10) {
  char str[] = "Hello, world!";
  int c = '\t';
  s21_size_t len = strlen(str);
  s21_size_t s21_len = s21_strlen(str);
  ck_assert_pstr_eq(memchr(str, c, len), s21_memchr(str, c, s21_len));
}
END_TEST

Suite *memchr_suite() {
  Suite *s = suite_create("MEMCHR");
  TCase *tc = tcase_create("memchr");
  tcase_add_test(tc, memchr_1);
  tcase_add_test(tc, memchr_2);
  tcase_add_test(tc, memchr_3);
  tcase_add_test(tc, memchr_4);
  tcase_add_test(tc, memchr_5);
  tcase_add_test(tc, memchr_6);
  tcase_add_test(tc, memchr_7);
  tcase_add_test(tc, memchr_8);
  tcase_add_test(tc, memchr_9);
  tcase_add_test(tc, memchr_10);
  suite_add_tcase(s, tc);
  return s;
}
