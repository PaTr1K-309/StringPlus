#include "s21_tests.h"

START_TEST(s21_insert_test1) {
  // char str1[11] = "I'm coding";
  // char str2[5] = " love";
  // char *str3 = (char*)s21_insert(str1, str2, 3);
  // ck_assert_str_eq(str3, "I'm love coding");
  // free(str3);
  char str1[7] = "this +";
  char str2[6] = " this";
  char *str3 = (char *)s21_insert(str1, str2, 6);
  ck_assert_str_eq(str3, "this + this");
  free(str3);
}
END_TEST

START_TEST(s21_insert_test2) {
  char str1[1] = "";
  char str2[14] = "checking null";
  char *str3 = (char *)s21_insert(str1, str2, 1);
  ck_assert_ptr_eq(str3, S21_NULL);
  free(str3);
}
END_TEST

START_TEST(s21_insert_test3) {
  char str1[10] = "I'mcoder";
  char str2[3] = " ";
  char *str3 = (char *)s21_insert(str1, str2, 3);
  ck_assert_str_eq(str3, "I'm coder");
  free(str3);
}
END_TEST

START_TEST(s21_insert_test4) {
  char str1[14] = "checking null";
  char *str2 = S21_NULL;
  char *str3 = (char *)s21_insert(str1, str2, 0);
  ck_assert_ptr_eq(str3, S21_NULL);
  free(str3);
}
END_TEST

START_TEST(s21_insert_test5) {
  char str1[4] = "end";
  char str2[6] = "start";
  char *str3 = (char *)s21_insert(str1, str2, 0);
  ck_assert_str_eq(str3, "startend");
  free(str3);
}
END_TEST

START_TEST(s21_insert_test6) {
  char *str1 = S21_NULL;
  char str2[14] = "checking null";
  char *str3 = (char *)s21_insert(str1, str2, 1);
  ck_assert_ptr_eq(str3, S21_NULL);
  free(str3);
}
END_TEST

START_TEST(s21_insert_test7) {
  char *str1 = S21_NULL;
  char *str2 = S21_NULL;
  char *str3 = (char *)s21_insert(str1, str2, 0);
  ck_assert_ptr_eq(str3, S21_NULL);
  free(str3);
}
END_TEST

Suite *insert_suite() {
  Suite *s = suite_create("INSERT");
  TCase *tc = tcase_create("insert");
  tcase_add_test(tc, s21_insert_test1);
  tcase_add_test(tc, s21_insert_test2);
  tcase_add_test(tc, s21_insert_test3);
  tcase_add_test(tc, s21_insert_test4);
  tcase_add_test(tc, s21_insert_test5);
  tcase_add_test(tc, s21_insert_test6);
  tcase_add_test(tc, s21_insert_test7);
  suite_add_tcase(s, tc);
  return s;
}
