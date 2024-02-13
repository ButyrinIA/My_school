#include "s21_sprintf.h"

void parse_flags(char* flags_str, va_list args, tokens* t) {
  while (*flags_str != '\0') {
    bool not_add = false;
    if (*flags_str == '.') {
      t->dot = 1;
      char for_number[BUFF_SIZE] = "";
      if (is_char_int(*(flags_str + 1))) {
        while (is_char_int(*(flags_str + 1))) {
          s21_strncat(for_number, flags_str + 1, 1);
          flags_str++;
        }
        t->accurancy = str_to_int(for_number);
      } else if (*(flags_str + 1) == '*') {
        t->accurancy = va_arg(args, int);
        flags_str++;
      } else {
        t->accurancy = 0;
      }
    } else if (*flags_str == '+') {
      t->f_plus = 1;
    } else if (*flags_str == '-') {
      t->f_minus = 1;
    } else if (*flags_str == '#') {
      t->f_hashtag = 1;
    } else if (*flags_str == ' ') {
      t->f_space = 1;
    } else if (*flags_str == '0') {
      t->f_zero = 1;
    } else if (is_char_int(*flags_str) && *flags_str != '0') {
      char for_number[BUFF_SIZE] = "";
      while (is_char_int(*flags_str)) {
        s21_strncat(for_number, flags_str, 1);
        flags_str++;
      }
      not_add = true;
      t->width = str_to_int(for_number);
    } else if (*flags_str == '*') {
      int test = va_arg(args, int);
      t->width = test;
    } else if (*flags_str == 'h') {
      t->length = 0;
    } else if (*flags_str == 'l') {
      t->length = 1;
    } else if (*flags_str == 'L') {
      t->length = 2;
    }
    if (!not_add) flags_str++;
  }
}

int parse_specifer(char** format, char* flags_str) {
  char specificator = ' ';
  int stop_flag = 0;
  while (**format != '\0' && !stop_flag) {
    specificator = is_specificator(**format);
    if (specificator != ' ') {
      stop_flag = 1;
    } else {
      s21_strncat(flags_str, *format, 1);
      *(format) += 1;
    }
  }
  return specificator;
}

char is_specificator(char format) {
  const char* specificators = "cdieEfgGosuxXpn%";
  char res = ' ';
  for (size_t i = 0; i < s21_strlen(specificators); i++) {
    if (specificators[i] == format) res = specificators[i];
  }
  return res;
}

int s21_sprintf(char* str, const char* format, ...) {
  va_list args;
  va_start(args, format);
  *str = '\0';

  int flag = 0;
  char* format_temp = (char*)format;

  while (*format_temp != '\0' && flag != -1) {
    if (*format_temp == '%') {
      char specif = ' ';
      char flags_str[1024] = "";

      tokens t = {0};
      initialize_tokens(&t);
      format_temp++;

      specif = parse_specifer(&format_temp, flags_str);
      parse_flags(flags_str, args, &t);
      flag = parse_for_specifies(str, specif, args, &t);

    } else {
      s21_strncat(str, format_temp, 1);
    }
    format_temp++;
  }
  va_end(args);
  return s21_strlen(str);
}

void double_to_str(char* res, long double f_val, int accurancy, int f_plus) {
  char buff[BUFF_SIZE] = {'\0'};
  int idx = BUFF_SIZE - 2;

  bool is_neg = f_val < 0 ? 1 : 0;
  f_val = fabsl(f_val);

  long double l = 0;
  long double r = modfl(f_val, &l);
  if (accurancy == 0) {
    l = roundl(f_val);
    r = 0;
  }
  r = r * pow(10, accurancy);
  long long right = roundl(r), left = l;

  if (!right) {
    for (int i = 0; i < accurancy; idx--, i++) buff[idx] = '0';
  } else if (right == pow(10, accurancy)) {
    left++;
    for (int i = 0; i < accurancy; i++, idx--) {
      buff[idx] = '0';
    }
  } else {
    for (int i = accurancy; right || i > 0; right /= 10, idx--, i--) {
      buff[idx] = (int)(right % 10 + 0.05) + '0';
    }
  }
  if ((accurancy != 0) && (((int)r != 0) || (f_val != 0))) buff[idx--] = '.';
  if (!left) {
    buff[idx] = '0';
    idx--;
  } else {
    for (; left; left /= 10, idx--) buff[idx] = (int)(left % 10) + '0';
  }
  for (int i = 0; buff[idx + 1]; idx++, i++) {
    if (is_neg && i == 0) {
      res[i] = '-';
      i++;
    }
    res[i] = buff[idx + 1];
  }
  if (f_plus && !is_neg) {
    add_to_start(res, '+');
  }
}

void initialize_tokens(tokens* t) {
  t->width = 0;
  t->accurancy = 6;

  t->f_plus = 0;
  t->f_minus = 0;
  t->f_space = 0;
  t->f_hashtag = 0;
  t->f_zero = 0;

  t->dot = 0;
}

