#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *byte = (unsigned char *)str;
  void *result = S21_NULL;

  for (s21_size_t i = 0; i < n; i++) {
    if (byte[i] == c) {
      result = &byte[i];
      i = n;
    }
  }

  return result;
}