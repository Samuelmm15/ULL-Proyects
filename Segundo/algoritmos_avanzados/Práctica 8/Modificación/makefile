all: sort_methods_modificado

sort_methods_modificado: main_sort_modificado.o 
	g++ main_sort_modificado.o -o sort_methods_modificado

main_sort_modificado.o: main_sort_modificado.o
	g++ -c main_sort_modificado.cc

clean:
	rm -rf *.o sort_modificado.o