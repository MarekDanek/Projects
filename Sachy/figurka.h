#pragma once
#include "barva.h"

class Figurka{

    public:
        Figurka(Barva m_barva){
            this->barva = m_barva;
        }
        Barva get_barva() const{
            return barva;
        }
        bool virtual validace_tahu(int startX, int startY,int cilX, int cilY) = 0;

        char virtual get_znak() const = 0;

    protected:
        Barva barva;

};