int parse_for_specifies(char* str, char format, va_list args, tokens* t) {
  int flag = 0;
  char temp[BUFF_SIZE] = "";
  if (format == 'd' || format == 'i') {
    int_specifes(temp, args, t);
  } else if (format == 'c') {
    flag = char_specifes(temp, args);
  } else if (format == 's') {
    string_specifes(temp, args, t);
  } else if (format == 'f') {
    float_specifes(temp, args, t);
  } else if (format == '%') {
    s21_strncat(temp, "%", 1);
  } else if (format == 'e' || format == 'E') {
    mantissa_specifes(temp, args, t, format);
  } else if (format == 'p') {
    ptr_specifes(temp, args);
  } else if (format == 'x' || format == 'X') {
    hex_specifes(temp, args, format);
  } else if (format == 'g' || format == 'G') {
    g_specifes(temp, args, t, format);
  } else if (format == 'u') {
    uint_specifes(temp, args);
  } else if (format == 'o') {
    o_specifes(temp, args, t);
  }
  if (t->f_hashtag) hashtag_flag(temp, format);
  if ((format == 'o' || format == 'x' || format == 'X' || format == 'u') &&
      t->dot)
    fill_zeros(temp, t->accurancy);
  if (t->width != 0) {
    fill_spaces(temp, t->width, t->f_minus, t->f_zero);
  }

  s21_strncat(str, temp, s21_strlen(temp));

  return flag;
}

void int_specifes(char* temp, va_list args, tokens* t) {
  int i = va_arg(args, int);
  if (t->dot == 1) {
    if (i >= 0) {
      s21_itoa(i, temp, 10);
      if (t->f_plus) {
        add_to_start(temp, '+');
      }
      fill_zeros(temp, t->accurancy);
    } else {
      s21_itoa(abs(i), temp, 10);
      fill_zeros(temp, t->accurancy);
      add_to_start(temp, '-');
    }
  } else {
    s21_itoa(i, temp, 10);
    if (t->f_plus) add_to_start(temp, '+');
  }
}

void uint_specifes(char* temp, va_list args) {
  unsigned int i = va_arg(args, unsigned int);
  uint_to_char(i, temp);
}

int char_specifes(char* str, va_list args) {
  char temp = va_arg(args, int);
  s21_strncat(str, &temp, 1);
  return temp == '\0' ? -1 : 1;
}

void o_specifes(char* temp, va_list args, tokens* t) {
  int i = va_arg(args, int);
  s21_itoa(i, temp, 8);
  if (t->f_hashtag && i != 0) {
    add_to_start(temp, '0');
  }
}

void mantissa_specifes(char* temp, va_list args, tokens* t, char mantiss) {
  long double f_value;
  if (t->length == 2) {
    f_value = va_arg(args, long double);
  } else {
    f_value = va_arg(args, double);
  }
  if (f_value == 0) {
    s21_strncat(temp, "0", 1);
    if (t->accurancy > 0) {
      s21_strncat(temp, ".", 1);
      for (int i = 0; i < t->accurancy; i++) {
        s21_strncat(temp, "0", 1);
      }
    }
    s21_strncat(temp, mantiss == 'e' ? "e+00" : "E+00", 4);
  } else {
    e_counter(temp, f_value, t->accurancy, mantiss, false);
  }

  if (t->f_plus && f_value > 0) {
    add_to_start(temp, '+');
  }
}

int exp_counter(long double f_value) {
  int expa = 0;
  bool sign = f_value < 1 ? true : false;
  if (!sign) {
    while ((long long)f_value > 9) {
      f_value = f_value / 10;
      expa++;
    }
  } else {
    while ((long long)f_value < 1) {
      f_value = f_value * 10;
      expa++;
    }
  }
  expa = sign ? expa * -1 : expa;
  return expa;
}

void e_counter(char* temp, long double f_value, int accurancy, char mantiss,
               bool without_zeroes) {
  bool sign_num = f_value < 0.0 ? false : true;

  f_value = fabsl(f_value);
  int expa = exp_counter(f_value);

  f_value = f_value * pow(10, expa * -1);
  f_value = !sign_num ? f_value * -1 : f_value;
  double_to_str(temp, f_value, accurancy, 0);

  if (without_zeroes) remove_zeros(temp);
  s21_size_t idx = s21_strlen(temp);
  temp[idx++] = mantiss;
  temp[idx++] = expa < 0 ? '-' : '+';
  expa = abs(expa);
  char buff[BUFF_SIZE] = "";
  s21_itoa(expa, buff, 10);
  if (expa < 10) {
    temp[idx++] = '0';
  }

  s21_strncat(temp, buff, s21_strlen(buff));
}

void string_specifes(char* temp, va_list args, tokens* t) {
  const char* temp_str = va_arg(args, const char*);
  s21_strncat(temp, temp_str,
              t->accurancy == -1  ? 0
              : t->accurancy == 6 ? BUFF_SIZE
                                  : t->accurancy);
}

