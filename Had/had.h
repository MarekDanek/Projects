#pragma once
#include "pozice.h"
#include "mapa.h"
#include "smer.h"

class Mapa;
class Had{
    public:
        std::vector<Pozice> segment;
        Smer aktual_smer;
        bool endGame;

        Had(Mapa& mapa);
    private:
        int score;
};