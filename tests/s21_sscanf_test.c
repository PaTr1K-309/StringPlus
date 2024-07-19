#include "../s21_sscanf.h"

#include "s21_tests.h"

START_TEST(sscanf_test_int_1) {
  char format[100] = "%d %d";
  char str[100] = "45 12";
  int o1 = 0, o2 = 0, s1 = 0, s2 = 0;
  int original = sscanf(str, format, &o1, &o2);
  int s21_func = s21_sscanf(str, format, &s1, &s2);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
}
END_TEST

START_TEST(sscanf_test_int_2) {
  char format[100] = "%d %d";
  char str[100] = "-45 -12";
  int o1 = 0, o2 = 0, s1 = 0, s2 = 0;
  int original = sscanf(str, format, &o1, &o2);
  int s21_func = s21_sscanf(str, format, &s1, &s2);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
}
END_TEST

START_TEST(sscanf_test_int_3) {
  char format[100] = "%d %d";
  char str[100] = "1 a";
  int o1 = 0, o2 = 0, s1 = 0, s2 = 0;
  int original = sscanf(str, format, &o1, &o2);
  int s21_func = s21_sscanf(str, format, &s1, &s2);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
}
END_TEST

START_TEST(sscanf_test_int_4) {
  const char *input = "+42";
  int original = 0, s21_func = 0;
  sscanf(input, "%d", &original);
  s21_sscanf(input, "%d", &s21_func);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_int_5) {
  const char *input = "   42";
  int original = 0, s21_func = 0;
  sscanf(input, "%d", &original);
  s21_sscanf(input, "%d", &s21_func);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_o_1) {
  char format[] = "%o";
  char str[] = "123";
  int o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
}
END_TEST

START_TEST(sscanf_test_o_2) {
  char format[] = "%o";
  char str[] = "777";
  int o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
}
END_TEST

START_TEST(sscanf_test_o_3) {
  char format[] = "%o";
  char str[] = "0";
  int o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
}
END_TEST

START_TEST(sscanf_test_o_4) {
  char format[] = "%o %o %o %o %o %o";
  char str[] = "65534 -1 0 65535 65536 -1024";
  int o1 = 0.0, o2 = 0.0, o3 = 0.0, o4 = 0.0, o5 = 0.0, o6 = 0.0, s1 = 0.0,
      s2 = 0.0, s3 = 0.0, s4 = 0.0, s5 = 0.0, s6 = 0.0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(o3, s3);
  ck_assert_int_eq(o4, s4);
  ck_assert_int_eq(o5, s5);
  ck_assert_int_eq(o6, s6);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_u_1) {
  char format[] = "%u";
  char str[] = "123";
  unsigned int o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
}
END_TEST

START_TEST(sscanf_test_u_2) {
  char format[] = "%u";
  char str[] = "4294967295";
  unsigned int o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
}
END_TEST

START_TEST(sscanf_test_u_3) {
  char format[] = "%u";
  char str[] = "0";
  unsigned int o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
}
END_TEST

START_TEST(sscanf_test_u_4) {
  const char format[] = "%u";
  const char str[] = "-123";
  unsigned int o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert_uint_eq(o1, s1);
}
END_TEST

START_TEST(sscanf_test_u_5) {
  char format[] = "%u";
  char str[] = "-4294967295";
  unsigned int o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_u_6) {
  const char format[] = "%u %u %u %u %u %u";
  const char str[] = "+4294967295 -1 0 +4294967294 4294967296 -1024";
  unsigned int o1 = 0, o2 = 0, o3 = 0, o4 = 0, o5 = 0, o6 = 0, s1 = 0, s2 = 0,
               s3 = 0, s4 = 0, s5 = 0, s6 = 0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert_uint_eq(o1, s1);
  ck_assert_uint_eq(o2, s2);
  ck_assert_uint_eq(o3, s3);
  ck_assert_uint_eq(o4, s4);
  ck_assert_uint_eq(o5, s5);
  ck_assert_uint_eq(o6, s6);
  ck_assert_uint_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_x_1) {
  char format[] = "%x";
  char str[] = "  1a3";
  unsigned int o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
}
END_TEST

START_TEST(sscanf_test_x_2) {
  char format[] = "%x";
  char str[] = " 0";
  unsigned int o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
}
END_TEST

START_TEST(sscanf_test_x_3) {
  char format[] = "%x";
  char str[] = "ffff";
  unsigned int o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
}
END_TEST

START_TEST(sscanf_test_x_4) {
  char format[] = "%x";
  char str[] = "0x1a3";
  unsigned int o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
}
END_TEST

START_TEST(sscanf_test_x_5) {
  char format[] = "%x";
  char str[] = "0XFFFF";
  unsigned int o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
}
END_TEST

START_TEST(sscanf_test_X_1) {
  char format[] = "%X";
  char str[] = "1A3";
  unsigned int o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
}
END_TEST

START_TEST(sscanf_test_X_2) {
  char format[] = "%X";
  char str[] = "0";
  unsigned int o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
}
END_TEST

START_TEST(sscanf_test_X_3) {
  char format[] = "%X";
  char str[] = "  FFFF";
  unsigned int o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
}
END_TEST

START_TEST(sscanf_test_X_4) {
  char format[] = "%X";
  char str[] = "0x1A3";
  unsigned int o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
}
END_TEST

START_TEST(sscanf_test_X_5) {
  char format[] = "%X";
  char str[] = "  0XFFFF";
  unsigned int o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
}
END_TEST

START_TEST(sscanf_test_int_dec) {
  const char *input = "123";
  int expected = 123;
  int actual = 0;
  int original = sscanf(input, "%i", &expected);
  int s21_func = s21_sscanf(input, "%i", &actual);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(expected, actual);
}
END_TEST

START_TEST(sscanf_test_int_neg_dec) {
  const char *input = "-123";
  int expected = -123;
  int actual = 0;
  int original = sscanf(input, "%i", &expected);
  int s21_func = s21_sscanf(input, "%i", &actual);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(expected, actual);
}
END_TEST

START_TEST(sscanf_test_int_oct) {
  const char *input = "0173";
  int expected = 123;
  int actual = 0;
  int original = sscanf(input, "%i", &expected);
  int s21_func = s21_sscanf(input, "%i", &actual);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(expected, actual);
}
END_TEST

START_TEST(sscanf_test_int_neg_oct) {
  const char *input = "-0173";
  int expected = -123;
  int actual = 0;
  int original = sscanf(input, "%i", &expected);
  int s21_func = s21_sscanf(input, "%i", &actual);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(expected, actual);
}
END_TEST

START_TEST(sscanf_test_int_hex) {
  const char *input = "0x7B";
  int expected = 123;
  int actual = 0;
  int original = sscanf(input, "%i", &expected);
  int s21_func = s21_sscanf(input, "%i", &actual);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(expected, actual);
}
END_TEST

START_TEST(sscanf_test_int_neg_hex) {
  const char *input = "-0x7B";
  int expected = -123;
  int actual = 0;
  int original = sscanf(input, "%i", &expected);
  int s21_func = s21_sscanf(input, "%i", &actual);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(expected, actual);
}
END_TEST

START_TEST(sscanf_test_int_invalid) {
  const char *input = "abc";
  int expected = 0;
  int actual = 0;
  int original = sscanf(input, "%i", &expected);
  int s21_func = s21_sscanf(input, "%i", &actual);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(expected, actual);
}
END_TEST

START_TEST(sscanf_test_str_1) {
  char s1[100] = {'\0'};
  char s2[100] = {'\0'};
  char s3[100] = {'\0'};
  char s4[100] = {'\0'};

  char s5[100] = {'\0'};
  char s6[100] = {'\0'};
  char s7[100] = {'\0'};
  char s8[100] = {'\0'};

  const char str[] = "Aboba Floppa Keppa Shleppa Anuroba";
  const char fstr[] = "%s %s %s %s";

  int res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(sscanf_test_str_2) {
  const char *input = "  ";
  char buf[100] = {'\0'};
  int original = sscanf(input, "%2s", buf);
  int s21_func = s21_sscanf(input, "%2s", buf);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_str_3) {
  const char *input = "";
  char buf[100] = {'\0'};
  int original = sscanf(input, "%1s", buf);
  int s21_func = s21_sscanf(input, "%1s", buf);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_float_1) {
  char format[100] = "%f %f %f %f";
  char str[100] = "1.0 2.0 3.0 4.0";
  float o1 = 0, o2 = 0, o3 = 0, o4 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4);
  ck_assert_int_eq(original, s21_func);
  ck_assert_float_eq(o1, s1);
  ck_assert_float_eq(o2, s2);
  ck_assert_float_eq(o3, s3);
  ck_assert_float_eq(o4, s4);
}
END_TEST

