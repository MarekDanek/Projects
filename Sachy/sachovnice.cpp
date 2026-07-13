#include "sachovnice.h"
#include "vez.h"
#include "strelec.h"
#include <iostream>

Sachovnice::Sachovnice(){
    m_naTahu = Barva::Bila;
    m_plocha[0][0] = std::make_unique<Vez>(Barva ::Cerna);
    m_plocha[7][0] = std::make_unique<Vez>(Barva ::Bila);

    m_plocha[0][7] = std::make_unique<Strelec>(Barva ::Cerna);
    m_plocha[7][7] = std::make_unique<Strelec>(Barva ::Bila);
};

void Sachovnice::vykresli() const {
    if (m_naTahu == Barva::Bila) {
        std::cout << "Na tahu je: Bily\n";
    } else {
        std::cout << "Na tahu je: Cerny\n";
    }

    std::cout << "  ";
    for (int x = 0; x <= 7; x++) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    for (int i = 0; i <= 7; i++) {
        std::cout << i << " ";
        for (int j = 0; j <= 7; j++) {
            if (m_plocha[i][j] != nullptr) {
                std::cout << m_plocha[i][j]->get_znak() << " ";
            } else {
                std::cout << ". ";
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void Sachovnice::pohni(int startX, int startY, int cilX, int cilY){
    if(m_plocha[startY][startX] != nullptr && m_plocha[startX][startY]->validace_tahu(startX, startY, cilX, cilY) == true && m_plocha[startY][startX]->get_barva() == m_naTahu){
        m_plocha[cilY][cilX] = std::move(m_plocha[startY][startX]);
        if(m_naTahu == Barva::Bila){
            m_naTahu = Barva::Cerna;
        }else{
            m_naTahu = Barva::Bila;
        };
    }else{
        return;
    };
};