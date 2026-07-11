#include <iostream>
#include <cstdlib>
#include <vector>
#include<conio.h>
#include<string>
#include <windows.h>

#include "had.h"
#include "pozice.h"
#include "mapa.h"
#include "smer.h"
#include "ovoce.h"

int main() {
    Mapa mapa;
    Had had(mapa);
    Ovoce ovoce;
    ovoce.spawnOvoce(mapa, had);

    while(!had.endGame){

        std::cout << "\033[2J\033[1;1H";

        mapa.vykresli(had, ovoce);

        char key = 0;

        if (_kbhit()) {
            key = getch();
        }

        if(had.segment.size() != 0){
            switch(key){
                case 'w':
                    had.aktual_smer = Smer::Nahoru;
                    had.segment[0].y -= 1;
                    break;

                case 's':
                    had.aktual_smer = Smer::Dolu;
                    had.segment[0].y += 1;
                    break;

                case 'a':
                    had.aktual_smer = Smer::Doleva;
                    had.segment[0].x -= 1;
                    break;

                case 'd':
                    had.aktual_smer = Smer::Doprava;
                    had.segment[0].x += 1;
                    break;
                case 'm':
                    exit(0);
            }
            std::cout << had.segment[0].x << " " << had.segment[0].y;
        }else{

            had.endGame = true;
            std::cout << "Vector je prázdný.";

        };
        Sleep(250);
 };
};