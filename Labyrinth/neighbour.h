#include "node.h"

class Neighbour{
    public:
        Neighbour();
        int ID_neighbour;
        int X;
        int Y;
        std::list<Node> neighbours;
};