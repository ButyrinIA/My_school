#include "../s21_string.h"

#include <stdbool.h>
#include <math.h>

#define BUFF_SIZE 1024

typedef struct tokens {
    int width;
    int accurancy;

    int length;

    int f_plus;
    int f_minus;
    int f_space;
    int f_hashtag ;
    int f_zero;

    int dot;
} tokens;

int s21_format_parser(char* str, const char* format, va_list args, tokens* t, int* counter);
int parse_for_specifies(char* str, char format, va_list args, tokens *t);
void parse_flags(char* flags_str, va_list args, tokens* t);

void initialize_tokens(tokens *t);
void e_counter(char* temp, long double f_value, int accurancy, char mantiss, bool without_zeroes);
int exp_counter(long double f_value);
int parse_specifer(char** format, char* flags_str);
char is_specificator(char format);
void hashtag_flag(char* temp, char format);

void fill_spaces(char* str, int size, int f_minus, int f_zero);
void fill_zeros(char* str, int size);
void remove_zeros(char* str);

int str_to_int(const char* str);
void parse_to_ptr(uint64_t num, char* res);
void parse_to_hex(int num, char* res, char x_specifer);
char* uint_to_char(unsigned int value, char* res);
bool is_char_int(char ch);
void double_to_str(char* res, long double f_val, int accurancy, int f_plus);

void float_specifes(char* str, va_list args, tokens* t);
void string_specifes(char* str, va_list args, tokens* t);
void int_specifes(char* str, va_list args, tokens* t);
int char_specifes(char* str, va_list args);
void ptr_specifes(char* str, va_list args);
void mantissa_specifes(char* str, va_list args, tokens* t, char mantiss);
void hex_specifes(char* str, va_list args, char x_specifer);
void g_specifes(char* str, va_list args, tokens* t, char specificator);
void uint_specifes(char* str, va_list args);
void o_specifes(char* str, va_list args, tokens* t);

void add_to_start(char* str, char ch);