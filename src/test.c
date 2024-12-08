#include <stdio.h>
#include <string.h>

#include "s21_string.h"

void memchr_test();
void memcmp_test();
void strlen_test();
void strcmp_test();
void s21_strchr_test();
void null_test();
void size_t_test();
void strstr_test();
void strncpy_test();
void memcpy_test();
void memset_test();
void strcat_test();
void s21_strrchr_test();
void s21_to_upper_test();
void s21_to_lower_test();
void s21_strcspn_test();
void strpbrk_test();
int main() {
  strpbrk_test();
  return 0;
}

void strpbrk_test() {
  const char *str1 = "hello";
  const char *str2 = "l";

  char *result_custom = s21_strpbrk(str1, str2);
  char *result_standard = strpbrk(str1, str2);

  printf("Custom strpbrk result: %s\n", result_custom ? result_custom : "NULL");
  printf("Standard strpbrk result: %s\n",
         result_standard ? result_standard : "NULL");
}
void s21_strcspn_test() {
  const char *str1 = "Hello, World!";
  const char *str2 = "aeiou";

  s21_size_t result1 = s21_strcspn(str1, str2);
  s21_size_t result2 = strcspn(str1, str2);
  printf("Length of initial segment: %lu\n", result1);
  printf("Length of initial segment: %lu\n", result2);
}
void s21_to_lower_test() {
  const char *str = "Hello, World!";
  char *upper_str = (char *)s21_to_lower(str);
  if (upper_str != NULL) {
    printf("Original: %s\n", str);
    printf("Upper: %s\n", upper_str);
    free(upper_str);
  } else {
    printf("Memory allocation failed\n");
  }
}
void s21_to_upper_test() {
  const char *str = "Hello, World!";
  char *upper_str = (char *)s21_to_upper(str);
  if (upper_str != NULL) {
    printf("Original: %s\n", str);
    printf("Upper: %s\n", upper_str);
    free(upper_str);
  } else {
    printf("Memory allocation failed\n");
  }
}
void s21_strrchr_test() {
  char str1[] = "Hellol";
  char *result1 = s21_strrchr(str1, (int)'o');
  char *result2 = strrchr(str1, (int)'o');

  if (result1 != NULL) {
    printf("s21_strchr found: %s\n", result1);
  } else {
    printf("s21_strchr did not find 'o'\n");
  }
  if (result2 != NULL) {
    printf("strchr found: %s\n", result2);
  } else {
    printf("strchr did not find 'o'\n");
  }
}
void strcat_test() {
  char dest1[20] = "Hello ";
  char dest2[20] = "Hello ";
  const char *str = "world";

  s21_strncat(dest1, str, 5);
  strncat(dest2, str, 5);

  printf("Custom strcat result: %s\n", dest1);
  printf("Standard strcat result: %s\n", dest2);
}
void memset_test() {
  char buffer1[20];
  char buffer2[20];
  s21_memset(buffer1, 'A', sizeof(buffer1) - 1);
  memset(buffer2, 'A', sizeof(buffer2) - 1);
  buffer1[sizeof(buffer1) - 1] = '\0';
  buffer2[sizeof(buffer1) - 1] = '\0';

  printf("Buffer after memset: %s\n", buffer1);
  printf("Buffer after memset: %s\n", buffer2);
}
void memcpy_test() {
  char src[] = "Hello, world!";
  char dest1[s21_strlen(src)];
  char dest2[strlen(src)];
  s21_memcpy(dest1, src, sizeof(src));
  memcpy(dest2, src, sizeof(src));
  printf("Destination after memcpy: %s\n", dest1);
  printf("Destination after memcpy: %s\n", dest2);
}
void strncpy_test() {
  char str[] = "Hellol";
  char dest[s21_strlen(str)];
  char *result1 = s21_strncpy(dest, str, 5);
  char *result2 = s21_strncpy(dest, str, 5);
  if (result1 != NULL) {
    printf("dest : %s\n", result1);
  } else {
    printf("NULL\n");
  }
  if (result2 != NULL) {
    printf("dest : %s\n", result2);
  } else {
    printf("NULL\n");
  }
}
void null_test() {
  if (s21_NULL == NULL)
    printf("SUCCESS\n");
  else
    printf("FAIL\n");
}
void size_t_test() {
  if (sizeof(size_t) == sizeof(s21_size_t))
    printf("SUCCESS\n");
  else
    printf("FAIL\n");
}
void memcmp_test() {
  char str1[] = "Hellol";
  char str2[] = "Helloh";
  int result1 = s21_memcmp(str1, str2, 6);
  int result2 = memcmp(str1, str2, 6);
  printf("Result of comparing str1 and str2: %d\n", result1);
  printf("Result of comparing str1 and str3: %d\n", result2);
}
void memchr_test() {
  char str1[] = "Hellol";
  char ch = 'o';
  void *result1 = s21_memchr(str1, (int)'e', 4);
  void *result2 = s21_memchr(str1, (int)'e', 4);
  if (result1 != NULL) {
    printf("Character '%c' found at position: %ld\n", ch,
           (unsigned char *)result1 - (unsigned char *)str1);
  } else {
    printf("Character '%c' not found.\n", ch);
  }
  if (result2 != NULL) {
    printf("Character '%c' found at position: %ld\n", ch,
           (unsigned char *)result2 - (unsigned char *)str1);
  } else {
    printf("Character '%c' not found.\n", ch);
  }
}
void strlen_test() {
  char str1[] = "Hellol";
  int result1 = s21_strlen(str1);
  int result2 = strlen(str1);
  printf("Result of length str1: %d\n", result1);
  printf("Result of length str1: %d\n", result2);
}
void strcmp_test() {
  char str1[] = "Hellol";
  char str2[] = "Helloh";
  int result1 = s21_strncmp(str1, str2, 6);
  int result2 = strncmp(str1, str2, 6);
  printf("Result of comparing str1 and str2: %d\n", result1);
  printf("Result of comparing str1 and str3: %d\n", result2);
}
void s21_strchr_test() {
  char str1[] = "Hellol";
  char *result1 = s21_strchr(str1, (int)'z');
  char *result2 = strchr(str1, (int)'z');

  if (result1 != NULL) {
    printf("s21_strchr found: %s\n", result1);
  } else {
    printf("s21_strchr did not find 'o'\n");
  }
  if (result2 != NULL) {
    printf("strchr found: %s\n", result2);
  } else {
    printf("strchr did not find 'o'\n");
  }
}
void strstr_test() {
  const char *haystack = "Hello, world!";
  const char *needle = "world";

  char *result1 = s21_strstr(haystack, needle);
  char *result2 = strstr(haystack, needle);
  if (result1 != s21_NULL) {
    printf("Found substring: %s\n", result1);
  } else {
    printf("Substring not found.\n");
  }
  if (result2 != s21_NULL) {
    printf("Found substring: %s\n", result2);
  } else {
    printf("Substring not found.\n");
  }
}