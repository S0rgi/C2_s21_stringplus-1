#include <stdio.h>
#include <string.h>

#include "s21_string.h"

void memchr_test();
void memcmp_test();
void strlen_test();
void strcmp_test();
void s21_strchr_test();
int main() {
  s21_strchr_test();
  return 0;
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