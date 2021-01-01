//
// Created by bilgi on 12/24/2020.
//

#include "game_object.h"

#include <utility>

// GAME_OBJECT
std::string GameObject :: GetUuid() const {
    return uuid_;
}

int GameObject :: GetId() const {
    return id_;
}
bool GameObject :: IsSolid() const {
    return is_solid_;
}
void GameObject :: SetSolid(bool is_solid) {
    this->is_solid_ = is_solid;
}
void GameObject :: SetCollider(Collider* collider) {
    delete this->collider_;
    this->collider_ = collider;
}
Transform* GameObject :: GetTransform() {
    return transform_;
}
GameObject :: GameObject(int x, int y, int width, int height) {
    // when object is created. get x, y as the center point of the object instead of 
    int half_width = width/2;
    int half_height = height/2;
    int left = x - half_width;
    int right = x + half_width;
    int bottom = y + half_height;
    int top = y - half_height;

    this->transform_ = new Transform(x, y, width, height);
    obj_border_rect_ = new Rect();
    // updateRectPosition uses transform so transform should be initialized before calling it.
    updateRectPosition();

    Rect *rect = new Rect(left, top, right, bottom);
    std::cout<<"left= "<<left<<", right= "<<right<<", top= "<<top<<", bottom= "<<bottom<<"\n";
    this->collider_ = new Collider(rect);
}
void GameObject :: SetUuid(std::string uuid) {
    this->uuid_ = std::move(uuid);
}
bool GameObject :: OnCollision(GameObject& intersected_obj) {
    std::cout<<"Collision happened";
    return false;
}
Collider* GameObject :: GetCollider() {
    return collider_;
}

void GameObject :: updateRectPosition() {
    int x = transform_->GetPosition()->GetX();
    int y = transform_->GetPosition()->GetY();

    int width = transform_->GetWidth();
    int height = transform_->GetHeight();

    int left = x - width/2;
    int right = x + (width + 1)/2;
    int top = y - height/2 ;
    int bottom = y + (height + 1)/2;

    obj_border_rect_->SetBottom(bottom);
    obj_border_rect_->SetRight(right);
    obj_border_rect_->SetLeft(left);
    obj_border_rect_->SetTop(top); 
}

void GameObject :: onPositionChangedInternal() {

}

void GameObject :: onInputTriggered(char input) {
    updateRectPosition();
}
void GameObject :: onPositionChanged(){}
bool GameObject :: onPositionChangeRequested(int x, int y) {
    return false;
}