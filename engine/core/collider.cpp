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

void Collider :: updateCollision(GameObject &collided_obj) {
    this->collision_->updateCollisionStatus(collided_obj);
}

void Collision :: updateCollisionStatus(GameObject &collided_obj) {

    std::string obj_uuid = collided_obj.GetUuid();
    // never saw it before first confrontaion. 
    if(collided_object_cache_.find(obj_uuid) == collided_object_cache_.end()) {
        // because it is first confrontaion collisionEnter event must be triggered.
        collided_object_cache_[obj_uuid] = Status::COLLISION_STAY;
        OnCollisionEnter(collided_obj);
        OnCollisionStay(collided_obj);
        return;
    }

    // we saw the object before check its status
    Status curr_status = collided_object_cache_[obj_uuid];
    if(curr_status == Status::COLLISION_STAY) {
        OnCollisionStay(collided_obj);
    }

}