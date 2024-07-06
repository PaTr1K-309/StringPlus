#include "s21_string.h"
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
  if (number == 1 || number == 0)
    return 1;
  return multiply_ten(number - 1) * 10;
}

bool is_digit(char symb) {
  return symb >= '0' && symb <= '9';
}

void *parse_params(options *format_str, char possible_formats[], char *psymb, char *p_tb) {
  char *format_buffer = (char*)calloc(sizeof(*psymb), sizeof(char*));
  if (format_buffer == NULL) {
    ;
  } else {
    char *p = format_buffer;
    while (s21_strchr(possible_formats, *psymb) == NULL && is_digit(*psymb)) {
        *p =  *psymb;
        *p_tb = *psymb;
        p++;
        psymb++;
        p_tb++;
    }
    for (int i = 0; i < (int)(p - format_buffer); i++) {
      int num = (int)format_buffer[i] - '0';
      if (format_str->is_exactness)
        format_str->exactness += num * multiply_ten((int)(p - format_buffer - i));
      else
        format_str->width += num * multiply_ten((int)(p - format_buffer - i));
    }
    free(format_buffer);

    format_str->new_p_tb = p_tb;
    if (*psymb == '.' && !format_str->is_exactness){
      *p_tb++ = '.';
      psymb++;
      if(!is_digit(*psymb)) {
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



// {
// //   if (s21_strchr("eEfgG", symb) && !format_str->exactness)
// //     format_str->exactness = (format_str->exactness == 0 && s21_strchr("eEfgG", symb)) ? 6 : 1;
//   // char *p = buffer1;

//   printf("AFTER---%s---\n", buffer);
//   (void)flags;
//   (void)format_str;
//   (void)factor;
//   switch (symb) {
//     case 'c':
//       // char c = (char)va_arg(factor, int);
//       // *p = c;
//       // *buffer++;
//       // *buffer++;
//       // if(format_str->space || format_str->minus || format_str->plus || format_str->zero || format_str->dot) {
//         // exit(1); // пока exit уточняю
//       // }

//       // char *p = c;
//       // add_symb(&str, p);
//       break;
//     // case 'd':
//     //   int d = va_arg(factor, int);
//     //   add_to_string(d, str, format_str);
//     //   break;
//     // case 'f':
//     //   double f = va_arg(factor, double);
//     //   float_to_int(f, f - (int)f, str,format_str);
//     //   break;
//     // case 's':
//     //   char *s = va_arg(factor, char *);
//     //   // *str_counter += s21_strlen(s);
//     //   s21_strcat(str, s);
//     //   break;
//     // case 'u':
//     //   unsigned int u = va_arg(factor, unsigned int);
//     //   add_to_string(u, str, format_str);
//     //   break;
//     // case 'o':
//     //   int o = va_arg(factor, int);
//     //   format_str->oct = true;
//     //   add_to_string(o, str, format_str);
//     //   break;
//     // case 'x':
//     //   int x = va_arg(factor, int);
//     //   format_str->hex_lower = true;
//     //   add_to_string(x, str, format_str);
//     //   break;
//     // case 'X':
//     //   int X = va_arg(factor, int);
//     //   format_str->hex_upper = true;
//     //   add_to_string(X, str, format_str);
//     //   break;
//     // default:
//       // exit(1); // исправить
//   }
// }

// void chars_to_int(options *format_str, char **psymb) {
//   

//   for (; i < format_str->len_buffer; i++) {
//     int num = format_str->buffer[i];
//     printf("%d*", num);
//     if (format_str->is_exactness){

//       format_str->exactness += num * multiply_ten(format_str->len_buffer - i);
//     }
//     else{
//       format_str->width += num * multiply_ten(format_str->len_buffer - i);
//     }
//   }
//       printf("YES %d %d --\n", format_str->width, format_str->exactness);
// }

// void parse_format(char symb, flags *flags, options *format_str, char * str, va_list factor) {
//   switch (symb) {
//   case '.':
//   // printf("%d %ls...\n", format_str->width, format_str->buffer);
//     format_str->dot = true;
//     // -- при наличии ширины, парсим её --
//     if (format_str->len_buffer > 0) {
//       chars_to_int(format_str); 
//       // -- освобождаем буфер для записи точности --
//       int i = 0;
//       while ((format_str->buffer[i] != 0)) {
//         format_str->buffer[i] = 0;
//         i++;
//       }
//       format_str->len_buffer = 0;
//       format_str->is_exactness = 1;
//     }
//     break;
//   case '0':
//     format_str->zero = true;
//     break;
//   case '#':
//     format_str->sharp = true;
//     break;
//   default:
//     char possible_formats[] = "cdieEfgGosuxXpn"; // -- строка с возможными форматами --
//     printf("%d///", flags->hash);
//     if (symb >= '0' && symb <= '9') {
//       format_str->buffer[format_str->len_buffer] = (int)(symb - '0');
//       // printf("%d %d --------------\n", format_str->is_exactness, format_str->buffer[format_str->len_buffer]);
//       format_str->len_buffer += 1;
//     // -- проверка на конец форматной строки --
//     } else if (s21_strchr(possible_formats, symb) != NULL) { 
//       chars_to_int(format_str);
//       format_str->len_buffer = 0;
      
//       // printf("---w%d-e%d-1:%d-2:%d-%c\n", format_str->width, format_str->exactness, format_str->buffer[0], format_str->buffer[1], symb);
//       parse_next(symb, str, factor, format_str);
//       format_str->is_format = 0;
//       format_str->is_negative = false;
//       format_str->width = 0;
//       format_str->exactness = 0;

//     } else 
//       exit(2); // change to flag
//     break;
//   }

// }


// void float_to_int(double f, double n, char *str, options *format_str) {  //, spec *f_str
//   format_str->is_float = true;
//   // -- убираем минус от остатка --
//   if (n < 0)
//     n = (n * -1.0);

//   // -- добавление в буфер целой части --
//   add_to_string((int)f, str, format_str);
 
//   // if (format_str->exactness != 0 && format_str->dot) {

//     // -- добавление точки --
//     add_symb(str, '.');
    
//     // -- перевод остатка от числа в int --
//     int n_rest = 0;

//     for (int i = 0; i < 6; i++) {
//       // -- проверка на нули после точки --
//       if (n * 10 < 1) {
//         add_symb(str, '0');
//       }
//       n *= 10;
//       n_rest = n + 0.5;
//     }
//     // -- отметка, что это остаток, добавление остатка --
//     format_str->is_rest = true; 
//     add_to_string(n_rest, str, format_str);
//   // }
// }



