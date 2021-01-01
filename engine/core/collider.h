//
// Created by bilgi on 12/24/2020.
//

#ifndef CLIENGINEDEMO_COLLIDER_H
#define CLIENGINEDEMO_COLLIDER_H

class Collision;
class Collider;

#include "rect.h"
#include "game_object.h"


class Collider {
private:
    Rect *rect_;
    Collision *collision_{};
public:
    Collider(int left, int right, int bottom, int top);
    explicit Collider(Rect*);
    Rect* GetRect();
    void SetCollision(Collision* collision);
};


class Collision {
public:
    virtual void OnCollision(GameObject &parent) = 0;
    virtual void OnCollisionEnter(GameObject &parent) = 0;
    virtual void OnCollisionExit(GameObject &parent) = 0;
    virtual void OnCollisionStay(GameObject &parent) = 0;
};


#endif //CLIENGINEDEMO_COLLIDER_H
