#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  if (dest != S21_NULL && src != S21_NULL && n) {
    char *s_ind = dest + s21_strlen(dest);
    char *e_ind = s_ind + n;
    int j = 0;

    for (char *i = s_ind; i < e_ind; i++) {
      *i = src[j];
      j++;
    }
    dest[s21_strlen(dest)] = '\0';
  }
  return dest;
}
