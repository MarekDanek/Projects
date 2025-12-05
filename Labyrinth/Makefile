runme: main.o node.o labyrinthAlgorithm.o
	g++ -o runme main.o node.o labyrinthAlgorithm.o `pkg-config --libs gtkmm-4.0`

main.o: main.cpp labyrinthAlgorithm.h
	g++ -g -O0 -c main.cpp `pkg-config --cflags gtkmm-4.0` -o main.o 

node.o: node.cpp
	g++ -g -O0 -c node.cpp `pkg-config --cflags gtkmm-4.0` -o node.o

labyrinthAlgorithm.o: labyrinthAlgorithm.cpp coords.h node.h
	g++ -g -O0 -c labyrinthAlgorithm.cpp  `pkg-config --cflags gtkmm-4.0` -o labyrinthAlgorithm.o
