#include "vez.h"
#include "sachovnice.h"


bool Vez::validace_tahu(int startX, int startY,int cilX, int cilY){
    if(startX != cilX && startY == cilY){
        return true;
    }else if(startY != cilY && startX == cilX){
        return true;
    }else{
        return false;
    };
};



