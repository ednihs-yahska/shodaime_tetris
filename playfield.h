#pragma once
#include "shape/misc.h"

class Playfield {

    private:

    public:
        int playfieldX;
        int playfieldY;
        Cell* playField;
        Playfield(int playfieldX=10, int playfieldY=20);  
        ~Playfield();
};