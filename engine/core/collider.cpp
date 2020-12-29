//
// Created by bilgi on 12/24/2020.
//

#include "collider.h"

void Collider :: SetCollision(Collision* collision) {
    this->collision_ = collision_;
}
Rect* Collider :: GetRect() {
    return rect_;
}
Rect Collider ::GetRectR() {
    int left = this->center_->GetX() - 5;
    int right = this->center_->GetX() + 5;
    int top = this->center_->GetY() - 5;
    int bottom = this->center_->GetY() + 5;
    return Rect(left, right, bottom, top);
}
Collider :: Collider(int left, int right, int bottom, int top){
    this->rect_ = new Rect(left, right, bottom, top);
    // this->collision_ = new Collision; Default collision function
}
Collider :: Collider(Rect *rect) {
    this->rect_ = rect;
}
Collider::Collider(Position *pos) {
    this->center_ = pos;
}