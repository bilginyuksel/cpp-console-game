//
// Created by bilgi on 12/24/2020.
//

#ifndef CLIENGINEDEMO_COLLIDER_H
#define CLIENGINEDEMO_COLLIDER_H

class Collision;
class Collider;
#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include "rect.h"
#include "game_object.h"

class Collider {
private:
    Rect *rect_;
    Collision *collision_;
public:
    Collider(int left, int right, int bottom, int top);
    Collider(Rect rect, int width, int height);
    explicit Collider(Rect*);
    Rect* GetRect();

    void updateCollision(GameObject& interstected_obj);
    void SetCollision(Collision* collision);
    bool isShadowCollision(const Rect *collided_rect);
};


enum Status {
    COLLISION_ENTER,
    COLLISION_EXIT,
    COLLISION_STAY
};

class Collision {
private:
    std::vector<std::string> collision_history_;
    std::unordered_map<std::string, Status> collided_object_cache_;
protected:
    void updateCollisionStatus(GameObject &parent);
public:
    friend Collider;
    //virtual void OnCollision(GameObject &parent) = 0;
    virtual void OnCollisionEnter(GameObject &parent);
    virtual void OnCollisionExit(GameObject &parent);
    virtual void OnCollisionStay(GameObject &parent);
};


#endif //CLIENGINEDEMO_COLLIDER_H
