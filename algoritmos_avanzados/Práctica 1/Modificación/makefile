all: langton_ant_copy

langton_ant_copy: main_langton_ant_copy.o langton_ant_copy.o
	g++ main_langton_ant_copy.o langton_ant_copy.o -o langton_copy

main_langton_ant_copy.o: main_langton_ant_copy.o
	g++ -c main_langton_ant_copy.cc

langton_ant_copy.o: langton_ant_copy.o
	g++ -c langton_ant_copy.cc

clean:
	rm -rf *.o langton_ant_copy.o