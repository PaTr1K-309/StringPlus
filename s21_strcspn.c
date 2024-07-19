#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t result = 0;
  unsigned short found_flag = 0;
  for (; *str1 != '\0' && !found_flag; str1++) {
    const char *s2;
    for (s2 = str2; *s2 != '\0' && !found_flag; s2++) {
      if (*str1 == *s2) {
        found_flag = 1;
      }
    }
    if (!found_flag) result++;
  }
  return result;
}