#pragma once
#include <memory>
#include "figurka.h"

class Sachovnice{
    public:
        Sachovnice();
        void vykresli() const;
        void pohni(int startX, int startY, int cilX, int cilY);

    private:
        std::unique_ptr<Figurka> m_plocha[8][8];
        Barva m_naTahu;
};