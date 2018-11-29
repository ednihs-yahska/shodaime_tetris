#include "shapeI.h"
#include <iostream>

Position* ShapeI::definition(int _x, int _y){
    //fprintf(stderr, "Above possible segmentation fault");
    Position* p1; Position* p2; Position* p3; Position* p4;
    Position* pos = new Position[4];
    switch(this->state){
        case A:
        case D:
            p1 = new Position(_x, _y);
            p2 = new Position(_x, _y-1);
            p3 = new Position(_x, _y-2);
            p4 = new Position(_x, _y-3);
            break;
        case B:
            //fprintf(stderr, "Test B\n");
            p1 = new Position(_x, _y);
            p2 = new Position(_x+1, _y);
            p3 = new Position(_x+2, _y);
            p4 = new Position(_x+3, _y);
            //fprintf(stderr, "Test B\n");
            break;
        case C:
            //fprintf(stderr, "Test B\n");
            p1 = new Position(_x, _y);
            p2 = new Position(_x-1, _y);
            p3 = new Position(_x-2, _y);
            p4 = new Position(_x-3, _y);
            //fprintf(stderr, "Test C \n");
            break;
    }
    //fprintf(stderr, "After possible segmentation fault\n");
    pos[0] = *p1;
    pos[1] = *p2;
    pos[2] = *p3;
    pos[3] = *p4;
    fprintf(stderr, "Test 2 \n %d %d\n %d %d\n %d %d \n %d %d\n", p1->x, p1->y, p2->x, p2->y, p3->x, p3->y, p4->x, p4->y);
    return pos;
};

ShapeI::ShapeI(long id): id(id){}


// ShapeI::~ShapeI(){
//     int a = 0;
// }
