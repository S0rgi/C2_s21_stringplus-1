#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"  // Include your custom string library

// Tests for s21_strpbrk
START_TEST(strpbrk_test) {
  const char *str1 = "hello";
  const char *str2 = "l";

  char *result_custom = s21_strpbrk(str1, str2);
  char *result_standard = strpbrk(str1, str2);

  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

// Tests for s21_strcspn
START_TEST(s21_strcspn_test) {
  const char *str1 = "Hello, World!";
  const char *str2 = "aeiou";

  s21_size_t result1 = s21_strcspn(str1, str2);
  s21_size_t result2 = strcspn(str1, str2);

  ck_assert_int_eq(result1, result2);
}
END_TEST

// Tests for s21_to_lower
START_TEST(s21_to_lower_test) {
  const char *str = "Hello, World!";
  char *lower_str = s21_to_lower(str);

  ck_assert_str_eq(lower_str, "hello, world!");

  free(lower_str);
}
END_TEST

// Tests for s21_to_upper
START_TEST(s21_to_upper_test) {
  const char *str = "Hello, World!";
  char *upper_str = s21_to_upper(str);

  ck_assert_str_eq(upper_str, "HELLO, WORLD!");

  free(upper_str);
}
END_TEST

// Tests for s21_strrchr
START_TEST(s21_strrchr_test) {
  char str1[] = "Hellol";
  char *result_custom = s21_strrchr(str1, 'o');
  char *result_standard = strrchr(str1, 'o');

  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

// Tests for strcat
START_TEST(strcat_test) {
  char dest1[20] = "Hello ";
  char dest2[20] = "Hello ";
  const char *str = "world";

  s21_strncat(dest1, str, 5);
  strncat(dest2, str, 5);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

// Tests for memset
START_TEST(memset_test) {
  char buffer1[20];
  char buffer2[20];

  s21_memset(buffer1, 'A', sizeof(buffer1) - 1);
  memset(buffer2, 'A', sizeof(buffer2) - 1);

  buffer1[sizeof(buffer1) - 1] = '\0';
  buffer2[sizeof(buffer2) - 1] = '\0';

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

// Tests for memcpy
START_TEST(memcpy_test) {
  char src[] = "Hello, world!";
  char dest1[20];
  char dest2[20];

  s21_memcpy(dest1, src, sizeof(src));
  memcpy(dest2, src, sizeof(src));

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

// Tests for strncpy
START_TEST(strncpy_test) {
  const char str[] = "Hellol";
  char dest[10];

  s21_strncpy(dest, str, 5);

  dest[5] = '\0';

  ck_assert_str_eq(dest, "Hello");
}
END_TEST

// Tests for null_check
START_TEST(null_test) { ck_assert_ptr_eq(s21_NULL, NULL); }
END_TEST

// Tests for size_t_check
START_TEST(size_t_test) {
  ck_assert_int_eq(sizeof(size_t), sizeof(s21_size_t));
}
END_TEST

// Tests for memcmp
START_TEST(memcmp_test) {
  char str1[] = "Hellol";
  char str2[] = "Helloh";
  int result_custom = s21_memcmp(str1, str2, 6);
  int result_standard = memcmp(str1, str2, 6);

  ck_assert_int_eq(result_custom, result_standard);
}
END_TEST

// Tests for memchr
START_TEST(memchr_test) {
  char str1[] = "Hellol";
  void *result_custom = s21_memchr(str1, 'o', 6);
  void *result_standard = memchr(str1, 'o', 6);

  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

// Tests for strlen
START_TEST(strlen_test) {
  const char str1[] = "Hellol";
  int result_custom = s21_strlen(str1);
  int result_standard = strlen(str1);

  ck_assert_int_eq(result_custom, result_standard);
}
END_TEST

// Tests for strcmp
START_TEST(strcmp_test) {
  const char str1[] = "Hellol";
  const char str2[] = "Helloh";
  int result_custom = s21_strncmp(str1, str2, 6);
  int result_standard = strncmp(str1, str2, 6);

  ck_assert_int_eq(result_custom, result_standard);
}
END_TEST

// Tests for s21_strchr
START_TEST(s21_strchr_test) {
  const char str1[] = "Hellol";
  char *result_custom = s21_strchr(str1, 'o');
  char *result_standard = strchr(str1, 'o');

  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

// Tests for strstr
START_TEST(strstr_test) {
  const char *haystack = "Hello, world!";
  const char *needle = "world";

  char *result_custom = s21_strstr(haystack, needle);
  char *result_standard = strstr(haystack, needle);

  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

// Tests for s21_strtok
START_TEST(strtok_test) {
  const char str_1[] = "Hello World";
  const char str_1_[] = "Goodbye Cruel World";

  char *str = malloc(20);
  char *str_ = malloc(30);

  memset(str, 0, 20);
  memset(str_, 0, 30);

  strcpy(str, str_1);
  strcpy(str_, str_1_);

  char *token;

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
// Test for s21_strerror with a non-existent file
START_TEST(test_s21_strerror_nonexistent_file) {
  FILE *file;
  char filename[512] = {0};
  strcpy(filename, "nofile.txt");

  if (!(file = fopen(filename, "r"))) {
    ck_assert_int_eq(errno, ENOENT);
    const char *error_message = s21_strerror(errno);
    ck_assert_str_eq(error_message, "No such file or directory");
  }

  if (file) {
    fclose(file);
  }
}
END_TEST
int main(void) {
  Suite *suite;
  SRunner *runner;

  suite = suite_create("String Tests");

  TCase *tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, strpbrk_test);
  tcase_add_test(tcase_core, s21_strcspn_test);
  tcase_add_test(tcase_core, s21_to_lower_test);
  tcase_add_test(tcase_core, s21_to_upper_test);
  tcase_add_test(tcase_core, s21_strrchr_test);
  tcase_add_test(tcase_core, strcat_test);
  tcase_add_test(tcase_core, memset_test);
  tcase_add_test(tcase_core, memcpy_test);
  tcase_add_test(tcase_core, strncpy_test);
  tcase_add_test(tcase_core, null_test);
  tcase_add_test(tcase_core, size_t_test);
  tcase_add_test(tcase_core, memcmp_test);
  tcase_add_test(tcase_core, memchr_test);
  tcase_add_test(tcase_core, strlen_test);
  tcase_add_test(tcase_core, strcmp_test);
  tcase_add_test(tcase_core, s21_strchr_test);
  tcase_add_test(tcase_core, strstr_test);
  tcase_add_test(tcase_core, test_s21_strerror_nonexistent_file);
  tcase_add_test(tcase_core, strtok_test);

  suite_add_tcase(suite, tcase_core);

  runner = srunner_create(suite);

  srunner_run_all(runner, CK_NORMAL);

  int failed_count = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}