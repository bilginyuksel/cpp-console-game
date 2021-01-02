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

Collider :: Collider(int left, int right, int bottom, int top){
    this->rect_ = new Rect(left, top, right, bottom);
    // this->collision_ = new Collision; Default collision function
    collision_ = new Collision;
}
Collider ::Collider(const Rect rect, int width, int height) {
    this->rect_ = new Rect(rect.GetLeft() - width,
                           rect.GetTop() - height,
                           rect.GetRight() + width,
                           rect.GetBottom() + height);
    collision_ = new Collision;
}
Collider :: Collider(Rect *rect) {
    this->rect_ = rect;
}

void Collider :: updateCollision(GameObject &collided_obj) {
    this->collision_->updateCollisionStatus(collided_obj);
}

void Collision::OnCollisionEnter(GameObject &parent) {}
void Collision::OnCollisionStay(GameObject &parent) {}
void Collision::OnCollisionExit(GameObject &parent) {}

void Collision :: updateCollisionStatus(GameObject &collided_obj) {

    const std::string id = collided_obj.GetUuid();
    // never saw it before first confrontation.
//    std::cout<<"collision happening\n";
    if(collided_object_cache_.find(id) == collided_object_cache_.end()) {
        // because it is first confrontation collisionEnter event must be triggered.
//        std::cout<<"collision enter\n";
        collided_object_cache_[id] = Status::COLLISION_STAY;
        OnCollisionEnter(collided_obj);
        OnCollisionStay(collided_obj);
        return;
    }

    // we saw the object before check its status
    Status curr_status = collided_object_cache_[id];
    if(curr_status == Status::COLLISION_STAY) {
//        std::cout<<"collision stay\n";
        OnCollisionStay(collided_obj);
    }

}