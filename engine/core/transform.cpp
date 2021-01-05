//
// Created by bilgi on 12/24/2020.
//

#include "transform.h"

Position* Transform :: GetPosition() {
    return position_;
}
int Transform :: GetRotation() const {
    return rotation_;
}
int Transform :: GetWidth() const {
    return width_;
}
int Transform :: GetHeight() const {
    return height_;
}
void Transform :: SetPosition(int x, int y) {
    //if(obj->onPositionChangeRequested(x, y));
    if(position_record_.size() > 20) {
        position_record_.pop_front();
    }
    position_record_.push_back(Position(this->position_));
    this->position_->x_ = x;
    this->position_->y_ = y;
}

void Transform :: SetPosition(Position& pos) {
    SetPosition(pos.x_, pos.y_);
}

Transform :: Transform(int x, int y, int width, int height) {
    this->rotation_ = 0;
    this->width_ = width;
    this->height_ = height;
    this->position_ = new Position(x, y);
}
