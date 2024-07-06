#include "s21_tests.h"

START_TEST(strcat_test1) {
  char dest1[20] = "World never";
  char dest2[20] = "World never";
  char src[] = "stops";

  strcat(dest1, src);
  s21_strcat(dest2, src);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strcat_test2) {
  char dest1[20] = "World never";
  char dest2[20] = "World never";
  char src[] = "stops";

  strcat(dest1, src);
  s21_strcat(dest2, src);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strcat_test3) {
  char dest1[] = "stops";
  char dest2[] = "stops";
  char src[] = "";

  strcat(dest1, src);
  s21_strcat(dest2, src);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strcat_test4) {
  char dest1[10] = "";
  char dest2[10] = "";
  char src[] = "";

  strcat(dest1, src);
  s21_strcat(dest2, src);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strcat_test5) {
  char dest1[10] = "";
  char dest2[10] = "";
  char src[] = "Hello";

  strcat(dest1, src);
  s21_strcat(dest2, src);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

Suite *strcat_suite() {
  Suite *s = suite_create("STRCAT");
  TCase *tc = tcase_create("strcat");
  tcase_add_test(tc, strcat_test1);
  tcase_add_test(tc, strcat_test2);
  tcase_add_test(tc, strcat_test3);
  tcase_add_test(tc, strcat_test4);
  tcase_add_test(tc, strcat_test5);
  suite_add_tcase(s, tc);
  return s;
}
