#include <stdarg.h>
// #include <vadefs.h>
//#include <stdio.h>
#include "s21_string.h"
#include <stdlib.h> 
void spec_parse(const char *spec, const char **str, va_list args);
int str_to_int(const char *str);
void process_d(va_list args, const char **str);
void process_s(va_list args, const char **str);
void process_f(va_list args, const char **str);
int main() {
  const char *input = "42.5 21 L lol";
  float num;
  int number;
  char ch;
  char arr[20];
  int count = s21_sscanf(input, "%f %d %c %s", &num, &number, &ch,arr);
  printf("Number-int: %d\n", number);
  printf("Number-float: %f\n",num);
  printf("Char: %c\n", ch);
  printf("Str:%s\n",arr);
  printf("Values read: %d\n", count);

  return 0;
}
int s21_sscanf(const char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  int delim_count=0;
  const char *ptr = str;
  
  while (*format) {
    while (*format !='%') {
      format++;
      delim_count++;
    }
    if (*format == '%') {
      format++;
      spec_parse(format, &ptr, args);
      while (*format && *format != ' ') {
        format++;
      }
    } else {
      if (*ptr != *format) {
        break;
      }
      ptr++;
      format++;
    }
  }

  va_end(args);
  return (ptr - str);
}

void spec_parse(const char *spec, const char **str, va_list args) {
  switch (*spec) {
  case 'd': {
    process_d(args, str);
    break;
  }
  case 's': {
    process_s(args, str);
    break;
  }
  case 'c': {
    char *char_ptr = va_arg(args, char *);
    if (**str != '\0') {
      *char_ptr = **str;
      (*str)++;
    }
    break;
  }
  case 'f':
    process_f(args, str);
    break;
  case 'i':
    break;
  case 'e':
    break;
  case 'E':
    break;

  case 'g':
    break;
  case 'G':
    break;
  case 'o':
    break;
  case 'u':
    break;
  case 'x':
    break;
  case 'X':
    break;
  case 'p':
    break;
  case 'n':
    break;
  default:
    break;
  }
}

int str_to_int(const char *str) {
  if (str == s21_NULL || *str == '\0') {
    return 0;
  }

  int sign = 1;
  int result = 0;

  if (*str == '-') {
    sign = -1;
    str++;
  } else if (*str == '+') {
    str++;
  }

  for (s21_size_t i = 0; i < s21_strlen(str); i++) {
    if (str[i] < '0' || str[i] > '9') {
      break;
    }

    result = result * 10 + (str[i] - '0');
  }

  return sign * result;
}
void process_d(va_list args, const char **str) {
  int *int_ptr = va_arg(args, int *);
  char num[20];
  s21_size_t i = 0;

  while (**str >= '0' && **str <= '9' && i < sizeof(num) - 1) {
    num[i++] = **str;
    (*str)++;
  }
  num[i] = '\0';
  *int_ptr = str_to_int(num);
}
void process_s(va_list args, const char **str) {
  char *str_ptr = va_arg(args, char *);
  s21_size_t i = 0;

  while (**str != ' ' && **str != '\0' && i < 99) {
    str_ptr[i++] = **str;
    (*str)++;
  }
  str_ptr[i] = '\0';
}
void process_f(va_list args, const char **str) {
    float *float_ptr = va_arg(args, float *);
    char num[20];
    s21_size_t i = 0;

    while ((**str >= '0' && **str <= '9') || **str == '.' || **str == '-' || **str == '+') {
        if (i < sizeof(num) - 1) {
            num[i++] = **str;
            (*str)++;
        } else {
            break;
        }
    }

    num[i] = '\0';

    if (i > 0) {
        *float_ptr = (float) atof(num);
    } else {
        *float_ptr = 0.0f;
    }
}