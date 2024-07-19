#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (src == S21_NULL || str == S21_NULL ||
      (src[0] == '\0' && str[0] != '\0')) {
    return S21_NULL;
  }
  char *start_i = S21_NULL;
  s21_size_t size_src = s21_strlen(src);
  s21_size_t size_str = s21_strlen(str);
  s21_size_t free_line = size_str + size_src + start_index + 1;
  start_i = calloc(free_line, sizeof(char));
  s21_size_t i;
  for (i = 0; i < start_index; i++) start_i[i] = src[i];
  s21_size_t j;
  for (j = 0; j < size_str; j++) start_i[i++] = str[j];
  for (; i < free_line; i++) start_i[i] = src[start_index++];
  return start_i;
}
