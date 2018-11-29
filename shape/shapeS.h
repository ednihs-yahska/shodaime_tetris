#include "shape.h"
#include "misc.h"

class ShapeS: public Shape{
    private:
    public:
        long id;
        ShapeS(long);
        virtual Position* definition(int _x, int _y);
};