#include "s21_sprintf.h"

int s21_sprintf(char *buffer1, char *psymb,
                ...) {  // всё должно сразу записываться в str

  char *buffer = buffer1;
  va_list factor;
  va_start(factor, psymb);

  for (; *psymb; psymb++) {
    if (*psymb == '%') {
      // -- если экранирование, печатаем один символ --
      if ((*psymb == '%' && *(psymb + 1) == '%')) {
        *buffer++ = *psymb;
        psymb++;
        continue;
      }

      char *temp_buffer = (char *)calloc(sizeof(*psymb), sizeof(char *));
      char *p_tb = temp_buffer;

      char possible_formats[] =
          "cdieEfgGosuxXpn.";  // -- строка с возможными форматами --
      options format_str = {0};

      // -- парсинг флагов --
      while (s21_strchr(possible_formats, *psymb) == NULL &&
             !is_digit(*psymb)) {
        *p_tb++ = *psymb;
        parse_flags(&psymb, &format_str);
      }

      // -- парсинг ширины и точности--
      psymb = parse_params(&format_str, possible_formats, psymb, p_tb);
      p_tb = format_str.new_p_tb;
      format_str.exactness =
          format_str.is_exactness ? format_str.exactness : -1;

      Function functions[] = {{'c', &add_char},
                              {'i', &add_int},
                              {'d', &add_int},
                              {'s', &add_string},
                              {'f', &add_float},
                              {'x', &add_to_hex_lower},
                              {'X', &add_to_hex_upper},
                              {'o', &add_to_octal},
                              {'\0', NULL}};

      // printf("%c!!!", *psymb);
      for (size_t i = 0; i < sizeof(functions) / sizeof(functions[0]); i++) {
        if (functions[i].key != '\0' && functions[i].key == *psymb) {
          buffer = functions[i].function(buffer, factor, &format_str);
          format_str.options_counter++;
        }
      }
      if (!format_str.options_counter) {
        s21_strcpy(buffer, temp_buffer);
        buffer += s21_strlen(temp_buffer);
      }
      free(temp_buffer);
    } else
      *buffer++ = *psymb;
  }
  *buffer = '\0';
  va_end(factor);
  return s21_strlen(buffer1);
};
