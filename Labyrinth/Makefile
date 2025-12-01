runme: main.o node.o neighbour.o
	g++ -o runme main.o node.o neighbour.o `pkg-config --libs gtkmm-4.0`

main.o: main.cpp node.h neighbour.h
	g++ -g -O0 -c main.cpp `pkg-config --cflags gtkmm-4.0` -o main.o 

node.o: node.cpp
	g++ -g -O0 -c node.cpp `pkg-config --cflags gtkmm-4.0` -o node.o

neighbour.o: neighbour.cpp
	g++ -g -O0 -c neighbour.cpp `pkg-config --cflags gtkmm-4.0` -o neighbour.o