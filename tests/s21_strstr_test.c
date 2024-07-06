#include "s21_tests.h"

START_TEST(strstr_1) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_2) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello,";
  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_3) {
  char str1[] = "Hello, world!";
  char str2[] = ",";
  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_4) {
  char str1[] = "Hello, world!";
  char str2[] = "wor";
  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_5) {
  char str1[] = "Hello, world!";
  char str2[] = "P";
  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_6) {
  char str1[] = "";
  char str2[] = "";
  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_7) {
  char str1[] = "";
  char str2[] = "Hello, world!";
  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_8) {
  char str1[] = "147896321";
  char str2[] = "\0";
  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_9) {
  char str1[] = "77777777775555555555224699";
  char str2[] = "52";
  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_10) {
  char str1[] = "Hellllllo";
  char str2[] = "Heeelllpo";
  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

Suite *strstr_suite() {
  Suite *s = suite_create("STRSTR");
  TCase *tc = tcase_create("strstr");
  tcase_add_test(tc, strstr_1);
  tcase_add_test(tc, strstr_2);
  tcase_add_test(tc, strstr_3);
  tcase_add_test(tc, strstr_4);
  tcase_add_test(tc, strstr_5);
  tcase_add_test(tc, strstr_6);
  tcase_add_test(tc, strstr_7);
  tcase_add_test(tc, strstr_8);
  tcase_add_test(tc, strstr_9);
  tcase_add_test(tc, strstr_10);
  suite_add_tcase(s, tc);
  return s;
}
