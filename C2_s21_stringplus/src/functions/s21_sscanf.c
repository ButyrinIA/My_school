#include "../s21_string.h"

int s21_sscanf(const char *str, const char *format, ...) {
  int fields = 0;
  if (!s21_memcmp(str, "", (s21_strlen((char *)str)))) {
    return fields = -1;
  }
  char *p_for = (char *)format;
  char *p_str = (char *)str;
  va_list ptr;
  va_start(ptr, format);
  int count_int_symbols = 0;
  int width = 0;
  int start = 0;
  width = s21_strlen((char *)str);
  sscanf_struct sample = {0, 0, 0, 0, 0};
  while (*p_str == ' ' || *p_str == '+') p_str++;
  while (*p_for == ' ') p_for++;
  while (*p_for) {
    if (sample.flag_stop == 1) break;
    if (*p_for == '%') {
      int count_str = 0;
      count_int_symbols =
          s21_sscanf_hlL(p_for, p_str, &sample, &width, &count_str);
      while (count_int_symbols--) p_for++;
      while (count_str--) p_str++;
      start = 1;
    } else if ((s21_strchr("cspndiouxXfeEgG", *p_for) != S21_NULL) &&
               start == 1) {
      int count = s21_sscanf_specificator(p_for, p_str, str, sample, &fields,
                                          ptr, width);
      p_for++;
      while (count--) p_str++;
      sample.flag_double = sample.flag_long = sample.flag_short =
          sample.asterix = 0;
      start = 0;
    } else if (*p_for == 32 || *p_for == '\t' || *p_for == '\n') {
      while (*p_for == ' ' || *p_for == '\t' || *p_for == '\n') {
        while (*p_str == *p_for) {
          p_str++;
        }
        p_for++;
        count_int_symbols++;
      }
    } else if (*p_for != *p_str) {
      sample.flag_stop = 1;
    } else {
      p_for++;
      p_str++;
    }
  }
  va_end(ptr);
  return fields;
}
// int main(){

// // // для для
// дабл//-------------------------------------------------------------------------------------------------------------------------------------------------------
// //     // int d = 0;
// //     // int d2 = 0;
//     long double fl = 0;
//     long double fl2 = 0;
// //     // //unsigned int a = 0;
// //     // int a = 0;
// //     // int a2 = 0;
// //     // char c = 0;
// //     // char c2 = 0;
// //     // //char s[1024];
//     char str[]= "   3.14";
//     char str2[]="   3.14";
//     s21_sscanf(str, "%10Lf", &fl);
//     sscanf(str2, "%10Lf", &fl2);
//     printf("%Lf\n", fl);
//     printf("%Lf", fl2);

//     return 0;
//     }
// для чаров //
// --------------------------------------------------------------------------------------------------------------------------------------------------------------------
// char str[]="345.623";
// char str2[]="345.623";
// s21_sscanf(str, "%f", &fl);
// sscanf(str2, "%f", &fl2);
// printf("%f\n", fl);
// printf("%f", fl2);

// для о //
// -----------------------------------------------------------------------------------------------------------------------------------------------------------------
// int main(){
//     unsigned int a = 0;
//     unsigned a2 = 0;
//      unsigned a3 = 0;
//       unsigned a4 = 0;
//     char str[]="8 3787";
//     char str2[]="8 3787";
//     int result = s21_sscanf(str, "%o %o", &a, &a3);
//     int result2 = sscanf(str2, "%o %o", &a2, &a4);
//     printf("%d %o %o\n", result, a, a3);
//     printf("%d %o %o",result2, a2, a4);
//     return 0;
// }
// для i //
// -----------------------------------------------------------------------------------------------------------------------------------------------------------------
// int main(){
//     int a = 0;
//     int a2 = 0;
//     char str[]="377";
//     char str2[]="377";
//     s21_sscanf(str, "%i", &a);
//     sscanf(str2, "%i", &a2);
//     printf("%i\n", a);
//     printf("%i", a2);
//     return 0;
// }
// для x и X //
// -----------------------------------------------------------------------------------------------------------------------------------------------------------------
// int main(){
//     unsigned int value;
//     unsigned int value2;
//     const char *str = "b18A";
//     const char *str2 = "b18A";
//     const char *format = "%X";
//   s21_sscanf(str, format, &value);
//   sscanf(str2, format, &value2);
//     printf("%X\n", value);
//     printf("%X", value2);
//     return 0;
// }

// для строк
// //----------------------------------------------------------------------------------------------------------------------
//      char s[1024];
//      char s2[1024];
//      char str[]="-08";
//      char str2[]="-08";
//      s21_sscanf(str, "%s", s);
//      sscanf(str2, "%s", s2);
//      printf("%s\n", s);
//      printf("%s", s2);
//      return 0;
//  }

