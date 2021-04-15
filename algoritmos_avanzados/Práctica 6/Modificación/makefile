all: hash_table_modificado

hash_table_modificado: main_hash_table_modificado.o 
	g++ main_hash_table_modificado.o -o hash_table_modificado

main_hash_table_modificado.o: main_hash_table_modificado.o
	g++ -c main_hash_table_modificado.cc

clean:
	rm -rf *.o hash_table_modificado.o