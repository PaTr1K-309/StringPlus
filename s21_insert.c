#include"s21_string.h" 

void  * s21_insert(const char  * src, const char  * str, s21_size_t start_index) {
    if (src == S21_NULL || str == S21_NULL) {
        return S21_NULL;
    }
    if ( * src == '\0' &&  * str != '\0') {
        return S21_NULL;
    }
    s21_size_t new_size = s21_strlen(src) + s21_strlen(str) + 1;
    char  * new_str = malloc(new_size  *  sizeof(char));
    // if (new_str == S21_NULL) {
    //     return S21_NULL;
    // }
    s21_memcpy(new_str, (void*)src, start_index);
    s21_memcpy((new_str + start_index), (void*)str, s21_strlen(str));
    s21_memcpy((new_str + start_index + s21_strlen(str)), (void*)(src + start_index), (s21_strlen(src) - start_index + 1));

    return new_str;
}


// int main() { 
//   char* a = "hellld  fafa";
//   char* b = "o wor";
//   size_t start = 7;
//   char *s = (char*)s21_insert(a, b, start);
//   printf("%s\n", s);
//   free(s);
//   return 0;
// }