START_TEST(sscanf_test_float_2) {
  char format[100] = "%f";
  char str[100] = "-123.456";
  float o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert_float_eq(o1, s1);
}
END_TEST

START_TEST(sscanf_test_float_3) {
  char format[100] = "%f";
  char str[100] = "+123.456";
  float o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert_float_eq(o1, s1);
}
END_TEST

START_TEST(sscanf_test_float_4) {
  char format[100] = "%f";
  char str[100] = "-.e";
  float o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert_float_eq(o1, s1);
}
END_TEST

START_TEST(sscanf_test_float_5) {
  char format[100] = "%f";
  char str[100] = "abc";
  float o1 = 0.0, s1 = 0.0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert_float_eq(o1, s1);
}
END_TEST

START_TEST(sscanf_test_float_6) {
  char format[100] = "%f";
  char str[100] = "+";
  float o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert_float_eq(o1, s1);
}
END_TEST

START_TEST(sscanf_test_float_7) {
  char format[100] = "%f";
  char str[100] = " -123.456";
  float o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert_float_eq(o1, s1);
}
END_TEST

START_TEST(sscanf_test_float_8) {
  char format[] = "%f %f %f %f %f %f";
  char str[] = "123.45e+6 -123.45e-6 +123.456 123.456 -123.45e+6 +123.456";
  float o1 = 0.0, o2 = 0.0, o3 = 0.0, o4 = 0.0, o5 = 0.0, o6 = 0.0, s1 = 0.0,
        s2 = 0.0, s3 = 0.0, s4 = 0.0, s5 = 0.0, s6 = 0.0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert(fabs(o1 - s1) < 1e-6);
  ck_assert(fabs(o2 - s2) < 1e-6);
  ck_assert(fabs(o3 - s3) < 1e-6);
  ck_assert(fabs(o4 - s4) < 1e-6);
  ck_assert(fabs(o5 - s5) < 1e-6);
  ck_assert(fabs(o6 - s6) < 1e-6);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_exp_float_1) {
  char format[100] = "%e";
  char str[100] = "+1.23e+10";
  float o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert_float_eq_tol(o1, s1, 1e-6);
}
END_TEST

START_TEST(sscanf_test_exp_float_2) {
  char format[100] = "%e";
  char str[100] = "-4.56e-2";
  float o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert_float_eq_tol(o1, s1, 1e-6);
}
END_TEST

START_TEST(sscanf_test_exp_float_3) {
  char format[100] = "%g";
  char str[100] = "7.89E+3";
  float o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert_float_eq_tol(o1, s1, 1E-6);
}
END_TEST

START_TEST(sscanf_test_exp_float_4) {
  char format[100] = "%e";
  char str[100] = "0.0e0";
  float o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert_float_eq_tol(o1, s1, 1e-6);
}
END_TEST

START_TEST(sscanf_test_exp_float_5) {
  char format[100] = "%E";
  char str[100] = "1.23E+10";
  float o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert_float_eq_tol(o1, s1, 1E-6);
}
END_TEST

START_TEST(sscanf_test_exp_float_6) {
  char format[100] = "%E";
  char str[100] = "-4.56E-2";
  float o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert_float_eq_tol(o1, s1, 1E-6);
}
END_TEST

START_TEST(sscanf_test_exp_float_7) {
  char format[100] = "%e";
  char str[100] = "7.89E-4";
  float o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert_float_eq_tol(o1, s1, 1e-6);
}
END_TEST

START_TEST(sscanf_test_exp_float_no_digits_1) {
  char format[] = "%e";
  char str[] = ".";
  float o1 = 0.0, s1 = 0.0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert_float_eq(o1, s1);
}
END_TEST

START_TEST(sscanf_test_exp_float_no_digits_2) {
  char format[] = "%e";
  char str[] = "e-2";
  float o1 = 0.0, s1 = 0.0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert_float_eq(o1, s1);
}
END_TEST

START_TEST(sscanf_test_g_float_1) {
  char format[] = "%g";
  char str[] = "123.456";
  float o1 = 0.0, s1 = 0.0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert(fabs(o1 - s1) < 1e-6);
}
END_TEST

START_TEST(sscanf_test_g_float_2) {
  char format[] = "%g";
  char str[] = "1.23e3";
  float o1 = 0.0, s1 = 0.0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert(fabs(o1 - s1) < 1e-6);
}
END_TEST

START_TEST(sscanf_test_g_float_3) {
  char format[] = "%g";
  char str[] = "123e-2";
  float o1 = 0.0, s1 = 0.0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert_float_eq(o1, s1);
}
END_TEST

START_TEST(sscanf_test_g_float_4) {
  char format[] = "%g";
  char str[] = ".";
  float o1 = 0.0, s1 = 0.0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert_float_eq(o1, s1);
}
END_TEST

START_TEST(sscanf_test_g_float_5) {
  char format[] = "%g";
  char str[] = "e-2";
  float o1 = 0.0, s1 = 0.0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert_float_eq(o1, s1);
}
END_TEST

START_TEST(sscanf_test_g_float_6) {
  char format[] = "%g";
  char str[] = "3.14e";
  float o1 = 0.0, s1 = 0.0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert(fabs(o1 - s1) < 1e-6);
  ck_assert_double_eq(o1, s1);
}
END_TEST

START_TEST(sscanf_test_g_float_7) {
  char format[] = "%G";
  char str[] = "1.23E3";
  float o1 = 0.0, s1 = 0.0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert(fabs(o1 - s1) < 1e-6);
}
END_TEST

START_TEST(sscanf_test_g_float_8) {
  char format[] = "%G";
  char str[] = "123.456";
  float o1 = 0.0, s1 = 0.0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert(fabs(o1 - s1) < 1e-6);
}
END_TEST

START_TEST(sscanf_test_g_float_9) {
  char format[] = "%g %g %g %g %g %g";
  char str[] = "123.45e+6 -123.45e-6 +123.456 123.456 -123.45e+6 +123.456";
  float o1 = 0.0, o2 = 0.0, o3 = 0.0, o4 = 0.0, o5 = 0.0, o6 = 0.0, s1 = 0.0,
        s2 = 0.0, s3 = 0.0, s4 = 0.0, s5 = 0.0, s6 = 0.0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert(fabs(o1 - s1) < 1e-6);
  ck_assert(fabs(o2 - s2) < 1e-6);
  ck_assert(fabs(o3 - s3) < 1e-6);
  ck_assert(fabs(o4 - s4) < 1e-6);
  ck_assert(fabs(o5 - s5) < 1e-6);
  ck_assert(fabs(o6 - s6) < 1e-6);
  ck_assert_ldouble_eq(o2, s2);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_char_1) {
  char format[100] = "%c";
  char str[100] = "a";
  char a, b;
  int original = sscanf(str, format, &a);
  int s21_func = s21_sscanf(str, format, &b);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_test_char_2) {
  const char *input = " A";
  char c;
  int original = sscanf(input, "%c", &c);
  int s21_func = s21_sscanf(input, "%c", &c);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_char_3) {
  char format[100] = "%c %c %c";
  char str[100] = "a b c";
  char o1, o2, o3, s1, s2, s3;
  int original = sscanf(str, format, &o1, &o2, &o3);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(o3, s3);
}
END_TEST

START_TEST(sscanf_test_char_4) {
  const char *input = "";
  char c;
  int original = sscanf(input, "%c", &c);
  int s21_func = s21_sscanf(input, "%c", &c);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_mismatch) {
  char format[100] = "%d %d";
  char str[100] = "1 a";
  int o1 = 0, o2 = 0, s1 = 0, s2 = 0;
  int original = sscanf(str, format, &o1, &o2);
  int s21_func = s21_sscanf(str, format, &s1, &s2);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_premature_end) {
  char format[100] = "%d %d";
  char str[100] = "1";
  int o1, o2 = -1, s1, s2 = -1;
  int original = sscanf(str, format, &o1, &o2);
  int s21_func = s21_sscanf(str, format, &s1, &s2);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_digits_width_1) {
  char format[100] = "%5d %2d";
  char str[100] = "1234567 123";
  int o1 = 0, o2 = 0, s1 = 0, s2 = 0;
  int original = sscanf(str, format, &o1, &o2);
  int s21_func = s21_sscanf(str, format, &s1, &s2);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_digits_width_2) {
  char format[100] = "%5d %2d";
  char str[100] = "-1234567 +123";
  int o1 = 0, o2 = 0, s1 = 0, s2 = 0;
  int original = sscanf(str, format, &o1, &o2);
  int s21_func = s21_sscanf(str, format, &s1, &s2);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_digits_width_3) {
  char format[100] = "%10d %10d";
  char str[100] = "+1234567 -123";
  int o1 = 0, o2 = 0, s1 = 0, s2 = 0;
  int original = sscanf(str, format, &o1, &o2);
  int s21_func = s21_sscanf(str, format, &s1, &s2);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_digits_width_4) {
  char format[100] = "%1d %1d";
  char str[100] = "-1234567 +123";
  int o1 = 0, o2 = 0, s1 = 0, s2 = 0;
  int original = sscanf(str, format, &o1, &o2);
  int s21_func = s21_sscanf(str, format, &s1, &s2);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
}
END_TEST

