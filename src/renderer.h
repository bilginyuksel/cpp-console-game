#ifndef CLI_RENDERER_
#define CLI_RENDERER_
#include <iostream>
#include <vector>
#include <windows.h>
#include "game_object.h"

class CLIRenderer {
private:
  int scene_max_x_;
  int scene_max_y_;
  std::vector<std::vector<std::string>> screen_scene_;
  std::vector<GameObject*> game_objects_;

  void clearScene();
  std::string getVisibleRegionPxData();
  void draw();
  void checkCollision();

public:
  std::vector<std::string> log_;
  
  CLIRenderer();
  CLIRenderer(int , int);
  void AttachObject(GameObject*);
  void Render();
};


#endif