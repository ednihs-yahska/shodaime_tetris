#include "shapeS.h"
#include <iostream>

Position* ShapeS::definition(int _x, int _y){
    Position* p1; Position* p2; Position* p3; Position* p4;
    Position* pos = new Position[4];
    RotationState r = RotationState::D;
    this->state = r;
    switch(this->state){
        case A:
        case C:{
            p1 = new Position(_x, _y);
            p2 = new Position(_x+1, _y);
            p3 = new Position(_x+1, _y-1);
            p4 = new Position(_x+2, _y-1);
            break;}
        case B:
        case D:{
            p1 = new Position(_x, _y);
            p2 = new Position(_x, _y-1);
            p3 = new Position(_x-1, _y-1);
            p4 = new Position(_x-1, _y-2);
            break;}
    }
    pos[0] = *p1;
    pos[1] = *p2;
    pos[2] = *p3;
    pos[3] = *p4;
    fprintf(stderr, "Test 3 \n %d %d\n %d %d\n %d %d \n %d %d\n\n", p1->x, p1->y, p2->x, p2->y, p3->x, p3->y, p4->x, p4->y);
    for(int i=0;i<4;i++){
        fprintf(stderr, "pos[].x %d \n", pos[i].x);
        fprintf(stderr, "pos[].y %d \n", pos[i].y);
    }
    return pos;
};

ShapeS::ShapeS(long id): id(id){}

// ShapeS::~ShapeS(){
//     int a = 0;
// }
