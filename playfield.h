#include "model.h"

class Payfield {
    public:
        Playfield(int playfieldX=10, int playfieldY=20);
        int[] identifyClearingLines();


    private:
        int playfieldX = 10;
        int playfieldY = 20;
        Model model;


    
}