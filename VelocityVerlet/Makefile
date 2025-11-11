runme: main.o
    g++ -o runme main.o `pkg-config --libs gtkmm-4.0`

main.o: main.cpp
    g++ g- -O0 -c main.cpp `pkg-config --cflags gtkmm-4.0` -o main.o 

velocityVerletIntegrator.o: velocityVerletIntegrator.cpp
	g++ -g -O0 -c velocityVerletIntegrator.cpp `pkg-config --cflags gtkmm-4.0` -o velocityVerletIntegrator.o

vector.o: vector.cpp
	g++ -g -O0 -c vector.cpp `pkg-config --cflags gtkmm-4.0` -o vector.o    