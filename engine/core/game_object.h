//
// Created by bilgi on 12/24/2020.
//

#ifndef CLIENGINEDEMO_GAME_OBJECT_H
#define CLIENGINEDEMO_GAME_OBJECT_H


#include <iostream>
#include <vector>

class GameObject;

#include "position.h"
#include "rect.h"
#include "transform.h"
#include "collider.h"

const int rotationLeft = -1;
const int rotationRight = 1;
const int rotationStay = 0;


class GameObject {
protected:
    Collider *collider_;
    Transform *transform_;
private:
    std::string uuid_;
    int id_{};
    bool is_solid_{};
public:
    Rect *obj_border_rect_;
public:
    GameObject(int x, int y, int width, int height);
    virtual std::vector<std::vector<std::string>> Draw() = 0;
    bool onCollisionInternal(GameObject&);

    bool IsSolid() const;
    void SetSolid(bool is_solid);
    void SetCollider(Collider*);
    void SetUuid(std::string uuid);

    Transform* GetTransform();
    std::string GetUuid() const;
    int GetId() const;
    Collider* GetCollider();

	virtual void onInputTriggered(char input);
    virtual bool onPositionChangeRequested(int x, int y);
    // new position will be the transform's current position.
    virtual void onPositionChanged();
private:
    void onPositionChangedInternal();
    void updateRectPosition();
};



#endif //CLIENGINEDEMO_GAME_OBJECT_H
