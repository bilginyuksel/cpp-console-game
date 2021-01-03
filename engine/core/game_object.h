//
// Created by bilgi on 12/24/2020.
//

#ifndef CLIENGINEDEMO_GAME_OBJECT_H
#define CLIENGINEDEMO_GAME_OBJECT_H


#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

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
    std::unordered_set<std::string> collide_cache_;
public:
    Rect *obj_border_rect_;
protected:
    void revert();
public:
    GameObject(int x, int y, int width, int height);
    virtual std::vector<std::vector<std::string>> Draw() = 0;

    bool IsSolid() const;
    void SetSolid(bool is_solid);
    void SetCollider(Collider*);
    void SetId(int id);
    void SetUuid(std::string uuid);

    Transform* GetTransform();
    std::string GetUuid() const;
    int GetId() const;
    Collider* GetCollider();

    virtual void Update();
	virtual void onInputTriggered(char input);
    virtual bool onPositionChangeRequested(int x, int y);
    // new position will be the transform's current position.
    bool onCollisionInternal(GameObject&);
    virtual void onCollisionEnter(GameObject& intersected_obj, std::string tag);
    virtual void onCollisionStay(GameObject& intersected_obj, std::string tag);
    virtual void onCollisionExit(GameObject& intersected_obj, std::string tag);
    
    virtual void onPositionChanged();
    virtual void onPositionChangeCancelled();
private:
    void onPositionChangedInternal();
    void updateRectPosition();

};



#endif //CLIENGINEDEMO_GAME_OBJECT_H
