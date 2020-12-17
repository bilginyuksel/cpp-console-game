#include "collider.h"

void Collider :: SetCollision(Collision* collision) {
    this->collision_ = collision_;
}
Rect* Collider :: GetRect() {
    return rect_;
}
Collider :: Collider(int left, int right, int bottom, int top){
    this->rect_ = new Rect(left, right, bottom, top);
    // this->collision_ = new Collision; Default collision function
}
Collider :: Collider(Rect *rect) {
    this->rect_ = rect;
}