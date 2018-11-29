
#include "gameRunner.h"
#include "playfield.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "shape/shape.h"
#include "shape/shapeS.h"
#include "shape/shapeI.h"
#include <fstream>

using namespace std;

GameRunner::GameRunner(Playfield* pf){
    this->playField = pf;
}

Shape* GameRunner::generateShape(long id){
    srand((unsigned)time(0)); 
    int lowest=1, highest=2; 
    int range=(highest-lowest)+1;
    int random_integer = 2;//lowest+int(range*rand()/(RAND_MAX + 1.0));
    //fprintf(stderr, "Generated random number");
    //myfile << "Generated random number " << random_integer;
    Shape* currentShape;
    switch(random_integer){
        case 1:{
            currentShape = new ShapeI(id);
            break;}
        case 2:{
            currentShape = new ShapeS(id);
            break;}
        default:{
            int a = 0;
            break;}
    }
    //fprintf(stderr, "Calling definition \n");
    Position* shapePosition = currentShape->definition(4,4);
    //Position s[4] = *shapePosition;
    // for(int i=0;i<4;i++){
    //     fprintf(stderr, "s.x %d \n", s[i].x);
    //     fprintf(stderr, "s.y %d \n", s[i].y);
    // }
    for(int i=0;i<4;i++){
        // fprintf(stderr, "Entering for\n");
        // fprintf(stderr, "shapePosition->x %d \n", shapePosition->x);
        // fprintf(stderr, "shapePosition->y %d \n", shapePosition->y);
        // fprintf(stderr, "this->playField->playfieldX %d \n", this->playField->playfieldX);
        // fprintf(stderr, "this->playField->playfieldY %d \n", this->playField->playfieldY);
        // fprintf(stderr, "YX %d \n", (shapePosition->y*this->playField->playfieldX)+shapePosition->x);
        // fprintf(stderr, "Id %ld\n", id);
        this->playField->playField[(shapePosition->y*this->playField->playfieldX)+shapePosition->x] = Cell(id, 1);
        shapePosition++;
    }
    this->currentShape = currentShape;

    // for(int i=this->playField->playfieldY-1; i>=0; i--){
    //     for( int j=this->playField->playfieldX-1; j>=0; j--){
    //         fprintf(stderr, "%d", this->playField->playField[(shapePosition->y*this->playField->playfieldX)+shapePosition->x].val);
    //     }
    //     fprintf(stderr,"\n");
    // }

    fprintf(stderr, "Exiting generate shape \n");
    return currentShape;
}

void GameRunner::sendTick(){
    fprintf(stderr, "Receiving tick");
    for(int i=this->playField->playfieldY-2; i>0; i--){
        for( int j=this->playField->playfieldX-1; j>=0; j--){
            int nextI = ((i+1)*this->playField->playfieldX)+j;
            int currentI = (i*this->playField->playfieldX)+j;
            if(this->playField->playField[nextI].val==0){
                this->playField->playField[nextI]=this->playField->playField[currentI];
                this->playField->playField[currentI].val=0;
            }
        }
    }
}

GameRunner::~GameRunner(){
    delete currentShape;
    delete playField;
}

// int main(){
//     Playfield* pf = new Playfield(10, 20);
//     GameRunner* gr = new GameRunner(pf);
//     Shape* s = gr->generateShape();
// }