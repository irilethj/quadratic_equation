CC=gcc
TEST=tests_quadratic_equation
CFLAGS=-Wall -Werror -Wextra
SRC = quadratic_equation.c tests_quadratic_equation.c
GCOV=--coverage
OPEN_CMD=xdg-open
UNAME = $(shell uname -s)
ifeq ($(UNAME),Linux)
	LDFLAGS=-lcheck -lsubunit -lrt -lpthread
	OPEN_CM=xdg-open
endif
ifeq ($(UNAME),Darwin)
	LDFLAGS=-lcheck
	OPEN_CM=open
endif
all : clean gcov_report

check : $(SRC)
	$(CC) $(CFLAGS) $(GCOV) $(SRC) $(LDFLAGS) -o $(TEST) -lm
	./$(TEST)

gcov_report: check
	lcov -o report.info -c -d .
	genhtml -o report report.info
	$(OPEN_CM) ./report/index.html	

format:
	clang-format -i -style=Google *.c *.h

clean: 
	-rm -rf *.o && rm -rf *.gcno
	-rm -rf *.a && rm -rf *.gcda
	-rm -rf *.info && rm -rf *.gcov
	-rm -rf ./tests_quadratic_equation && rm -rf ./gcov_report
	-rm -rf ./report/
