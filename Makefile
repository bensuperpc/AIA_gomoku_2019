##
## EPITECH PROJECT, 2019
## IA_Gomoku
## File description:
## Makefile
##

BIN		=	pbrain-gomoku-ai

BINTEST	=	unit_tests

INCLUDE 	=	include/										\

SRC			=	source/Gomoku.cpp								\
				source/AI.cpp									\
				source/Board/Board.cpp							\
				source/Board/BoardRTree.cpp						\

SRC_MAIN	=	$(SRC)											\
				source/main.cpp									\

SRC_TEST	=	$(SRC)											\
				tests/test_gomoku.cpp							\
				tests/test_ai.cpp								\
				tests/test_board.cpp							\
				tests/test_board_rtree.cpp						\
				tests/test_attack.cpp							\
				tests/test_defense.cpp							\
				tests/test_divers.cpp							\

OBJ			=	$(SRC_MAIN:%.cpp=%.o)

OBJ_TEST	=	$(SRC_TEST:%.cpp=%.o)

GCDAS		=	$(SRC:%.cpp=%.gcda) $(SRC_TEST:%.cpp=%.gcda)
GCNOS		=	$(SRC:%.cpp=%.gcno) $(SRC_TEST:%.cpp=%.gcno)

CXX			=	g++

CPPFLAGS	=	-W -Wall -Wpedantic -Wextra -Wshadow -Wstrict-overflow=5 -Wmissing-declarations -Wundef	\
				-Wstack-protector -Wno-unused-parameter -march=native -pipe -std=c++14		\
				-lpthread -I $(INCLUDE)	

RM			=	rm -f

GCOVR		=	gcovr -r . --exclude tests/


all: CPPFLAGS += -O3
all:$(BIN)

$(BIN): $(OBJ) 
	$(CXX) $(OBJ) $(LDFLAGS) -o $(BIN)

tests_run: CPPFLAGS += -O0 -g3 -lcriterion
tests_run: $(BINTEST)
	./$(BINTEST)

$(BINTEST): $(OBJ_TEST) 
	$(CXX) $(OBJ_TEST) $(LDFLAGS) --coverage -lcriterion -o $(BINTEST)

coverage_run: CPPFLAGS += --coverage
coverage_run: tests_run
	$(GCOVR)

branches_run: CPPFLAGS += --coverage
branches_run: tests_run
	$(GCOVR) --branches 

coverage_html_run: CPPFLAGS += --coverage
coverage_html_run: tests_run
	$(GCOVR) --html --html-details -o coverage.html 

gdb: CPPFLAGS += -O0 -g3 -ggdb3
gdb:$(BIN)
	gdb ./$(BIN)

valgrind: CPPFLAGS += -g3 -O0 -ggdb3
valgrind:$(BIN)
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all -v ./$(BIN)

re:	fclean all

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_TEST)
	$(RM) $(GCDAS)
	$(RM) $(GCNOS)

fclean: clean
	$(RM) $(BIN)
	$(RM) $(BINTEST)

.PHNOY: clean fclean re all tests_run $(BIN) $(BINTEST) coverage_run
