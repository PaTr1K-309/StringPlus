#include "s21_tests.h"

START_TEST(memset_1) {
  char src[100] = "something";
  size_t len = strlen(src) + 1;
  ck_assert_ptr_eq(memset(src, '1', len), s21_memset(src, '1', len));
}
END_TEST

START_TEST(memset_2) {
  char src[100] = "mne etot mir absolute ponyaten";
  ck_assert_ptr_eq(memset(src, '>', 30), s21_memset(src, '>', 30));
}
END_TEST

START_TEST(memset_3) {
  char src[100] = "";
  ck_assert_ptr_eq(memset(src, '-', 40), s21_memset(src, '-', 40));
}
END_TEST

START_TEST(memset_4) {
  char src[100] = "";
  ck_assert_ptr_eq(memset(src, 'R', 10), s21_memset(src, 'R', 10));
}
END_TEST

START_TEST(memset_5) {
  char src[100] = "everything works just fine";
  ck_assert_ptr_eq(memset(src, 'R', 20), s21_memset(src, 'R', 20));
}
END_TEST

Suite *memset_suite() {
  Suite *s = suite_create("MEMSET");
  TCase *tc = tcase_create("memset");
  tcase_add_test(tc, memset_1);
  tcase_add_test(tc, memset_2);
  tcase_add_test(tc, memset_3);
  tcase_add_test(tc, memset_4);
  tcase_add_test(tc, memset_5);
  suite_add_tcase(s, tc);
  return s;
}
