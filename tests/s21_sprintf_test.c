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
  sprintf(dest1, "stops %d people %s!", 123, who);
  s21_sprintf(dest2, "stops %d people %s!", 123, who);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(sprintf_test7) {
  char dest1[100] = "World never";
  char dest2[100] = "World never";
  char who[] = "say YES";
  sprintf(dest1, "stops %%%%%d people %%%s!", 123, who);
  s21_sprintf(dest2, "stops %%%%%d people %%%s!", 123, who);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(sprintf_test8) {
  char dest1[100] = "World never";
  char dest2[100] = "World never";
  char who[] = "say YES";
  sprintf(dest1, "stops %%d%d people %%s%s!", 123, who);
  s21_sprintf(dest2, "stops %%d%d people %%s%s!", 123, who);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST


START_TEST(sprintf_test9) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  int res1 = sprintf(str1, str3, 'b', '4', '#', '@', '\0');
  int res2 = s21_sprintf(str2, str3, 'b', '4', '#', '@', '\0');
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_test10) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %u Test";
  unsigned int a = 012;
  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test11) {
  char str1[4000];
  char str2[4000];
  char *str3 = "%f TEST %.f TEST %4f TEST %4.f TEST %5.10f!";
  float num = 76.756589367;
  sprintf(str1, str3, num, num, num, num, num);
  s21_sprintf(str2, str3, num, num, num, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test12) {
  char str1[20000];
  char str2[20000];
  char *str3 = "%f TEST %f TEST %fTEST %f TEST %f!";
  double num1 = 0.007;
  double num2 = 110001.10;
  double num3 = 1.100001;
  double num4 = 0.0005;
  double num5 = 2475.0193;
  sprintf(str1, str3, num1, num2, num3, num4, num5);
  s21_sprintf(str2, str3, num1, num2, num3, num4, num5);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test13) {
  char str1[200];
  char str2[200];
  char *str3 = "%+d TEST %+f TEST ";
  int num1 = 5;
  float num2 = 39200.2220;
  sprintf(str1, str3, num1, num2);
  s21_sprintf(str2, str3, num1, num2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test14) {
  char str1[200];
  char str2[200];
  char *str3 = "%+d plus";
  int num1 = 45;
  sprintf(str1, str3, num1);
  s21_sprintf(str2, str3, num1);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test15) {
  char str1[200];
  char str2[200];
  char *str3 = "%+f "; 
  float num1 = 30.09;
  sprintf(str1, str3, num1);
  s21_sprintf(str2, str3, num1);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test16) {
  char str1[200];
  char str2[200];
  char *str3 = "%+d minus"; 
  int num1 = -30;
  sprintf(str1, str3, num1);
  s21_sprintf(str2, str3, num1);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test17) {
  char str1[200];
  char str2[200];
  char *str3 = "%+f "; 
  float num1 = -30.09;
  sprintf(str1, str3, num1);
  s21_sprintf(str2, str3, num1);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test18) {
  char str1[200];
  char str2[200];
  char *str3 = "%+d TEST %+f TEST "; 
  int num1 = 5;
  float num2 = -30.20;
  sprintf(str1, str3, num1, num2);
  s21_sprintf(str2, str3, num1, num2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test19) {
  char str1[200];
  char str2[200];
  char *str3 = "%+d TEST %+f TEST "; 
  int num1 = -15;
  float num2 = 200.20;
  sprintf(str1, str3, num1, num2);
  s21_sprintf(str2, str3, num1, num2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test20) {
  char str1[200];
  char str2[200];
  char *str3 = "% d TEST % f TEST ";
  int num1 = 5;
  float num2 = 39200.2220;
  sprintf(str1, str3, num1, num2);
  s21_sprintf(str2, str3, num1, num2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test21) {
  char str1[200];
  char str2[200];
  char *str3 = "% d plus";
  int num1 = 45;
  sprintf(str1, str3, num1);
  s21_sprintf(str2, str3, num1);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test22) {
  char str1[200];
  char str2[200];
  char *str3 = "% f "; 
  float num1 = 30.09;
  sprintf(str1, str3, num1);
  s21_sprintf(str2, str3, num1);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test23) {
  char str1[200];
  char str2[200];
  char *str3 = "% d minus"; 
  int num1 = -30;
  sprintf(str1, str3, num1);
  s21_sprintf(str2, str3, num1);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test24) {
  char str1[200];
  char str2[200];
  char *str3 = "% f "; 
  float num1 = -30.09;
  sprintf(str1, str3, num1);
  s21_sprintf(str2, str3, num1);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test25) {
  char str1[200];
  char str2[200];
  char *str3 = "% d TEST % f TEST "; 
  int num1 = 5;
  float num2 = -30.20;
  sprintf(str1, str3, num1, num2);
  s21_sprintf(str2, str3, num1, num2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test26) {
  char str1[200];
  char str2[200];
  char *str3 = "% d TEST % f TEST "; 
  int num1 = -15;
  float num2 = 200.20;
  sprintf(str1, str3, num1, num2);
  s21_sprintf(str2, str3, num1, num2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test27) {
  char str1[20000];
  char str2[20000];
  char *str3 = "%-d TEST %-f TEST "; 
  int num1 = -54;
  float num2 = 200.20;
  sprintf(str1, str3, num1, num2);
  s21_sprintf(str2, str3, num1, num2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test28) {
  char str1[200];
  char str2[200];
  char *str3 = "%-4d TEST %-8f TEST "; 
  int num1 = 5;
  float num2 = 12.50;
  sprintf(str1, str3, num1, num2);
  s21_sprintf(str2, str3, num1, num2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test29) {
  char str1[20000];
  char str2[20000];
  char *str3 = "%-2d TEST %-f TEST %-d U %-4f all"; 
  int num1 = 43;
  int num3 = 12;
  float num2 = 123.203;
  float num4 = 0.123;
  sprintf(str1, str3, num1, num2, num3, num4);
  s21_sprintf(str2, str3, num1, num2, num3, num4);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test30) {
  char str1[200];
  char str2[200];
  char *str3 = "%-7d %-4f TEST "; 
  int num1 = 43;
  float num2 = 123.203;
  sprintf(str1, str3, num1, num2);
  s21_sprintf(str2, str3, num1, num2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test31) {
  char str1[2000];
  char str2[2000];
  char *str3 = "%10s TEST and %5f TEST "; 
  char num1[] = "hello ";
  float num2 = 123.203;
  sprintf(str1, str3, num1, num2);
  s21_sprintf(str2, str3, num1, num2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test32) {
  char str1[20000];
  char str2[20000];
  char *str3 = "%6d TEST %3f TEST %5s %10s "; 
  int num1 = 73;
  float num2 = 123.203;
  char num3[] = "and";
  char num4[] = "all!";
  sprintf(str1, str3, num1, num2, num3, num4);
  s21_sprintf(str2, str3, num1, num2, num3, num4);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test33) {
  char str1[200];
  char str2[200];
  char *str3 = "%hu";
  unsigned short int num1 = 15234;
  sprintf(str1, str3, num1);
  s21_sprintf(str2, str3, num1); 
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test34) {
  char str1[200];
  char str2[200];
  char *str3 = "%lu";
  unsigned long int num1 = 300920003032;
  sprintf(str1, str3, num1);
  s21_sprintf(str2, str3, num1);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test35) {
  char str1[200];
  char str2[200];
  char *str3 = "%lu, %u, %hu";
  unsigned long int num1 = 949149114140;
  unsigned short num2 = 65534;
  unsigned int num3 = 300922222;
  sprintf(str1, str3, num1, num2, num3);
  s21_sprintf(str2, str3, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test36) {
  char str1[200];
  char str2[200];
  char *str3 = "%3c%-11c%10c%-2c%c";
  sprintf(str1, str3, '\t', '\n', '0', 'S', 's');
  s21_sprintf(str2, str3, '\t', '\n', '0', 'S', 's');
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test37) {
  char str1[200];
  char str2[200];
  char *str3 = "thes %x and thes %x and thes %x and thes %x and thes %x";
  int num1 = INT16_MAX;
  int num2 = 309;
  int num3 = 0;
  int num4 = -309;
  int num5 = INT16_MIN;
  sprintf(str1, str3, num1, num2, num3, num4, num5);
  s21_sprintf(str2, str3, num1, num2, num3, num4, num5);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test38) {
  char str1[200];
  char str2[200];
  char *str3 = "thes %x and thes %x and thes %x and thes %x and thes %x";
  int num1 = INT16_MAX;
  char *num2 = "AEA";
  int num3 = 0;
  char *num4 = "FFF";
  int num5 = INT16_MIN;
  sprintf(str1, str3, num1, num2, num3, num4, num5);
  s21_sprintf(str2, str3, num1, num2, num3, num4, num5);
  ck_assert_str_eq(str1, str2);
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
  tcase_add_test(tc, sprintf_test12);
  tcase_add_test(tc, sprintf_test13);
  tcase_add_test(tc, sprintf_test14);
  tcase_add_test(tc, sprintf_test15);
  tcase_add_test(tc, sprintf_test16);
  tcase_add_test(tc, sprintf_test17);
  tcase_add_test(tc, sprintf_test18);
  tcase_add_test(tc, sprintf_test19);
  tcase_add_test(tc, sprintf_test20);
  tcase_add_test(tc, sprintf_test21);
  tcase_add_test(tc, sprintf_test22);
  tcase_add_test(tc, sprintf_test23);
  tcase_add_test(tc, sprintf_test24);
  tcase_add_test(tc, sprintf_test25);
  tcase_add_test(tc, sprintf_test26);
  tcase_add_test(tc, sprintf_test27);
  tcase_add_test(tc, sprintf_test28);
  tcase_add_test(tc, sprintf_test29);
  tcase_add_test(tc, sprintf_test30);
  tcase_add_test(tc, sprintf_test31);
  tcase_add_test(tc, sprintf_test32);
  tcase_add_test(tc, sprintf_test33);
  tcase_add_test(tc, sprintf_test34);
  tcase_add_test(tc, sprintf_test35);
  tcase_add_test(tc, sprintf_test36);
  tcase_add_test(tc, sprintf_test37);
  tcase_add_test(tc, sprintf_test38);
  suite_add_tcase(s, tc);
  return s;
}