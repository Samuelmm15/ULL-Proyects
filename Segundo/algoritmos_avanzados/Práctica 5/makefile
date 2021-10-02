all: hash_table

hash_table: main_hash_table.o 
	g++ main_hash_table.o -o hash_table

main_hash_table.o: main_hash_table.o
	g++ -c main_hash_table.cc

clean:
	rm -rf *.o hash_table.o