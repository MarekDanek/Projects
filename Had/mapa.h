#pragma once
#include<vector>
#include "ovoce.h"
class Had;
class Mapa{
    public:
        std::vector<std::vector<char>> mapa;
        void vykresli(const Had& had, const Ovoce& ovoce);
        Mapa();
        int getWidth() const;
        int getHeight() const;
    private:
        int width;
        int height;
};