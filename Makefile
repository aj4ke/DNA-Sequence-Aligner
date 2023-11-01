CC = g++
CFLAGS = --std=c++17 -Wall -Werror -pedantic -g -O3
LIB = -lsfml-system
PROG = OptDistance
OBJ = OptDistance.o main.o
DEPS = OptDistance.cpp OptDistance.hpp main.cpp 

.PHONY: all clean lint 

all: $(PROG)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< $(LIB)

OptDistance: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

clean:
	rm *.o $(PROG)

lint:
	cpplint *.cpp *.hpp
