// Возвращает копию строки (str), преобразованной в нижний регистр.
// В случае какой-либо ошибки следует вернуть значение NULL.

#include "s21_string.h"

void *s21_to_lower(const char *str) {
  char *low_str = S21_NULL;
  if (str) {
    low_str = (char *)malloc((s21_strlen(str) + 1) * sizeof(char));
  }

  if (low_str) {
    s21_strncpy(low_str, str, s21_strlen(str) + 1);
    for (char *low = low_str; *low; low++) {
      if ((*low >= 'A' && *low <= 'Z')) *low += 32;
    }
  }
  return (void *)low_str;
}
