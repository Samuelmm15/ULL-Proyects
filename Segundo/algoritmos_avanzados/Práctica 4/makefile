all: langton_ant

langton_ant: main_langton_ant.o langton_ant.o
	g++ main_langton_ant.o langton_ant.o -o langton

main_langton_ant.o: main_langton_ant.o
	g++ -c main_langton_ant.cc

langton_ant.o: langton_ant.o
	g++ -c langton_ant.cc

clean:
	rm -rf *.o langton_ant.o