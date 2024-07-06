#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *trim = S21_NULL;
  if (src && trim_chars) {
    char *first_char = (char *)src;
    char *last_char = (char *)src + s21_strlen(src);

    for (; *first_char && s21_strchr(trim_chars, *first_char); first_char++)
      ;
    for (; (last_char != first_char) &&
           (s21_strchr(trim_chars, *(last_char - 1)));
         last_char--)
      ;

    trim = (char *)malloc((last_char - first_char + 1) * sizeof(char));
    if (trim) {
      s21_strncpy(trim, first_char, last_char - first_char);
      *(trim + (last_char - first_char)) = '\0';
    }
  }
  return trim;
}
