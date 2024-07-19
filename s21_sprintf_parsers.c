#include "s21_sprintf.h"

void parse_flags(char **symb, options *format_str) {
  switch (**symb) {
    case '+':
      format_str->plus = true;
      break;
    case '-':
      format_str->minus = true;
      break;
    case ' ':
      format_str->space = true;
      break;
    case '0':
      format_str->zero = true;
      break;
    case '#':
      format_str->sharp = true;
      break;
  }
  (*symb)++;
}

int multiply_ten(int number) {
  if (number == 1 || number == 0) return 1;
  return multiply_ten(number - 1) * 10;
}

bool is_digit(char symb) { return symb >= '0' && symb <= '9'; }

void *parse_params(options *format_str, char possible_formats[], char *psymb,
                   char *p_tb) {
  char *format_buffer = (char *)calloc(sizeof(*psymb), sizeof(char *));
  if (format_buffer == NULL) {
    ;
  } else {
    char *p = format_buffer;
    while (s21_strchr(possible_formats, *psymb) == NULL && is_digit(*psymb)) {
      *p = *psymb;
      *p_tb = *psymb;
      p++;
      psymb++;
      p_tb++;
    }
    for (int i = 0; i < (int)(p - format_buffer); i++) {
      int num = (int)format_buffer[i] - '0';
      if (format_str->is_exactness)
        format_str->exactness +=
            num * multiply_ten((int)(p - format_buffer - i));
      else
        format_str->width += num * multiply_ten((int)(p - format_buffer - i));
    }
    free(format_buffer);

    format_str->new_p_tb = p_tb;
    if (*psymb == '.' && !format_str->is_exactness) {
      *p_tb++ = '.';
      psymb++;
      if (!is_digit(*psymb)) {
        *p_tb++ = '0';
        *p_tb++ = *psymb;
      }

      format_str->is_exactness = true;
      psymb = parse_params(format_str, possible_formats, psymb, p_tb);
    }
  }
  return psymb;
}

void int_to_char(int n, spec *d_str) {
  do {
    d_str->buffer[d_str->len_buffer] = n % 10 + '0';
    n = n / 10;
    d_str->len_buffer += 1;
  } while (n % 10 || n > 0);
}

void *add_float(char *buffer, va_list factor, options *format_str) {
  double f = va_arg(factor, double);
  format_str->is_float = true;
  // -- убираем минус от остатка --
  if (f < 0) f = (f * -1.0);

  if (format_str->exactness == 0) {
    buffer = parse_int(buffer, (int)(f + 0.5), format_str, factor);
  } else {
    // -- добавление в буфер целой части --
    buffer = parse_int(buffer, (int)f, format_str, factor);

    // -- перевод остатка от числа в int --
    double n = f - (int)f;
    int n_rest = 0;

    for (int i = 0; i < 6; i++) {
      // -- проверка на нули после точки --
      if (n * 10 < 1) *buffer++ = '0';
      n *= 10;
      n_rest = n + 0.5;
    }
    *buffer++ = '.';

    // -- отметка, что это остаток, добавление остатка --
    format_str->is_rest = true;
    buffer = parse_int(buffer, n_rest, format_str, factor);
  }
  return buffer;
}

void *parse_int(char *buffer, int n, options *format_str, va_list factor) {
  format_str->is_negative = n < 0;

  if (!format_str->is_rest) {
    if (n < 0) {
      n *= -1;
    }
  }

  spec d_str = {0};
  d_str.buffer = (char *)calloc(sizeof(&factor), sizeof(char));

  // -- записываем число в обратном порядке --
  int_to_char(n, &d_str);

  // -- переворачиваем буфер в правильном порядке --
  for (int i = 0; i < d_str.len_buffer / 2; i++) {
    char temp = d_str.buffer[i];
    d_str.buffer[i] = d_str.buffer[d_str.len_buffer - 1 - i];
    d_str.buffer[d_str.len_buffer - 1 - i] = temp;
  }

  if (format_str->is_float) format_str->float_width += d_str.len_buffer;

  // -- добавляем число из буфера в основной буфер по левому/правому краю --
  if (format_str->minus)
    buffer = add_to_left(buffer, format_str, &d_str);
  else
    buffer = add_to_right(buffer, format_str, &d_str);
  free(d_str.buffer);
  return buffer;
}
