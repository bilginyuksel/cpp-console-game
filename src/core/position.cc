#include "position.h"

Position :: Position(int x, int y){
    this->x_ = x;
    this->y_ = y;
}

void Position :: SetX(int x) {
    this->x_ = x;
}

void Position :: SetY(int y) {
    this->y_ = y;
}

const int Position :: GetX() {
    return this->x_;
}

const int Position :: GetY() {
    return this->y_;
}