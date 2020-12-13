#include "game_object.h"

// POSITION
const int Position :: GetX() {
    return x_;
}
const int Position :: GetY() {
    return y_;
}
void Position :: SetX(int x) {
    this->x_ = x;
}
void Position :: SetY(int y) {
    this->y_ = y;
}
Position :: Position(int x, int y) {
    this->x_ = x;
    this->y_ = y;
}

// TRANSFORM
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
    this->rect_->updateXY(x, y);
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

// COLLIDER
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
// RECT
Rect :: Rect(int left, int right, int bottom, int top) {
    this->left_ = left;
    this->right_ = right;
    this->bottom_ = bottom;
    this->top_ = top;
    std::cout<<"{left:"<<left<<", right:"<<right<<", bottom:"<<bottom<<", top:"<<top<<"}\n";
}
void Rect :: updateXY(int x, int y) {
    left_ += y;
    right_ += y;
    bottom_ += x;
    top_ += x;
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
const bool Rect :: Intersects(const Rect &rect) {
    // std::cout<<"{left:"<<left_<<", bottom:"<<bottom_<<", top:"<<top_<<", right:"<<right_<<"}\n";
    // std::cout<<"{left:"<<rect.left_<<", bottom:"<<rect.bottom_<<", top:"<<rect.top_<<", right:"<<rect.right_<<"}\n";
    return  (this->left_ > rect.right_) && (this->right_ < rect.left_) && (this->top_ < rect.bottom_) && (this->bottom_ > rect.top_);
}

// GAME_OBJECT
const std::string GameObject :: GetUuid() {
    return uuid_;
}
const int GameObject :: GetId() {
    return id_;
}
Transform* GameObject :: GetTransform() {
    return transform_;
}
GameObject :: GameObject(int x, int y, int width, int height) {
    int left = y;
    int right = y+width;
    int top = x;
    int bottom = x+height;
    Rect *rect = new Rect(left, right, bottom, top);
    this->collider_ = new Collider(rect);
    this->transform_ = new Transform(x, y, width, height, rect);
}
bool GameObject :: OnCollision(GameObject& intersected_obj) {
    std::cout<<"Collision happened";
    return false;
}
Collider* GameObject :: GetCollider() {
    return collider_;
}
void GameObject :: Move(char inp) {
    if(inp == 'H')
        transform_->updateXY(-1, 0);
    else if(inp == 'P')
        transform_->updateXY(1, 0);
    else if(inp == 'M')
        transform_->updateXY(0, 1);
    else if(inp == 'K')
        transform_->updateXY(0, -1);
    int left = this->collider_->GetRect()->GetLeft();
    int bottom = this->collider_->GetRect()->GetBottom();
    int top = this->collider_->GetRect()->GetTop();
    int right = this->collider_->GetRect()->GetRight();
    std::cout<<"{left:"<<left<<", right:"<<right<<", bottom:"<<bottom<<", top:"<<top<<"}\n";
    
}