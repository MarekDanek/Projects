#include <vector>
#include "coords.h"
#include "direction.h"
#pragma once

class Node
{
    public:
        Coords coords;
        int ID_node;
        std::vector<Direction> direction;
        Node(Coords coords_, int id_){
            this->coords = coords_;
            this->ID_node = id_;
            this->direction = {Direction::North, Direction::South, Direction::West, Direction::East};
        };

        std::vector<Node*> childs;
        void addNode(Node node);
};
