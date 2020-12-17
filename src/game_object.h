#ifndef CLI_GAME_OBJECT_
#define CLI_GAME_OBJECT_

#include <iostream>
#include <vector>
#include "position.h"
#include "rect.h"
#include "transform.h"

const int rotationLeft = -1;
const int rotationRight = 1;
const int rotationStay = 0;

class Collider;
class GameObject;
class Collision;

class GameObject {
protected:
  Collider *collider_;
  Transform *transform_;
private:
  std::string uuid_;
  int id_;
  bool is_solid_;
  bool updateObjPosition();
public:
  GameObject(int x, int y, int width, int height);
  virtual std::vector<std::vector<std::string>> Draw() = 0;
  virtual bool OnCollision(GameObject&);
 
  const bool IsSolid();
  void SetSolid(bool is_solid);
  void SetCollider(Collider*);
  
  Transform* GetTransform();
  const std::string GetUuid();
  const int GetId();
  Collider* GetCollider();
  void Move(char inp);
};

class Collider {
private:
  Rect *rect_;
  Collision *collision_;
public:
  Collider(int left, int right, int bottom, int top);
  Collider(Rect*);
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



#endif