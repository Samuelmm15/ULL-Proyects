all: sort_methods

sort_methods: main_sort.o 
	g++ main_sort.o -o sort_methods

main_sort.o: main_sort.o
	g++ -c main_sort.cc

clean:
	rm -rf *.o sort.o