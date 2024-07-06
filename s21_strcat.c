#include "s21_string.h"

char *s21_strcat(char *dest, char const *src) {
  if (dest != S21_NULL && src != S21_NULL) {
    char *s_ind = dest + s21_strlen(dest);
    int j = 0;

    for (char *i = s_ind; i < s_ind + s21_strlen(src); i++) {
      *i = src[j];
      j++;
    }
    dest[s21_strlen(dest)] = '\0';
  }
  return dest;
}
