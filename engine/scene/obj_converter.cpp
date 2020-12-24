//
// Created by bilgi on 12/24/2020.
//

#include "obj_converter.h"

struct obj_width_height {
    int width;
    int height;
};

obj_width_height findVecObjectWidthHeight(const std::string& text_game_object) {
    int obj_height= 0, obj_width = 0;
    int current_width = 0;
    for(char i : text_game_object){
        current_width++;
        if(i == '\n') {
            obj_height++;
            obj_width = std::max(obj_width, current_width);
            current_width = 0;
        }
    }
    return obj_width_height{obj_width, obj_height};
}

std::vector<std::vector<std::string>> cnv::Str2Vec(const std::string& text_game_object) {

    if(text_game_object.length() < 1)throw textGameObjectIsNotValid;
    obj_width_height wh = findVecObjectWidthHeight(text_game_object);
    // user doesn't have to write \n to last element.
    if(text_game_object[text_game_object.length()-1] != '\n') wh.height++;

    std::vector<std::vector<std::string>> vec_game_obj(wh.height, std::vector<std::string>(wh.width, ""));
    int curr_h =0, curr_w=0;
    for(char i : text_game_object) {
        if(i == '\n') {
            curr_w = 0;
            curr_h++;
            continue;
        }
        vec_game_obj[curr_h][curr_w++] = i;
    }

    return vec_game_obj;
}