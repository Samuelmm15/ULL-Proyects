all: ViewNetSend ViewNetReceive

ViewNetSend: ViewNetSend.o
	g++ ViewNetSend.o -o ViewNetSend

ViewNetS: ViewNetSend.o
	g++ -c ViewNetSend.cc

ViewNetReceive: ViewNetReceive.o
	g++ ViewNetReceive.o -o ViewNetReceive

ViewNetR: ViewNetReceive.o
	g++ -c ViewNetReceive.cc

clean:
	rm -rf *.o ViewNetSend.o ViewNetReceive.o