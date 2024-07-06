#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  int flg = 0;
  char *first_ch = S21_NULL;

  for (; !flg && *str1 != '\0'; str1++) {
    for (s21_size_t i = 0; !flg && str2[i] != '\0'; i++) {
      if (*str1 == str2[i]) {
        first_ch = (char *)(str1);
        flg = 1;
      }
    }
  }

  return first_ch;
}