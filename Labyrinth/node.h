#include <list>
#pragma once

class Node{
    public:
        int X;
        int Y;
        int ID_node;
           Node(int _X, int _Y, int _id){
            
            this->X = _X;
            this->Y = _Y;
            this->ID_node = _id;
        };

        std::list<Node> nodes;
        void addNode(Node node);
};
