all: langton_ant_modificado

langton_ant_modificado: main_langton_ant_modificado.o langton_ant_modificado.o
	g++ main_langton_ant_modificado.o langton_ant_modificado.o -o langton_modificado

main_langton_ant_modificado.o: main_langton_ant_modificado.o
	g++ -c main_langton_ant_modificado.cc

langton_ant_modificado.o: langton_ant_modificado.o
	g++ -c langton_ant_modificado.cc

clean:
	rm -rf *.o langton_ant_modificado.o