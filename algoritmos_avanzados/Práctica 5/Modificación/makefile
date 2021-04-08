all: hash_table_modificated

hash_table_modificated: main_hash_table_modificated.o 
	g++ main_hash_table_modificated.o -o hash_table_modificated

main_hash_table_modificated.o: main_hash_table_modificated.o
	g++ -c main_hash_table_modificated.cc

clean:
	rm -rf *.o hash_table_modificated.o