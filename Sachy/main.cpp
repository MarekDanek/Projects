#include "sachovnice.h"
#include <iostream>

int main(){
Sachovnice sachovnice;
int startX, startY, cilX, cilY;
std::cout << "Hraje Bily\n";
while(true){
    sachovnice.vykresli();
    std::cout << "Zadej tah v formatu (startX startY cilX cilY):\n";
    std::cin >> startX >> startY >> cilX >> cilY;
    sachovnice.pohni(startX, startY, cilX, cilY);
    std::cout << "-----------------------------\n";
    };
};