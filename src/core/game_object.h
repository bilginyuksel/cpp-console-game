#ifndef CLI_GAME_OBJECT_
#define CLI_GAME_OBJECT_

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
  void SetUuid(std::string uuid);

  Transform* GetTransform();
  const std::string GetUuid();
  const int GetId();
  Collider* GetCollider();
  void Move(char inp);
};




#endif