void g_specifes(char* temp, va_list args, tokens* t, char specificator) {
  char temp_e[BUFF_SIZE] = "";
  char temp_f[BUFF_SIZE] = "";

  long double f_value;

  if (t->length == 2) {
    f_value = va_arg(args, long double);
  } else {
    f_value = va_arg(args, double);
  }
  int expa = exp_counter(fabsl(f_value));
  if (t->accurancy > expa && expa >= -4) {
    double_to_str(temp_f, f_value, t->accurancy - (expa + 1), 0);
    remove_zeros(temp_f);
    s21_strncat(temp, temp_f, s21_strlen(temp_f));
  } else {
    e_counter(temp_e, f_value, t->accurancy - 1,
              specificator == 'G' ? 'E' : 'e', true);
    s21_strncat(temp, temp_e, s21_strlen(temp_e));
  }
  if (t->f_plus && f_value > 0.0) {
    add_to_start(temp, '+');
  }
}

void float_specifes(char* temp, va_list args, tokens* t) {
  long double f_value;
  if (t->length == 2) {
    f_value = va_arg(args, long double);
  } else {
    f_value = va_arg(args, double);
  }
  double_to_str(temp, f_value, t->accurancy, t->f_plus);
  if (f_value >= 0.0 && !t->f_plus && t->f_space) {
    add_to_start(temp, ' ');
  }
}

void ptr_specifes(char* temp, va_list args) {
  uint64_t ptr = va_arg(args, uint64_t);
  s21_strncat(temp, "0x", 2);
  parse_to_ptr(ptr, temp);
}

void parse_to_ptr(uint64_t num, char* res) {
  char temp[BUFF_SIZE] = "";

  while (num > 0) {
    int digit = num % 16;
    char ch = digit > 9 ? ('a' + digit - 10) : ('0' + digit);
    num /= 16;
    s21_strncat(temp, &ch, 1);
  }
  s21_strncat(res, s21_strrev(temp), s21_strlen(temp));
}

void parse_to_hex(int num, char* str, char x_specifer) {
  char temp[BUFF_SIZE] = "";
  int sign = num > 0 ? 1 : -1;
  num *= sign;
  char letter = x_specifer == 'x' ? 'a' : 'A';
  while (num > 0) {
    int digit = num % 16;
    char ch;
    ch = digit > 9 ? (letter + digit - 10) : ('0' + digit);
    num /= 16;
    s21_strncat(temp, &ch, 1);
  }
  s21_strncat(str, s21_strrev(temp), s21_strlen(temp));
}

void hex_specifes(char* temp, va_list args, char x_specifer) {
  int num = va_arg(args, int);
  if (num == 0) {
    s21_strncat(temp, "0", 1);
  } else {
    parse_to_hex(num, temp, x_specifer);
  }
}

int str_to_int(const char* str) {
  int digit = 0;
  for (; *str != '\0' && is_char_int(*str); str++) {
    digit *= 10;
    digit += (*str - 48);
  }
  return digit;
}

void remove_zeros(char* str) {
  s21_size_t length = s21_strlen(str) - 1;
  if (s21_strrchr(str, '.') == S21_NULL) return;
  for (; str[length] == '0'; length--) {
    str[length] = '\0';
  }
  if (str[length] == '.') {
    str[length] = '\0';
  }
}

char* uint_to_char(unsigned int value, char* res) {
  char temp[BUFF_SIZE] = "";
  while (value > 0) {
    unsigned int digit = value % 10;
    char ch = digit + '0';
    s21_strncat(temp, &ch, 1);
    value /= 10;
  }
  s21_strncat(res, s21_strrev(temp), s21_strlen(temp));
  return res;
}

void fill_zeros(char* str, int size) {
  s21_strrev(str);
  for (s21_size_t i = s21_strlen(str); (int)i < size; i++) {
    s21_strncat(str, "0", 1);
  }
  s21_strrev(str);
}

void fill_spaces(char* str, int size, int f_minus, int f_zero) {
  if (!f_minus) s21_strrev(str);
  for (s21_size_t i = s21_strlen(str); (int)i < size; i++) {
    s21_strncat(str, f_zero == 0 ? " " : "0", 1);
  }
  if (!f_minus) s21_strrev(str);
}

void add_to_start(char* str, char ch) {
  s21_strrev(str);
  s21_strncat(str, &ch, 1);
  s21_strrev(str);
}

void hashtag_flag(char* temp, char format) {
  if (format == 'x' || format == 'X') {
    s21_strrev(temp);
    s21_strncat(temp, format == 'X' ? "X0" : "x0", 2);
    s21_strrev(temp);
  } else if ((format == 'e' || format == 'E' || format == 'f' ||
              format == 'g' || format == 'G') &&
             (s21_strrchr(temp, '.') == S21_NULL)) {
    s21_strncat(temp, ".", 1);
  }
}

bool is_char_int(char ch) { return ('0' <= ch && ch <= '9'); }