START_TEST(sscanf_test_digits_width_5) {
  char format[100] = "%1d %1d";
  char str[100] = "+1234567 -123";
  int o1 = 0, o2 = 0, s1 = 0, s2 = 0;
  int original = sscanf(str, format, &o1, &o2);
  int s21_func = s21_sscanf(str, format, &s1, &s2);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
}
END_TEST

START_TEST(sscanf_test_digits_width_6) {
  char format[100] = "%1d %1d";
  char str[100] = "+1234567 +123";
  int o1 = 0, o2 = 0, s1 = 0, s2 = 0;
  int original = sscanf(str, format, &o1, &o2);
  int s21_func = s21_sscanf(str, format, &s1, &s2);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
}
END_TEST

START_TEST(sscanf_test_digits_width_7) {
  char format[100] = "%1d %1d";
  char str[100] = "-1234567 -123";
  int o1 = 0, o2 = 0, s1 = 0, s2 = 0;
  int original = sscanf(str, format, &o1, &o2);
  int s21_func = s21_sscanf(str, format, &s1, &s2);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_digits_width_8) {
  char format[100] = "%1d";
  char str[100] = "+1234567";
  int o1 = 0, o2 = 0, s1 = 0, s2 = 0;
  int original = sscanf(str, format, &o1, &o2);
  int s21_func = s21_sscanf(str, format, &s1, &s2);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_digits_width_9) {
  char format[100] = "%1d";
  char str[100] = "-1234567";
  int o1 = 0, o2 = 0, s1 = 0, s2 = 0;
  int original = sscanf(str, format, &o1, &o2);
  int s21_func = s21_sscanf(str, format, &s1, &s2);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_strings_width_1) {
  char s1[100] = {'\0'};
  char s2[100] = {'\0'};
  char s3[100] = {'\0'};
  char s4[100] = {'\0'};
  char s5[100] = {'\0'};

  char s6[100] = {'\0'};
  char s7[100] = {'\0'};
  char s8[100] = {'\0'};
  char s9[100] = {'\0'};
  char s10[100] = {'\0'};

  char str[] = "Lorem ipsum dolor sit amet";
  char fstr[] = "%4s %3s %2s %1s %s";

  int res1 = sscanf(str, fstr, s1, s2, s3, s4, s5);
  int res2 = s21_sscanf(str, fstr, s6, s7, s8, s9, s10);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s6);
  ck_assert_str_eq(s2, s7);
  ck_assert_str_eq(s3, s8);
  ck_assert_str_eq(s4, s9);
  ck_assert_str_eq(s5, s10);
}
END_TEST

START_TEST(sscanf_test_strings_width_2) {
  char s1[100] = {'\0'};
  char s2[100] = {'\0'};
  char s3[100] = {'\0'};
  char s4[100] = {'\0'};
  char s5[100] = {'\0'};

  char s6[100] = {'\0'};
  char s7[100] = {'\0'};
  char s8[100] = {'\0'};
  char s9[100] = {'\0'};
  char s10[100] = {'\0'};

  char str[] = "Lorem ipsum dolor sit amet";
  char fstr[] = "%1s %s %5s %10s %20s";

  int res1 = sscanf(str, fstr, s1, s2, s3, s4, s5);
  int res2 = s21_sscanf(str, fstr, s6, s7, s8, s9, s10);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s6);
  ck_assert_str_eq(s2, s7);
  ck_assert_str_eq(s3, s8);
  ck_assert_str_eq(s4, s9);
  ck_assert_str_eq(s5, s10);
}
END_TEST

START_TEST(sscanf_test_strings_width_3) {
  char s1[100] = {'\0'};
  char s2[100] = {'\0'};
  char s3[100] = {'\0'};
  char s4[100] = {'\0'};
  char s5[100] = {'\0'};

  char s6[100] = {'\0'};
  char s7[100] = {'\0'};
  char s8[100] = {'\0'};
  char s9[100] = {'\0'};
  char s10[100] = {'\0'};

  char str[] = "0Lorem 1ipsum 2dolor 3sit 4amet";
  char fstr[] = "%2s %2s %2s %2s %2s";

  int res1 = sscanf(str, fstr, s1, s2, s3, s4, s5);
  int res2 = s21_sscanf(str, fstr, s6, s7, s8, s9, s10);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s6);
  ck_assert_str_eq(s2, s7);
  ck_assert_str_eq(s3, s8);
  ck_assert_str_eq(s4, s9);
  ck_assert_str_eq(s5, s10);
}
END_TEST

START_TEST(sscanf_test_float_width_1) {
  char format[100] = "%1f %2f %3f %4f";
  char str[100] = "11.0 12.0 13.0 14.0";
  float o1 = 0, o2 = 0, o3 = 0, o4 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4);
  ck_assert_float_eq(o1, s1);
  ck_assert_float_eq(o2, s2);
  ck_assert_float_eq(o4, s4);
  ck_assert_float_eq(o3, s3);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_float_width_2) {
  char format[100] = "%10f";
  char str[100] = "-123.456";
  float o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_float_eq(o1, s1);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_float_width_3) {
  char format[100] = "%10f";
  char str[100] = "+123.456";
  float o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_float_eq(o1, s1);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_float_width_4) {
  char format[100] = "%1f";
  char str[100] = "-123.456";
  float o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_float_eq(o1, s1);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_float_width_5) {
  char format[100] = "%1f";
  char str[100] = "+123.456";
  float o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_float_eq(o1, s1);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_float_width_6) {
  char format[100] = "%3f";
  char str[100] = "+123.456";
  float o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_float_eq(o1, s1);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_float_width_7) {
  char format[100] = "%4f";
  char str[100] = "-123.456";
  float o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_float_eq(o1, s1);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_float_width_8) {
  char format[100] = "%5f";
  char str[100] = "-123.456";
  float o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert_float_eq(o1, s1);
}
END_TEST

