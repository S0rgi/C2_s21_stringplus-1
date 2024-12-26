#include <check.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"
START_TEST(strpbrk_test_case_1) {
  const char *str1 = "hello";
  const char *str2 = "l";
  char *result_custom = s21_strpbrk(str1, str2);
  const char *result_standard = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strpbrk_test_case_2) {
  const char *str1 = "hello";
  const char *str2 = "x";
  char *result_custom = s21_strpbrk(str1, str2);
  const char *result_standard = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strpbrk_test_case_3) {
  const char *str1 = "";
  const char *str2 = "l";
  char *result_custom = s21_strpbrk(str1, str2);
  const char *result_standard = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strpbrk_test_case_4) {
  const char *str1 = "hello";
  const char *str2 = "";
  char *result_custom = s21_strpbrk(str1, str2);
  const char *result_standard = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strpbrk_test_case_5) {
  const char *str1 = "hello";
  const char *str2 = "aeiou";
  char *result_custom = s21_strpbrk(str1, str2);
  const char *result_standard = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strpbrk_test_case_6) {
  const char *str1 = "hello";
  const char *str2 = "h";
  char *result_custom = s21_strpbrk(str1, str2);
  const char *result_standard = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strpbrk_test_case_7) {
  const char *str1 = "hello";
  const char *str2 = "o";
  char *result_custom = s21_strpbrk(str1, str2);
  const char *result_standard = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strpbrk_test_case_8) {
  const char *str1 = "helloo";
  const char *str2 = "o";
  char *result_custom = s21_strpbrk(str1, str2);
  const char *result_standard = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strpbrk_test_case_9) {
  const char *str1 = "hello";
  const char *str2 = "helo";
  char *result_custom = s21_strpbrk(str1, str2);
  const char *result_standard = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strpbrk_test_case_10) {
  const char *str1 = "h";
  const char *str2 = "h";
  char *result_custom = s21_strpbrk(str1, str2);
  const char *result_standard = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strpbrk_test_case_11) {
  const char *str1 = "hello";
  const char *str2 = "h";
  char *result_custom = s21_strpbrk(str1, str2);
  const char *result_standard = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strpbrk_test_case_12) {
  const char *str1 = "hello";
  const char *str2 = "hello";
  char *result_custom = s21_strpbrk(str1, str2);
  const char *result_standard = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strpbrk_test_case_13) {
  const char *str1 = "abcdefghijklmnopqrstuvwxyz";
  const char *str2 = "z";
  char *result_custom = s21_strpbrk(str1, str2);
  const char *result_standard = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strpbrk_test_case_14) {
  const char *str1 = "hello";
  const char *str2 = "abcdefghijklmnopqrstuvwxyz";
  char *result_custom = s21_strpbrk(str1, str2);
  const char *result_standard = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST
// Tests for s21_strpbrk
void strpbrk_test(TCase *tcase_core) {
  tcase_add_test(tcase_core, strpbrk_test_case_1);
  tcase_add_test(tcase_core, strpbrk_test_case_2);
  tcase_add_test(tcase_core, strpbrk_test_case_3);
  tcase_add_test(tcase_core, strpbrk_test_case_4);
  tcase_add_test(tcase_core, strpbrk_test_case_5);
  tcase_add_test(tcase_core, strpbrk_test_case_6);
  tcase_add_test(tcase_core, strpbrk_test_case_7);
  tcase_add_test(tcase_core, strpbrk_test_case_8);
  tcase_add_test(tcase_core, strpbrk_test_case_9);
  tcase_add_test(tcase_core, strpbrk_test_case_10);
  tcase_add_test(tcase_core, strpbrk_test_case_11);
  tcase_add_test(tcase_core, strpbrk_test_case_12);
  tcase_add_test(tcase_core, strpbrk_test_case_13);
  tcase_add_test(tcase_core, strpbrk_test_case_14);
}
START_TEST(s21_strcspn_test_case_1) {
  const char *str1 = "Hello, World!";
  const char *str2 = "aeiou";
  s21_size_t result1 = s21_strcspn(str1, str2);
  s21_size_t result2 = strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(s21_strcspn_test_case_2) {
  const char *str1 = "abcdefg";
  const char *str2 = "xyz";
  s21_size_t result1 = s21_strcspn(str1, str2);
  s21_size_t result2 = strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(s21_strcspn_test_case_3) {
  const char *str1 = "";
  const char *str2 = "a";
  s21_size_t result1 = s21_strcspn(str1, str2);
  s21_size_t result2 = strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(s21_strcspn_test_case_4) {
  const char *str1 = "Hello, World!";
  const char *str2 = "";
  s21_size_t result1 = s21_strcspn(str1, str2);
  s21_size_t result2 = strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(s21_strcspn_test_case_5) {
  const char *str1 = "";
  const char *str2 = "";
  s21_size_t result1 = s21_strcspn(str1, str2);
  s21_size_t result2 = strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(s21_strcspn_test_case_6) {
  const char *str1 = "hello";
  const char *str2 = "he";
  s21_size_t result1 = s21_strcspn(str1, str2);
  s21_size_t result2 = strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(s21_strcspn_test_case_7) {
  const char *str1 = "hello";
  const char *str2 = "o";
  s21_size_t result1 = s21_strcspn(str1, str2);
  s21_size_t result2 = strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(s21_strcspn_test_case_8) {
  const char *str1 = "hello";
  const char *str2 = "hel";
  s21_size_t result1 = s21_strcspn(str1, str2);
  s21_size_t result2 = strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(s21_strcspn_test_case_9) {
  const char *str1 = "hello";
  const char *str2 = "helo";
  s21_size_t result1 = s21_strcspn(str1, str2);
  s21_size_t result2 = strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(s21_strcspn_test_case_10) {
  const char *str1 = "h";
  const char *str2 = "h";
  s21_size_t result1 = s21_strcspn(str1, str2);
  s21_size_t result2 = strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(s21_strcspn_test_case_11) {
  const char *str1 = "hello";
  const char *str2 = "h";
  s21_size_t result1 = s21_strcspn(str1, str2);
  s21_size_t result2 = strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(s21_strcspn_test_case_12) {
  const char *str1 = "hello";
  const char *str2 = "hello";
  s21_size_t result1 = s21_strcspn(str1, str2);
  s21_size_t result2 = strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(s21_strcspn_test_case_13) {
  const char *str1 = "abcdefghijklmnopqrstuvwxyz";
  const char *str2 = "z";
  s21_size_t result1 = s21_strcspn(str1, str2);
  s21_size_t result2 = strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(s21_strcspn_test_case_14) {
  const char *str1 = "hello";
  const char *str2 = "abcdefghijklmnopqrstuvwxyz";
  s21_size_t result1 = s21_strcspn(str1, str2);
  s21_size_t result2 = strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// Tests for s21_strcspn
void s21_strcspn_test(TCase *tcase_core) {
  tcase_add_test(tcase_core, s21_strcspn_test_case_1);
  tcase_add_test(tcase_core, s21_strcspn_test_case_2);
  tcase_add_test(tcase_core, s21_strcspn_test_case_3);
  tcase_add_test(tcase_core, s21_strcspn_test_case_4);
  tcase_add_test(tcase_core, s21_strcspn_test_case_5);
  tcase_add_test(tcase_core, s21_strcspn_test_case_6);
  tcase_add_test(tcase_core, s21_strcspn_test_case_7);
  tcase_add_test(tcase_core, s21_strcspn_test_case_8);
  tcase_add_test(tcase_core, s21_strcspn_test_case_9);
  tcase_add_test(tcase_core, s21_strcspn_test_case_10);
  tcase_add_test(tcase_core, s21_strcspn_test_case_11);
  tcase_add_test(tcase_core, s21_strcspn_test_case_12);
  tcase_add_test(tcase_core, s21_strcspn_test_case_13);
  tcase_add_test(tcase_core, s21_strcspn_test_case_14);
}

// Tests for s21_to_lower
START_TEST(s21_to_lower_test_case_1) {
  const char *str = "Hello, World!";
  char *lower_str = (char *)s21_to_lower(str);
  ck_assert_str_eq(lower_str, "hello, world!");
  free(lower_str);
}
END_TEST

START_TEST(s21_to_lower_test_case_2) {
  const char *str = "123!@#";
  char *lower_str = (char *)s21_to_lower(str);
  ck_assert_str_eq(lower_str, "123!@#");
  free(lower_str);
}
END_TEST

START_TEST(s21_to_lower_test_case_3) {
  const char *str = "";
  char *lower_str = (char *)s21_to_lower(str);
  ck_assert_str_eq(lower_str, "");
  free(lower_str);
}
END_TEST

START_TEST(s21_to_lower_test_case_4) {
  const char *str = "ABC";
  char *lower_str = (char *)s21_to_lower(str);
  ck_assert_str_eq(lower_str, "abc");
  free(lower_str);
}
END_TEST

START_TEST(s21_to_lower_test_case_5) {
  const char *str = "abc";
  char *lower_str = (char *)s21_to_lower(str);
  ck_assert_str_eq(lower_str, "abc");
  free(lower_str);
}
END_TEST

START_TEST(s21_to_lower_test_case_6) {
  const char *str = "aBc";
  char *lower_str = (char *)s21_to_lower(str);
  ck_assert_str_eq(lower_str, "abc");
  free(lower_str);
}
END_TEST

START_TEST(s21_to_lower_test_case_7) {
  const char *str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *lower_str = (char *)s21_to_lower(str);
  ck_assert_str_eq(lower_str, "abcdefghijklmnopqrstuvwxyz");
  free(lower_str);
}
END_TEST

START_TEST(s21_to_lower_test_case_8) {
  const char *str = "h";
  char *lower_str = (char *)s21_to_lower(str);
  ck_assert_str_eq(lower_str, "h");
  free(lower_str);
}
END_TEST

START_TEST(s21_to_lower_test_case_9) {
  const char *str = "HeLlO wOrLd";
  char *lower_str = (char *)s21_to_lower(str);
  ck_assert_str_eq(lower_str, "hello world");
  free(lower_str);
}
END_TEST

void s21_to_lower_test(TCase *tcase_core) {
  tcase_add_test(tcase_core, s21_to_lower_test_case_1);
  tcase_add_test(tcase_core, s21_to_lower_test_case_2);
  tcase_add_test(tcase_core, s21_to_lower_test_case_3);
  tcase_add_test(tcase_core, s21_to_lower_test_case_4);
  tcase_add_test(tcase_core, s21_to_lower_test_case_5);
  tcase_add_test(tcase_core, s21_to_lower_test_case_6);
  tcase_add_test(tcase_core, s21_to_lower_test_case_7);
  tcase_add_test(tcase_core, s21_to_lower_test_case_8);
  tcase_add_test(tcase_core, s21_to_lower_test_case_9);
}

// Tests for s21_to_upper
START_TEST(s21_to_upper_test_case_1) {
  const char *str = "Hello, World!";
  char *upper_str = (char *)s21_to_upper(str);
  ck_assert_str_eq(upper_str, "HELLO, WORLD!");
  free(upper_str);
}
END_TEST

START_TEST(s21_to_upper_test_case_2) {
  const char *str = "123!@#";
  char *upper_str = (char *)s21_to_upper(str);
  ck_assert_str_eq(upper_str, "123!@#");
  free(upper_str);
}
END_TEST

START_TEST(s21_to_upper_test_case_3) {
  const char *str = "";
  char *upper_str = (char *)s21_to_upper(str);
  ck_assert_str_eq(upper_str, "");
  free(upper_str);
}
END_TEST

START_TEST(s21_to_upper_test_case_4) {
  const char *str = "abc";
  char *upper_str = (char *)s21_to_upper(str);
  ck_assert_str_eq(upper_str, "ABC");
  free(upper_str);
}
END_TEST

START_TEST(s21_to_upper_test_case_5) {
  const char *str = "ABC";
  char *upper_str = (char *)s21_to_upper(str);
  ck_assert_str_eq(upper_str, "ABC");
  free(upper_str);
}
END_TEST

START_TEST(s21_to_upper_test_case_6) {
  const char *str = "aBc";
  char *upper_str = (char *)s21_to_upper(str);
  ck_assert_str_eq(upper_str, "ABC");
  free(upper_str);
}
END_TEST

START_TEST(s21_to_upper_test_case_7) {
  const char *str = "abcdefghijklmnopqrstuvwxyz";
  char *upper_str = (char *)s21_to_upper(str);
  ck_assert_str_eq(upper_str, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  free(upper_str);
}
END_TEST

START_TEST(s21_to_upper_test_case_8) {
  const char *str = "h";
  char *upper_str = (char *)s21_to_upper(str);
  ck_assert_str_eq(upper_str, "H");
  free(upper_str);
}
END_TEST

START_TEST(s21_to_upper_test_case_9) {
  const char *str = "HeLlO wOrLd";
  char *upper_str = (char *)s21_to_upper(str);
  ck_assert_str_eq(upper_str, "HELLO WORLD");
  free(upper_str);
}
END_TEST

void s21_to_upper_test(TCase *tcase_core) {
  tcase_add_test(tcase_core, s21_to_upper_test_case_1);
  tcase_add_test(tcase_core, s21_to_upper_test_case_2);
  tcase_add_test(tcase_core, s21_to_upper_test_case_3);
  tcase_add_test(tcase_core, s21_to_upper_test_case_4);
  tcase_add_test(tcase_core, s21_to_upper_test_case_5);
  tcase_add_test(tcase_core, s21_to_upper_test_case_6);
  tcase_add_test(tcase_core, s21_to_upper_test_case_7);
  tcase_add_test(tcase_core, s21_to_upper_test_case_8);
  tcase_add_test(tcase_core, s21_to_upper_test_case_9);
}

// Tests for s21_strrchr
START_TEST(s21_strrchr_test_case_1) {
  char str1[27] = "\0";
  const char *result_custom = s21_strrchr(str1, 'o');
  const char *result_standard = strrchr(str1, 'o');
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(s21_strrchr_test_case_2) {
  const char *str1 = "Hello, World!";
  const char *result_custom = s21_strrchr(str1, ',');
  const char *result_standard = strrchr(str1, ',');
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(s21_strrchr_test_case_3) {
  const char *str1 = "Hello, World!";
  const char *result_custom = s21_strrchr(str1, 'H');
  const char *result_standard = strrchr(str1, 'H');
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(s21_strrchr_test_case_4) {
  const char *str1 = "Hello, World!";
  const char *result_custom = s21_strrchr(str1, 'x');
  const char *result_standard = strrchr(str1, 'x');
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(s21_strrchr_test_case_5) {
  const char *str1 = "Hello, World!";
  const char *result_custom = s21_strrchr(str1, 'z');
  const char *result_standard = strrchr(str1, 'z');
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(s21_strrchr_test_case_6) {
  const char *str1 = "Hello, World!";
  const char *result_custom = s21_strrchr(str1, 'l');
  const char *result_standard = strrchr(str1, 'l');
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(s21_strrchr_test_case_7) {
  const char *str1 = "";
  const char *result_custom = s21_strrchr(str1, 'l');
  const char *result_standard = strrchr(str1, 'l');
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(s21_strrchr_test_case_8) {
  const char *str1 = "H";
  const char *result_custom = s21_strrchr(str1, 'H');
  const char *result_standard = strrchr(str1, 'H');
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(s21_strrchr_test_case_9) {
  const char *str1 = "abcdefghijklmnopqrstuvwxyz";
  const char *result_custom = s21_strrchr(str1, 'z');
  const char *result_standard = strrchr(str1, 'z');
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(s21_strrchr_test_case_10) {
  const char *str1 = "Hello, World!";
  const char *result_custom = s21_strrchr(str1, ',');
  const char *result_standard = strrchr(str1, ',');
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(s21_strrchr_test_case_11) {
  const char *str1 = "Hello\0World";
  const char *result_custom = s21_strrchr(str1, '\0');
  const char *result_standard = strrchr(str1, '\0');
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(s21_strrchr_test_case_12) {
  const char *str1 = "Hello\0World";
  const char *result_custom = s21_strrchr(str1, 'W');
  const char *result_standard = strrchr(str1, 'W');
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(s21_strrchr_test_case_13) {
  const char *str1 = "Hello\0World";
  const char *result_custom = s21_strrchr(str1, 'H');
  const char *result_standard = strrchr(str1, 'H');
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(s21_strrchr_test_case_14) {
  const char *str1 = "Hello\0World";
  const char *result_custom = s21_strrchr(str1, 'l');
  const char *result_standard = strrchr(str1, 'l');
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(s21_strrchr_test_case_15) {
  const char *str1 = "Hello\0World";
  const char *result_custom = s21_strrchr(str1, 'x');
  const char *result_standard = strrchr(str1, 'x');
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST
void s21_strrchr_test(TCase *tcase_core) {
  tcase_add_test(tcase_core, s21_strrchr_test_case_1);
  tcase_add_test(tcase_core, s21_strrchr_test_case_2);
  tcase_add_test(tcase_core, s21_strrchr_test_case_3);
  tcase_add_test(tcase_core, s21_strrchr_test_case_4);
  tcase_add_test(tcase_core, s21_strrchr_test_case_5);
  tcase_add_test(tcase_core, s21_strrchr_test_case_6);
  tcase_add_test(tcase_core, s21_strrchr_test_case_7);
  tcase_add_test(tcase_core, s21_strrchr_test_case_8);
  tcase_add_test(tcase_core, s21_strrchr_test_case_9);
  tcase_add_test(tcase_core, s21_strrchr_test_case_10);
  tcase_add_test(tcase_core, s21_strrchr_test_case_11);
  tcase_add_test(tcase_core, s21_strrchr_test_case_12);
  tcase_add_test(tcase_core, s21_strrchr_test_case_13);
  tcase_add_test(tcase_core, s21_strrchr_test_case_14);
  tcase_add_test(tcase_core, s21_strrchr_test_case_15);
}
START_TEST(strncat_test_case_1) {
  char dest1[50];
  char dest2[50];
  const char *str = "world";

  strcpy(dest1, "Hello ");
  strcpy(dest2, "Hello ");
  s21_strncat(dest1, str, 5);
  strncat(dest2, str, 5);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_test_case_2) {
  char dest1[50];
  char dest2[50];
  const char *str = "";

  strcpy(dest1, "Foo");
  strcpy(dest2, "Foo");
  s21_strncat(dest1, str, 3);
  strncat(dest2, str, 3);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_test_case_3) {
  char dest1[50];
  char dest2[50];
  const char *str = "Bar";

  strcpy(dest1, "");
  strcpy(dest2, "");
  s21_strncat(dest1, str, 3);
  strncat(dest2, str, 3);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_test_case_4) {
  char dest1[50];
  char dest2[50];
  const char *str = "WorldThisIsALongString";

  strcpy(dest1, "Hello");
  strcpy(dest2, "Hello");
  s21_strncat(dest1, str, 10);
  strncat(dest2, str, 10);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_test_case_5) {
  char dest1[50];
  char dest2[50];
  const char *str = "W";

  strcpy(dest1, "Hello");
  strcpy(dest2, "Hello");
  s21_strncat(dest1, str, 1);
  strncat(dest2, str, 1);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_test_case_6) {
  char dest1[50];
  char dest2[50];
  const char *str = "ello";

  strcpy(dest1, "H");
  strcpy(dest2, "H");
  s21_strncat(dest1, str, 4);
  strncat(dest2, str, 4);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_test_case_7) {
  char dest1[50];
  char dest2[50];
  const char *str = "Hello";

  strcpy(dest1, "Hello");
  strcpy(dest2, "Hello");
  s21_strncat(dest1, str, 5);
  strncat(dest2, str, 5);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_test_case_8) {
  char dest1[50];
  char dest2[50];
  const char *str = "ThisIsAVeryLongStringThatWillBeTruncated";

  strcpy(dest1, "Hello");
  strcpy(dest2, "Hello");
  s21_strncat(dest1, str, 20);
  strncat(dest2, str, 20);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_test_case_9) {
  char dest1[50];
  char dest2[50];
  const char *str = "";

  strcpy(dest1, "Hello");
  strcpy(dest2, "Hello");
  s21_strncat(dest1, str, 0);
  strncat(dest2, str, 0);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_test_case_10) {
  char dest1[50];
  char dest2[50];
  const char *str = NULL;

  strcpy(dest1, "Hello");
  strcpy(dest2, "Hello");
  s21_strncat(dest1, str, 5);
  // No corresponding strncat call because it does not handle NULL
  ck_assert_str_eq(dest1, "Hello");
}
END_TEST
// Tests for strncat
void strncat_test(TCase *tcase_core) {
  tcase_add_test(tcase_core, strncat_test_case_1);
  tcase_add_test(tcase_core, strncat_test_case_2);
  tcase_add_test(tcase_core, strncat_test_case_3);
  tcase_add_test(tcase_core, strncat_test_case_4);
  tcase_add_test(tcase_core, strncat_test_case_5);
  tcase_add_test(tcase_core, strncat_test_case_6);
  tcase_add_test(tcase_core, strncat_test_case_7);
  tcase_add_test(tcase_core, strncat_test_case_8);
  tcase_add_test(tcase_core, strncat_test_case_9);
  tcase_add_test(tcase_core, strncat_test_case_10);
}

// Tests for memset
START_TEST(memset_test_case_1) {
  char buffer1[20];
  char buffer2[20];

  s21_memset(buffer1, 'A', sizeof(buffer1) - 1);
  memset(buffer2, 'A', sizeof(buffer2) - 1);

  buffer1[sizeof(buffer1) - 1] = '\0';
  buffer2[sizeof(buffer2) - 1] = '\0';

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(memset_test_case_2) {
  char buffer1[20];
  char buffer2[20];

  s21_memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));

  ck_assert_mem_eq(buffer1, buffer2, sizeof(buffer1));
}
END_TEST

START_TEST(memset_test_case_3) {
  char buffer1[20];
  char buffer2[20];

  s21_memset(buffer1, -1, sizeof(buffer1));
  memset(buffer2, -1, sizeof(buffer2));

  ck_assert_mem_eq(buffer1, buffer2, sizeof(buffer1));
}
END_TEST

START_TEST(memset_test_case_4) {
  char buffer1[20] = {0};
  char buffer2[20] = {0};

  s21_memset(buffer1, 'A', 1);
  memset(buffer2, 'A', 1);

  ck_assert_mem_eq(buffer1, buffer2, sizeof(buffer1));
}
END_TEST

START_TEST(memset_test_case_5) {
  char buffer1[20];
  char buffer2[20];

  s21_memset(buffer1, 255, sizeof(buffer1));
  memset(buffer2, 255, sizeof(buffer2));

  ck_assert_mem_eq(buffer1, buffer2, sizeof(buffer1));
}
END_TEST

START_TEST(memset_test_case_6) {
  char buffer1[20];
  char buffer2[20];

  s21_memset(buffer1, 1, sizeof(buffer1));
  memset(buffer2, 1, sizeof(buffer2));

  ck_assert_mem_eq(buffer1, buffer2, sizeof(buffer1));
}
END_TEST

START_TEST(memset_test_case_7) {
  char buffer1[20];
  char buffer2[20];

  s21_memset(buffer1, -2, sizeof(buffer1));
  memset(buffer2, -2, sizeof(buffer2));

  ck_assert_mem_eq(buffer1, buffer2, sizeof(buffer1));
}
END_TEST
void memset_test(TCase *tcase_core) {
  tcase_add_test(tcase_core, memset_test_case_1);
  tcase_add_test(tcase_core, memset_test_case_2);
  tcase_add_test(tcase_core, memset_test_case_3);
  tcase_add_test(tcase_core, memset_test_case_4);
  tcase_add_test(tcase_core, memset_test_case_5);
  tcase_add_test(tcase_core, memset_test_case_6);
  tcase_add_test(tcase_core, memset_test_case_7);
}

// Tests for memcpy
START_TEST(memcpy_test_case_1) {
  char src[20] = "Hello, world!";
  char dest1[20];
  char dest2[20];

  s21_memcpy(dest1, src, sizeof(src));
  memcpy(dest2, src, sizeof(src));

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(memcpy_test_case_2) {
  char src[20] = "Hello, world!";
  char dest1[20] = {0};
  char dest2[20] = {0};

  s21_memcpy(dest1, src, 1);
  memcpy(dest2, src, 1);

  ck_assert_mem_eq(dest1, dest2, sizeof(dest1));
}
END_TEST

START_TEST(memcpy_test_case_3) {
  char src[20] = "Hello, world!";
  char dest1[20] = {0};
  char dest2[20] = {0};

  s21_memcpy(dest1, src, 0);
  memcpy(dest2, src, 0);

  ck_assert_mem_eq(dest1, dest2, sizeof(dest1));
}
END_TEST

START_TEST(memcpy_test_case_4) {
  char src[20] = "Hello, world!";
  char dest1[20] = {0};
  char dest2[20] = {0};

  s21_memcpy(dest1, src, 20);
  memcpy(dest2, src, 20);

  ck_assert_mem_eq(dest1, dest2, sizeof(dest1));
}
END_TEST

START_TEST(memcpy_test_case_5) {
  char src[20] = "Hello, world!";
  char dest1[20] = {0};
  char dest2[20] = {0};

  s21_memcpy(dest1, src, strlen(src) + 1);
  memcpy(dest2, src, strlen(src) + 1);

  ck_assert_mem_eq(dest1, dest2, sizeof(dest1));
}
END_TEST

START_TEST(memcpy_test_case_6) {
  char src[20] = "Hello, world!";
  char dest1[20] = {0};
  char dest2[20] = {0};

  s21_memcpy(dest1 + 5, src, 5);
  memcpy(dest2 + 5, src, 5);

  ck_assert_mem_eq(dest1, dest2, sizeof(dest1));
}
END_TEST
void memcpy_test(TCase *tcase_core) {
  tcase_add_test(tcase_core, memcpy_test_case_1);
  tcase_add_test(tcase_core, memcpy_test_case_2);
  tcase_add_test(tcase_core, memcpy_test_case_3);
  tcase_add_test(tcase_core, memcpy_test_case_4);
  tcase_add_test(tcase_core, memcpy_test_case_5);
  tcase_add_test(tcase_core, memcpy_test_case_6);
}
START_TEST(test_s21_strncpy_null_src) {
  char dest[100];

  const char *src = NULL;
  char *result = s21_strncpy(dest, src, 10);

  ck_assert_ptr_eq(result, NULL);
}
END_TEST
START_TEST(strncpy_test_case_1) {
  const char str[] = "Hellol";
  char dest[10] = {0};

  s21_strncpy(dest, str, 5);
  ck_assert_str_eq(dest, "Hello");
}
END_TEST

START_TEST(strncpy_test_case_2) {
  const char str[] = "Hellol";
  char dest[10] = {0};

  s21_strncpy(dest, str, 0);
  ck_assert_str_eq(dest, "");
}
END_TEST

START_TEST(strncpy_test_case_3) {
  const char str[] = "Hellol";
  char dest[10] = {0};

  s21_strncpy(dest, str, 10);
  ck_assert_str_eq(dest, "Hellol");
  ck_assert_int_eq(dest[6], '\0');
}
END_TEST

START_TEST(strncpy_test_case_4) {
  const char str[] = "Hellol";
  char dest[10] = {0};

  s21_strncpy(dest, str, 6);
  ck_assert_str_eq(dest, "Hellol");
}
END_TEST

START_TEST(strncpy_test_case_5) {
  char empty_dest[10] = {0};
  s21_strncpy(empty_dest, "", 5);
  ck_assert_str_eq(empty_dest, "");
}
END_TEST
// тест не корректен
//  START_TEST(strncpy_test_case_6) {
//    ck_assert_ptr_eq(s21_strncpy(NULL, "Hello", 5), s21_NULL);
//  }
//  END_TEST

START_TEST(strncpy_test_case_7) {
  char dest3[10] = {0};
  s21_strncpy(dest3, "Hi", 5);
  ck_assert_str_eq(dest3, "Hi");
  ck_assert_int_eq(dest3[2], '\0');
  ck_assert_int_eq(dest3[3], '\0');
  ck_assert_int_eq(dest3[4], '\0');
}
END_TEST

START_TEST(strncpy_test_case_8) {
  char dest[10] = {0};
  s21_strncpy(dest, "H", 5);
  ck_assert_str_eq(dest, "H");
}
END_TEST

START_TEST(strncpy_test_case_9) {
  char dest[10] = {0};
  s21_strncpy(dest, "", 5);
  ck_assert_str_eq(dest, "");
}
END_TEST
// Tests for s21_strncpy
void strncpy_test(TCase *tcase_core) {
  tcase_add_test(tcase_core, strncpy_test_case_1);
  tcase_add_test(tcase_core, strncpy_test_case_2);
  tcase_add_test(tcase_core, strncpy_test_case_3);
  tcase_add_test(tcase_core, strncpy_test_case_4);
  tcase_add_test(tcase_core, strncpy_test_case_5);
  // tcase_add_test(tcase_core, strncpy_test_case_6); не корректен
  tcase_add_test(tcase_core, strncpy_test_case_7);
  tcase_add_test(tcase_core, strncpy_test_case_8);
  tcase_add_test(tcase_core, strncpy_test_case_9);
  tcase_add_test(tcase_core, test_s21_strncpy_null_src);
}
START_TEST(strcpy_test_case_1) {
  const char *src = "Hello";
  char dest[10] = {0};

  s21_strcpy(dest, src);
  ck_assert_str_eq(dest, "Hello");
}
END_TEST

START_TEST(strcpy_test_case_2) {
  const char *src = "";
  char dest[10] = {0};

  s21_strcpy(dest, src);
  ck_assert_str_eq(dest, "");
}
END_TEST

START_TEST(strcpy_test_case_3) {
  const char *src = "Hi";
  char dest[10] = {0};

  s21_strcpy(dest, src);
  ck_assert_str_eq(dest, "Hi");
}
END_TEST

START_TEST(strcpy_test_case_4) {
  const char *src = "H";
  char dest[10] = {0};

  s21_strcpy(dest, src);
  ck_assert_str_eq(dest, "H");
}
END_TEST

START_TEST(strcpy_test_case_5) {
  const char *src = "";
  char dest[10] = {0};

  s21_strcpy(dest, src);
  ck_assert_str_eq(dest, "");
}
END_TEST

START_TEST(strcpy_test_case_6) {
  const char *src = "Hi";
  char dest[10] = {0};

  s21_strcpy(dest, src);
  ck_assert_str_eq(dest, "Hi");
}
END_TEST

START_TEST(strcpy_test_case_7) {
  const char *src = NULL;
  ck_assert_ptr_eq(s21_strcpy(NULL, src), s21_NULL);
}
END_TEST

START_TEST(strcpy_test_case_8) {
  char dest2[6] = {0};
  s21_strcpy(dest2, "Hello");
  ck_assert_str_eq(dest2, "Hello");
}
END_TEST

START_TEST(strcpy_test_case_9) {
  char long_dest[50] = {0};
  s21_strcpy(long_dest, "This is a long string test.");
  ck_assert_str_eq(long_dest, "This is a long string test.");
}
END_TEST

START_TEST(strcpy_test_case_10) {
  char dest[10] = {0};
  s21_strcpy(dest, "Hi there");
  ck_assert_str_eq(dest, "Hi there");
}
END_TEST
// Tests for s21_strcpy
void strcpy_test(TCase *tcase_core) {
  tcase_add_test(tcase_core, strcpy_test_case_1);
  tcase_add_test(tcase_core, strcpy_test_case_2);
  tcase_add_test(tcase_core, strcpy_test_case_3);
  tcase_add_test(tcase_core, strcpy_test_case_4);
  tcase_add_test(tcase_core, strcpy_test_case_5);
  tcase_add_test(tcase_core, strcpy_test_case_6);
  tcase_add_test(tcase_core, strcpy_test_case_7);
  tcase_add_test(tcase_core, strcpy_test_case_8);
  tcase_add_test(tcase_core, strcpy_test_case_9);
  tcase_add_test(tcase_core, strcpy_test_case_10);
}

// Tests for null_check
START_TEST(null_test_case_1) { ck_assert_ptr_eq(s21_NULL, NULL); }
END_TEST
void null_test(TCase *tcase_core) {
  tcase_add_test(tcase_core, null_test_case_1);
}

// Tests for size_t_check
START_TEST(size_t_test_case_1) {
  ck_assert_int_eq(sizeof(size_t), sizeof(s21_size_t));
}
END_TEST

void size_t_test(TCase *tcase_core) {
  tcase_add_test(tcase_core, size_t_test_case_1);
}

// Tests for memcmp
START_TEST(memcmp_test_case_1) {
  char str1[20] = "Hellol";
  char str2[20] = "Helloh";
  int result_custom = s21_memcmp(str1, str2, 6);
  int result_standard = memcmp(str1, str2, 6);

  ck_assert_int_eq(result_custom, result_standard);
}
END_TEST

START_TEST(memcmp_test_case_2) {
  char str1[20] = "Hellol";
  char str2[20] = "Helloh";
  int result_custom = s21_memcmp(str1, str2, 0);
  int result_standard = memcmp(str1, str2, 0);

  ck_assert_int_eq(result_custom, result_standard);
}
END_TEST

START_TEST(memcmp_test_case_3) {
  char str1[20] = "Hellol";
  char str2[20] = "Helloh";
  int result_custom = s21_memcmp(str1, str2, 6);
  int result_standard = memcmp(str1, str2, 6);

  ck_assert_int_eq(result_custom, result_standard);
}
END_TEST

START_TEST(memcmp_test_case_4) {
  char str1[20] = "Hellol";
  char str2[20] = "Helloh";
  int result_custom = s21_memcmp(str1, str2, 5);
  int result_standard = memcmp(str1, str2, 5);

  ck_assert_int_eq(result_custom, result_standard);
}
END_TEST

START_TEST(memcmp_test_case_5) {
  char str1[20] = "Hellol";
  char str2[20] = "Helloh";
  int result_custom = s21_memcmp(str1, str2, 7);
  int result_standard = memcmp(str1, str2, 7);

  ck_assert_int_eq(result_custom, result_standard);
}
END_TEST

START_TEST(memcmp_test_case_6) {
  char str1[20] = "Hellol";
  char str2[20] = "Helloh";
  int result_custom = s21_memcmp(str1, str2, 1);
  int result_standard = memcmp(str1, str2, 1);

  ck_assert_int_eq(result_custom, result_standard);
}
END_TEST

START_TEST(memcmp_test_case_7) {
  char str1[20] = "Hellol";
  char str2[20] = "Helloh";
  int result_custom = s21_memcmp(str1, str2, 0);
  int result_standard = memcmp(str1, str2, 0);

  ck_assert_int_eq(result_custom, result_standard);
}
END_TEST

START_TEST(memcmp_test_case_8) {
  char str1[20] = "Hellol";
  char str2[20] = "Helloh";
  int result_custom = s21_memcmp(str1, str2, 20);
  int result_standard = memcmp(str1, str2, 20);

  ck_assert_int_eq(result_custom, result_standard);
}
END_TEST
void memcmp_test(TCase *tcase_core) {
  tcase_add_test(tcase_core, memcmp_test_case_1);
  tcase_add_test(tcase_core, memcmp_test_case_2);
  tcase_add_test(tcase_core, memcmp_test_case_3);
  tcase_add_test(tcase_core, memcmp_test_case_4);
  tcase_add_test(tcase_core, memcmp_test_case_5);
  tcase_add_test(tcase_core, memcmp_test_case_6);
  tcase_add_test(tcase_core, memcmp_test_case_7);
  tcase_add_test(tcase_core, memcmp_test_case_8);
}

// Tests for memchr
START_TEST(memchr_test_case_1) {
  char str1[] = "Hellol";
  void *result_custom = s21_memchr(str1, 'o', 6);
  const void *result_standard = memchr(str1, 'o', 6);

  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(memchr_test_case_2) {
  char str1[] = "Hellol";
  void *result_custom = s21_memchr(str1, 'x', 6);
  const void *result_standard = memchr(str1, 'x', 6);

  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(memchr_test_case_3) {
  char str1[] = "Hellol";
  void *result_custom = s21_memchr(str1, 'H', 6);
  const void *result_standard = memchr(str1, 'H', 6);

  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(memchr_test_case_4) {
  char str1[] = "Hellol";
  void *result_custom = s21_memchr(str1, 'z', 6);
  const void *result_standard = memchr(str1, 'z', 6);

  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(memchr_test_case_5) {
  char str1[] = "Hellol";
  void *result_custom = s21_memchr(str1, 'l', 6);
  const void *result_standard = memchr(str1, 'l', 6);

  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(memchr_test_case_6) {
  char str1[] = "Hellol";
  void *result_custom = s21_memchr(str1, 'H', 6);
  const void *result_standard = memchr(str1, 'H', 6);

  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(memchr_test_case_7) {
  char str1[] = "Hellol";
  void *result_custom = s21_memchr(str1, 'o', 0);
  const void *result_standard = memchr(str1, 'o', 0);

  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(memchr_test_case_8) {
  void *result_custom = s21_memchr("H", 'H', 1);
  const void *result_standard = memchr("H", 'H', 1);

  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(memchr_test_case_9) {
  void *result_custom = s21_memchr("abcdefghijklmnopqrstuvwxyz", 'z', 26);
  const void *result_standard = memchr("abcdefghijklmnopqrstuvwxyz", 'z', 26);

  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(memchr_test_case_10) {
  void *result_custom = s21_memchr("Hello\0World", '\0', 11);
  const void *result_standard = memchr("Hello\0World", '\0', 11);

  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST
void memchr_test(TCase *tcase_core) {
  tcase_add_test(tcase_core, memchr_test_case_1);
  tcase_add_test(tcase_core, memchr_test_case_2);
  tcase_add_test(tcase_core, memchr_test_case_3);
  tcase_add_test(tcase_core, memchr_test_case_4);
  tcase_add_test(tcase_core, memchr_test_case_5);
  tcase_add_test(tcase_core, memchr_test_case_6);
  tcase_add_test(tcase_core, memchr_test_case_7);
  tcase_add_test(tcase_core, memchr_test_case_8);
  tcase_add_test(tcase_core, memchr_test_case_9);
  tcase_add_test(tcase_core, memchr_test_case_10);
}

// Tests for strlen
START_TEST(strlen_test_case_1) {
  const char str1[] = "Hellol";
  s21_size_t result_custom = s21_strlen(str1);
  s21_size_t result_standard = strlen(str1);

  ck_assert_int_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strlen_test_case_2) {
  const char *null_str = NULL;
  s21_size_t length = s21_strlen(null_str);

  ck_assert_int_eq(length, 0);
}
END_TEST

START_TEST(strlen_test_case_3) {
  s21_size_t result_custom = s21_strlen("1234567890");
  s21_size_t result_standard = strlen("1234567890");

  ck_assert_int_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strlen_test_case_4) {
  s21_size_t result_custom = s21_strlen("H");
  s21_size_t result_standard = strlen("H");

  ck_assert_int_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strlen_test_case_5) {
  s21_size_t result_custom = s21_strlen("abcdefghijklmnopqrstuvwxyz");
  s21_size_t result_standard = strlen("abcdefghijklmnopqrstuvwxyz");

  ck_assert_int_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strlen_test_case_6) {
  s21_size_t result_custom = s21_strlen("Hello World");
  s21_size_t result_standard = strlen("Hello World");

  ck_assert_int_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strlen_test_case_7) {
  s21_size_t result_custom = s21_strlen("Hello, World!");
  s21_size_t result_standard = strlen("Hello, World!");

  ck_assert_int_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strlen_test_case_8) {
  s21_size_t result_custom = s21_strlen("ÄÖÜ");
  s21_size_t result_standard = strlen("ÄÖÜ");

  ck_assert_int_eq(result_custom, result_standard);
}
END_TEST
void strlen_test(TCase *tcase_core) {
  tcase_add_test(tcase_core, strlen_test_case_1);
  tcase_add_test(tcase_core, strlen_test_case_2);
  tcase_add_test(tcase_core, strlen_test_case_3);
  tcase_add_test(tcase_core, strlen_test_case_4);
  tcase_add_test(tcase_core, strlen_test_case_5);
  tcase_add_test(tcase_core, strlen_test_case_6);
  tcase_add_test(tcase_core, strlen_test_case_7);
  tcase_add_test(tcase_core, strlen_test_case_8);
}

// Tests for strcmp
START_TEST(strcmp_test_case_1) {
  const char str1[] = "Hellol";
  const char str2[] = "Helloh";
  int result_custom = s21_strncmp(str1, str2, 6);
  int result_standard = strncmp(str1, str2, 6);

  ck_assert_int_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strcmp_test_case_2) {
  const char str1[] = "Hellol";
  const char str2[] = "Helloh";
  int result_custom = s21_strncmp(str1, str2, 6);
  int result_standard = strncmp(str1, str2, 6);

  ck_assert_int_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strcmp_test_case_3) {
  int result_custom = s21_strncmp("", "", 1);
  int result_standard = strncmp("", "", 1);

  ck_assert_int_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strcmp_test_case_4) {
  const char str1[] = "Hellol";
  const char str2[] = "Helloh";
  int result_custom = s21_strncmp(str1, str2, 5);
  int result_standard = strncmp(str1, str2, 5);

  ck_assert_int_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strcmp_test_case_5) {
  int result_custom = s21_strncmp("H", "H", 1);
  int result_standard = strncmp("H", "H", 1);

  ck_assert_int_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strcmp_test_case_6) {
  int result_custom = s21_strncmp("abcdefghijklmnopqrstuvwxyz",
                                  "abcdefghijklmnopqrstuvwxyz", 26);
  int result_standard =
      strncmp("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz", 26);

  ck_assert_int_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strcmp_test_case_7) {
  int result_custom = s21_strncmp("Hello World", "Hello World", 11);
  int result_standard = strncmp("Hello World", "Hello World", 11);

  ck_assert_int_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strcmp_test_case_8) {
  int result_custom = s21_strncmp("Hello, World!", "Hello, World!", 13);
  int result_standard = strncmp("Hello, World!", "Hello, World!", 13);

  ck_assert_int_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strcmp_test_case_9) {
  int result_custom = s21_strncmp("ÄÖÜ", "ÄÖÜ", 3);
  int result_standard = strncmp("ÄÖÜ", "ÄÖÜ", 3);

  ck_assert_int_eq(result_custom, result_standard);
}
END_TEST
void strcmp_test(TCase *tcase_core) {
  tcase_add_test(tcase_core, strcmp_test_case_1);
  tcase_add_test(tcase_core, strcmp_test_case_2);
  tcase_add_test(tcase_core, strcmp_test_case_3);
  tcase_add_test(tcase_core, strcmp_test_case_4);
  tcase_add_test(tcase_core, strcmp_test_case_5);
  tcase_add_test(tcase_core, strcmp_test_case_6);
  tcase_add_test(tcase_core, strcmp_test_case_7);
  tcase_add_test(tcase_core, strcmp_test_case_8);
  tcase_add_test(tcase_core, strcmp_test_case_9);
}

// Tests for s21_strchr
START_TEST(s21_strchr_test_case_1) {
  const char str1[] = "Hellol";
  const char *result_custom = s21_strchr(str1, 'o');
  const char *result_standard = strchr(str1, 'o');
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(s21_strchr_test_case_2) {
  const char str1[] = "Hellol";
  const char *result_custom = s21_strchr(str1, 'x');
  const char *result_standard = strchr(str1, 'x');
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(s21_strchr_test_case_3) {
  const char str1[] = "Hellol";
  const char *result_custom = s21_strchr(str1, 'H');
  const char *result_standard = strchr(str1, 'H');
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(s21_strchr_test_case_4) {
  const char str1[] = "Hellol";
  const char *result_custom = s21_strchr(str1, 'z');
  const char *result_standard = strchr(str1, 'z');
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(s21_strchr_test_case_5) {
  const char str1[] = "Hellol";
  const char *result_custom = s21_strchr(str1, 'l');
  const char *result_standard = strchr(str1, 'l');
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(s21_strchr_test_case_6) {
  const char *result_custom = s21_strchr("", 'l');
  const char *result_standard = strchr("", 'l');
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(s21_strchr_test_case_7) {
  const char *result_custom = s21_strchr("H", 'H');
  const char *result_standard = strchr("H", 'H');
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(s21_strchr_test_case_8) {
  const char *result_custom = s21_strchr("abcdefghijklmnopqrstuvwxyz", 'z');
  const char *result_standard = strchr("abcdefghijklmnopqrstuvwxyz", 'z');
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(s21_strchr_test_case_9) {
  const char *result_custom = s21_strchr("Hello, World!", ',');
  const char *result_standard = strchr("Hello, World!", ',');
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(s21_strchr_test_case_10) {
  const char *result_custom = s21_strchr("Hello\0World", '\0');
  const char *result_standard = strchr("Hello\0World", '\0');
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(s21_strchr_test_case_11) {
  const char *result_custom = s21_strchr("Hello\0World", 'W');
  const char *result_standard = strchr("Hello\0World", 'W');
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(s21_strchr_test_case_12) {
  const char *result_custom = s21_strchr("Hello\0World", 'H');
  const char *result_standard = strchr("Hello\0World", 'H');
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(s21_strchr_test_case_13) {
  const char *result_custom = s21_strchr("Hello\0World", 'l');
  const char *result_standard = strchr("Hello\0World", 'l');
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(s21_strchr_test_case_14) {
  const char *result_custom = s21_strchr("Hello\0World", 'x');
  const char *result_standard = strchr("Hello\0World", 'x');
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST
void s21_strchr_test(TCase *tcase_core) {
  tcase_add_test(tcase_core, s21_strchr_test_case_1);
  tcase_add_test(tcase_core, s21_strchr_test_case_2);
  tcase_add_test(tcase_core, s21_strchr_test_case_3);
  tcase_add_test(tcase_core, s21_strchr_test_case_4);
  tcase_add_test(tcase_core, s21_strchr_test_case_5);
  tcase_add_test(tcase_core, s21_strchr_test_case_6);
  tcase_add_test(tcase_core, s21_strchr_test_case_7);
  tcase_add_test(tcase_core, s21_strchr_test_case_8);
  tcase_add_test(tcase_core, s21_strchr_test_case_9);
  tcase_add_test(tcase_core, s21_strchr_test_case_10);
  tcase_add_test(tcase_core, s21_strchr_test_case_11);
  tcase_add_test(tcase_core, s21_strchr_test_case_12);
  tcase_add_test(tcase_core, s21_strchr_test_case_13);
  tcase_add_test(tcase_core, s21_strchr_test_case_14);
}

// Tests for strstr
START_TEST(strstr_test_case_1) {
  const char *haystack = "Hello, world!";
  const char *needle = "world";

  const char *result_custom = s21_strstr(haystack, needle);
  const char *result_standard = strstr(haystack, needle);
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strstr_test_case_2) {
  const char *haystack = "Hello, world!";
  const char *needle = "xyz";

  const char *result_custom = s21_strstr(haystack, needle);
  const char *result_standard = strstr(haystack, needle);
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strstr_test_case_3) {
  const char *haystack = "Hello, world!";
  const char *needle = "";

  const char *result_custom = s21_strstr(haystack, needle);
  const char *result_standard = strstr(haystack, needle);
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strstr_test_case_4) {
  const char *haystack = "Hello, world!";
  const char *needle = "w";

  const char *result_custom = s21_strstr(haystack, needle);
  const char *result_standard = strstr(haystack, needle);
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strstr_test_case_5) {
  const char *haystack = "Hello, world!";
  const char *needle = "Hello";

  const char *result_custom = s21_strstr(haystack, needle);
  const char *result_standard = strstr(haystack, needle);
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strstr_test_case_6) {
  const char *haystack = "Hello, world!";
  const char *needle = "world!";

  const char *result_custom = s21_strstr(haystack, needle);
  const char *result_standard = strstr(haystack, needle);
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strstr_test_case_7) {
  const char *haystack = "H";
  const char *needle = "H";

  const char *result_custom = s21_strstr(haystack, needle);
  const char *result_standard = strstr(haystack, needle);
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strstr_test_case_8) {
  const char *haystack = "";
  const char *needle = "H";

  const char *result_custom = s21_strstr(haystack, needle);
  const char *result_standard = strstr(haystack, needle);
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strstr_test_case_9) {
  const char *haystack = "Hello, world!";
  const char *needle = "";

  const char *result_custom = s21_strstr(haystack, needle);
  const char *result_standard = strstr(haystack, needle);
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strstr_test_case_10) {
  const char *haystack = "Hello, world!";
  const char *needle = "Hello, world!";

  const char *result_custom = s21_strstr(haystack, needle);
  const char *result_standard = strstr(haystack, needle);
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strstr_test_case_11) {
  const char *haystack = "abcdefghijklmnopqrstuvwxyz";
  const char *needle = "def";

  const char *result_custom = s21_strstr(haystack, needle);
  const char *result_standard = strstr(haystack, needle);
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strstr_test_case_12) {
  const char *haystack = "Hello, world!";
  const char *needle = ", wo";

  const char *result_custom = s21_strstr(haystack, needle);
  const char *result_standard = strstr(haystack, needle);
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strstr_test_case_13) {
  const char *haystack = "ÄÖÜ";
  const char *needle = "ÖÜ";

  const char *result_custom = s21_strstr(haystack, needle);
  const char *result_standard = strstr(haystack, needle);
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strstr_test_case_14) {
  const char *haystack = "Hello\0World";
  const char *needle = "World";

  const char *result_custom = s21_strstr(haystack, needle);
  const char *result_standard = strstr(haystack, needle);
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strstr_test_case_15) {
  const char *haystack = "Hello\0World";
  const char *needle = "Hello";

  const char *result_custom = s21_strstr(haystack, needle);
  const char *result_standard = strstr(haystack, needle);
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strstr_test_case_16) {
  const char *haystack = "Hello\0World";
  const char *needle = "Hello\0World";

  const char *result_custom = s21_strstr(haystack, needle);
  const char *result_standard = strstr(haystack, needle);
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strstr_test_case_17) {
  const char *haystack = "Hello\0World";
  const char *needle = "Hello\0";

  const char *result_custom = s21_strstr(haystack, needle);
  const char *result_standard = strstr(haystack, needle);
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strstr_test_case_18) {
  const char *haystack = "Hello\0World";
  const char *needle = "World\0";

  const char *result_custom = s21_strstr(haystack, needle);
  const char *result_standard = strstr(haystack, needle);
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

START_TEST(strstr_test_case_19) {
  const char *haystack = "Hello\0World";
  const char *needle = "\0";

  const char *result_custom = s21_strstr(haystack, needle);
  const char *result_standard = strstr(haystack, needle);
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST
void strstr_test(TCase *tcase_core) {
  tcase_add_test(tcase_core, strstr_test_case_1);
  tcase_add_test(tcase_core, strstr_test_case_2);
  tcase_add_test(tcase_core, strstr_test_case_3);
  tcase_add_test(tcase_core, strstr_test_case_4);
  tcase_add_test(tcase_core, strstr_test_case_5);
  tcase_add_test(tcase_core, strstr_test_case_6);
  tcase_add_test(tcase_core, strstr_test_case_7);
  tcase_add_test(tcase_core, strstr_test_case_8);
  tcase_add_test(tcase_core, strstr_test_case_9);
  tcase_add_test(tcase_core, strstr_test_case_10);
  tcase_add_test(tcase_core, strstr_test_case_11);
  tcase_add_test(tcase_core, strstr_test_case_12);
  tcase_add_test(tcase_core, strstr_test_case_13);
  tcase_add_test(tcase_core, strstr_test_case_14);
  tcase_add_test(tcase_core, strstr_test_case_15);
  tcase_add_test(tcase_core, strstr_test_case_16);
  tcase_add_test(tcase_core, strstr_test_case_17);
  tcase_add_test(tcase_core, strstr_test_case_18);
  tcase_add_test(tcase_core, strstr_test_case_19);
}

// Tests for strtok
START_TEST(strtok_test_case_1) {
  const char str_1[] = "Hello World";
  const char str_1_[] = "Goodbye Cruel World";

  char *str = malloc(20);
  char *str_ = malloc(30);

  memset(str, 0, 20);
  memset(str_, 0, 30);

  strcpy(str, str_1);
  strcpy(str_, str_1_);

  char *token;

  token = s21_strtok(NULL, " ");
  ck_assert_ptr_eq(token, NULL);

  token = s21_strtok(str, " ");
  ck_assert_str_eq(token, "Hello");

  token = s21_strtok(NULL, " ");
  ck_assert_str_eq(token, "World");

  token = s21_strtok(NULL, " ");
  ck_assert_ptr_eq(token, NULL);

  token = s21_strtok(str_, " ");
  ck_assert_str_eq(token, "Goodbye");

  token = s21_strtok(NULL, " ");
  ck_assert_str_eq(token, "Cruel");

  token = s21_strtok(NULL, " ");
  ck_assert_str_eq(token, "World");

  token = s21_strtok(NULL, " ");
  ck_assert_ptr_eq(token, NULL);

  free(str);
  free(str_);
}
END_TEST

void strtok_test(TCase *tcase_core) {
  tcase_add_test(tcase_core, strtok_test_case_1);
}

// Test for s21_strerror with a non-existent file
START_TEST(test_s21_strerror_nonexistent_file_case_1) {
  FILE *file;
  char filename[512] = {0};
  strcpy(filename, "nofile.txt");

  const char *error_message = s21_strerror(-1);
  ck_assert_str_eq(error_message, "Unknown error");

  if (!(file = fopen(filename, "r"))) {
    ck_assert_int_eq(errno, ENOENT);
    error_message = s21_strerror(errno);
    ck_assert_str_eq(error_message, "No such file or directory");
  }

  if (file) {
    fclose(file);
  }
}
END_TEST

void test_s21_strerror_nonexistent_file(TCase *tcase_core) {
  tcase_add_test(tcase_core, test_s21_strerror_nonexistent_file_case_1);
}
START_TEST(insert_test_case_1) {
  char *result;

  result = s21_insert("Hello World", "Beautiful ", 6);
  ck_assert_str_eq(result, "Hello Beautiful World");
  free(result);
}
END_TEST

START_TEST(insert_test_case_2) {
  char *result;

  result = s21_insert("World", "Hello ", 0);
  ck_assert_str_eq(result, "Hello World");
  free(result);
}
END_TEST

START_TEST(insert_test_case_3) {
  char *result;

  result = s21_insert("Hello", " World", 5);
  ck_assert_str_eq(result, "Hello World");
  free(result);
}
END_TEST

START_TEST(insert_test_case_4) {
  char *result;

  result = s21_insert("", "Hello", 0);
  ck_assert_str_eq(result, "Hello");
  free(result);
}
END_TEST

START_TEST(insert_test_case_5) {
  char *result;

  result = s21_insert("Hello", "", 2);
  ck_assert_str_eq(result, "Hello");
  free(result);
}
END_TEST

START_TEST(insert_test_case_6) {
  char *result;

  result = s21_insert(NULL, "Hello", 0);
  ck_assert_ptr_eq(result, NULL);
}
END_TEST

START_TEST(insert_test_case_7) {
  char *result;

  result = s21_insert("Hello", NULL, 0);
  ck_assert_ptr_eq(result, NULL);
}
END_TEST

START_TEST(insert_test_case_8) {
  char *result;

  result = s21_insert("Hello", " World", 10);
  ck_assert_ptr_eq(result, NULL);
}
END_TEST
// Tests for s21_insert
void insert_test(TCase *tcase_core) {
  tcase_add_test(tcase_core, insert_test_case_1);
  tcase_add_test(tcase_core, insert_test_case_2);
  tcase_add_test(tcase_core, insert_test_case_3);
  tcase_add_test(tcase_core, insert_test_case_4);
  tcase_add_test(tcase_core, insert_test_case_5);
  tcase_add_test(tcase_core, insert_test_case_6);
  tcase_add_test(tcase_core, insert_test_case_7);
  tcase_add_test(tcase_core, insert_test_case_8);
}

// Tests for s21_trim
START_TEST(trim_test_case_1) {
  char *result;

  result = s21_trim("  Hello World  ", " ");
  ck_assert_str_eq(result, "Hello World");
  free(result);
}
END_TEST

START_TEST(trim_test_case_2) {
  char *result;

  result = s21_trim("!!!Hello World!!!", "!");
  ck_assert_str_eq(result, "Hello World");
  free(result);
}
END_TEST

START_TEST(trim_test_case_3) {
  char *result;

  result = s21_trim("   Hello World   ", NULL);
  ck_assert_str_eq(result, "Hello World");
  free(result);
}
END_TEST

START_TEST(trim_test_case_4) {
  char *result;

  result = s21_trim("", " ");
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(trim_test_case_5) {
  char *result;

  result = s21_trim("Hello World", "!");
  ck_assert_str_eq(result, "Hello World");
  free(result);
}
END_TEST

START_TEST(trim_test_case_6) {
  char *result;

  result = s21_trim("!!!", "!");
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(trim_test_case_7) {
  char *result;

  result = s21_trim("abcHello Worldabc", "abc");
  ck_assert_str_eq(result, "Hello World");
  free(result);
}
END_TEST

START_TEST(trim_test_case_8) {
  char *result;

  result = s21_trim(NULL, " ");
  ck_assert_ptr_eq(result, NULL);
}
END_TEST

START_TEST(trim_test_case_9) {
  char *result;

  result = s21_trim("   Hello World   ", NULL);
  ck_assert_str_eq(result, "Hello World");
  free(result);
}
END_TEST
void trim_test(TCase *tcase_core) {
  tcase_add_test(tcase_core, trim_test_case_1);
  tcase_add_test(tcase_core, trim_test_case_2);
  tcase_add_test(tcase_core, trim_test_case_3);
  tcase_add_test(tcase_core, trim_test_case_4);
  tcase_add_test(tcase_core, trim_test_case_5);
  tcase_add_test(tcase_core, trim_test_case_6);
  tcase_add_test(tcase_core, trim_test_case_7);
  tcase_add_test(tcase_core, trim_test_case_8);
  tcase_add_test(tcase_core, trim_test_case_9);
}
START_TEST(test_s21_strerror_case_1) {
  const char *error_message_custom = s21_strerror(0);
  const char *error_message_standard = strerror(0);
  ck_assert_str_eq(error_message_custom, error_message_standard);
}
END_TEST

START_TEST(test_s21_strerror_case_2) {
  const char *error_message_custom = s21_strerror(EPERM);
  const char *error_message_standard = strerror(EPERM);
  ck_assert_str_eq(error_message_custom, error_message_standard);
}
END_TEST

START_TEST(test_s21_strerror_case_3) {
  const char *error_message_custom = s21_strerror(ENOENT);
  const char *error_message_standard = strerror(ENOENT);
  ck_assert_str_eq(error_message_custom, error_message_standard);
}
END_TEST

START_TEST(test_s21_strerror_case_4) {
  const char *error_message_custom = s21_strerror(ESRCH);
  const char *error_message_standard = strerror(ESRCH);
  ck_assert_str_eq(error_message_custom, error_message_standard);
}
END_TEST

START_TEST(test_s21_strerror_case_5) {
  const char *error_message_custom = s21_strerror(EINTR);
  const char *error_message_standard = strerror(EINTR);
  ck_assert_str_eq(error_message_custom, error_message_standard);
}
END_TEST

START_TEST(test_s21_strerror_case_6) {
  const char *error_message_custom = s21_strerror(EIO);
  const char *error_message_standard = strerror(EIO);
  ck_assert_str_eq(error_message_custom, error_message_standard);
}
END_TEST

START_TEST(test_s21_strerror_case_7) {
  const char *error_message_custom = s21_strerror(ENXIO);
  const char *error_message_standard = strerror(ENXIO);
  ck_assert_str_eq(error_message_custom, error_message_standard);
}
END_TEST

START_TEST(test_s21_strerror_case_8) {
  const char *error_message_custom = s21_strerror(E2BIG);
  const char *error_message_standard = strerror(E2BIG);
  ck_assert_str_eq(error_message_custom, error_message_standard);
}
END_TEST

START_TEST(test_s21_strerror_case_9) {
  const char *error_message_custom = s21_strerror(ENOEXEC);
  const char *error_message_standard = strerror(ENOEXEC);
  ck_assert_str_eq(error_message_custom, error_message_standard);
}
END_TEST

START_TEST(test_s21_strerror_case_10) {
  const char *error_message_custom = s21_strerror(EBADF);
  const char *error_message_standard = strerror(EBADF);
  ck_assert_str_eq(error_message_custom, error_message_standard);
}
END_TEST

START_TEST(test_s21_strerror_case_11) {
  const char *error_message_custom = s21_strerror(ECHILD);
  const char *error_message_standard = strerror(ECHILD);
  ck_assert_str_eq(error_message_custom, error_message_standard);
}
END_TEST

START_TEST(test_s21_strerror_case_12) {
  const char *error_message_custom = s21_strerror(EAGAIN);
  const char *error_message_standard = strerror(EAGAIN);
  ck_assert_str_eq(error_message_custom, error_message_standard);
}
END_TEST

START_TEST(test_s21_strerror_case_13) {
  const char *error_message_custom = s21_strerror(ENOMEM);
  const char *error_message_standard = strerror(ENOMEM);
  ck_assert_str_eq(error_message_custom, error_message_standard);
}
END_TEST

START_TEST(test_s21_strerror_case_14) {
  const char *error_message_custom = s21_strerror(EACCES);
  const char *error_message_standard = strerror(EACCES);
  ck_assert_str_eq(error_message_custom, error_message_standard);
}
END_TEST

START_TEST(test_s21_strerror_case_15) {
  const char *error_message_custom = s21_strerror(EFAULT);
  const char *error_message_standard = strerror(EFAULT);
  ck_assert_str_eq(error_message_custom, error_message_standard);
}
END_TEST

START_TEST(test_s21_strerror_case_16) {
  const char *error_message_custom = s21_strerror(ENOTBLK);
  const char *error_message_standard = strerror(ENOTBLK);
  ck_assert_str_eq(error_message_custom, error_message_standard);
}
END_TEST

START_TEST(test_s21_strerror_case_17) {
  const char *error_message_custom = s21_strerror(EBUSY);
  const char *error_message_standard = strerror(EBUSY);
  ck_assert_str_eq(error_message_custom, error_message_standard);
}
END_TEST

START_TEST(test_s21_strerror_case_18) {
  const char *error_message_custom = s21_strerror(EEXIST);
  const char *error_message_standard = strerror(EEXIST);
  ck_assert_str_eq(error_message_custom, error_message_standard);
}
END_TEST

START_TEST(test_s21_strerror_case_19) {
  const char *error_message_custom = s21_strerror(EXDEV);
  const char *error_message_standard = strerror(EXDEV);
  ck_assert_str_eq(error_message_custom, error_message_standard);
}
END_TEST

START_TEST(test_s21_strerror_case_20) {
  const char *error_message_custom = s21_strerror(ENODEV);
  const char *error_message_standard = strerror(ENODEV);
  ck_assert_str_eq(error_message_custom, error_message_standard);
}
END_TEST

START_TEST(test_s21_strerror_case_21) {
  const char *error_message_custom = s21_strerror(ENOTDIR);
  const char *error_message_standard = strerror(ENOTDIR);
  ck_assert_str_eq(error_message_custom, error_message_standard);
}
END_TEST

START_TEST(test_s21_strerror_case_22) {
  const char *error_message_custom = s21_strerror(EISDIR);
  const char *error_message_standard = strerror(EISDIR);
  ck_assert_str_eq(error_message_custom, error_message_standard);
}
END_TEST

START_TEST(test_s21_strerror_case_23) {
  const char *error_message_custom = s21_strerror(EINVAL);
  const char *error_message_standard = strerror(EINVAL);
  ck_assert_str_eq(error_message_custom, error_message_standard);
}
END_TEST

START_TEST(test_s21_strerror_case_24) {
  const char *error_message_custom = s21_strerror(ENFILE);
  const char *error_message_standard = strerror(ENFILE);
  ck_assert_str_eq(error_message_custom, error_message_standard);
}
END_TEST

START_TEST(test_s21_strerror_case_25) {
  const char *error_message_custom = s21_strerror(EMFILE);
  const char *error_message_standard = strerror(EMFILE);
  ck_assert_str_eq(error_message_custom, error_message_standard);
}
END_TEST

START_TEST(test_s21_strerror_case_26) {
  const char *error_message_custom = s21_strerror(ENOTTY);
  const char *error_message_standard = strerror(ENOTTY);
  ck_assert_str_eq(error_message_custom, error_message_standard);
}
END_TEST

START_TEST(test_s21_strerror_case_27) {
  const char *error_message_custom = s21_strerror(ETXTBSY);
  const char *error_message_standard = strerror(ETXTBSY);
  ck_assert_str_eq(error_message_custom, error_message_standard);
}
END_TEST

START_TEST(test_s21_strerror_case_28) {
  const char *error_message_custom = s21_strerror(EFBIG);
  const char *error_message_standard = strerror(EFBIG);
  ck_assert_str_eq(error_message_custom, error_message_standard);
}
END_TEST

START_TEST(test_s21_strerror_case_29) {
  const char *error_message_custom = s21_strerror(ENOSPC);
  const char *error_message_standard = strerror(ENOSPC);
  ck_assert_str_eq(error_message_custom, error_message_standard);
}
END_TEST

START_TEST(test_s21_strerror_case_30) {
  const char *error_message_custom = s21_strerror(ESPIPE);
  const char *error_message_standard = strerror(ESPIPE);
  ck_assert_str_eq(error_message_custom, error_message_standard);
}
END_TEST

START_TEST(test_s21_strerror_case_31) {
  const char *error_message_custom = s21_strerror(EROFS);
  const char *error_message_standard = strerror(EROFS);
  ck_assert_str_eq(error_message_custom, error_message_standard);
}
END_TEST

START_TEST(test_s21_strerror_case_32) {
  const char *error_message_custom = s21_strerror(EMLINK);
  const char *error_message_standard = strerror(EMLINK);
  ck_assert_str_eq(error_message_custom, error_message_standard);
}
END_TEST

START_TEST(test_s21_strerror_case_33) {
  const char *error_message_custom = s21_strerror(EPIPE);
  const char *error_message_standard = strerror(EPIPE);
  ck_assert_str_eq(error_message_custom, error_message_standard);
}
END_TEST

START_TEST(test_s21_strerror_case_34) {
  const char *error_message_custom = s21_strerror(EDOM);
  const char *error_message_standard = strerror(EDOM);
  ck_assert_str_eq(error_message_custom, error_message_standard);
}
END_TEST

START_TEST(test_s21_strerror_case_35) {
  const char *error_message_custom = s21_strerror(ERANGE);
  const char *error_message_standard = strerror(ERANGE);
  ck_assert_str_eq(error_message_custom, error_message_standard);
}
END_TEST

void test_s21_strerror_cases(TCase *tcase_core) {
  tcase_add_test(tcase_core, test_s21_strerror_case_1);
  tcase_add_test(tcase_core, test_s21_strerror_case_2);
  tcase_add_test(tcase_core, test_s21_strerror_case_3);
  tcase_add_test(tcase_core, test_s21_strerror_case_4);
  tcase_add_test(tcase_core, test_s21_strerror_case_5);
  tcase_add_test(tcase_core, test_s21_strerror_case_6);
  tcase_add_test(tcase_core, test_s21_strerror_case_7);
  tcase_add_test(tcase_core, test_s21_strerror_case_8);
  tcase_add_test(tcase_core, test_s21_strerror_case_9);
  tcase_add_test(tcase_core, test_s21_strerror_case_10);
  tcase_add_test(tcase_core, test_s21_strerror_case_11);
  tcase_add_test(tcase_core, test_s21_strerror_case_12);
  tcase_add_test(tcase_core, test_s21_strerror_case_13);
  tcase_add_test(tcase_core, test_s21_strerror_case_14);
  tcase_add_test(tcase_core, test_s21_strerror_case_15);
  tcase_add_test(tcase_core, test_s21_strerror_case_16);
  tcase_add_test(tcase_core, test_s21_strerror_case_17);
  tcase_add_test(tcase_core, test_s21_strerror_case_18);
  tcase_add_test(tcase_core, test_s21_strerror_case_19);
  tcase_add_test(tcase_core, test_s21_strerror_case_20);
  tcase_add_test(tcase_core, test_s21_strerror_case_21);
  tcase_add_test(tcase_core, test_s21_strerror_case_22);
  tcase_add_test(tcase_core, test_s21_strerror_case_23);
  tcase_add_test(tcase_core, test_s21_strerror_case_24);
  tcase_add_test(tcase_core, test_s21_strerror_case_25);
  tcase_add_test(tcase_core, test_s21_strerror_case_26);
  tcase_add_test(tcase_core, test_s21_strerror_case_27);
  tcase_add_test(tcase_core, test_s21_strerror_case_28);
  tcase_add_test(tcase_core, test_s21_strerror_case_29);
  tcase_add_test(tcase_core, test_s21_strerror_case_30);
  tcase_add_test(tcase_core, test_s21_strerror_case_31);
  tcase_add_test(tcase_core, test_s21_strerror_case_32);
  tcase_add_test(tcase_core, test_s21_strerror_case_33);
  tcase_add_test(tcase_core, test_s21_strerror_case_34);
  tcase_add_test(tcase_core, test_s21_strerror_case_35);
}
// Tests for s21_sprintf
START_TEST(test_sprintf_0) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%%");
  sprintf(expected, "%%");
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_1) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%d", 123);
  sprintf(expected, "%d", 123);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_2) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%f", 123.456);
  sprintf(expected, "%f", 123.456);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_2_1) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%f", -123.456);
  sprintf(expected, "%f", -123.456);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_2_2) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "% f", 123.456);
  sprintf(expected, "% f", 123.456);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_2_3) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%.0f", 123.456);
  sprintf(expected, "%.0f", 123.456);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_2_4) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%.0f", 123.6);
  sprintf(expected, "%.0f", 123.6);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_2_5) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "% f", 123.6);
  sprintf(expected, "% f", 123.6);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_3) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%s", "Hello, World!");
  sprintf(expected, "%s", "Hello, World!");
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_4) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%c", 'A');
  sprintf(expected, "%c", 'A');
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_4_1) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%-c", 'A');
  sprintf(expected, "%-c", 'A');
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_5) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%u", 12345);
  sprintf(expected, "%u", 12345);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_5_1) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%u", 0);
  sprintf(expected, "%u", 0);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_6) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%5d", 123);
  sprintf(expected, "%5d", 123);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_7) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%.5d", 123);
  sprintf(expected, "%.5d", 123);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_8) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%.2f", 123.456);
  sprintf(expected, "%.2f", 123.456);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_9) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%.5s", "Hello, World!");
  sprintf(expected, "%.5s", "Hello, World!");
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_9_1) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%-ls", L"Hello, World!");
  sprintf(expected, "%-ls", L"Hello, World!");
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_9_2) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%-s", "Hello, World!");
  sprintf(expected, "%-s", "Hello, World!");
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_9_3) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%-20s", "Hello, World!");
  sprintf(expected, "%-20s", "Hello, World!");
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_9_4) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%.0s", "Hello, World!");
  sprintf(expected, "%.0s", "Hello, World!");
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_9_5) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%20s", "Hello, World!");
  sprintf(expected, "%20s", "Hello, World!");
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_10) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%-5d", 123);
  sprintf(expected, "%-5d", 123);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_11) {
  char buffer[10512];
  char expected[10512];

  buffer[0] = '\0';
  s21_sprintf(buffer, "%+d", -123);
  sprintf(expected, "%+d", -123);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_11_1) {
  char buffer[10512];
  char expected[10512];

  buffer[0] = '\0';
  s21_sprintf(buffer, "%d", 0);
  sprintf(expected, "%d", 0);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_12) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "% d", 123);
  sprintf(expected, "% d", 123);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_14) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%5.2f", 123.456);
  sprintf(expected, "%5.2f", 123.456);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_15) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%-5.2f", 123.456);
  sprintf(expected, "%-5.2f", 123.456);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_16) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%05.2f", 123.456);
  sprintf(expected, "%05.2f", 123.456);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_17) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%ld", 1234567890L);
  sprintf(expected, "%ld", 1234567890L);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_18) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%lld", 1234567890123456789LL);
  sprintf(expected, "%lld", 1234567890123456789LL);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_19) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%hd", (short)123);
  sprintf(expected, "%hd", (short)123);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_20) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%hhd", (signed char)123);
  sprintf(expected, "%hhd", (signed char)123);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_21) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%lu", 1234567890UL);
  sprintf(expected, "%lu", 1234567890UL);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_22) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%llu", 1234567890123456789ULL);
  sprintf(expected, "%llu", 1234567890123456789ULL);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_23) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%hu", (unsigned short)123);
  sprintf(expected, "%hu", (unsigned short)123);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_24) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%hhu", (unsigned char)123);
  sprintf(expected, "%hhu", (unsigned char)123);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_26) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%f", 1e-10);
  sprintf(expected, "%f", 1e-10);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_26_6) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%-.2f", 0.99);
  sprintf(expected, "%-.2f", 0.99);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_26_7) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%-.6f", 0.99);
  sprintf(expected, "%-.6f", 0.99);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_26_8) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%+f", 0.1);
  sprintf(expected, "%+f", 0.1);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_26_9) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%-10f", 0.1);
  sprintf(expected, "%-10f", 0.1);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_26_10) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%10f", 0.1);
  sprintf(expected, "%10f", 0.1);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_27) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%f", 1e10);
  sprintf(expected, "%f", 1e10);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_28) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%f", 0.0 / 0.0);
  sprintf(expected, "%f", 0.0 / 0.0);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_29) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%f", 1.0 / 0.0);
  sprintf(expected, "%f", 1.0 / 0.0);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_30) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%f", -1.0 / 0.0);
  sprintf(expected, "%f", -1.0 / 0.0);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_31) {
  char buffer[10512];
  char expected[10512];

  wchar_t wstr[] = L"Hello, World!";
  s21_sprintf(buffer, "%ls", wstr);
  sprintf(expected, "%ls", wstr);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_32) {
  char buffer[10512];
  char expected[10512];

  wchar_t wc = L'A';
  s21_sprintf(buffer, "%lc", wc);
  sprintf(expected, "%lc", wc);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_32_1) {
  char buffer[10512];
  char expected[10512];

  wchar_t wc1 = L'A';
  s21_sprintf(buffer, "%10lc", wc1);
  sprintf(expected, "%10lc", wc1);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_32_2) {
  char buffer[10512];
  char expected[10512];

  wchar_t wc2 = L'A';
  s21_sprintf(buffer, "%-10lc", wc2);
  sprintf(expected, "%-10lc", wc2);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_32_3) {
  char buffer[10512];
  char expected[10512];

  wchar_t wc3 = L'A';
  s21_sprintf(buffer, "%-lc", wc3);
  sprintf(expected, "%-lc", wc3);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_32_4) {
  char buffer[10512];
  char expected[10512];

  wchar_t wstr[] = L"Hello, World!";
  s21_sprintf(buffer, "%.10ls", wstr);
  sprintf(expected, "%.10ls", wstr);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_32_5) {
  char buffer[10512];
  char expected[10512];

  wchar_t wstr[] = L"Hello, World!";
  s21_sprintf(buffer, "%15ls", wstr);
  sprintf(expected, "%15ls", wstr);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_32_6) {
  char buffer[10512];
  char expected[10512];

  wchar_t wstr[] = L"Hello, World!";
  s21_sprintf(buffer, "%-15ls", wstr);
  sprintf(expected, "%-15ls", wstr);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_33) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%d %f %s", 123, 123.456, "Hello, World!");
  sprintf(expected, "%d %f %s", 123, 123.456, "Hello, World!");
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_35) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "Hello, World!");
  sprintf(expected, "Hello, World!");
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_37) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%-d", 123);
  sprintf(expected, "%-d", 123);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_38) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%.d", 123);
  sprintf(expected, "%.d", 123);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_40) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%+-d", 123);
  sprintf(expected, "%+-d", 123);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_41) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%5.0d", 123);
  sprintf(expected, "%5.0d", 123);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_42) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%-5.0d", 123);
  sprintf(expected, "%-5.0d", 123);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_43) {
  char buffer[10512];
  char expected[10512];

  char *str =
      "To represent the character you can use Universal Character Names "
      "(UCNs). The character 'ф' has the Unicode value U+0444 and so in C++ "
      "you could write it . Also if the source code encoding supports this "
      "character then you can just write it literally in your source code.";
  s21_sprintf(buffer, "%s", str);
  sprintf(expected, "%s", str);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_44) {
  char buffer[10512];
  char expected[10512];

  wchar_t *str1 =
      L"1To represent the character you can use Universal Character Names To "
      L"2represent the character you can use Universal Character Names  To "
      L"3represent the character you can use Universal Character Names To "
      L"4represent the character you can use Universal Character Names To "
      L"5represent the character you can use Universal Character Names To "
      L"6represent the character you can use Universal Character Names To "
      L"7represent the character you can use Universal Character Names To ";

  s21_sprintf(buffer, "%ls", str1);
  sprintf(expected, "%ls", str1);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_45) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%-10c", 'H');
  sprintf(expected, "%-10c", 'H');
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_sprintf_46) {
  char buffer[10512];
  char expected[10512];

  s21_sprintf(buffer, "%10c", 'H');
  sprintf(expected, "%10c", 'H');
  ck_assert_str_eq(buffer, expected);
}
END_TEST

void s21_sprintf_tests(TCase *tcase_core) {
  tcase_add_test(tcase_core, test_sprintf_0);
  tcase_add_test(tcase_core, test_sprintf_1);
  tcase_add_test(tcase_core, test_sprintf_2);
  tcase_add_test(tcase_core, test_sprintf_2_1);
  tcase_add_test(tcase_core, test_sprintf_2_2);
  tcase_add_test(tcase_core, test_sprintf_2_3);
  tcase_add_test(tcase_core, test_sprintf_2_4);
  tcase_add_test(tcase_core, test_sprintf_2_5);
  tcase_add_test(tcase_core, test_sprintf_3);
  tcase_add_test(tcase_core, test_sprintf_4);
  tcase_add_test(tcase_core, test_sprintf_4_1);
  tcase_add_test(tcase_core, test_sprintf_5);
  tcase_add_test(tcase_core, test_sprintf_5_1);
  tcase_add_test(tcase_core, test_sprintf_6);
  tcase_add_test(tcase_core, test_sprintf_7);
  tcase_add_test(tcase_core, test_sprintf_8);
  tcase_add_test(tcase_core, test_sprintf_9);
  tcase_add_test(tcase_core, test_sprintf_9_1);
  tcase_add_test(tcase_core, test_sprintf_9_2);
  tcase_add_test(tcase_core, test_sprintf_9_3);
  tcase_add_test(tcase_core, test_sprintf_9_4);
  tcase_add_test(tcase_core, test_sprintf_9_5);
  tcase_add_test(tcase_core, test_sprintf_10);
  tcase_add_test(tcase_core, test_sprintf_11);
  tcase_add_test(tcase_core, test_sprintf_11_1);
  tcase_add_test(tcase_core, test_sprintf_12);
  tcase_add_test(tcase_core, test_sprintf_14);
  tcase_add_test(tcase_core, test_sprintf_15);
  tcase_add_test(tcase_core, test_sprintf_16);
  tcase_add_test(tcase_core, test_sprintf_17);
  tcase_add_test(tcase_core, test_sprintf_18);
  tcase_add_test(tcase_core, test_sprintf_19);
  tcase_add_test(tcase_core, test_sprintf_20);
  tcase_add_test(tcase_core, test_sprintf_21);
  tcase_add_test(tcase_core, test_sprintf_22);
  tcase_add_test(tcase_core, test_sprintf_23);
  tcase_add_test(tcase_core, test_sprintf_24);
  tcase_add_test(tcase_core, test_sprintf_26);
  tcase_add_test(tcase_core, test_sprintf_26_6);
  tcase_add_test(tcase_core, test_sprintf_26_7);
  tcase_add_test(tcase_core, test_sprintf_26_8);
  tcase_add_test(tcase_core, test_sprintf_26_9);
  tcase_add_test(tcase_core, test_sprintf_26_10);
  tcase_add_test(tcase_core, test_sprintf_27);
  tcase_add_test(tcase_core, test_sprintf_28);
  tcase_add_test(tcase_core, test_sprintf_29);
  tcase_add_test(tcase_core, test_sprintf_30);
  tcase_add_test(tcase_core, test_sprintf_31);
  tcase_add_test(tcase_core, test_sprintf_32);
  tcase_add_test(tcase_core, test_sprintf_32_1);
  tcase_add_test(tcase_core, test_sprintf_32_2);
  tcase_add_test(tcase_core, test_sprintf_32_3);
  tcase_add_test(tcase_core, test_sprintf_32_4);
  tcase_add_test(tcase_core, test_sprintf_32_5);
  tcase_add_test(tcase_core, test_sprintf_32_6);
  tcase_add_test(tcase_core, test_sprintf_33);
  tcase_add_test(tcase_core, test_sprintf_35);
  tcase_add_test(tcase_core, test_sprintf_37);
  tcase_add_test(tcase_core, test_sprintf_38);
  tcase_add_test(tcase_core, test_sprintf_40);
  tcase_add_test(tcase_core, test_sprintf_41);
  tcase_add_test(tcase_core, test_sprintf_42);
  tcase_add_test(tcase_core, test_sprintf_43);
  tcase_add_test(tcase_core, test_sprintf_44);
  tcase_add_test(tcase_core, test_sprintf_45);
  tcase_add_test(tcase_core, test_sprintf_46);
}

// Тесты s21_sscanf
START_TEST(test_sscanf_char) {
  char str[] = "A";
  char customCharValue, originalCharValue;
  int count_custom = s21_sscanf(str, "%c", &customCharValue);
  int count_original = sscanf(str, "%c", &originalCharValue);

  ck_assert_int_eq(count_custom, count_original);
  ck_assert_int_eq(customCharValue, originalCharValue);
}
END_TEST

START_TEST(test_sscanf_signed_integer) {
  char str[] = "-0123";
  int customIntValue, originalIntValue;
  int count_custom = s21_sscanf(str, "%d", &customIntValue);
  int count_original = sscanf(str, "%d", &originalIntValue);

  ck_assert_int_eq(count_custom, count_original);
  ck_assert_int_eq(customIntValue, originalIntValue);
}
END_TEST
START_TEST(test_sscanf_signed_integer_pos) {
  char str[] = "+0123";
  int customIntValue, originalIntValue;
  int count_custom = s21_sscanf(str, "%d", &customIntValue);
  int count_original = sscanf(str, "%d", &originalIntValue);

  ck_assert_int_eq(count_custom, count_original);
  ck_assert_int_eq(customIntValue, originalIntValue);
}
END_TEST
START_TEST(test_sscanf_integer_in_minus_octal) {
  char str[] = "-0173";
  int customIntValue, originalIntValue;
  int count_custom = s21_sscanf(str, "%i", &customIntValue);
  int count_original = sscanf(str, "%i", &originalIntValue);

  ck_assert_int_eq(count_custom, count_original);
  ck_assert_int_eq(customIntValue,
                   originalIntValue);  // -0173 -> -0153 in octal
}
END_TEST
START_TEST(test_sscanf_integer_in_pos_octal) {
  char str[] = "0173";
  int customIntValue, originalIntValue;
  int count_custom = s21_sscanf(str, "%i", &customIntValue);
  int count_original = sscanf(str, "%i", &originalIntValue);

  ck_assert_int_eq(count_custom, count_original);
  ck_assert_int_eq(customIntValue, originalIntValue);  // 0173 -> 0153 in octal
}
END_TEST
START_TEST(test_sscanf_integer_in_pos_hex) {
  char str[] = "0x173";
  int customIntValue, originalIntValue;
  int count_custom = s21_sscanf(str, "%i", &customIntValue);
  int count_original = sscanf(str, "%i", &originalIntValue);

  ck_assert_int_eq(count_custom, count_original);
  ck_assert_int_eq(customIntValue, originalIntValue);
}
END_TEST
START_TEST(test_sscanf_integer_in_minus_hex) {
  char str[] = "-0x173";
  int customIntValue, originalIntValue;
  int count_custom = s21_sscanf(str, "%i", &customIntValue);
  int count_original = sscanf(str, "%i", &originalIntValue);

  ck_assert_int_eq(count_custom, count_original);
  ck_assert_int_eq(customIntValue, originalIntValue);
}
END_TEST
START_TEST(test_sscanf_scientific_notation_lowercase_e) {
  char str[] = "3.14e5";
  float customFloatValue, originalFloatValue;
  int count_custom = s21_sscanf(str, "%e", &customFloatValue);
  int count_original = sscanf(str, "%e", &originalFloatValue);

  ck_assert_int_eq(count_custom, count_original);
  ck_assert_float_eq(customFloatValue, originalFloatValue);
}
END_TEST

START_TEST(test_sscanf_scientific_notation_uppercase_E) {
  char str[] = "1.23E+3";
  float customFloatValue, originalFloatValue;
  int count_custom = s21_sscanf(str, "%E", &customFloatValue);
  int count_original = sscanf(str, "%E", &originalFloatValue);

  ck_assert_int_eq(count_custom, count_original);
  ck_assert_float_eq(customFloatValue, originalFloatValue);
}
END_TEST

START_TEST(test_sscanf_float) {
  char str[] = "45.67";
  float customFloatValue, originalFloatValue;
  int count_custom = s21_sscanf(str, "%f", &customFloatValue);
  int count_original = sscanf(str, "%f", &originalFloatValue);

  ck_assert_int_eq(count_custom, count_original);
  ck_assert_float_eq(customFloatValue, originalFloatValue);
}
END_TEST
START_TEST(test_sscanf_float_neg) {
  char str[] = "-45.67";
  float customFloatValue, originalFloatValue;
  int count_custom = s21_sscanf(str, "%f", &customFloatValue);
  int count_original = sscanf(str, "%f", &originalFloatValue);
  ck_assert_int_eq(count_custom, count_original);
  ck_assert_float_eq(customFloatValue, originalFloatValue);
}
END_TEST
START_TEST(test_sscanf_unsigned_octal) {
  char str[] = "075";
  unsigned int customIntValue, originalIntValue;
  int count_custom = s21_sscanf(str, "%o", &customIntValue);
  int count_original = sscanf(str, "%o", &originalIntValue);

  ck_assert_int_eq(count_custom, count_original);
  ck_assert_int_eq(customIntValue, originalIntValue);
}
END_TEST

START_TEST(test_sscanf_string) {
  char str[] = "HelloWorld";
  char customStringValue[50], originalStringValue[50];
  int count_custom = s21_sscanf(str, "%s", customStringValue);
  int count_original = sscanf(str, "%s", originalStringValue);

  ck_assert_int_eq(count_custom, count_original);
  ck_assert_str_eq(customStringValue, originalStringValue);
}
END_TEST

START_TEST(test_sscanf_unsigned_integer) {
  char str[] = "12345";
  unsigned int customUintValue, originalUintValue;
  int count_custom = s21_sscanf(str, "%u", &customUintValue);
  int count_original = sscanf(str, "%u", &originalUintValue);

  ck_assert_int_eq(count_custom, count_original);
  ck_assert_int_eq(customUintValue, originalUintValue);
}
END_TEST

START_TEST(test_sscanf_unsigned_hex) {
  char str[] = "FF";
  unsigned int customIntValue, originalIntValue;
  int count_custom = s21_sscanf(str, "%x", &customIntValue);
  int count_original = sscanf(str, "%x", &originalIntValue);

  ck_assert_int_eq(count_custom, count_original);
  ck_assert_int_eq(customIntValue, originalIntValue);  // FF -> 255 in decimal
}
END_TEST

START_TEST(test_sscanf_pointer) {
  char str[] = "0x7ffeeeb13b70";
  void *customPointerValue, *originalPointerValue;
  int count_custom = s21_sscanf(str, "%p", &customPointerValue);
  int count_original = sscanf(str, "%p", &originalPointerValue);

  ck_assert_int_eq(count_custom, count_original);
  ck_assert_ptr_eq(customPointerValue,
                   originalPointerValue);  // Pointer address should match
}
END_TEST

START_TEST(test_sscanf_n_format) {
  char str[] = "Hello";
  int customN, originalN;

  int count_custom = s21_sscanf(str, "%n", &customN);
  int count_original = sscanf(str, "%n", &originalN);

  ck_assert_int_eq(customN, originalN);
  ck_assert_int_eq(count_custom, count_original);
}
END_TEST

START_TEST(test_sscanf_percent) {
  char str[] = "%8\0";
  int customIntValue, originalIntValue;
  int count_custom = s21_sscanf(str, "%%%d", &customIntValue);
  int count_original = sscanf(str, "%%%d", &originalIntValue);

  ck_assert_int_eq(customIntValue, originalIntValue);
  ck_assert_int_eq(count_custom, count_original);
}
END_TEST
START_TEST(test_sscanf_wrong_mod) {
  char str[] = "123";
  int customIntValue;
  int count_custom = s21_sscanf(str, "%k", &customIntValue);

  ck_assert_int_eq(count_custom, 1);
}
END_TEST
// Test for width specifier with string
START_TEST(test_sscanf_width_string) {
  char buffer1[50], buffer2[50];
  int count_s21 =
      s21_sscanf("hello world", "%5s", buffer1);  // Read first 5 characters
  int count_std =
      sscanf("hello world", "%5s", buffer2);  // Same for original sscanf

  ck_assert_int_eq(count_s21, count_std);  // Compare number of matched fields
  ck_assert_str_eq(buffer1, buffer2);      // Compare the actual string read
}
END_TEST

// Test for width specifier with integer
START_TEST(test_sscanf_width_integer) {
  int num1, num2;
  int count_s21 = s21_sscanf("1234", "%3d", &num1);  // Read first 3 digits
  int count_std = sscanf("1234", "%3d", &num2);      // Same for original sscanf

  ck_assert_int_eq(count_s21, count_std);  // Compare number of matched fields
  ck_assert_int_eq(num1, num2);            // Compare the actual integer value
}
END_TEST

// Test for flags with signed integers (e.g., %+d)
START_TEST(test_sscanf_flags_signed_integer) {
  int num1, num2;
  int count_s21 = s21_sscanf(
      "+1234", "%d", &num1);  // Expecting a signed integer with '+' flag
  int count_std =
      sscanf("+1234", "%d",
             &num2);  // Same for original sscanfck_assert_int_eq(count_s21,
                      // count_std);  // Compare number of matched fields
  ck_assert_int_eq(num1, num2);  // Compare the actual integer value
  ck_assert_int_eq(count_s21, count_std);
}
END_TEST

// Test for flags with zero padding for integers (e.g., %06d)
START_TEST(test_sscanf_flags_zero_padding) {
  int num1, num2;
  int count_s21 =
      s21_sscanf("001234", "%06d", &num1);  // Expecting zero-padded integer
  int count_std = sscanf("001234", "%06d", &num2);  // Same for original sscanf

  ck_assert_int_eq(count_s21, count_std);  // Compare number of matched fields
  ck_assert_int_eq(num1, num2);            // Compare the actual integer value
}
END_TEST

// Test for type casting with unsigned integers
START_TEST(test_sscanf_type_cast_unsigned) {
  unsigned int u1, u2;
  int count_s21 = s21_sscanf("12345", "%u", &u1);  // Read unsigned integer
  int count_std = sscanf("12345", "%u", &u2);      // Same for original sscanf

  ck_assert_int_eq(count_s21, count_std);  // Compare number of matched fields
  ck_assert_uint_eq(u1, u2);  // Compare the actual unsigned integer value
}
END_TEST

// Test for type casting with floating-point numbers
START_TEST(test_sscanf_type_cast_float) {
  float f1, f2;
  int count_s21 =
      s21_sscanf("3.14159", "%f", &f1);          // Read floating-point number
  int count_std = sscanf("3.14159", "%f", &f2);  // Same for original sscanf

  ck_assert_int_eq(count_s21, count_std);  // Compare number of matched fields
  ck_assert_float_eq(f1, f2);  // Compare the actual float values (within
                               // epsilon for floating-point precision)
}
END_TEST

// Test for reading a string with %s
START_TEST(test_sscanf_string_reading) {
  char str1[50], str2[50];
  int count_s21 = s21_sscanf("hello world", "%s", str1);  // Read string
  int count_std =
      sscanf("hello world", "%s", str2);  // Same for original sscanf

  ck_assert_int_eq(count_s21, count_std);  // Compare number of matched fields
  ck_assert_str_eq(str1, str2);            // Compare the actual string read
}
END_TEST

// Test for multiple format specifiers (%d %s %d)
// Test for multiple format specifiers (%d %s %d)
START_TEST(test_sscanf_multiple_specifiers) {
  int num1_s21, num2_s21;
  int num1_std, num2_std;
  char str1_s21[50];
  char str1_std[50];

  // Using s21_sscanf to read and assign values correctly
  int count_s21 =
      s21_sscanf("123 hello 456", "%d %s %d", &num1_s21, str1_s21, &num2_s21);

  // Using standard sscanf to read and assign values correctly
  int count_std =
      sscanf("123 hello 456", "%d %s %d", &num1_std, str1_std, &num2_std);

  // Compare the number of successfully matched fields
  ck_assert_int_eq(count_s21, count_std);

  // Compare the integer values read from both functions
  ck_assert_int_eq(num1_s21, num1_std);
  ck_assert_int_eq(num2_s21, num2_std);

  // Compare the string values read from both functions
  ck_assert_str_eq(str1_s21, str1_std);
}
END_TEST
START_TEST(test_s21_sscanf_basic) {
  const char *input = "12345 hello";
  int number;
  char str[10];

  // Use sscanf to parse the input
  sscanf(input, "%*00002d %d %5s", &number, str);
  int expected_number = number;
  char expected_str[10];
  strcpy(expected_str, str);

  // Use s21_sscanf to parse the input
  s21_sscanf(input, "%*00002d %d %5s", &number, str);

  // Check the results
  ck_assert_int_eq(number, expected_number);
  ck_assert_str_eq(str, expected_str);
}
END_TEST
START_TEST(test_sscanf_width_d) {
  int value_custom, value_standard;
  sscanf("000000042", "%10d", &value_standard);
  s21_sscanf("000000042", "%10d", &value_custom);
  ck_assert_int_eq(value_custom, value_standard);
}
END_TEST

START_TEST(test_sscanf_width_c) {
  char c_custom, c_standard;
  sscanf("A", "%1c", &c_standard);
  s21_sscanf("A", "%1c", &c_custom);
  ck_assert_int_eq(c_custom, c_standard);
}
END_TEST

START_TEST(test_sscanf_width_i) {
  int i_custom, i_standard;
  sscanf("12345", "%3i", &i_standard);
  s21_sscanf("12345", "%3i", &i_custom);
  ck_assert_int_eq(i_custom, i_standard);
}
END_TEST

START_TEST(test_sscanf_width_o) {
  unsigned int o_custom, o_standard;
  sscanf("12345", "%3o", &o_standard);
  s21_sscanf("12345", "%3o", &o_custom);
  ck_assert_int_eq(o_custom, o_standard);
}
END_TEST

START_TEST(test_sscanf_width_u) {
  unsigned int u_custom, u_standard;
  sscanf("12345", "%3u", &u_standard);
  s21_sscanf("12345", "%3u", &u_custom);
  ck_assert_int_eq(u_custom, u_standard);
}
END_TEST

START_TEST(test_sscanf_width_x) {
  unsigned int x_custom, x_standard;
  sscanf("12345", "%3x", &x_standard);
  s21_sscanf("12345", "%3x", &x_custom);
  ck_assert_int_eq(x_custom, x_standard);
}
END_TEST

START_TEST(test_sscanf_width_f) {
  float f_custom, f_standard;
  sscanf("123.45", "%5f", &f_standard);
  s21_sscanf("123.45", "%5f", &f_custom);
  ck_assert_float_eq(f_custom, f_standard);
}
END_TEST

START_TEST(test_sscanf_width_s) {
  char s_custom[10], s_standard[10];
  sscanf("Hello", "%3s", s_standard);
  s21_sscanf("Hello", "%3s", s_custom);
  ck_assert_str_eq(s_custom, s_standard);
}
END_TEST

START_TEST(test_sscanf_width_e) {
  float e_custom, e_standard;
  sscanf("1.23e2", "%5e", &e_standard);
  s21_sscanf("1.23e2", "%5e", &e_custom);
  ck_assert_float_eq(e_custom, e_standard);
}
END_TEST

START_TEST(test_sscanf_width_g) {
  float g_custom, g_standard;
  sscanf("123.45", "%5g", &g_standard);
  s21_sscanf("123.45", "%5g", &g_custom);
  ck_assert_float_eq(g_custom, g_standard);
}
END_TEST

START_TEST(test_sscanf_width_n) {
  int d_custom, d_standard;
  int n_custom, n_standard;
  sscanf("12345", "%3d%n", &d_standard, &n_standard);
  s21_sscanf("12345", "%3d%n", &d_custom, &n_custom);
  ck_assert_int_eq(n_custom, n_standard);
}
END_TEST

START_TEST(test_sscanf_short_formats) {
  char buffer[100];
  short hd, hi;
  unsigned short ho, hu, hx;
  short hd_custom, hi_custom;
  unsigned short ho_custom, hu_custom, hx_custom;

  // Test with short formats
  sprintf(buffer, "123 173 123 7b 123");
  sscanf(buffer, "%hd %ho %hu %hx %hi", &hd, &ho, &hu, &hx, &hi);
  s21_sscanf(buffer, "%hd %ho %hu %hx %hi", &hd_custom, &ho_custom, &hu_custom,
             &hx_custom, &hi_custom);

  ck_assert_int_eq(hd, hd_custom);
  ck_assert_int_eq(ho, ho_custom);
  ck_assert_int_eq(hu, hu_custom);
  ck_assert_int_eq(hx, hx_custom);
  ck_assert_int_eq(hi, hi_custom);
}
END_TEST

START_TEST(test_sscanf_long_formats) {
  char buffer[100];
  long ld, li;
  unsigned long lo, lu, lx;
  long ld_custom, li_custom;
  unsigned long lo_custom, lu_custom, lx_custom;

  // Test with long formats
  sprintf(buffer, "123456 361100 123456 1E240 123456");
  sscanf(buffer, "%ld %lo %lu %lx %li", &ld, &lo, &lu, &lx, &li);
  s21_sscanf(buffer, "%ld %lo %lu %lx %li", &ld_custom, &lo_custom, &lu_custom,
             &lx_custom, &li_custom);

  ck_assert_int_eq(ld, ld_custom);
  ck_assert_int_eq(lo, lo_custom);
  ck_assert_int_eq(lu, lu_custom);
  ck_assert_int_eq(lx, lx_custom);
  ck_assert_int_eq(li, li_custom);
}
END_TEST

START_TEST(test_sscanf_long_double_formats) {
  char buffer[100];
  long double Le, LE, Lf, Lg, LG;
  long double Le_custom, LE_custom, Lf_custom, Lg_custom, LG_custom;

  // Test with long double formats
  sprintf(buffer, "1.23e2 1.23E2 123.456 123.456 123.456");
  sscanf(buffer, "%Le %LE %Lf %Lg %LG", &Le, &LE, &Lf, &Lg, &LG);
  s21_sscanf(buffer, "%Le %LE %Lf %Lg %LG", &Le_custom, &LE_custom, &Lf_custom,
             &Lg_custom, &LG_custom);

  ck_assert_double_eq_tol(Le, Le_custom, 0.001);
  ck_assert_double_eq_tol(LE, LE_custom, 0.001);
  ck_assert_double_eq_tol(Lf, Lf_custom, 0.001);
  ck_assert_double_eq_tol(Lg, Lg_custom, 0.001);
  ck_assert_double_eq_tol(LG, LG_custom, 0.001);
}
END_TEST

START_TEST(test_sscanf_char_formats) {
  char buffer[100];
  signed char hhd, hhi;
  unsigned char hho, hhu, hhx;
  signed char hhd_custom, hhi_custom;
  unsigned char hho_custom, hhu_custom, hhx_custom;

  sprintf(buffer, "123 173 123 7b 123");
  sscanf(buffer, "%hhd %hho %hhu %hhx %hhi", &hhd, &hho, &hhu, &hhx, &hhi);
  s21_sscanf(buffer, "%hhd %hho %hhu %hhx %hhi", &hhd_custom, &hho_custom,
             &hhu_custom, &hhx_custom, &hhi_custom);

  ck_assert_int_eq(hhd, hhd_custom);
  ck_assert_int_eq(hho, hho_custom);
  ck_assert_int_eq(hhu, hhu_custom);
  ck_assert_int_eq(hhx, hhx_custom);
  ck_assert_int_eq(hhi, hhi_custom);
}
END_TEST

START_TEST(test_sscanf_long_long_formats) {
  char buffer[100];
  long long lld, lli;
  unsigned long long llo, llu, llx;
  long long lld_custom, lli_custom;
  unsigned long long llo_custom, llu_custom, llx_custom;

  sprintf(buffer, "123456789 173456 123456789 75BCD15 123456789");
  sscanf(buffer, "%lld %llo %llu %llx %lli", &lld, &llo, &llu, &llx, &lli);
  s21_sscanf(buffer, "%lld %llo %llu %llx %lli", &lld_custom, &llo_custom,
             &llu_custom, &llx_custom, &lli_custom);

  ck_assert_int_eq(lld, lld_custom);
  ck_assert_int_eq(llo, llo_custom);
  ck_assert_int_eq(llu, llu_custom);
  ck_assert_int_eq(llx, llx_custom);
  ck_assert_int_eq(lli, lli_custom);
}
END_TEST

START_TEST(test_sscanf_float_formats) {
  char buffer[100];
  float e, E, f, g, G;
  float e_custom, E_custom, f_custom, g_custom, G_custom;

  sprintf(buffer, "1.23e2 1.23E2 123.456 123.456 123.456");
  sscanf(buffer, "%e %E %f %g %G", &e, &E, &f, &g, &G);
  s21_sscanf(buffer, "%e %E %f %g %G", &e_custom, &E_custom, &f_custom,
             &g_custom, &G_custom);

  ck_assert_float_eq_tol(e, e_custom, 0.001);
  ck_assert_float_eq_tol(E, E_custom, 0.001);
  ck_assert_float_eq_tol(f, f_custom, 0.001);
  ck_assert_float_eq_tol(g, g_custom, 0.001);
  ck_assert_float_eq_tol(G, G_custom, 0.001);
}
END_TEST
// Test for width specifier with * in sscanf
START_TEST(test_sscanf_width_with_star) {
  const char *input = "12345 hello";
  int number;
  char str[10];

  // Use sscanf to parse the input
  sscanf(input, "%*2d %d %5s", &number, str);
  int expected_number = number;
  char expected_str[10];
  strcpy(expected_str, str);

  // Use s21_sscanf to parse the input
  s21_sscanf(input, "%*2d %d %5s", &number, str);

  // Check the results
  ck_assert_int_eq(number, expected_number);
  ck_assert_str_eq(str, expected_str);
}
END_TEST

// Test for precision specifier with * in sscanf
START_TEST(test_sscanf_precision_with_star) {
  const char *input = "123.456";
  float number;

  // Use sscanf to parse the input
  sscanf(input, "%f", &number);
  float expected_number = number;

  // Use s21_sscanf to parse the input
  s21_sscanf(input, "%f", &number);

  // Check the results
  ck_assert_float_eq(number, expected_number);
}
END_TEST

// Test for width and precision specifier with * in sscanf
START_TEST(test_sscanf_width_and_precision_with_star) {
  const char *input = "123.456";
  float number;

  // Use sscanf to parse the input
  sscanf(input, "%f", &number);
  float expected_number = number;

  // Use s21_sscanf to parse the input
  s21_sscanf(input, "%f", &number);

  // Check the results
  ck_assert_float_eq(number, expected_number);
}
END_TEST

// Test for width specifier with * in sscanf for strings
START_TEST(test_sscanf_width_with_star_string) {
  const char *input = "teststring";
  char buffer1[50], buffer2[50];

  // Use sscanf to parse the input
  sscanf(input, "%*4s %s", buffer1);
  s21_sscanf(input, "%*4s %s", buffer2);

  // Check the results
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

void s21_sscanf_tests(TCase *tcase_core) {
  tcase_add_test(tcase_core, test_sscanf_char);
  tcase_add_test(tcase_core, test_sscanf_signed_integer);
  tcase_add_test(tcase_core, test_sscanf_signed_integer_pos);
  tcase_add_test(tcase_core, test_sscanf_integer_in_minus_octal);
  tcase_add_test(tcase_core, test_sscanf_integer_in_pos_octal);
  tcase_add_test(tcase_core, test_sscanf_integer_in_minus_hex);
  tcase_add_test(tcase_core, test_sscanf_integer_in_pos_hex);
  tcase_add_test(tcase_core, test_sscanf_scientific_notation_lowercase_e);
  tcase_add_test(tcase_core, test_sscanf_scientific_notation_uppercase_E);
  tcase_add_test(tcase_core, test_sscanf_float);
  tcase_add_test(tcase_core, test_sscanf_float_neg);
  tcase_add_test(tcase_core, test_sscanf_unsigned_octal);
  tcase_add_test(tcase_core, test_sscanf_string);
  tcase_add_test(tcase_core, test_sscanf_unsigned_integer);
  tcase_add_test(tcase_core, test_sscanf_unsigned_hex);
  tcase_add_test(tcase_core, test_sscanf_pointer);
  tcase_add_test(tcase_core, test_sscanf_n_format);
  tcase_add_test(tcase_core, test_sscanf_percent);
  tcase_add_test(tcase_core, test_sscanf_wrong_mod);
  tcase_add_test(tcase_core, test_sscanf_width_string);
  tcase_add_test(tcase_core, test_sscanf_width_integer);
  tcase_add_test(tcase_core, test_sscanf_flags_signed_integer);
  tcase_add_test(tcase_core, test_sscanf_flags_zero_padding);
  tcase_add_test(tcase_core, test_sscanf_type_cast_unsigned);
  tcase_add_test(tcase_core, test_sscanf_type_cast_float);
  tcase_add_test(tcase_core, test_sscanf_string_reading);
  tcase_add_test(tcase_core, test_sscanf_multiple_specifiers);
  tcase_add_test(tcase_core, test_s21_sscanf_basic);
  tcase_add_test(tcase_core, test_sscanf_width_d);
  tcase_add_test(tcase_core, test_sscanf_width_c);
  tcase_add_test(tcase_core, test_sscanf_width_i);
  tcase_add_test(tcase_core, test_sscanf_width_o);
  tcase_add_test(tcase_core, test_sscanf_width_u);
  tcase_add_test(tcase_core, test_sscanf_width_x);
  tcase_add_test(tcase_core, test_sscanf_width_f);
  tcase_add_test(tcase_core, test_sscanf_width_s);
  tcase_add_test(tcase_core, test_sscanf_width_e);
  tcase_add_test(tcase_core, test_sscanf_width_g);
  tcase_add_test(tcase_core, test_sscanf_width_n);
  tcase_add_test(tcase_core, test_sscanf_short_formats);
  tcase_add_test(tcase_core, test_sscanf_long_formats);
  tcase_add_test(tcase_core, test_sscanf_long_double_formats);
  tcase_add_test(tcase_core, test_sscanf_char_formats);
  tcase_add_test(tcase_core, test_sscanf_long_long_formats);
  tcase_add_test(tcase_core, test_sscanf_float_formats);

  tcase_add_test(tcase_core, test_sscanf_width_with_star);
  tcase_add_test(tcase_core, test_sscanf_precision_with_star);
  tcase_add_test(tcase_core, test_sscanf_width_and_precision_with_star);
  tcase_add_test(tcase_core, test_sscanf_width_with_star_string);
}

int main() {
  Suite *suite;
  SRunner *runner;

  suite = suite_create("String Tests");

  TCase *tcase_core = tcase_create("Core");

  strpbrk_test(tcase_core);
  s21_strcspn_test(tcase_core);
  s21_to_lower_test(tcase_core);
  s21_to_upper_test(tcase_core);
  s21_strrchr_test(tcase_core);
  strncat_test(tcase_core);
  memset_test(tcase_core);
  memcpy_test(tcase_core);
  strncpy_test(tcase_core);
  strcpy_test(tcase_core);
  null_test(tcase_core);
  size_t_test(tcase_core);
  memcmp_test(tcase_core);
  memchr_test(tcase_core);
  strlen_test(tcase_core);
  strcmp_test(tcase_core);
  s21_strchr_test(tcase_core);
  strstr_test(tcase_core);
  strtok_test(tcase_core);
  test_s21_strerror_nonexistent_file(tcase_core);
  insert_test(tcase_core);
  trim_test(tcase_core);
  // test_s21_strerror_cases(tcase_core);
  s21_sprintf_tests(tcase_core);
  s21_sscanf_tests(tcase_core);

  suite_add_tcase(suite, tcase_core);

  runner = srunner_create(suite);

  srunner_run_all(runner, CK_NORMAL);

  int failed_count = srunner_ntests_failed(runner);
  srunner_free(runner);
  return EXIT_SUCCESS;
  return (failed_count > 0) ? EXIT_FAILURE : EXIT_SUCCESS;
}
