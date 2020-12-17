#ifndef CAMERA_
#define CAMERA_

class VisibleRegion;
class Camera;

class VisibleRegion {
public:
    const int left_;
    const int right_;
    const int bottom_;
    const int top_;
    const int width_;
    const int height_;
};

class Camera {
public:
    int x_;
    int y_;
    // We can lock this center position to a game object.
    // That means they can share the same position reference.
    // Position *center; 
    VisibleRegion *visible_region_;
};
#endif