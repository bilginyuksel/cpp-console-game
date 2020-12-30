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
Rect Collider ::GetRectR(){
    int left = this->center_->GetX() -2;
    int right = this->center_->GetX() + 7;
    int top = this->center_->GetY() +2;
    int bottom = this->center_->GetY() - 9;
    return Rect(left, top, right, bottom);
}
Collider :: Collider(int left, int right, int bottom, int top){
    this->rect_ = new Rect(left, top, right, bottom);
    // this->collision_ = new Collision; Default collision function
}
Collider :: Collider(Rect *rect) {
    this->rect_ = rect;
}
Collider::Collider(Position *pos) {
    this->center_ = pos;
}
void Collider::SetCenter(Position *center) {
    this->center_ = center;
}