// для n
// //----------------------------------------------------------------------------------------------------------------------

// int a = 0;
// int a2 = 0;
// int d = 0;
// int d2 = 0;
// char str[]="345345 erg";
// char str2[]="345345 erg";
// s21_sscanf(str, "%d %n", &d, &a);
// sscanf(str2, "%d %n", &d2, a2);
// printf("%d %d\n", d, a);
// printf("%d %d", d2, a2);

// для p
// //----------------------------------------------------------------------------------------------------------------------
// int main(){
//    char s[1024];
//      char s2[1024];
// int a = 0;
// (void)a;
// int a2 = 0;
// int d = 0;
// int d2 = 0;
// char str[]=" 345 345   dfdf";
// char str2[]=" 345 345   dfdf";
// int num, num2 = 0;
// int result = s21_sscanf(str, "%d %d %n %s", &d, &a2, &num, s);
// int result2 = sscanf(str2, "%d %d %n %s", &d2, &a2, &num2, s2);
// printf("%d %d %d %d %s\n", result, d, a2, num, s);
// printf("%d %d %d %d %s", result2, d2, a2, num2, s2);
// return 0;
// }

// для % \t \n
// *//----------------------------------------------------------------------------------------------------------------------

// void **a = 0;
// (void)a;
// void  **a2 = 0;
// int d3 = 0;
// int d = 0;
// int d2 = 0;
// char str[]="50345345 erg";
// char str2[]="345345 erg";
// s21_sscanf(str, "50%*d %p", &a2);
// sscanf(str2, "%3d%3d %p", &d, &d2, &a2);
// printf("%d %p\n", d3, a2);
// printf("%d %d %p",d, d2, a2);

// для
// ширины//----------------------------------------------------------------------------------------------------------------------
// int main(){
// int d3 = 0;
// int d = 0;
// int d2 = 0;
// int d4 = 0;
// char str[]="3456456 erg";
// char str2[]="345345 erg";
// s21_sscanf(str, "%3d%3d", &d, &d2);
// sscanf(str2, "%3d%3d", &d3, &d4);
// printf("%d %d\n", d, d2);
// printf("%d %d",d3, d4);
// return 0;
// }
// для
// длины//----------------------------------------------------------------------------------------------------------------------
// int main(){
//     short int d = 0;
//     short int d2 = 0;
//     long double fl = 0;
//     long double fl2 = 0;
//     //unsigned int a = 0;
//     long int a = 0;
//     long int a2 = 0;
//     //char s[1024];
//     char str[]= "431 5.56 345";
//     char str2[]="431 5.56 345";
//     s21_sscanf(str, "%hd %Lf %li", &d, &fl, &a);
//     sscanf(str2, "%hd %Lf %li", &d2, &fl2, &a2);
//     printf("%hd %Lf %li\n", d, fl, a);
//     printf("%hd %Lf %li", d2, fl2, a2);
//     return 0;
// }

// int main(){
//     int value = 0;
//     int value2 = 0;
//     int value3 = 0;
//     int value4 = 0;
//     int num = 0;
//     int num2 = 0;
//     const char *str = "fd123 4";
//     const char *format = "fd  %d %d %n";
//     int result = s21_sscanf(str, format, &value, &value3, &num);
//     int result2 = sscanf(str, format, &value2, &value4, &num2);
//     printf("%d %d %d %d\n", result, value, value3, num);
//     printf("%d %d %d %d\n", result2, value2, value4, num2);
//     return 0;
// }

// для ld //
// -----------------------------------------------------------------------------------------------------------------------------------------------------------------
// int main(){

//     long int value;
//     long int value2;
//     const char *str = "9223372036854775807";
//     const char *format = "%ld";
//     s21_sscanf(str, format, &value);
//     sscanf(str, format, &value2);
//         printf("%ld\n", value);
//     printf("%ld", value2);
//         return 0;

// }
// для exp //
// -----------------------------------------------------------------------------------------------------------------------------------------------------------------
// int main(){
//     long int value, value2;
//     const char *str = "1E+6";
//     const char *format = "%Ld";
//     s21_sscanf(str, format, &value);
//     sscanf(str, format, &value2);
//     printf("%ld\n", value);
//     printf("%ld", value2);
//         return 0;

// }

// для % \t \n
// *//----------------------------------------------------------------------------------------------------------------------
// int main(){
// int d = 0;
// int d2 = 0;
// char str[]="%2";
// char str2[]="%2";
// s21_sscanf(str, "%%%d", &d);
// sscanf(str2, "%%%d", &d2);
// printf("%d\n", d);
// printf("%d", d2);

// return 0;
// }