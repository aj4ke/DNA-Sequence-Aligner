CC = g++
CFLAGS = --std=c++17 -Wall -Werror -pedantic -g -O3
PROG = OptDistance
OBJ = OptDistance.o main.o
DEPS = OptDistance.cpp OptDistance.hpp main.cpp

# Detect platform and set SFML paths
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
    # macOS (Homebrew)
    SFML_INC = -I/opt/homebrew/include
    SFML_LIB = -L/opt/homebrew/lib
else ifeq ($(UNAME_S),Linux)
    # Linux (apt-installed SFML)
    SFML_INC = -I/usr/include
    SFML_LIB = -L/usr/lib
endif

LIB = $(SFML_LIB) -lsfml-system
CFLAGS += $(SFML_INC)

.PHONY: all clean lint dist

all: $(PROG)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

$(PROG): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

clean:
	rm -f *.o $(PROG) OptAlignment.txt

lint:
	cpplint *.cpp *.hpp