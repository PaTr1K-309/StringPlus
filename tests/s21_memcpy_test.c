#include "s21_tests.h"

START_TEST(memcpy_1) {
  char dest[100] = "";
  char src[100] = "Geeksfor";
  size_t len = strlen(src) + 1;
  ck_assert_ptr_eq(memcpy(dest, src, len), s21_memcpy(dest, src, len));
}
END_TEST

START_TEST(memcpy_2) {
  char dest[100] = "";
  char src[100] = "";
  size_t len = strlen(src) + 1;
  ck_assert_ptr_eq(memcpy(dest, src, len), s21_memcpy(dest, src, len));
}
END_TEST

START_TEST(memcpy_3) {
  char dest[100] = "";
  char src[100] = "JustWorks";
  size_t len = strlen(src) + 1;
  ck_assert_ptr_eq(memcpy(dest, src, len), s21_memcpy(dest, src, len));
}
END_TEST

START_TEST(memcpy_4) {
  char dest[100] = "Duck";
  char src[100] = "Geeksfor";
  size_t len = strlen(src) + 1;
  ck_assert_ptr_eq(memcpy(dest, src, len), s21_memcpy(dest, src, len));
}
END_TEST

START_TEST(memcpy_5) {
  char dest[100] = "/////////";
  char src[100] = "///////////////";
  size_t len = strlen(src) + 1;
  ck_assert_ptr_eq(memcpy(dest, src, len), s21_memcpy(dest, src, len));
}
END_TEST

START_TEST(memcpy_6) {
  char dest[100] = "check";
  char src[100] = "";
  size_t len = strlen(src) + 1;
  ck_assert_ptr_eq(memcpy(dest, src, len), s21_memcpy(dest, src, len));
}
END_TEST

Suite *memcpy_suite() {
  Suite *s = suite_create("MEMCPY");
  TCase *tc = tcase_create("memcpy");
  tcase_add_test(tc, memcpy_1);
  tcase_add_test(tc, memcpy_2);
  tcase_add_test(tc, memcpy_3);
  tcase_add_test(tc, memcpy_4);
  tcase_add_test(tc, memcpy_5);
  tcase_add_test(tc, memcpy_6);
  suite_add_tcase(s, tc);
  return s;
}
