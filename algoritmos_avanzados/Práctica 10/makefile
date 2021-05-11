all: search_binary_tree

search_binary_tree: main_search_binary_tree.o 
	g++ main_search_binary_tree.o -o search_binary_tree

main_search_binary_tree.o: main_search_binary_tree.o
	g++ -c main_search_binary_tree.cc

clean:
	rm -rf *.o search_binary_tree.o