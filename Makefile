CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++17
HEADERS = $(wildcard 3DViewer/controller/*h 3DViewer/model/*h 3DViewer/command/*h 3DViewer/parser/*h 3DViewer/transformations/*h)
SOURCES = $(wildcard 3DViewer/controller/*cc 3DViewer/model/*cc 3DViewer/command/*cc 3DViewer/parser/*cc 3DViewer/transformations/*cc)
OBJECTS = $(SOURCES:.cc=.o)
TEST_SOURCES = $(wildcard tests/*cc)
NAME_TEST = tests 
TEST_OBJECTS = $(TEST_SOURCES:.cc=.o)
PROJECT = s21_Wiewer
EXECUTABLE = s21_test
OS = $(shell uname)
REPORT = report
INDEX_FILE = $(REPORT)/index.html
INSTALL_DIR = build
DOXYGEN = doxygen 
DOCS_DIR = docs/
DOXYFILE = Doxyfile 
DOCS_PATH = ../docs/html/index.html

ifeq ($(OS), Linux)
	LIBS = $(shell pkg-config --cflags --libs gtest) -lgtest_main
	OPEN_APPLICATION = xdg-open
	PATH_OPEN = build/
endif 

ifeq ($(OS), Darwin) 
	LIBS = -lgtest -lgmock -pthread 
	OPEN_APPLICATION = open
	PATH_OPEN = build/3DViewer.app

endif

all: $(PROJECT).a tests

%.o: %.cc
	$(CC) $(CFLAGS) -c $< -o $@

$(PROJECT).a: $(OBJECTS)
	ar rcs $@ $^
	ranlib $@

tests: $(PROJECT).a $(TEST_OBJECTS)
	$(CC) $(CFLAGS) $(TEST_OBJECTS) -L. $(PROJECT).a $(LIBS) -o $(EXECUTABLE)
	@./$(EXECUTABLE)

install:
	mkdir $(INSTALL_DIR)
	cd $(INSTALL_DIR) && qmake ../3DViewer/3DViewer.pro && make all

open:
	$(OPEN_APPLICATION) $(PATH_OPEN)

uninstall:
	rm -rf $(INSTALL_DIR)

dvi: $(DOXYFILE)
	$(DOXYGEN) $(DOXYFILE)
	open $(DOCS_PATH)
	open ./manual.md

dist:
	mkdir -p ../dist
	cp -r ../src/* ../dist
	zip -r ../CPP_3DViewer.zip * ../dist
	rm -rf ../dist

gcov_report: $(SOURCES) $(TEST_SOURCES)
	$(CC) $(CFLAGS) --coverage $(SOURCES) -L. $(TEST_SOURCES) $(PROJECT).a $(LIBS) -o $(EXECUTABLE)
	@./$(EXECUTABLE)
	lcov --no-external -t "$(PROJECT)" -o $(PROJECT).info -c -d . --ignore-errors inconsistent --exclude "*/*.h"
	genhtml --ignore-errors inconsistent -o $(REPORT) $(PROJECT).info
	@$(OPEN_APPLICATION) $(INDEX_FILE)

clean:
	rm -rf 3DViewer/model/*.o 3DViewer/controller/*.o tests/*.o 3DViewer/parser/*.o 3DViewer/transformations/*.o 
	rm -rf 3DViewer/command/*.o
	rm -rf $(EXECUTABLE)
	rm -rf *.info *.gcda tests/*.o *.gcno report $(PROJECT).a 
	rm -rf ../$(DOCS_DIR)
	rm -rf build

style_check:
	cp ../materials/linters/.clang-format .
	clang-format -n -style=Google $(SOURCES) $(TEST_SOURCES) $(HEADERS)
	rm -rf .clang-format 

leak_check:
	CK_FORK=no leaks -atExit -- ./$(EXECUTABLE)

valgrind_check:
	CK_FORK=no valgrind --leak_check=full ./$(EXECUTABLE)

style_correct:
	cp ../materials/linters/.clang-format .
	clang-format -i -style=Google $(SOURCES) $(TEST_SOURCES) $(HEADERS)
	rm -rf .clang-format
