//
// Created by bilgi on 12/24/2020.
//

#include "position.h"

Position :: Position(int x, int y){
    this->x_ = x;
    this->y_ = y;
}

int Position :: GetX() const {
    return this->x_;
}

int Position :: GetY() const {
    return this->y_;
}