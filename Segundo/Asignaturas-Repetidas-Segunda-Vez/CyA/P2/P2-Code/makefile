CC=g++
CXXFLAGS=-g -std=c++14

OBJS = Alphabet.o Chain.o Language.o main.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o p02_languages ${OBJS}

clean: 
	rm -rf *.o p02_languages