//
// Created by bilgi on 12/24/2020.
//

#ifndef CLIENGINEDEMO_OBJ_CONVERTER_H
#define CLIENGINEDEMO_OBJ_CONVERTER_H

#include <iostream>
#include <vector>
#include <fstream>

const int textGameObjectIsNotValid = -150;
const int fileCouldntFound = -111;

namespace cnv {
    std::vector<std::vector<std::string>> Str2Vec(const std::string& text_game_object);
    std::vector<std::vector<std::string>> FromFile(const std::string& filename);
};


#endif //CLIENGINEDEMO_OBJ_CONVERTER_H
