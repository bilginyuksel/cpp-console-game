#ifndef CAMERA_
#define CAMERA_

#include "../core/position.h"
#include "../core/rect.h"

class VisibleRegion;
class Camera;

class VisibleRegion {
private:
    const int max_width_;
    const int max_height_;

    // If this can stay as constant. We can change the camera position
    // and this will be updated automatically.
    const Position *camera_center_;
    Rect *visible_rect_;

};

class Camera {
public:
    Position *center_;
    // We can lock this center position to a game object.
    // That means they can share the same position reference.
    // Position *center; 
    VisibleRegion *visible_region_;
};
#endif