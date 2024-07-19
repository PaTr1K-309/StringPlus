#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *res = S21_NULL;
  int flag = 0;

  for (; !flag && *str != '\0'; str++) {
    if (*str == c) {
      res = (char *)str;
      flag = 1;
    }
  }

  if (c == '\0') res = (char *)str;
  return res;
}