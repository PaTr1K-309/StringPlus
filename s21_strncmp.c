#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  if (str1 && str2 && n > 0) {
    for (; n && *str1 && *str1 == *str2; n--, str1++, str2++)
      ;
  }
  return *str1 - *str2;
}