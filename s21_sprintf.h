#ifndef S21_sprintf___
#define S21_sprintf___
#include "s21_string.h"

typedef struct options {
  bool plus;  // написать + перед положительным числом, - перед отрицательным
  bool minus;  // отступ по левому краю в пределах числа до va_arg
  bool space;  // для чисел: нет знака или плюс → пробел; минус → вместо пробела
               // минус,
  bool zero;   // при d и введённом 0, 0 не печатаем
  bool sharp;
  bool num_to_print;  // число после процента или точки задаёт количество
                      // символов для печати, Если записываемое значение короче
                      // этого числа, результат дополняется нулями
  int exactness;  // точность
  int width;      // ширина
  int *buffer;
  int len_buffer;
  bool is_rest;
  bool oct;
  bool hex_lower;
  bool hex_upper;
  int options_counter;
  char *new_p_tb;  // указатель на смещённый временный буфер в s21_sprintf
  bool is_format;
  bool is_negative;
  bool is_exactness;  // для проверки, что записывается ширина или точность
  bool is_float;
  int float_width;  // фактическая ширина float
} options;
// возможно добавить в опции s —  минимальное количество печатуемых символов

// буфер для записи числа в перевёрнутом формате
typedef struct spec {
  char *buffer;
  int len_buffer;
} spec;

// ----- структура для функций-обаботчиков ----
typedef struct flag_function {
  char key;
  void *(*function)(char *, va_list, options *);
} Function;

// ----- функция-запуск -----
int s21_sprintf(char *str, char *format, ...);

// ----- функции-конвертеры -----
void parse_flags(char **symb, options *format_str);
int multiply_ten(int number);
bool is_digit(char symb);
void *parse_params(options *format_str, char possible_formats[], char *psymb,
                   char *p_tb);
void int_to_char(int n, spec *d_str);
void *parse_int(char *buffer, int n, options *format_str, va_list factor);
void *add_to_hex_upper(char *buffer, va_list factor, options *format_str);
void *add_to_hex_lower(char *buffer, va_list factor, options *format_str);
void *add_to_octal(char *buffer, va_list factor, options *format_str);

// ----- функции-добавители -----
void *add_char(char *buffer, va_list factor, options *format_str);
void *add_int(char *buffer, va_list factor, options *format_str);
void *add_to_right(char *str, options *format_str, spec *d_str);
void *add_to_left(char *str, options *format_str, spec *d_str);
void *add_spaces(char *buffer, int space_counter);
void *add_sign(char *buffer, options format_str);
void *add_zeros(char *buffer, options *format_str, spec *d_str);
void *add_string(char *buffer, va_list factor, options *format_str);
void *add_float(char *buffer, va_list factor, options *format_str);

// ------------------------------

#endif
