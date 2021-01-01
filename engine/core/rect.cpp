//
// Created by bilginyuksel on 12/24/2020.
//

#include "rect.h"
Rect ::Rect() {
    this->left_ = 0;
    this->right_ = 0;
    this->bottom_ = 0;
    this->top_ = 0;
}

Rect :: Rect(int left, int top, int right, int bottom) {
    this->left_ = left;
    this->right_ = right;
    this->bottom_ = bottom;
    this->top_ = top;
}
void Rect :: SetLeft(int left) {
    this->left_ = left;
}
void Rect :: SetRight(int right) {
    this->right_ = right;
}
void Rect :: SetTop(int top) {
    this->top_ = top;
}
void Rect :: SetBottom(int bottom) {
    this->bottom_ = bottom;
}
int Rect :: GetLeft() const {
    return left_;
}
int Rect :: GetRight() const {
    return right_;
}
int Rect :: GetBottom() const {
    return bottom_;
}
int Rect :: GetTop() const {
    return top_;
}
bool Rect :: Contains(const Rect &rect) const {
    return (this->left_ <= rect.left_ && this->right_ >= rect.right_) &&
           (this->top_ <= rect.top_ && this->bottom_ >= rect.bottom_);
}
bool Rect :: Contains(int x, int y) const {
    return (this->left_ <= x && this->right_ >= x) && (this->bottom_ <= y && this->top_ >= y);
}
bool Rect :: Intersects(const Rect &rect) const {
    return  (this->left_ > rect.right_) && (this->right_ < rect.left_) && (this->top_ < rect.bottom_) && (this->bottom_ > rect.top_);
}