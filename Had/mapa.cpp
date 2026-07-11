#include "mapa.h"
#include "had.h"
#include "ovoce.h"
#include <iostream>


Mapa::Mapa() {
    width = 10;
    height = 10;
}

int Mapa::getWidth() const {
    return width;
}

int Mapa::getHeight() const {
    return height;
}


void Mapa::vykresli(const Had& had, const Ovoce& ovoce) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            bool existuje_had = false;
            bool existuje_ovoce = false;

            for(const Pozice& k : had.segment){
                if (k.x == j && k.y == i) {
                    existuje_had = true;
                }
            }

            if (ovoce.fruit_x == j && ovoce.fruit_y == i) {
                existuje_ovoce = true;
            }

            if (existuje_had) {
                std::cout << "O";
            } else if (existuje_ovoce) {
                std::cout << "X";
            } else {
                std::cout << ".";
            }
        }
        std::cout << "\n";
    }
}