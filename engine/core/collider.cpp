//
// Created by bilgi on 12/24/2020.
//

#include "collider.h"


Rect* Collider :: GetRect() {
    return rect_;
}

Collider :: Collider(int left, int right, int bottom, int top){
    this->rect_ = new Rect(left, top, right, bottom);
}
Collider ::Collider(const Rect rect, int width, int height) {
    this->rect_ = new Rect(rect.GetLeft() - width,
                           rect.GetTop() - height,
                           rect.GetRight() + width,
                           rect.GetBottom() + height);
}
Collider :: Collider(Rect *rect) {
    this->rect_ = rect;
}

bool Collider :: isShadowCollision(const Rect *rect) {
    int top = this->rect_->GetTop();
    int bot = this->rect_->GetBottom();
    int left = this->rect_->GetLeft();
    int right = this->rect_->GetRight();
    // if the intersected part of the collider is the corners then this is shadowCollision.
    bool notIntersects = left > rect->GetRight() || top > rect->GetBottom() || rect->GetLeft() > right || rect->GetTop() > bot;
    return notIntersects;
}
