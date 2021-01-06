//
// Created by bilgi on 1/6/2021.
//

#include "animation.h"


void Animation :: add_animation_frame(animation_frame frame) {
    anim_frames_.push_back(frame);
}

Animation :: Animation(int total_frame) {
    this->total_frame_ = total_frame;
    this->current_frame_ = 0;
}

// NULL CHECK
animation_frame Animation :: get_current_anim() const {
    return *current_anim_frame_;
}
