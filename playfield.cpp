
#include "playfield.h"
#include <iostream>

Playfield::Playfield(int playfieldX, int playfieldY): playField(new Cell[playfieldX*playfieldY]), playfieldX(playfieldX), playfieldY(playfieldY) {
    fprintf(stderr, "Playfield initializing\n ");
    for(int i=0; i<playfieldY; i++){
        for( int j=0; j<playfieldX; j++){
            this->playField[i*playfieldY+j] = Cell(0l, 0);
        }
    }
    for(int i=0; i<playfieldY; i++){
        for( int j=0; j<playfieldX; j++){
            fprintf(stderr, "%d ", this->playField[i*playfieldY+j].val);
        }
        fprintf(stderr, "\n ");
    }
    fprintf(stderr, "Playfield initialized\n ");
}

Playfield::~Playfield(){
    delete[] playField;
};
