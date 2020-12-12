#ifndef CLI_GAME_OBJECT_
#define CLI_GAME_OBJECT_

#include <iostream>
#include <vector>

const int rotationLeft = -1;
const int rotationRight = 1;
const int rotationStay = 0;

class Collider;
class Transform;
class Position;
class Rect;
class GameObject;
class Collision;

class GameObject {
protected:
  Collider *collider_;
  Transform *transform_;
private:
  std::string uuid_;
  int id_;
  bool updateObjPosition();
public:
  GameObject(int x, int y, int width, int height);
  virtual std::vector<std::vector<std::string>> Draw() = 0;
  virtual bool OnCollision(GameObject&);
  const std::string GetUuid();
  const int GetId();
  Transform* GetTransform();
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

class Transform {
private:
  int width_;
  int height_;
  int rotation_;
  friend class GameObject;
  Position *position_;
  Rect *rect_;
  void updateXY(int, int);
public:
  Transform(int x, int y, int width, int height, Rect*);
  void SetPosition(int x, int y);
  Position* GetPosition();
  const int GetRotation();
  const int GetWidth();
  const int GetHeight();
};

class Position {
private:
  int x_;
  int y_;
public:
  Position(int, int);
  void SetX(int x);
  void SetY(int y);
  const int GetX();
  const int GetY();
};

class Collision {
public:
  virtual void OnCollision(GameObject &parent) = 0;
};

class Rect {
private:
  int left_;
  int right_;
  int bottom_;
  int top_;
  friend class Transform;
  void updateXY(int x, int y);
public:
  Rect(int left, int right, int bottom, int top);
  const int GetLeft();
  const int GetRight();
  const int GetBottom();
  const int GetTop();
  const bool Contains(const Rect &rect);
  const bool Intersects(const Rect &rect);
};


#endif