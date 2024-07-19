#include "s21_sprintf.h"

void *add_char(char *buffer, va_list factor, options *format_str) {
  (void)format_str;
  char c = (char)va_arg(factor, int);
  if (format_str->minus) {
    *buffer++ = c;
    if (format_str->width) buffer = add_spaces(buffer, format_str->width - 1);
  } else {
    if (format_str->width) buffer = add_spaces(buffer, format_str->width - 1);
    *buffer++ = c;
  }

  return buffer;
}

void *add_int(char *buffer, va_list factor, options *format_str) {
  int n = va_arg(factor, int);
  buffer = parse_int(buffer, n, format_str, factor);
  return buffer;
}

void *add_to_right(char *buffer, options *format_str, spec *d_str) {
  // -- это не остаток --
  if (!format_str->is_rest) {
    format_str->width =
        format_str->is_negative ? format_str->width - 1 : format_str->width;
    int space_counter = 0;
    space_counter = format_str->exactness > d_str->len_buffer
                        ? format_str->width - format_str->exactness
                        : format_str->width - d_str->len_buffer;
    buffer = add_spaces(buffer, space_counter);
    buffer = add_sign(buffer, *format_str);
    buffer = add_zeros(buffer, format_str, d_str);

    for (int i = 0; i < d_str->len_buffer; i++) *buffer++ = d_str->buffer[i];

    // -- это остаток --
  } else {
    // -- добавление точки --
    if (format_str->exactness) {  // format_str->sharp &&
      for (int i = 0; i < d_str->len_buffer; i++) *buffer++ = d_str->buffer[i];
    }
  }
  return buffer;
}

void *add_to_left(char *buffer, options *format_str, spec *d_str) {
  format_str->width =
      format_str->is_negative ? format_str->width - 1 : format_str->width;
  int space_counter = 0;
  if (format_str->is_rest)
    space_counter = format_str->float_width + 1;
  else
    space_counter = format_str->exactness > d_str->len_buffer
                        ? format_str->width - format_str->exactness
                        : format_str->width - d_str->len_buffer;
  if (!format_str->is_rest) {
    buffer = add_sign(buffer, *format_str);
    buffer = add_zeros(buffer, format_str, d_str);
    for (int i = 0; i < d_str->len_buffer; i++) *buffer++ = d_str->buffer[i];
    buffer = add_spaces(buffer, space_counter);

  } else {
    // -- добавление точки --
    if (format_str->exactness) {  // format_str->sharp &&
      for (int i = 0; i < d_str->len_buffer; i++) *buffer++ = d_str->buffer[i];
    }
  }

  return buffer;
}

void *add_spaces(char *buffer, int space_counter) {
  for (int i = 0; i < space_counter; i++) *buffer++ = ' ';
  return buffer;
}

void *add_sign(char *buffer, options format_str) {
  if (format_str.is_negative)
    *buffer++ = '-';
  else if (format_str.space && !format_str.is_negative && !format_str.plus)
    *buffer++ = ' ';
  else if (format_str.plus)
    *buffer++ = '+';
  else if (format_str.sharp && format_str.hex_lower) {
    *buffer++ = '0';
    *buffer++ = 'x';
  } else if (format_str.sharp && format_str.hex_upper) {
    *buffer++ = '0';
    *buffer++ = 'X';
  } else if (format_str.sharp && format_str.oct) {
    *buffer++ = '0';
  }
  return buffer;
}

void *add_zeros(char *buffer, options *format_str, spec *d_str) {
  for (int i = 0; i < format_str->exactness - d_str->len_buffer; i++)
    *buffer++ = '0';
  return buffer;
}

void *add_string(char *buffer, va_list factor, options *format_str) {
  char *s = va_arg(factor, char *);
  int length = (int)s21_strlen(s);

  if (format_str->exactness == 0)
    length = 0;
  else if (format_str->exactness < length && format_str->exactness > 0)
    length = format_str->exactness;
  int space_counter = format_str->width - length;
  if (format_str->minus) {
    s21_strncpy(buffer, s, length);
    buffer += length;
    buffer = add_spaces(buffer, space_counter);
  } else {
    buffer = add_spaces(buffer, space_counter);
    s21_strncpy(buffer, s, length);
    buffer += length;
  }
  return buffer;
}

void *add_to_octal(char *buffer, va_list factor, options *format_str) {
  int o = va_arg(factor, int);
  format_str->oct = true;

  do {
    *buffer++ = (o % 8) + '0';
    o /= 8;
  } while (o > 0);

  spec d_str = {0};
  d_str.buffer = (char *)calloc(sizeof(&factor), sizeof(char));

  // -- записываем число в обратном порядке --
  int_to_char(o, &d_str);

  // -- переворачиваем буфер в правильном порядке --
  for (int i = 0; i < d_str.len_buffer / 2; i++) {
    char temp = d_str.buffer[i];
    d_str.buffer[i] = d_str.buffer[d_str.len_buffer - 1 - i];
    d_str.buffer[d_str.len_buffer - 1 - i] = temp;
  }

  // -- добавляем число из буфера в основной буфер по левому/правому краю --
  if (format_str->minus)
    buffer = add_to_left(buffer, format_str, &d_str);
  else
    buffer = add_to_right(buffer, format_str, &d_str);

  free(d_str.buffer);
  return buffer;
}

void *add_to_hex_lower(char *buffer, va_list factor, options *format_str) {
  int x = va_arg(factor, int);
  format_str->hex_lower = true;

  char *digits = "0123456789abcdef";
  while (x != 0) {
    *buffer++ = digits[x % 16];
    x /= 16;
  }
  spec d_str = {0};
  d_str.buffer = (char *)calloc(sizeof(&factor), sizeof(char));

  // -- записываем число в обратном порядке --
  int_to_char(x, &d_str);

  // -- переворачиваем буфер в правильном порядке --
  for (int i = 0; i < d_str.len_buffer / 2; i++) {
    char temp = d_str.buffer[i];
    d_str.buffer[i] = d_str.buffer[d_str.len_buffer - 1 - i];
    d_str.buffer[d_str.len_buffer - 1 - i] = temp;
  }
  // -- добавляем число из буфера в основной буфер по левому/правому краю --
  if (format_str->minus)
    buffer = add_to_left(buffer, format_str, &d_str);
  else
    buffer = add_to_right(buffer, format_str, &d_str);
  free(d_str.buffer);
  return buffer;
}

void *add_to_hex_upper(char *buffer, va_list factor, options *format_str) {
  int x = va_arg(factor, int);
  format_str->hex_upper = true;
  char *digits = "0123456789ABCDEF";
  while (x != 0) {
    *buffer++ = digits[x % 16];
    x /= 16;
  }
  spec d_str = {0};
  d_str.buffer = (char *)calloc(sizeof(&factor), sizeof(char));

  // -- записываем число в обратном порядке --
  int_to_char(x, &d_str);

  // -- переворачиваем буфер в правильном порядке --
  for (int i = 0; i < d_str.len_buffer / 2; i++) {
    char temp = d_str.buffer[i];
    d_str.buffer[i] = d_str.buffer[d_str.len_buffer - 1 - i];
    d_str.buffer[d_str.len_buffer - 1 - i] = temp;
  }

  // -- добавляем число из буфера в основной буфер по левому/правому краю --
  if (format_str->minus)
    buffer = add_to_left(buffer, format_str, &d_str);
  else
    buffer = add_to_right(buffer, format_str, &d_str);
  free(d_str.buffer);
  return buffer;
}
