#include <cstdlib>
#include "mapa.h"
#include "had.h"

void Ovoce::spawnOvoce(const Mapa& mapa, Had& had){
    fruit_x = rand() % mapa.getWidth();
    fruit_y = rand() % mapa.getHeight();

    if(fruit_x == had.segment[0].x &&
       fruit_y == had.segment[0].y)
    {
        fruit_x = rand() % mapa.getWidth();
        fruit_y = rand() % mapa.getHeight();
    }
}

