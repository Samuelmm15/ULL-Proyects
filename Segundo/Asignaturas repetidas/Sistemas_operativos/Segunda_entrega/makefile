all: ViewNet

ViewNet: main_ViewNet.o
	g++ main_ViewNet.o -o ViewNet

main_ViewNet: main_ViewNet.o
	g++ -c main_ViewNet.cc

clean:
	rm -rf *.o main_ViewNet.o