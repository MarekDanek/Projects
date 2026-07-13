#pragma once
#include "figurka.h"

class Vez : public Figurka{
    public:
        Vez(Barva m_barva) : Figurka(m_barva) {};
        bool validace_tahu(int startX, int startY,int cilX, int cilY) override {return true;};
        char get_znak() const {
            if(barva == Barva::Bila){
                return 'V';
            }else{
                return 'v';
            };
        };

};