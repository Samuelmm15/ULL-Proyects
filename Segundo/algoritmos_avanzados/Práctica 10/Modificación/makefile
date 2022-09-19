all: search_binary_tree_modificado

search_binary_tree_modificado: main_search_binary_tree_modificado.o 
	g++ main_search_binary_tree_modificado.o -o search_binary_tree_modificado

main_search_binary_tree_modificado.o: main_search_binary_tree_modificado.o
	g++ -c main_search_binary_tree_modificado.cc

clean:
	rm -rf *.o search_binary_tree_modificado.o