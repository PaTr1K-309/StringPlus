#include "s21_tests.h"

START_TEST(strtok_test1) {
  char dest1[] = "World.never.stops";
  char dest2[] = "World.never.stops";
  char *div = ".";

  char *token1 = strtok(dest1, div);
  char *token2 = s21_strtok(dest2, div);

  while (token1 != NULL) {
    ck_assert_str_eq(token1, token2);
    token1 = strtok(S21_NULL, div);
    token2 = s21_strtok(NULL, div);
  }
}
END_TEST

START_TEST(strtok_test2) {
  char dest1[] = "World.never/stops";
  char dest2[] = "World.never/stops";
  char *div = "./";

  char *token1 = strtok(dest1, div);
  char *token2 = s21_strtok(dest2, div);

  while (token1 != NULL) {
    ck_assert_str_eq(token1, token2);
    token1 = strtok(S21_NULL, div);
    token2 = s21_strtok(NULL, div);
  }
}
END_TEST

START_TEST(strtok_test3) {
  char dest1[] = "World./never/stops";
  char dest2[] = "World./never/stops";
  char *div = "./";

  char *token1 = strtok(dest1, div);
  char *token2 = s21_strtok(dest2, div);

  while (token1 != NULL) {
    ck_assert_str_eq(token1, token2);
    token1 = strtok(S21_NULL, div);
    token2 = s21_strtok(NULL, div);
  }
}
END_TEST

Suite *strtok_suite() {
  Suite *s = suite_create("STRTOK");
  TCase *tc = tcase_create("strtok");
  tcase_add_test(tc, strtok_test1);
  tcase_add_test(tc, strtok_test2);
  tcase_add_test(tc, strtok_test3);
  suite_add_tcase(s, tc);
  return s;
}
