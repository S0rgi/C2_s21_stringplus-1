#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *s21_strtok(char *str, const char *delim);

int main() {
	const char str_1[] = "Hello, World";
	const char str_1_[] = "Goodbye, Cruel World";
	char* str_2 = NULL;
	char* str = malloc(20);
	char* str_ = malloc(30);
	memset(str, 0, 20);
	memset(str_, 0, 20);
	strcpy(str, str_1);
	strcpy(str_, str_1_);
	str_2 = s21_strtok(str, " l");
	printf("%s\n", str_2);
	str_2 = s21_strtok(NULL, " l");
	if (str_2) {
		printf("%s\n", str_2);
	}
	str_2 = s21_strtok(NULL, " l");
	if (str_2) {
		printf("%s\n", str_2);
	}
	str_2 = s21_strtok(NULL, " l");
	if (str_2) {
		printf("%s\n", str_2);
	}
	str_2 = s21_strtok(NULL, " l");
	if (str_2) {
		printf("%s\n", str_2);
	}

	str_2 = s21_strtok(NULL, " l");
	if (str_2) {
		printf("%s\n", str_2);
	}

	str_2 = s21_strtok(NULL, " l");
	if (str_2) {
		printf("%s\n", str_2);
	}
	
	str_2 = s21_strtok(str_, " l");
	printf("%s\n", str_2);
	str_2 = s21_strtok(NULL, " l");
	if (str_2) {
		printf("%s\n", str_2);
	}
	str_2 = s21_strtok(NULL, " l");
	if (str_2) {
		printf("%s\n", str_2);
	}
	str_2 = s21_strtok(NULL, " l");
	if (str_2) {
		printf("%s\n", str_2);
	}
	free(str);
	free(str_);
	return 0;
}

char* s21_strtok(char *str, const char *delim) {
  static char* str_stat;
  char* token;

  if (!str) {
	if (!str_stat) {
		return NULL;
	} else {
		str = str_stat;
	}
  }

  str += strspn(str, delim);

  if (!str) {
	str_stat = str;
	token = NULL;
  } else {
	token = str;
	str = strpbrk(token, delim);
	if (!str) {
		str_stat = NULL;
	} else {
		*str = '\0';
		str_stat = str + 1;
	}
  }

  return token;
}