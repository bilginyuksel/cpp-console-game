//
// Created by bilgi on 12/24/2020.
//

#ifndef CLIENGINEDEMO_TRANSFORM_H
#define CLIENGINEDEMO_TRANSFORM_H

#include <deque>

#include "position.h"
#include "rect.h"

class Transform {
private:
    int width_;
    int height_;
    int rotation_;
    friend class GameObject;
    Position *position_;
    std::deque<Position> position_record_;
public:
    Transform(int x, int y, int width, int height);
    void SetPosition(int x, int y);
    void SetPosition(Position& pos);
    Position* GetPosition();
    int GetRotation() const;
    int GetWidth() const;
    int GetHeight() const;
};

#endif //CLIENGINEDEMO_TRANSFORM_H
