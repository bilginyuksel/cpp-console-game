//
// Created by bilgi on 12/24/2020.
//

#include "position.h"

Position :: Position(int x, int y){
    this->x_ = x;
    this->y_ = y;
}

Position :: Position(Position* pos){
    this->x_ = pos->x_;
    this->y_ = pos->y_;
}

int Position :: GetX() const {
    return this->x_;
}

int Position :: GetY() const {
    return this->y_;
}
