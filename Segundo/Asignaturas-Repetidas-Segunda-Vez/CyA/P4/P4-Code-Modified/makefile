CC=g++
CXXFLAGS=-g -std=c++14

OBJS = FileOperations.o CodeAnalyzer.o main.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o p04_code_analyzer ${OBJS}

clean: 
	rm -rf *.o p04_code_analyzer