#include "s21_tests.h"

START_TEST(sprintf_test1) {
  char dest1[20] = "World never";
  char dest2[20] = "World never";
  sprintf(dest1, "stops");
  s21_sprintf(dest2, "stops");

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(sprintf_test2) {
  char dest1[20] = "World never";
  char dest2[20] = "World never";
  sprintf(dest1, "stops %d", 1);
  s21_sprintf(dest2, "stops %d", 1);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(sprintf_test3) {
  char dest1[100] = "World never";
  char dest2[100] = "World never";
  sprintf(dest1, "stops %d people", 1);
  s21_sprintf(dest2, "stops %d people", 1);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(sprintf_test4) {
  char dest1[100] = "World never";
  char dest2[100] = "World never";
  sprintf(dest1, "stops %d people", 123);
  s21_sprintf(dest2, "stops %d people", 123);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(sprintf_test5) {
  char dest1[100] = "World never";
  char dest2[100] = "World never";
  sprintf(dest1, "stops %d people %d", 123, 25);
  s21_sprintf(dest2, "stops %d people %d", 123, 25);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(sprintf_test6) {
  char dest1[100] = "World never";
  char dest2[100] = "World never";
  char who[] = "say YES";
  sprintf(dest1, "stops %d people %.0s!", 123, who);
  s21_sprintf(dest2, "stops %d people %.0s!", 123, who);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(sprintf_test7) {
  char dest1[100] = "World never";
  char dest2[100] = "World never";
  char who[] = "say YES";
  sprintf(dest1, "stops %%%%% 0d people %%%.2s!", 123, who);
  s21_sprintf(dest2, "stops %%%%% 0d people %%%.2s!", 123, who);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(sprintf_test8) {
  char dest1[100] = "World never";
  char dest2[100] = "World never";
  char who[] = "say YES";
  sprintf(dest1, "stops %%d% .2d people %%s%s!", -123, who);
  s21_sprintf(dest2, "stops %%d% .2d people %%s%s!", -123, who);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(sprintf_test9) {
  char str1[100] = {"\0"};
  char str2[100] = {"\0"};
  char *str3 = "%c Test %c Test %-2c Test %3c Test %c";
  int res1 = sprintf(str1, str3, 'b', '4', '#', '@', '\0');
  int res2 = s21_sprintf(str2, str3, 'b', '4', '#', '@', '\0');
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_test10) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %u Test";
  unsigned int a = 012;
  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test11) {
  char str1[200] = {"\0"};
  char str2[200] = {"\0"};
  char *str3 = "%f TEST %.f TEST %4f TEST %-4.3f TEST %+5.10f!";
  double num = 76.756589367;
  sprintf(str1, str3, num, num, num, num, num);
  s21_sprintf(str2, str3, num, num, num, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprint_oct) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  char str[] = "  055555 0f 0f 0f5555555 0ddd   4    3    1 ";
  char fstr[] = "%o %X %x %i";
  int res1 = s21_sprintf(str, fstr, a1, b1, c1, d1);
  int res2 = sprintf(str, fstr, a2, b2, c2, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sprintf_hex) {
  long long a1 = 2367, a2 = 2367, b1 = -2, b2 = -2, c1 = 58122, c2 = 58122,
            d1 = 45, d2 = 45;
  char str[] = " 63DD 0xf 0xf 0xf5555555 ddd   4    3    1 ";
  char fstr[] = "%-#0.6x %#.5o %-#5.7X %ld";
  int res1 = s21_sprintf(str, fstr, a1, b1, c1, d1);
  int res2 = sprintf(str, fstr, a2, b2, c2, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(s21_sscanf_test_17_o_option) {
  int a1 = 0, a2 = 0;
  char str[] = "          \n             \n     5";
  char fstr[] = "%o";
  int res1 = s21_sprintf(str, fstr, a1);
  int res2 = sprintf(str, fstr, a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_18_o_option) {
  unsigned short a1 = 0, a2 = 0;
  char str[] = "12";
  char fstr[] = "%ho";
  int res1 = s21_sprintf(str, fstr, a1);
  int res2 = sprintf(str, fstr, a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_19_u_option) {
  unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  char str[] = "-1337 +21 --5008 3000";
  char fstr[] = "%hu %hu %hu %hu";
  int res1 = s21_sprintf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sprintf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

Suite *sprintf_suite() {
  Suite *s = suite_create("SPRINTF");
  TCase *tc = tcase_create("sprintf");
  tcase_add_test(tc, sprintf_test1);
  tcase_add_test(tc, sprintf_test2);
  tcase_add_test(tc, sprintf_test3);
  tcase_add_test(tc, sprintf_test4);
  tcase_add_test(tc, sprintf_test5);
  tcase_add_test(tc, sprintf_test6);
  tcase_add_test(tc, sprintf_test7);
  tcase_add_test(tc, sprintf_test8);
  tcase_add_test(tc, sprintf_test9);
  tcase_add_test(tc, sprintf_test10);
  tcase_add_test(tc, sprintf_test11);
  tcase_add_test(tc, test_sprint_oct);
  tcase_add_test(tc, test_sprintf_hex);
  tcase_add_test(tc, s21_sscanf_test_17_o_option);
  tcase_add_test(tc, s21_sscanf_test_18_o_option);
  tcase_add_test(tc, s21_sscanf_test_19_u_option);

  suite_add_tcase(s, tc);
  return s;
}
