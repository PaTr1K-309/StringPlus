#include "s21_string.h"

void *s21_memcpy(void *dest, void *src, s21_size_t n) {
  if (dest != S21_NULL) {
    char *char_dest = (char *)dest;
    char *char_src = (char *)src;

    for (int i = 0; (s21_size_t)i < n; i++) {
      char_dest[i] = char_src[i];
    }
  }
  return dest;
}