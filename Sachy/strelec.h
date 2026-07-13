#pragma once
#include "figurka.h"

class Strelec : public Figurka{
    public:
        Strelec(Barva m_barva) : Figurka(m_barva) {};
        bool validace_tahu(int startX, int startY,int cilX, int cilY) override {return true;};
        char get_znak() const {
            if(barva == Barva::Bila){
                return 'S';
            }else{
                return 's';
            };
        };
};