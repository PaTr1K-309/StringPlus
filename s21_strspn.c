#include "s21_string.h"

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t result = 0;
  unsigned short str1_length = s21_strlen(str1);
  unsigned short str2_length = s21_strlen(str2);
  for (s21_size_t i = 0; i < str1_length; i++) {
    unsigned short found_flag = 0;
    for (s21_size_t j = 0; j < str2_length && !found_flag; j++) {
      if (str1[i] == str2[j]) {
        result++;
        found_flag = 1;
      }
    }
    if (!found_flag) i = str1_length;
  }
  return result;
}