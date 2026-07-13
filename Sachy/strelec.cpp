#include "strelec.h"
#include "sachovnice.h"
#include <iostream>

bool Strelec::validace_tahu(int startX, int startY,int cilX, int cilY){
    if(std::abs(startX - cilX) == std::abs(startY - cilY) &&  startX != cilX){
        return true;
    }else{
        false;
    };
};