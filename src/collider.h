#ifndef COLLIDER_
#define COLLIDER_
#include "rect.h"
#include "game_object.h"

class Collision;

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