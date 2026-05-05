#include <map>
#include "coords.h"
#include "node.h"
#pragma once

class LabyrinthAlgorithm
{
    public:
        std::map<Coords, Node*> generateLabyrinth(int weight, int height, int nodeSize);
};