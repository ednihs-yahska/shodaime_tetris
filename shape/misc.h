#pragma once

struct Position{
    int x,y;
    Position(): x(0), y(0){};
    Position(int _x, int _y): x(_x), y(_y){};
};

struct Cell {
    int val;
    long id;
    Cell(): val(0), id(0l){};
    Cell(long id, int val): id(id), val(val){};
};