CC = g++
CFLAGS = --std=c++20 -Wall -Werror -pedantic -g
LIB = -lboost_unit_test_framework

DEPS =

OBJECTS = Solution.cpp

PROGRAM = Solution

.PHONY: all clean lint $(PROGRAM)

all: $(PROGRAM)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

$(PROGRAM): main.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

clean:
	rm -rf *.o $(PROGRAM) *.dSYM
lint:
	cpplint *.cpp *.hpp
