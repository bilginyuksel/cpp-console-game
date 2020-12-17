#include "transform.h"

Position* Transform :: GetPosition() {
    return position_;
}
const int Transform :: GetRotation() {
    return rotation_;
}
const int Transform :: GetWidth() {
    return width_;
}
const int Transform :: GetHeight() {
    return height_;
}
void Transform :: updateXY(int x, int y){
    this->position_->SetX(this->position_->GetX()+x);
    this->position_->SetY(this->position_->GetY()+y);
}
void Transform :: SetPosition(int x, int y) {
    this->position_->SetX(x);
    this->position_->SetY(y);
}
Transform :: Transform(int x, int y, int width, int height, Rect* rec) {
    this->width_ = width;
    this->height_ = height;
    this->rect_ = rec;
    this->position_ = new Position(x, y);
}