START_TEST(sscanf_test_float_width_9) {
  char format[100] = "%2f";
  char str[100] = "-123.456";
  float o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_float_eq(o1, s1);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_float_width_10) {
  char format[100] = "%6f";
  char str[100] = "-123.456";
  float o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_float_eq(o1, s1);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_float_width_11) {
  char format[100] = "%4f";
  char str[100] = "+123.456";
  float o1 = 0, s1 = 0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_float_eq(o1, s1);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_float_width_12) {
  char format[] = "%3f %3f %3f %4f %4f %4f";
  char str[] = "123.45e+6 -123.45e-6 +123.456 123.456 -123.45e+6 +123.456";
  float o1 = 0.0, o2 = 0.0, o3 = 0.0, o4 = 0.0, o5 = 0.0, o6 = 0.0, s1 = 0.0,
        s2 = 0.0, s3 = 0.0, s4 = 0.0, s5 = 0.0, s6 = 0.0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert(fabs(o1 - s1) < 1e-6);
  ck_assert(fabs(o2 - s2) < 1e-6);
  ck_assert(fabs(o3 - s3) < 1e-6);
  ck_assert(fabs(o4 - s4) < 1e-6);
  ck_assert(fabs(o5 - s5) < 1e-6);
  ck_assert(fabs(o6 - s6) < 1e-6);
  ck_assert_ldouble_eq(o2, s2);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_float_width_13) {
  char format[] = "%2f %1f %5f %3f %4f %4f";
  char str[] = "123.45e+6 -123.45e-6 +123.456 123.456 -123.45e+6 +123.456";
  float o1 = 0.0, o2 = 0.0, o3 = 0.0, o4 = 0.0, o5 = 0.0, o6 = 0.0, s1 = 0.0,
        s2 = 0.0, s3 = 0.0, s4 = 0.0, s5 = 0.0, s6 = 0.0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert(fabs(o1 - s1) < 1e-6);
  ck_assert(fabs(o2 - s2) < 1e-6);
  ck_assert(fabs(o3 - s3) < 1e-6);
  ck_assert(fabs(o4 - s4) < 1e-6);
  ck_assert(fabs(o5 - s5) < 1e-6);
  ck_assert(fabs(o6 - s6) < 1e-6);
  ck_assert_ldouble_eq(o2, s2);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_float_width_14) {
  char format[] = "%f %f %f %f %f %f";
  char str[] = "123.45e+6 -123.45e-6 +123.456 123.456 -123.45e+6 +123.456";
  float o1 = 0.0, o2 = 0.0, o3 = 0.0, o4 = 0.0, o5 = 0.0, o6 = 0.0, s1 = 0.0,
        s2 = 0.0, s3 = 0.0, s4 = 0.0, s5 = 0.0, s6 = 0.0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert(fabs(o1 - s1) < 1e-6);
  ck_assert(fabs(o2 - s2) < 1e-6);
  ck_assert(fabs(o3 - s3) < 1e-6);
  ck_assert(fabs(o4 - s4) < 1e-6);
  ck_assert(fabs(o5 - s5) < 1e-6);
  ck_assert(fabs(o6 - s6) < 1e-6);
  ck_assert_ldouble_eq(o2, s2);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_ptr_1) {
  char format[100] = "%p %p %p %p";
  char input[100] = "0x7ffe0ade 0x55fc8f96 0x91fde22d 0x23ff6d2f";
  unsigned int *o1 = 0, *o2 = 0, *o3 = 0, *o4 = 0, *s1 = 0, *s2 = 0, *s3 = 0,
               *s4 = 0;
  int original = sscanf(input, format, &o1, &o2, &o3, &o4);
  int s21_func = s21_sscanf(input, format, &s1, &s2, &s3, &s4);
  ck_assert_ptr_eq(o1, s1);
  ck_assert_ptr_eq(o2, s2);
  ck_assert_ptr_eq(o3, s3);
  ck_assert_ptr_eq(o4, s4);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_g_float_width_1) {
  char format[] = "%3g";
  char str[] = "123.456";
  float o1 = 0.0, s1 = 0.0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert(fabs(o1 - s1) < 1e-6);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_g_float_width_2) {
  char format[] = "%3g %3g %3g %4g %4g %4g";
  char str[] = "123.45e+6 -123.45e-6 +123.456 123.456 -123.45e+6 +123.456";
  float o1 = 0.0, o2 = 0.0, o3 = 0.0, o4 = 0.0, o5 = 0.0, o6 = 0.0, s1 = 0.0,
        s2 = 0.0, s3 = 0.0, s4 = 0.0, s5 = 0.0, s6 = 0.0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert(fabs(o1 - s1) < 1e-6);
  ck_assert(fabs(o2 - s2) < 1e-6);
  ck_assert(fabs(o3 - s3) < 1e-6);
  ck_assert(fabs(o4 - s4) < 1e-6);
  ck_assert(fabs(o5 - s5) < 1e-6);
  ck_assert(fabs(o6 - s6) < 1e-6);
  ck_assert_ldouble_eq(o2, s2);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_g_float_width_3) {
  char format[] = "%2g %1g %5g %3g %4g %4g";
  char str[] = "123.45e+6 -123.45e-6 +123.456 123.456 -123.45e+6 +123.456";
  float o1 = 0.0, o2 = 0.0, o3 = 0.0, o4 = 0.0, o5 = 0.0, o6 = 0.0, s1 = 0.0,
        s2 = 0.0, s3 = 0.0, s4 = 0.0, s5 = 0.0, s6 = 0.0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert(fabs(o1 - s1) < 1e-6);
  ck_assert(fabs(o2 - s2) < 1e-6);
  ck_assert(fabs(o3 - s3) < 1e-6);
  ck_assert(fabs(o4 - s4) < 1e-6);
  ck_assert(fabs(o5 - s5) < 1e-6);
  ck_assert(fabs(o6 - s6) < 1e-6);
  ck_assert_ldouble_eq(o2, s2);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_g_float_width_4) {
  char format[] = "%1g %1g %1g %1g %1g %1g";
  char str[] = "123.45e+6 -123.45e-6 +123.456 123.456 -123.45e+6 +123.456";
  float o1 = 0.0, o2 = 0.0, o3 = 0.0, o4 = 0.0, o5 = 0.0, o6 = 0.0, s1 = 0.0,
        s2 = 0.0, s3 = 0.0, s4 = 0.0, s5 = 0.0, s6 = 0.0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert(fabs(o1 - s1) < 1e-6);
  ck_assert(fabs(o2 - s2) < 1e-6);
  ck_assert(fabs(o3 - s3) < 1e-6);
  ck_assert(fabs(o4 - s4) < 1e-6);
  ck_assert(fabs(o5 - s5) < 1e-6);
  ck_assert(fabs(o6 - s6) < 1e-6);
  ck_assert_ldouble_eq(o2, s2);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_g_float_width_5) {
  char format[] = "%2g %2g %2g %2g %2g %2g";
  char str[] = "123.45e+6 -123.45e-6 +123.456 123.456 -123.45e+6 +123.456";
  float o1 = 0.0, o2 = 0.0, o3 = 0.0, o4 = 0.0, o5 = 0.0, o6 = 0.0, s1 = 0.0,
        s2 = 0.0, s3 = 0.0, s4 = 0.0, s5 = 0.0, s6 = 0.0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert(fabs(o1 - s1) < 1e-6);
  ck_assert(fabs(o2 - s2) < 1e-6);
  ck_assert(fabs(o3 - s3) < 1e-6);
  ck_assert(fabs(o4 - s4) < 1e-6);
  ck_assert(fabs(o5 - s5) < 1e-6);
  ck_assert(fabs(o6 - s6) < 1e-6);
  ck_assert_ldouble_eq(o2, s2);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_g_float_width_6) {
  char format[] = "%10g %10g %10g %10g %10g %10g";
  char str[] = "123.45e+6 -123.45e-6 +123.456 123.456 -123.45e+6 +123.456";
  float o1 = 0.0, o2 = 0.0, o3 = 0.0, o4 = 0.0, o5 = 0.0, o6 = 0.0, s1 = 0.0,
        s2 = 0.0, s3 = 0.0, s4 = 0.0, s5 = 0.0, s6 = 0.0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert(fabs(o1 - s1) < 1e-6);
  ck_assert(fabs(o2 - s2) < 1e-6);
  ck_assert(fabs(o3 - s3) < 1e-6);
  ck_assert(fabs(o4 - s4) < 1e-6);
  ck_assert(fabs(o5 - s5) < 1e-6);
  ck_assert(fabs(o6 - s6) < 1e-6);
  ck_assert_ldouble_eq(o2, s2);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_e_float_width_1) {
  char format[] = "%3e";
  char str[] = "123.456";
  float o1 = 0.0, s1 = 0.0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert(fabs(o1 - s1) < 1e-6);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_e_float_width_2) {
  char format[] = "%3e %3e %3e %4e %4e %4e";
  char str[] = "123.45e+6 -123.45e-6 +123.456 123.456 -123.45e+6 +123.456";
  float o1 = 0.0, o2 = 0.0, o3 = 0.0, o4 = 0.0, o5 = 0.0, o6 = 0.0, s1 = 0.0,
        s2 = 0.0, s3 = 0.0, s4 = 0.0, s5 = 0.0, s6 = 0.0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert(fabs(o1 - s1) < 1e-6);
  ck_assert(fabs(o2 - s2) < 1e-6);
  ck_assert(fabs(o3 - s3) < 1e-6);
  ck_assert(fabs(o4 - s4) < 1e-6);
  ck_assert(fabs(o5 - s5) < 1e-6);
  ck_assert(fabs(o6 - s6) < 1e-6);
  ck_assert_ldouble_eq(o2, s2);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_e_float_width_3) {
  char format[] = "%2e %1e %5e %3e %4e %4e";
  char str[] = "123.45e+6 -123.45e-6 +123.456 123.456 -123.45e+6 +123.456";
  float o1 = 0.0, o2 = 0.0, o3 = 0.0, o4 = 0.0, o5 = 0.0, o6 = 0.0, s1 = 0.0,
        s2 = 0.0, s3 = 0.0, s4 = 0.0, s5 = 0.0, s6 = 0.0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert(fabs(o1 - s1) < 1e-6);
  ck_assert(fabs(o2 - s2) < 1e-6);
  ck_assert(fabs(o3 - s3) < 1e-6);
  ck_assert(fabs(o4 - s4) < 1e-6);
  ck_assert(fabs(o5 - s5) < 1e-6);
  ck_assert(fabs(o6 - s6) < 1e-6);
  ck_assert_ldouble_eq(o2, s2);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_e_float_width_4) {
  char format[] = "%1e %1e %1e %1e %1e %1e";
  char str[] = "123.45e+6 -123.45e-6 +123.456 123.456 -123.45e+6 +123.456";
  float o1 = 0.0, o2 = 0.0, o3 = 0.0, o4 = 0.0, o5 = 0.0, o6 = 0.0, s1 = 0.0,
        s2 = 0.0, s3 = 0.0, s4 = 0.0, s5 = 0.0, s6 = 0.0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert(fabs(o1 - s1) < 1e-6);
  ck_assert(fabs(o2 - s2) < 1e-6);
  ck_assert(fabs(o3 - s3) < 1e-6);
  ck_assert(fabs(o4 - s4) < 1e-6);
  ck_assert(fabs(o5 - s5) < 1e-6);
  ck_assert(fabs(o6 - s6) < 1e-6);
  ck_assert_ldouble_eq(o2, s2);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_e_float_width_5) {
  char format[] = "%2e %2e %2e %2e %2e %2e";
  char str[] = "123.45e+6 -123.45e-6 +123.456 123.456 -123.45e+6 +123.456";
  float o1 = 0.0, o2 = 0.0, o3 = 0.0, o4 = 0.0, o5 = 0.0, o6 = 0.0, s1 = 0.0,
        s2 = 0.0, s3 = 0.0, s4 = 0.0, s5 = 0.0, s6 = 0.0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert(fabs(o1 - s1) < 1e-6);
  ck_assert(fabs(o2 - s2) < 1e-6);
  ck_assert(fabs(o3 - s3) < 1e-6);
  ck_assert(fabs(o4 - s4) < 1e-6);
  ck_assert(fabs(o5 - s5) < 1e-6);
  ck_assert(fabs(o6 - s6) < 1e-6);
  ck_assert_ldouble_eq(o2, s2);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_e_float_width_6) {
  const char format[] = "%10e %10e %10e %10e %10e %10e";
  const char str[] =
      "123.45e+6 -123.45e-6 +123.456 123.456 -123.45e+6 +123.456";
  float o1 = 0.0, o2 = 0.0, o3 = 0.0, o4 = 0.0, o5 = 0.0, o6 = 0.0, s1 = 0.0,
        s2 = 0.0, s3 = 0.0, s4 = 0.0, s5 = 0.0, s6 = 0.0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert(fabs(o1 - s1) < 1e-6);
  ck_assert(fabs(o2 - s2) < 1e-6);
  ck_assert(fabs(o3 - s3) < 1e-6);
  ck_assert(fabs(o4 - s4) < 1e-6);
  ck_assert(fabs(o5 - s5) < 1e-6);
  ck_assert(fabs(o6 - s6) < 1e-6);
  ck_assert_ldouble_eq(o2, s2);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_e_double_width) {
  const char format[] = "%10le %10le %10le %10le %10le %10le";
  const char str[] =
      "123.45e+6 -123.45e-6 +123.456 123.456 -123.45e+6 +123.456";
  double o1 = 0.0, o2 = 0.0, o3 = 0.0, o4 = 0.0, o5 = 0.0, o6 = 0.0, s1 = 0.0,
         s2 = 0.0, s3 = 0.0, s4 = 0.0, s5 = 0.0, s6 = 0.0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert(fabs(o1 - s1) < 1e-6);
  ck_assert(fabs(o2 - s2) < 1e-6);
  ck_assert(fabs(o3 - s3) < 1e-6);
  ck_assert(fabs(o4 - s4) < 1e-6);
  ck_assert(fabs(o5 - s5) < 1e-6);
  ck_assert(fabs(o6 - s6) < 1e-6);
  ck_assert_ldouble_eq(o2, s2);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_unsigned_short) {
  const char format[] = "%hu %hu %hu %hu %hu %hu";
  const char str[] = "65534 -1 0 65535 65536 -1024";
  unsigned short o1 = 0, o2 = 0, o3 = 0, o4 = 0, o5 = 0, o6 = 0, s1 = 0, s2 = 0,
                 s3 = 0, s4 = 0, s5 = 0, s6 = 0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert_uint_eq(o1, s1);
  ck_assert_uint_eq(o2, s2);
  ck_assert_uint_eq(o3, s3);
  ck_assert_uint_eq(o4, s4);
  ck_assert_uint_eq(o5, s5);
  ck_assert_uint_eq(o6, s6);
  ck_assert_uint_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_unsigned_short_width_1) {
  const char format[] = "%1hu %2hu %3hu %4hu %5hu %6hu";
  const char str[] = "65534 -1 0 65535 65536 -1024";
  unsigned short o1 = 0, o2 = 0, o3 = 0, o4 = 0, o5 = 0, o6 = 0, s1 = 0, s2 = 0,
                 s3 = 0, s4 = 0, s5 = 0, s6 = 0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert_uint_eq(o1, s1);
  ck_assert_uint_eq(o2, s2);
  ck_assert_uint_eq(o3, s3);
  ck_assert_uint_eq(o4, s4);
  ck_assert_uint_eq(o5, s5);
  ck_assert_uint_eq(o6, s6);
  ck_assert_uint_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_unsigned_short_width_2) {
  const char format[] = "%1hu %1hu %1hu %1hu %1hu %1hu";
  const char str[] = "65534 -1 0 65535 65536 -1024";
  unsigned short o1 = 0, o2 = 0, o3 = 0, o4 = 0, o5 = 0, o6 = 0, s1 = 0, s2 = 0,
                 s3 = 0, s4 = 0, s5 = 0, s6 = 0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert_uint_eq(o1, s1);
  ck_assert_uint_eq(o2, s2);
  ck_assert_uint_eq(o3, s3);
  ck_assert_uint_eq(o4, s4);
  ck_assert_uint_eq(o5, s5);
  ck_assert_uint_eq(o6, s6);
  ck_assert_uint_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_unsigned_short_width_3) {
  const char format[] = "%10hu %10hu %10hu %10hu %10hu %10hu";
  const char str[] = "65534 -1 0 65535 65536 -1024";
  unsigned short o1 = 0, o2 = 0, o3 = 0, o4 = 0, o5 = 0, o6 = 0, s1 = 0, s2 = 0,
                 s3 = 0, s4 = 0, s5 = 0, s6 = 0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert_uint_eq(o1, s1);
  ck_assert_uint_eq(o2, s2);
  ck_assert_uint_eq(o3, s3);
  ck_assert_uint_eq(o4, s4);
  ck_assert_uint_eq(o5, s5);
  ck_assert_uint_eq(o6, s6);
  ck_assert_uint_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_unsigned_long_width_1) {
  const char format[] = "%6lu %5lu %4lu %3lu %2lu %1lu";
  const char str[] =
      "28446744073709551615 -1 0 18446744073709551614 18446744073709551616 "
      "-1024";
  unsigned long int o1 = 0, o2 = 0, o3 = 0, o4 = 0, o5 = 0, o6 = 0, s1 = 0,
                    s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert_uint_eq(o1, s1);
  ck_assert_uint_eq(o2, s2);
  ck_assert_uint_eq(o3, s3);
  ck_assert_uint_eq(o4, s4);
  ck_assert_uint_eq(o5, s5);
  ck_assert_uint_eq(o6, s6);
  ck_assert_uint_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_unsigned_long_width_2) {
  const char format[] = "%1lu %1lu %1lu %1lu %1lu %1lu";
  const char str[] =
      "28446744073709551615 -1 0 18446744073709551614 18446744073709551616 "
      "-1024";
  unsigned long int o1 = 0, o2 = 0, o3 = 0, o4 = 0, o5 = 0, o6 = 0, s1 = 0,
                    s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert_uint_eq(o2, s2);
  ck_assert_uint_eq(o3, s3);
  ck_assert_uint_eq(o4, s4);
  ck_assert_uint_eq(o6, s6);
  ck_assert_uint_eq(o5, s5);
  ck_assert_uint_eq(o1, s1);
  ck_assert_uint_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_unsigned_long_long_width_1) {
  const char format[] = "%6llu %5llu %4llu %3llu %2llu %1llu";
  const char str[] =
      "28446744073709551615 -1 0 18446744073709551614 18446744073709551616 "
      "-1024";
  unsigned long long int o1 = 0, o2 = 0, o3 = 0, o4 = 0, o5 = 0, o6 = 0, s1 = 0,
                         s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert_uint_eq(o1, s1);
  ck_assert_uint_eq(o2, s2);
  ck_assert_uint_eq(o3, s3);
  ck_assert_uint_eq(o4, s4);
  ck_assert_uint_eq(o5, s5);
  ck_assert_uint_eq(o6, s6);
  ck_assert_uint_eq(original, s21_func);
}
END_TEST
START_TEST(sscanf_test_unsigned_long_long_width_2) {
  const char format[] = "%1llu %1llu %1llu %1llu %1llu %1llu";
  const char str[] =
      "28446744073709551615 -1 0 18446744073709551614 18446744073709551616 "
      "-1024";
  unsigned long long int o1 = 0, o2 = 0, o3 = 0, o4 = 0, o5 = 0, o6 = 0, s1 = 0,
                         s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert_uint_eq(o1, s1);
  ck_assert_uint_eq(o2, s2);
  ck_assert_uint_eq(o3, s3);
  ck_assert_uint_eq(o4, s4);
  ck_assert_uint_eq(o5, s5);
  ck_assert_uint_eq(o6, s6);
  ck_assert_uint_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_signed_short) {
  const char format[] = "%hd %hd %hd %hd %hd %hd";
  const char str[] = "32767 -1 0 65535 -32768 -1024";
  short o1 = 0, o2 = 0, o3 = 0, o4 = 0, o5 = 0, o6 = 0, s1 = 0, s2 = 0, s3 = 0,
        s4 = 0, s5 = 0, s6 = 0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(o3, s3);
  ck_assert_int_eq(o4, s4);
  ck_assert_int_eq(o5, s5);
  ck_assert_int_eq(o6, s6);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_signed_short_width_1) {
  const char format[] = "%1hd %1hd %1hd %1hd %1hd %1hd";
  const char str[] = "32767 -1 0 65535 -32768 -1024";
  short o1 = 0, o2 = 0, o3 = 0, o4 = 0, o5 = 0, o6 = 0, s1 = 0, s2 = 0, s3 = 0,
        s4 = 0, s5 = 0, s6 = 0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(o3, s3);
  ck_assert_int_eq(o4, s4);
  ck_assert_int_eq(o5, s5);
  ck_assert_int_eq(o6, s6);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_signed_short_width_2) {
  const char format[] = "%6hd %5hd %4hd %3hd %2hd %1hd";
  const char str[] = "32767 -1 0 65535 -32768 -1024";
  short o1 = 0, o2 = 0, o3 = 0, o4 = 0, o5 = 0, o6 = 0, s1 = 0, s2 = 0, s3 = 0,
        s4 = 0, s5 = 0, s6 = 0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(o3, s3);
  ck_assert_int_eq(o4, s4);
  ck_assert_int_eq(o5, s5);
  ck_assert_int_eq(o6, s6);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_signed_short_width_3) {
  const char format[] = "%20hd %20hd %20hd %20hd %20hd %20hd";
  const char str[] = "32767 -1 0 65535 -32768 -1024";
  short o1 = 0, o2 = 0, o3 = 0, o4 = 0, o5 = 0, o6 = 0, s1 = 0, s2 = 0, s3 = 0,
        s4 = 0, s5 = 0, s6 = 0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(o3, s3);
  ck_assert_int_eq(o4, s4);
  ck_assert_int_eq(o5, s5);
  ck_assert_int_eq(o6, s6);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_signed_long) {
  const char format[] = "%ld %ld %ld %ld %ld %ld";
  const char str[] =
      "9223372036854775807 -1 0 9223372036854775808 -9223372036854775808 -1024";
  long int o1 = 0, o2 = 0, o3 = 0, o4 = 0, o5 = 0, o6 = 0, s1 = 0, s2 = 0,
           s3 = 0, s4 = 0, s5 = 0, s6 = 0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(o3, s3);
  ck_assert_int_eq(o5, s5);
  ck_assert_int_eq(o6, s6);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o4, s4);
}
END_TEST

