#include "s21_string.h"

void *s21_memset(void *dest, int bite, int n) {
  if (dest != S21_NULL) {
    char *char_dest = (char *)dest;
    for (int i = 0; i < n; i++) {
      char_dest[i] = bite;
    }
  }
  return dest;
}
