#ifndef TRANSFORM_
#define TRANSFORM_
#include "position.h"
#include "rect.h"

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
#endif