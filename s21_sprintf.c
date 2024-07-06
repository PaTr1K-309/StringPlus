#include "s21_string.h"
#include "s21_sprintf.h"
#include <string.h>
#include "tests/s21_tests.h"

int s21_sprintf(char *buffer1, char *psymb, ...) { // всё должно сразу записываться в str 

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
      
      char *temp_buffer = (char*)calloc(sizeof(*psymb), sizeof(char*));
      char *p_tb = temp_buffer;
    
      char possible_formats[] = "cdieEfgGosuxXpn."; // -- строка с возможными форматами --
      options format_str = {0};
      
      // -- парсинг флагов --
      while (s21_strchr(possible_formats, *psymb) == NULL && !is_digit(*psymb)) {
        *p_tb++ = *psymb;
        parse_flags(&psymb, &format_str);
      }

      // -- парсинг ширины и точности--
      psymb = parse_params(&format_str, possible_formats, psymb, p_tb);
      p_tb = format_str.new_p_tb;
      format_str.exactness = format_str.is_exactness ? format_str.exactness : -1;

      Function functions[] = {
        {'c', &add_char},
        {'d', &add_int},
        {'s', &add_string},
        {'o', &add_to_octal},
        {'x', &add_to_hex_lower},
        {'X', &add_to_hex_upper},
        {'\0', S21_NULL}
      };

      // printf("%c!!!", *psymb);
      for (size_t i = 0; i < sizeof(functions)/sizeof(functions[0]); i++) {
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

// // -- эта часть в качестве отладки. Часть тестов написана в папке тестов --
// int main () {

//   // Suite *tests[] = { sprintf_suite(),
//   //     S21_NULL};
//   // for (Suite **cases = tests; *cases != NULL; cases++) {
//   //   SRunner *sr = srunner_create(*cases);
//   //   srunner_set_fork_status(sr, CK_NOFORK);
//   //   srunner_run_all(sr, CK_NORMAL);
//   //   srunner_free(sr);
//   //   printf("\n");
//   // }



//   // --------------

//   char str1[4000];
//   char str2[4000];

//   char *str3 = "TEST1 %20d TEST2 % 1.0d TEST3 %-16.8d TEST4 %.8d!";
//   char *str31 = "TEST1 %20d TEST2 % 1.0d TEST3 %-16.8d TEST4 %.8d!";
//   char *str4 = "TEST1 |%c| TEST3 |%-5c| TEST4 |%67..c| TEST5 |%2c| TEST |%.0c|!";
//   char *str5 = "TEST1 %%%%|%15.0s| TEST2 |%s| TEST3 |%15.5s| TEST4 | %5.15s|!";
//   char *str6 = "TEST1 %%%%|%15.0o| TEST2 |%o| TEST3 |%15.5o| TEST4 | %5.15o|!";
//   char *str7 = "TEST1 %%%%|%15.0x| TEST2 |%x| TEST3 |%15.5x| TEST4 | %5.15x|!";
//   char *str8 = "TEST1 %%%%|%15.0X| TEST2 |%X| TEST3 |%15.5X| TEST4 | %5.15X|!";
//   char *str9 = "TEST1 %%%%|%#15.0o| TEST2 |%#o| TEST3 |%X| TEST4 |%#15.5x| TEST5 | %#5.15X|!";
//   // char *str6 = "TEST1 |% +#50.7f| TEST2 |%.0f| TEST3 |%5f!";


//   // char *str3 = "TEST %cjdbgl.kjdk";

//   // float num = 76.756589367;
//   int num1 = 5600;
//   int num2 = -5600;
//   // int res1 = sprintf(str1, str3, '*');
//   // int res2 = s21_sprintf(str2, str3, '*');
//   // sprintf(str1, "%d", 13);
//   int res1 = sprintf(str1, str3, num1, num1, num1, num1);
//   int res2 = s21_sprintf(str2, str3, num1, num1, num1, num1);

//   printf("-----------------------------------------\n");
//   printf("SPRINTF|%s|%d|\n", str1, res1);
//   printf("    S21|%s|%d|\n", str2, res2);
//   printf("-----------------------------------------\n");

//   int res02 = sprintf(str1, str31, num2, num2, num2, num2);
//   int res03 = s21_sprintf(str2, str31, num2, num2, num2, num2);

//   printf("SPRINTF|%s|%d|\n", str1, res02);
//   printf("    S21|%s|%d|\n", str2, res03);
//   printf("-----------------------------------------\n");
  
//   int res3 = sprintf(str1, str4, '*', 'W', '<', '@', 'D');
//   int res4 = s21_sprintf(str2, str4, '*', 'W', '<', '@', 'D');
  

//   printf("SPRINTF|%s|%d|\n", str1, res3);
//   printf("    S21|%s|%d|\n", str2, res4);
//   printf("-----------------------------------------\n");
  
//   int res5 = sprintf(str1, str5, "Temet nosce", "Temet nosce", "Temet nosce", "Temet nosce");
//   int res6 = s21_sprintf(str2, str5, "Temet nosce", "Temet nosce", "Temet nosce", "Temet nosce");

//   printf("SPRINTF|%s|%d|\n", str1, res5);
//   printf("    S21|%s|%d|\n", str2, res6);
//   printf("-----------------------------------------\n");

//   int res7 = sprintf(str1, str6, num1, num1, num1, num1);
//   int res8 = s21_sprintf(str2, str6, num1, num1, num1, num1);

//   printf("SPRINTF|%s|%d|\n", str1, res7);
//   printf("    S21|%s|%d|\n", str2, res8);
//   printf("-----------------------------------------\n");  

//   int res9 = sprintf(str1, str7, num1, num1, num1, num1);
//   int res10 = s21_sprintf(str2, str7, num1, num1, num1, num1);

//   printf("SPRINTF|%s|%d|\n", str1, res9);
//   printf("    S21|%s|%d|\n", str2, res10);
//   printf("-----------------------------------------\n");

//   int res11 = sprintf(str1, str8, num1, num1, num1, num1);
//   int res12 = s21_sprintf(str2, str8, num1, num1, num1, num1);

//   printf("SPRINTF|%s|%d|\n", str1, res11);
//   printf("    S21|%s|%d|\n", str2, res12);
//   printf("-----------------------------------------\n");

//   int res13 = sprintf(str1, str9, num1, num1, num1, num1, num1);
//   int res14 = s21_sprintf(str2, str9, num1, num1, num1, num1, num1);

//   printf("SPRINTF|%s|%d|\n", str1, res13);
//   printf("    S21|%s|%d|\n", str2, res14);
//   printf("-----------------------------------------\n");

// // --------------------------
//   // char str2[200];
//   // char *str3 = "%-6d TEST %+f TEST ";
//   // int num1 = 5000;
//   // float num2 = 39200.2220;
//   // sprintf(str2, str3, num1, num2);

//   // int res = 0;
//   // int res2 = 0;

//   // printf(
//   //     "\n\n\n\n------------------------------------------------------------"
//   //     "------------------------------------------------------------------------"
//   //     "-"
//   //     "-----------------------\n");
//   // res =
//   //     s21_sprintf(str1,
//   //                 "s21_sprintf - : %d - %u - %lc - %s - %o - %x - %X - %p - n%n - %f",
//   //                               num1, -1234567, 'q', "qwerty", 123, 100, 100, &q, &n1, 3.14151212);
//   // printf("| %s -> %d |\n", str1, res);

//   // printf(
//   //     "----------------------------------------------------------------------"
//   //     "----------------------------------------------------------------------"
//   //     "----------------\n");
//   // res2 =
//   //     sprintf(buffer2,
//   //             "  sprintf   - : %d - %u - %lc - %s - %o - %x - %X - %p - n%n - %.8f",
//   //                           n4, -1234567, 'q', "qwerty", 123, 100, 100, &q, &n2, 3.14151212);
//   // printf("| %s -> %d |\n", buffer2, n2);
//   // printf(
//   //     "----------------------------------------------------------------------" 
//   //     "----------------------------------------------------------------------"
//   //     "----------------\n\n");

//   return 0;
// }

