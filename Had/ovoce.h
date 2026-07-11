#pragma once
#include "had.h"
class Mapa;
class Had;
struct Ovoce{
    int fruit_x;
    int fruit_y;

    void spawnOvoce(const Mapa& mapa, Had& had);
};
