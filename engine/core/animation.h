//
// Created by bilgi on 1/6/2021.
//

#ifndef CLI_GAME_ENGINE_ANIMATION_H
#define CLI_GAME_ENGINE_ANIMATION_H

#include <iostream>
#include <vector>

struct animation_frame;

class Animation {
private:
    std::vector<animation_frame> anim_frames_; 
    int animation_id_;
    int current_frame_;
    int total_frame_;
    animation_frame* current_anim_frame_;
public:
    Animation(int total_frame);
    void add_animation_frame(animation_frame frame);
    animation_frame get_current_anim() const;
};

struct animation_frame {
    std::vector<std::vector<std::string>> frame_picture_; 
    // frame time -- (how many ms that frame will stands)
    int frame_;
};

#endif //CLI_GAME_ENGINE_ANIMATION_H
