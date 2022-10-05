CC=g++
CXXFLAGS=-g -std=c++14

OBJS = Symbol.o Alphabet.o Chain.o MenuOptions.o main.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o p01_strings ${OBJS}

clean: 
	rm -rf *.o p01_strings