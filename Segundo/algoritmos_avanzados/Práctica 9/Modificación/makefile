all: balanced_binary_tree_modificado

balanced_binary_tree_modificado: main_balanced_binary_tree_modificado.o 
	g++ main_balanced_binary_tree_modificado.o -o balanced_binary_tree_modificado

main_balanced_binary_tree_modificado.o: main_balanced_binary_tree_modificado.o
	g++ -c main_balanced_binary_tree_modificado.cc

clean:
	rm -rf *.o balanced_binary_tree_modificado.o