all: sort_methods_modificated

sort_methods_modificated: main_sort_modificated.o 
	g++ main_sort_modificated.o -o sort_methods_modificated

main_sort_modificated.o: main_sort_modificated.o
	g++ -c main_sort_modificated.cc

clean:
	rm -rf *.o sort_methods_modificated.o