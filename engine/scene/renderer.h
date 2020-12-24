//
// Created by bilgi on 12/24/2020.
//

#ifndef CLIENGINEDEMO_RENDERER_H
#define CLIENGINEDEMO_RENDERER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include "../core/position.h"
#include "../core/game_object.h"
#include "../logger.h"

const std::string tag = "CLIRenderer";

class CLIRenderer {
private:
    int scene_max_visible_x_;
    int scene_max_visible_y_;

    int scene_max_x_;
    int scene_max_y_;
    std::vector<std::vector<std::string>> screen_scene_;
    std::vector<GameObject*> game_objects_;

    std::string getVisibleRegionPxData();
    void clearScene();
    void draw();
    void checkCollision();

public:
    std::vector<std::string> log_;

    CLIRenderer();
    CLIRenderer(int , int);
    void AttachObject(GameObject*);
    void Render();
};


#endif //CLIENGINEDEMO_RENDERER_H
