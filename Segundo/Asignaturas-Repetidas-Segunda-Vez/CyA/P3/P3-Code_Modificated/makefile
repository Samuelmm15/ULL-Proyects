CC=g++
CXXFLAGS=-g -std=c++14

OBJS = Alphabet.o Chain.o Language.o FileOperations.o main.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o p03_calculator ${OBJS}

clean: 
	rm -rf *.o p03_calculator