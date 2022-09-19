all: balanced_binary_tree

balanced_binary_tree: main_balanced_binary_tree.o 
	g++ main_balanced_binary_tree.o -o balanced_binary_tree

main_balanced_binary_tree.o: main_balanced_binary_tree.o
	g++ -c main_balanced_binary_tree.cc

clean:
	rm -rf *.o balanced_binary_tree.o