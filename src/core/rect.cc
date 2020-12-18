#include "rect.h"

Rect :: Rect(int left, int top, int right, int bottom) {
    this->left_ = left;
    this->right_ = right;
    this->bottom_ = bottom;
    this->top_ = top;
}

const int Rect :: GetLeft() {
    return left_;
}
const int Rect :: GetRight() {
    return right_;
}
const int Rect :: GetBottom() {
    return bottom_;
}
const int Rect :: GetTop() {
    return top_;
}
const bool Rect :: Contains(const Rect &rect) {
    return (this->left_ <= rect.left_ && this->right_ >= rect.right_) &&
        (this->top_ <= rect.top_ && this->bottom_ >= rect.bottom_);
}
const bool Rect :: Contains(int x, int y) {
    return (this->left_ <= x && this->right_ >= x) && (this->bottom_ <= y && this->top_ >= y);
}
const bool Rect :: Intersects(const Rect &rect) {
    return  (this->left_ > rect.right_) && (this->right_ < rect.left_) && (this->top_ < rect.bottom_) && (this->bottom_ > rect.top_);
}