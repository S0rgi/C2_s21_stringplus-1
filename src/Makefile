
CC = gcc

CFLAGS = -std=c11  -D_POSIX_C_SOURCE=200809L -lm -pedantic 
LIB_NAME = s21_string
CHECK_LIBS = -lcheck -lm -pthread -lsubunit -lgcov -pthread

REPORT_PATH = report

all: clean clang $(LIB_NAME).a test gcov_report

clean:
	rm -rf *.o *.a *.out $(REPORT_PATH) coverage.info *.gc* 

test: $(LIB_NAME).a test.o
	$(CC) $(CFLAGS) test.o -L. $(LIB_NAME).a $(CHECK_LIBS) -o test.out
	./test.out

$(LIB_NAME).a: $(LIB_NAME).o s21_sprintf.o
	ar rcs $(LIB_NAME).a $(LIB_NAME).o s21_sprintf.o

$(LIB_NAME).o:clean $(LIB_NAME).c
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage -c $(LIB_NAME).c -o $(LIB_NAME).o
s21_sprintf.o:s21_sprintf.c
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage -c s21_sprintf.c -o s21_sprintf.o
test.o: test.c
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage -c test.c -o test.o

gcov_report: test
	# Create directory for reports if it doesn't exist
	mkdir -p $(REPORT_PATH)

	# Generate gcov report in .info format
	lcov --capture --directory . --output-file coverage.info --exclude '*test*'
	genhtml coverage.info --output-directory $(REPORT_PATH)

	# Open the report in the browser if possible
	@{ \
		if command -v xdg-open > /dev/null; then \
			xdg-open $(REPORT_PATH)/index.html; \
		elif command -v open > /dev/null; then \
			open $(REPORT_PATH)/index.html; \
		elif command -v start > /dev/null; then \
			start $(REPORT_PATH)/index.html; \
		else \
			echo "Report generated at $(REPORT_PATH)/index.html"; \
		fi \
	}

cpp:
	cppcheck --enable=all --suppress=checkersReport --suppress=missingIncludeSystem *.c

clang:
	cp ../materials/linters/.clang-format ./
	clang-format -n *.c *.h
	clang-format -i *.c *.h
	rm -rf .clang-format

val: test
	valgrind --tool=memcheck --leak-check=yes ./test.out

lint:
	s21lint *.c *.h
scan:clean
	gcc $(CFLAGS) s21_string.c sscanf.c -o scan.out
	./scan.out