START_TEST(sscanf_test_signed_long_width_1) {
  const char format[] = "%6ld %5ld %4ld %3ld %2ld %1ld";
  const char str[] =
      "9223372036854775807 -1 0 9223372036854775808 -9223372036854775808 -1024";
  long int o1 = 0, o2 = 0, o3 = 0, o4 = 0, o5 = 0, o6 = 0, s1 = 0, s2 = 0,
           s3 = 0, s4 = 0, s5 = 0, s6 = 0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(o3, s3);
  ck_assert_int_eq(o4, s4);
  ck_assert_int_eq(o5, s5);
  ck_assert_int_eq(o6, s6);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_signed_long_width_2) {
  const char format[] = "%1ld %1ld %1ld %1ld %1ld %1ld";
  const char str[] =
      "9223372036854775807 -1 0 9223372036854775808 -9223372036854775808 -1024";
  long int o1 = 0, o2 = 0, o3 = 0, o4 = 0, o5 = 0, o6 = 0, s1 = 0, s2 = 0,
           s3 = 0, s4 = 0, s5 = 0, s6 = 0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(o3, s3);
  ck_assert_int_eq(o4, s4);
  ck_assert_int_eq(o5, s5);
  ck_assert_int_eq(o6, s6);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_signed_long_width_3) {
  const char format[] = "%30ld %30ld %30ld %25ld %30ld %30ld";
  const char str[] =
      "9223372036854775807 -1 0 9223372036854775810 -9223372036854775808 -1024";
  long int o1 = 0, o2 = 0, o3 = 0, o4 = 0, o5 = 0, o6 = 0, s1 = 0, s2 = 0,
           s3 = 0, s4 = 0, s5 = 0, s6 = 0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(o3, s3);
  ck_assert_int_eq(o4, s4);
  ck_assert_int_eq(o5, s5);
  ck_assert_int_eq(o6, s6);
}
END_TEST

