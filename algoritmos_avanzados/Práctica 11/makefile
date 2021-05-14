all: AVL_tree

AVL_tree: main_AVL_tree.o 
	g++ main_AVL_tree.o -o AVL_tree

main_AVL_tree.o: main_AVL_tree.o
	g++ -c main_AVL_tree.cc

clean:
	rm -rf *.o AVL_tree.o