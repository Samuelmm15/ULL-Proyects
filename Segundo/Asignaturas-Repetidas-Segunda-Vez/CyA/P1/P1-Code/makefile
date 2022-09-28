all: main_cya

main_cya: main_cya.o 
	g++ main_cya.o -o main

main_cya.o: main_cya.o
	g++ -c main.cc

clean:
	rm -rf *.o