START_TEST(sscanf_test_signed_long_long) {
  const char format[] = "%lld %lld %lld %lld %lld %lld";
  const char str[] =
      "9223372036854775807 -1 0 9223372036854775810 -9223372036854775808 -1024";
  long long int o1 = 0, o2 = 0, o3 = 0, o4 = 0, o5 = 0, o6 = 0, s1 = 0, s2 = 0,
                s3 = 0, s4 = 0, s5 = 0, s6 = 0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(o3, s3);
  ck_assert_int_eq(o4, s4);
  ck_assert_int_eq(o5, s5);
  ck_assert_int_eq(o6, s6);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_unsigned_short_octal_width_1) {
  const char format[] = "%1ho %2ho %3ho %4ho %5ho %6ho";
  const char str[] = "077777 -01 0 077778 -077777 -01024";
  unsigned short o1 = 0, o2 = 0, o3 = 0, o4 = 0, o5 = 0, o6 = 0, s1 = 0, s2 = 0,
                 s3 = 0, s4 = 0, s5 = 0, s6 = 0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(o3, s3);
  ck_assert_int_eq(o4, s4);
  ck_assert_int_eq(o5, s5);
  ck_assert_int_eq(o6, s6);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_unsigned_short_octal_width_2) {
  const char format[] = "%1ho %1ho %1ho %1ho %1ho %1ho";
  const char str[] = "077777 -01 0 077778 -077777 -01024";
  unsigned short o1 = 0, o2 = 0, o3 = 0, o4 = 0, o5 = 0, o6 = 0, s1 = 0, s2 = 0,
                 s3 = 0, s4 = 0, s5 = 0, s6 = 0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(o3, s3);
  ck_assert_int_eq(o4, s4);
  ck_assert_int_eq(o5, s5);
  ck_assert_int_eq(o6, s6);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_test_unsigned_short_octal_width_3) {
  const char format[] = "%10ho %10ho %10ho %10ho %10ho %10ho";
  const char str[] = "077777 -01 0 077778 -077777 -01024";
  unsigned short o1 = 0, o2 = 0, o3 = 0, o4 = 0, o5 = 0, o6 = 0, s1 = 0, s2 = 0,
                 s3 = 0, s4 = 0, s5 = 0, s6 = 0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(o3, s3);
  ck_assert_int_eq(o5, s5);
  ck_assert_int_eq(o6, s6);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o4, s4);
}
END_TEST

