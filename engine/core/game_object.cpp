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
void GameObject::SetId(int id) {
    this->id_ = id;
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
    this->obj_border_rect_ = new Rect();
    // updateRectPosition uses transform so transform should be initialized before calling it.
    updateRectPosition();

    std::cout<<"left= "<<left<<", right= "<<right<<", top= "<<top<<", bottom= "<<bottom<<"\n";
    this->collider_ = new Collider(*obj_border_rect_, 2, 1);
}
void GameObject :: SetUuid(std::string uuid) {
    this->uuid_ = std::move(uuid);
}

// Deprecated
void GameObject :: onPositionChangeCancelled() {
   // user can fill this method to understand forbidden moves. 
}

void GameObject :: revert() {
    // revert object position to laslt position recorded.
    Position last_position_ = transform_->position_record_.back();
    transform_->position_record_.pop_back();
    transform_->SetPosition(last_position_);
}

// collision happened with an object. Send information to collider and trigger 
// collision functions.
bool GameObject :: onCollisionInternal(GameObject& intersected_obj) {
    // if intersected object is a solid object revert not solid objects
    // last position.
    Rect *obj_rect = intersected_obj.GetCollider()->GetRect();
    Rect *collider_rect = this->GetCollider()->GetRect();
    int ins_obj_top = obj_rect->GetTop();
    int ins_obj_bot = obj_rect->GetBottom();
    int obj_top = collider_rect->GetTop();
    int obj_bot = collider_rect->GetBottom();
    bool isValidCollision = ins_obj_bot > obj_top || ins_obj_top < obj_bot;

    if(!isValidCollision && IsSolid()) {
        intersected_obj.revert();
    }
    // understand which collision state happened.
    // understanding mechanism consists unordered_set
    std::string uuid = intersected_obj.GetUuid();
    if(collide_cache_.find(uuid) == collide_cache_.end()) {
        collide_cache_.insert(uuid);
        onCollisionEnter(intersected_obj, "ENTER");
        return true;
    }

    if(intersected_obj.collider_->isShadowCollision(this->collider_->GetRect())){
        onCollisionExit(intersected_obj, "EXIT");
        collide_cache_.erase(uuid);
        return false;
    }

    onCollisionStay(intersected_obj, "STAY");
    //collider_->updateCollision(intersected_obj);
    return false;
}
void GameObject :: onCollisionEnter(GameObject& intersected_obj, std::string tag) {}
void GameObject :: onCollisionStay(GameObject& intersected_obj, std::string tag) {}
void GameObject :: onCollisionExit(GameObject& intersected_obj, std::string tag) {}
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

void GameObject :: Update() {

}

void GameObject :: onPositionChangedInternal() {
    updateRectPosition();
}

void GameObject :: onInputTriggered(char input) {
    updateRectPosition();
}
void GameObject :: onPositionChanged(){}
bool GameObject :: onPositionChangeRequested(int x, int y) {
    return false;
}
