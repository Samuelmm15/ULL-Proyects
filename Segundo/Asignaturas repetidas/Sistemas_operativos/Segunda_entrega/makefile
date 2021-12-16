all: Socket File ViewNetSend ViewNetReceive

ViewNetSend: ViewNetSend.o
	g++ ViewNetSend.o Socket.o File.o -o ViewNetSend

ViewNetS: ViewNetSend.o
	g++ -c ViewNetSend.cc 

ViewNetReceive: ViewNetReceive.o
	g++ ViewNetReceive.o Socket.o File.o -o ViewNetReceive

ViewNetR: ViewNetReceive.o
	g++ -c ViewNetReceive.cc 

Socket: Socket.o
	g++ -c Socket.cc

File: File.o
	g++ -c File.cc

clean:
	rm -rf *.o ViewNetSend.o ViewNetReceive.o Socket.o File.o