START_TEST(sscanf_test_unsigned_short_hex) {
  const char format[] = "%hx %hX %hx %hX %hx %hX";
  const char str[] = "0x7FFF -0X1 0x0 0X8001 0x7FFF -0x400";
  unsigned short o1 = 0, o2 = 0, o3 = 0, o4 = 0, o5 = 0, o6 = 0, s1 = 0, s2 = 0,
                 s3 = 0, s4 = 0, s5 = 0, s6 = 0;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4, &o5, &o6);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4, &s5, &s6);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(o3, s3);
  ck_assert_int_eq(o4, s4);
  ck_assert_int_eq(o5, s5);
  ck_assert_int_eq(o6, s6);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

// START_TEST(sscanf_test_n_spec_1) {
//   char format[100] = "%d %d %n";
//   char str[100] = "45 12";
//   int o1 = 0, o2 = 0, o3 = 0, s1 = 0, s2 = 0, s3 = 0;
//   int original = sscanf(str, format, &o1, &o2, &o3);
//   int s21_func = s21_sscanf(str, format, &s1, &s2, &s3);
//   ck_assert_int_eq(original, s21_func);
//   ck_assert_int_eq(o1, s1);
//   ck_assert_int_eq(o2, s2);
//   ck_assert_int_eq(o3, s3);
// }
// END_TEST

START_TEST(test_s21_sscanf_overflow_handling) {
  const char format[] = "%llu";
  const char str[] = "18446744073709551615";
  unsigned long long o1 = 0;
  int original = sscanf(str, format, &o1);
  unsigned long long s1 = 0;
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(original, s21_func);

  const char str_overflow[] = "18446744073709551616";
  unsigned long long o2 = 0;
  original = sscanf(str_overflow, format, &o2);
  unsigned long long s2 = 0;
  int s21_func_overflow = s21_sscanf(str_overflow, format, &s2);
  ck_assert_int_eq(ULLONG_MAX, s2);
  ck_assert_int_eq(0, s21_func_overflow);
}
END_TEST

START_TEST(test_s21_sscanf_signed_overflow_handling) {
  const char format[] = "%lld";
  const char str_overflow[] = "-9223372036854775809";
  long long int o1 = 0, s1 = 0;

  int original = sscanf(str_overflow, format, &o1);
  int s21_func = s21_sscanf(str_overflow, format, &s1);
  ck_assert_int_eq(o1, LLONG_MIN);
  ck_assert_int_eq(s1, LLONG_MIN);
  ck_assert_int_eq(original, 1);
  ck_assert_int_eq(s21_func, 1);
}
END_TEST

START_TEST(test_s21_sscanf_long_double_negative_conversion) {
  const char format[] = "%Lf";
  const char str[] = "-12345.6789";
  long double o1 = 0.0, s1 = 0.0;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_ldouble_eq(o1, s1);
  ck_assert_int_eq(original, 1);
  ck_assert_int_eq(s21_func, 1);
}
END_TEST

START_TEST(octal_star) {
  const char str[] = "521561612";
  const char fstr[] = "%*o";
  uint32_t s21_func = s21_sscanf(str, fstr);
  uint32_t original = sscanf(str, fstr);
  ck_assert_int_eq(s21_func, original);
}
END_TEST

START_TEST(test_s21_sscanf_suppress_assignment) {
  const char format[] = "%*d";
  const char str[] = "12345";
  int original = sscanf(str, format);
  int s21_func = s21_sscanf(str, format);
  ck_assert_int_eq(original, 0);
  ck_assert_int_eq(s21_func, 0);
}
END_TEST

START_TEST(test_s21_sscanf_suppress_assignment_digit) {
  const char format[] = "%*d";
  const char str[] = "12345";
  int original = sscanf(str, format);
  int s21_func = s21_sscanf(str, format);
  ck_assert_int_eq(original, 0);
  ck_assert_int_eq(s21_func, 0);
}
END_TEST

START_TEST(test_s21_sscanf_suppress_assignment_float) {
  const char format[] = "%*f";
  const char str[] = "456.78";
  int original = sscanf(str, format);
  int s21_func = s21_sscanf(str, format);
  ck_assert_int_eq(original, 0);
  ck_assert_int_eq(s21_func, 0);
}
END_TEST

START_TEST(test_s21_sscanf_suppress_assignment_string) {
  const char format[] = "%s %*d";
  const char str[] = "Hello, World! 123";
  char s1[50];
  int original = sscanf(str, format, s1);
  int s21_func = s21_sscanf(str, format, s1);
  ck_assert_int_eq(original, 1);
  ck_assert_int_eq(s21_func, 1);
}
END_TEST

START_TEST(docker_telegram_test_1) {
  const char format[] = "int: %d, char: %c, int int %d%*c%d";
  const char str[] = "int: 18753, char: W, int int 27/3";
  int io1 = 0, io2 = 0, io3 = 0, is1 = 0, is2 = 0, is3 = 0;
  char co = 0, cs = 0;
  int original = sscanf(str, format, &io1, &co, &io2, &io3);
  int s21_func = s21_sscanf(str, format, &is1, &cs, &is2, &is3);
  ck_assert_int_eq(io1, is1);
  ck_assert_int_eq(io2, is2);
  ck_assert_int_eq(io3, is3);
  ck_assert_int_eq(co, cs);
  ck_assert_int_eq(original, s21_func);
}
END_TEST

START_TEST(sscanf_n1) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int32_t n1 = 0, n2 = 5;

  const char str[100] = "50 160 70 80";
  const char fstr[100] = "%lli %lli %n %lli %lli";

  int16_t s21_func = s21_sscanf(str, fstr, &a1, &b1, &n1, &c1, &d1);
  int16_t original = sscanf(str, fstr, &a2, &b2, &n2, &c2, &d2);

  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(s21_func, original);
}
END_TEST

START_TEST(sscanf_n2) {
  int n1 = 1, n2 = 5;

  char s1[100] = {'\0'};
  char s2[100] = {'\0'};
  char s3[100] = {'\0'};
  char s5[100] = {'\0'};
  char s6[100] = {'\0'};
  char s7[100] = {'\0'};

  const char str[] = "cbobErobM fl? asdfasdflkasdf asdfasdf asdfasdf 88888";
  const char fstr[] = "%s %s %n %s";

  int32_t s21_func = s21_sscanf(str, fstr, s1, s2, &n1, s3);
  int32_t original = sscanf(str, fstr, s5, s6, &n2, s7);

  ck_assert_int_eq(s21_func, original);

  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
}
END_TEST

START_TEST(sscanf_n3) {
  int n1 = 0, n2 = 5;

  const char str[100] = "50 60 70 80";
  const char fstr[100] = "%n";

  int16_t s21_func = s21_sscanf(str, fstr, &n1);
  int16_t original = sscanf(str, fstr, &n2);

  ck_assert_int_eq(s21_func, original);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_n4) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int32_t n1 = 0, n2 = 5;

  const char str[] = "50 60 70 80";
  const char fstr[] = "%lli %lli %n %lli %lli";

  int16_t s21_func = s21_sscanf(str, fstr, &a1, &b1, &n1, &c1, &d1);
  int16_t original = sscanf(str, fstr, &a2, &b2, &n2, &c2, &d2);

  ck_assert_int_eq(s21_func, original);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_n5) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int n1 = 0, n2 = 5;

  const char str[] = "50 60 70 80";
  const char fstr[] = "%lli %lli %n %lli %lli";

  int16_t s21_func = s21_sscanf(str, fstr, &a1, &b1, &n1, &c1, &d1);
  int16_t original = sscanf(str, fstr, &a2, &b2, &n2, &c2, &d2);

  ck_assert_int_eq(s21_func, original);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

