//
// Created by bilgi on 12/24/2020.
//

#ifndef CLIENGINEDEMO_COLLIDER_H
#define CLIENGINEDEMO_COLLIDER_H

class Collider;

#include <iostream>
#include "rect.h"
#include "position.h"

class Collider {
private:
    Rect *rect_;
    Position *center;
    int width_;
    int height_;

public:
    Collider(int left, int right, int bottom, int top);
    Collider(Rect rect, int width, int height);
    explicit Collider(Rect*);
    Rect* GetRect();

    bool isShadowCollision(const Rect *collided_rect);
};

#endif //CLIENGINEDEMO_COLLIDER_H
