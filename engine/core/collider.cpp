//
// Created by bilgi on 12/24/2020.
//

#include "collider.h"

void Collider :: SetCollision(Collision* collision) {
    this->collision_ = collision;
}
Rect* Collider :: GetRect() {
    return rect_;
}

Collider :: Collider(int left, int right, int bottom, int top){
    this->rect_ = new Rect(left, top, right, bottom);
    // this->collision_ = new Collision; Default collision function
}
Collider :: Collider(Rect *rect) {
    this->rect_ = rect;
}