Suite *sscanf_suite() {
  Suite *s = suite_create("SSCANF");
  TCase *tc = tcase_create("sscanf");
  tcase_add_test(tc, test_s21_sscanf_long_double_negative_conversion);
  tcase_add_test(tc, octal_star);
  tcase_add_test(tc, test_s21_sscanf_suppress_assignment);
  tcase_add_test(tc, test_s21_sscanf_suppress_assignment_digit);
  tcase_add_test(tc, test_s21_sscanf_suppress_assignment_float);
  tcase_add_test(tc, test_s21_sscanf_suppress_assignment_string);
  tcase_add_test(tc, sscanf_test_int_1);
  tcase_add_test(tc, sscanf_test_int_2);
  tcase_add_test(tc, sscanf_test_int_3);
  tcase_add_test(tc, sscanf_test_int_4);
  tcase_add_test(tc, sscanf_test_int_5);
  tcase_add_test(tc, sscanf_test_o_1);
  tcase_add_test(tc, sscanf_test_o_2);
  tcase_add_test(tc, sscanf_test_o_3);
  tcase_add_test(tc, sscanf_test_o_4);
  tcase_add_test(tc, sscanf_test_u_1);
  tcase_add_test(tc, sscanf_test_u_2);
  tcase_add_test(tc, sscanf_test_u_3);
  tcase_add_test(tc, sscanf_test_u_4);
  tcase_add_test(tc, sscanf_test_u_5);
  tcase_add_test(tc, sscanf_test_u_6);
  tcase_add_test(tc, sscanf_test_x_1);
  tcase_add_test(tc, sscanf_test_x_2);
  tcase_add_test(tc, sscanf_test_x_3);
  tcase_add_test(tc, sscanf_test_x_4);
  tcase_add_test(tc, sscanf_test_x_5);
  tcase_add_test(tc, sscanf_test_X_1);
  tcase_add_test(tc, sscanf_test_X_2);
  tcase_add_test(tc, sscanf_test_X_3);
  tcase_add_test(tc, sscanf_test_X_4);
  tcase_add_test(tc, sscanf_test_X_5);
  tcase_add_test(tc, sscanf_test_int_dec);
  tcase_add_test(tc, sscanf_test_int_neg_dec);
  tcase_add_test(tc, sscanf_test_int_oct);
  tcase_add_test(tc, sscanf_test_int_neg_oct);
  tcase_add_test(tc, sscanf_test_int_hex);
  tcase_add_test(tc, sscanf_test_int_neg_hex);
  tcase_add_test(tc, sscanf_test_int_invalid);
  tcase_add_test(tc, sscanf_test_str_1);
  tcase_add_test(tc, sscanf_test_str_2);
  tcase_add_test(tc, sscanf_test_str_3);
  tcase_add_test(tc, sscanf_test_float_1);
  tcase_add_test(tc, sscanf_test_float_2);
  tcase_add_test(tc, sscanf_test_float_3);
  tcase_add_test(tc, sscanf_test_float_4);
  tcase_add_test(tc, sscanf_test_float_5);
  tcase_add_test(tc, sscanf_test_float_6);
  tcase_add_test(tc, sscanf_test_float_7);
  tcase_add_test(tc, sscanf_test_float_8);
  tcase_add_test(tc, sscanf_test_exp_float_1);
  tcase_add_test(tc, sscanf_test_exp_float_2);
  tcase_add_test(tc, sscanf_test_exp_float_3);
  tcase_add_test(tc, sscanf_test_exp_float_4);
  tcase_add_test(tc, sscanf_test_exp_float_5);
  tcase_add_test(tc, sscanf_test_exp_float_6);
  tcase_add_test(tc, sscanf_test_exp_float_7);
  tcase_add_test(tc, sscanf_test_exp_float_no_digits_1);
  tcase_add_test(tc, sscanf_test_exp_float_no_digits_2);
  tcase_add_test(tc, sscanf_test_g_float_1);
  tcase_add_test(tc, sscanf_test_g_float_2);
  tcase_add_test(tc, sscanf_test_g_float_3);
  tcase_add_test(tc, sscanf_test_g_float_4);
  tcase_add_test(tc, sscanf_test_g_float_5);
  tcase_add_test(tc, sscanf_test_g_float_6);
  tcase_add_test(tc, sscanf_test_g_float_7);
  tcase_add_test(tc, sscanf_test_g_float_8);
  tcase_add_test(tc, sscanf_test_g_float_9);
  tcase_add_test(tc, sscanf_test_char_1);
  tcase_add_test(tc, sscanf_test_char_2);
  tcase_add_test(tc, sscanf_test_char_3);
  tcase_add_test(tc, sscanf_test_char_4);
  tcase_add_test(tc, sscanf_test_mismatch);
  tcase_add_test(tc, sscanf_test_premature_end);
  tcase_add_test(tc, sscanf_test_digits_width_1);
  tcase_add_test(tc, sscanf_test_digits_width_2);
  tcase_add_test(tc, sscanf_test_digits_width_3);
  tcase_add_test(tc, sscanf_test_digits_width_4);
  tcase_add_test(tc, sscanf_test_digits_width_5);
  tcase_add_test(tc, sscanf_test_digits_width_6);
  tcase_add_test(tc, sscanf_test_digits_width_7);
  tcase_add_test(tc, sscanf_test_digits_width_8);
  tcase_add_test(tc, sscanf_test_digits_width_9);
  tcase_add_test(tc, sscanf_test_strings_width_1);
  tcase_add_test(tc, sscanf_test_strings_width_2);
  tcase_add_test(tc, sscanf_test_strings_width_3);
  tcase_add_test(tc, sscanf_test_float_width_1);
  tcase_add_test(tc, sscanf_test_float_width_2);
  tcase_add_test(tc, sscanf_test_float_width_3);
  tcase_add_test(tc, sscanf_test_float_width_4);
  tcase_add_test(tc, sscanf_test_float_width_5);
  tcase_add_test(tc, sscanf_test_float_width_6);
  tcase_add_test(tc, sscanf_test_float_width_7);
  tcase_add_test(tc, sscanf_test_float_width_8);
  tcase_add_test(tc, sscanf_test_float_width_9);
  tcase_add_test(tc, sscanf_test_float_width_10);
  tcase_add_test(tc, sscanf_test_float_width_11);
  tcase_add_test(tc, sscanf_test_float_width_12);
  tcase_add_test(tc, sscanf_test_float_width_13);
  tcase_add_test(tc, sscanf_test_float_width_14);
  tcase_add_test(tc, sscanf_test_ptr_1);
  tcase_add_test(tc, sscanf_test_g_float_width_1);
  tcase_add_test(tc, sscanf_test_g_float_width_2);
  tcase_add_test(tc, sscanf_test_g_float_width_3);
  tcase_add_test(tc, sscanf_test_g_float_width_4);
  tcase_add_test(tc, sscanf_test_g_float_width_5);
  tcase_add_test(tc, sscanf_test_g_float_width_6);
  tcase_add_test(tc, sscanf_test_e_float_width_1);
  tcase_add_test(tc, sscanf_test_e_float_width_2);
  tcase_add_test(tc, sscanf_test_e_float_width_3);
  tcase_add_test(tc, sscanf_test_e_float_width_4);
  tcase_add_test(tc, sscanf_test_e_float_width_5);
  tcase_add_test(tc, sscanf_test_e_float_width_6);
  tcase_add_test(tc, sscanf_test_e_double_width);
  tcase_add_test(tc, sscanf_test_unsigned_short);
  tcase_add_test(tc, sscanf_test_unsigned_short_width_1);
  tcase_add_test(tc, sscanf_test_unsigned_short_width_2);
  tcase_add_test(tc, sscanf_test_unsigned_short_width_3);
  tcase_add_test(tc, sscanf_test_unsigned_long_width_1);
  tcase_add_test(tc, sscanf_test_unsigned_long_width_2);
  tcase_add_test(tc, sscanf_test_unsigned_long_long_width_1);
  tcase_add_test(tc, sscanf_test_unsigned_long_long_width_2);
  tcase_add_test(tc, sscanf_test_signed_short);
  tcase_add_test(tc, sscanf_test_signed_short_width_1);
  tcase_add_test(tc, sscanf_test_signed_short_width_2);
  tcase_add_test(tc, sscanf_test_signed_short_width_3);
  tcase_add_test(tc, sscanf_test_signed_long);
  tcase_add_test(tc, sscanf_test_signed_long_width_1);
  tcase_add_test(tc, sscanf_test_signed_long_width_2);
  tcase_add_test(tc, sscanf_test_signed_long_width_3);
  tcase_add_test(tc, sscanf_test_signed_long_long);
  tcase_add_test(tc, sscanf_test_unsigned_short_octal_width_1);
  tcase_add_test(tc, sscanf_test_unsigned_short_octal_width_2);
  tcase_add_test(tc, sscanf_test_unsigned_short_octal_width_3);
  tcase_add_test(tc, sscanf_test_unsigned_short_hex);
  // tcase_add_test(tc, sscanf_test_n_spec_1);
  tcase_add_test(tc, test_s21_sscanf_overflow_handling);
  tcase_add_test(tc, test_s21_sscanf_signed_overflow_handling);
  tcase_add_test(tc, docker_telegram_test_1);
  tcase_add_test(tc, sscanf_n1);
  tcase_add_test(tc, sscanf_n2);
  tcase_add_test(tc, sscanf_n3);
  tcase_add_test(tc, sscanf_n4);
  tcase_add_test(tc, sscanf_n5);
  suite_add_tcase(s, tc);
  return s;
}