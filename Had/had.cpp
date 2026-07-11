#include <iostream>
#include <cstdlib>
#include <vector>
#include<conio.h>
#include<string>

#include "had.h"
#include "pozice.h"
#include "mapa.h"
#include "smer.h"
#include "ovoce.h"

Had::Had(Mapa& mapa) {
    segment.push_back({
        mapa.getWidth() / 2,
        mapa.getHeight() / 2
    });
    aktual_smer = Smer::Stop;
    endGame = false;
    score = 0;
};




