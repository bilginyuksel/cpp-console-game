#include <iostream>
#include <vector>
#include <unistd.h>
#include <conio.h>
#include <thread>
#include <memory>
#include "engine/core/game_object.h"
#include "engine/scene/renderer.h"
#include "engine/scene/obj_converter.h"


class Mehmet : public GameObject {
public:
    std::string tag_ = "Hasan";

    Mehmet(int x, int y, int width, int height) : GameObject(x, y, width, height) {
    }

    std::vector<std::vector<std::string>> Draw() override {
        std::string obj = " THE MEHMET \n"
                          "   [23]\n"
                          " -------- \n"
                          " |   |  |  /|>>\n"
                          " |   |  |_/=|  \n"
                          "     |   \n"
                          "  // | \\\\\n"
                          "_//  |  \\\\_";
        return cnv::Str2Vec(obj);
    }


};
class Ataberk : public GameObject {
public:
    std::string tag_ = "Hasan";

    Ataberk(int x, int y, int width, int height) : GameObject(x, y, width, height) {
    }

    std::vector<std::vector<std::string>> Draw() override {
        std::string obj = " ATABERK\n"
                          "  [17]\n"
                          "&=======&\n"
                          "| ***** |\n"
                          "|  ***  |\n"
                          "   ***\n"
                          " //  \\\\\n"
                          "//    \\\\";
        return cnv::Str2Vec(obj);
    }


};
class Alara : public GameObject {
public:
    std::string tag_ = "Hasan";

    Alara(int x, int y, int width, int height) : GameObject(x, y, width, height) {
    }

    std::vector<std::vector<std::string>> Draw() override {
        std::string res = "  ALARA \n"
                          "   [17] \n"
                          "  =======\n"
                          "  |  |  |\n"
                          "     |  \n"
                          "__   |  __\n"
                          "||_\\/ \\/_||\n";
        return cnv::Str2Vec(res);
    }


};
class Character : public GameObject {
public:
    std::string tag_ = "Character";

    Character(int x, int y, int width, int height) : GameObject(x, y, width, height) {
    }

    std::vector<std::vector<std::string>> Draw() override {
        std::string obj = "  YUKSEL\n"
                          "   [99]\n"
                          "(-------)\n"
                          "(|) | (|)\n"
                          "(|) | (|)\n"
                          "    |\n"
                          "  // \\\\\n"
                          "_//   \\\\_";
        return cnv::Str2Vec(obj);
    }

    void onInputTriggered(char input) override {
        int x = transform_->GetPosition()->GetX();
        int y = transform_->GetPosition()->GetY();

        if (input == 'H') {// up
            transform_->SetPosition(x, y - 1);
        } else if (input == 'P') {// down
            transform_->SetPosition(x, y + 1);
        } else if (input == 'M') {// right
            transform_->SetPosition(x + 1, y);
        } else if (input == 'K') { // left
            transform_->SetPosition(x - 1, y);
        }

        GameObject::onInputTriggered(input);
    }
};

class Selin : public GameObject {
public:
    Selin(int x, int y, int w, int h): GameObject(x, y, w, h) {}
    std::vector<std::vector<std::string>> Draw() override {
        std::string obj = "   SELIN\n"
                          "   [52]\n"
                          " ,,,,,,,,\n"
                          "/.  * *  .\\\n"
                          ".. ( | ) ..\n"
                          "..  ---  ..\n"
                          " . __|__ .\n"
                          "  /  |  \\\n"
                          "  \\  |   \\\n"
                          "    / \\\n"
                          "   /_  \\_";
        return cnv::Str2Vec(obj);
    }
};

class Box : public GameObject {
public:
    std::string tag_ = "Box";

    Box(int x, int y, int w, int h) : GameObject(x, y, w, h) {
    }

    std::vector<std::vector<std::string>> Draw() override {
        int height = transform_->GetHeight();
        int width = transform_->GetWidth();

        std::vector<std::vector<std::string>> obj_vw(height, std::vector<std::string>(width, " "));
        Log::d(tag_, "expected rows= " + std::to_string(height) + ", columns= " + std::to_string(width) + "\n");


        for (int i = 1; i <= 5; i++)
            obj_vw[0][i] = "_";
        obj_vw[1][0] = "|";
        for (int i = 1; i <= 5; i++)
            obj_vw[1][i] = "0";
        obj_vw[1][6] = "|";

        obj_vw[2][0] = "|";
        obj_vw[2][6] = "|";
        for (int i = 1; i <= 5; i++)
            obj_vw[2][i] = "_";
        /*
           _____
          |00000|
          |_____|
        */
        //return cnv::Str2Vec("--\n--");
        //return cnv::FromFile("../assets/box.txt");
        return obj_vw;
    }

};

void getKeyboardInput(char *input, CLIRenderer *renderer, GameObject *g_object) {
    while (*input != 'q') {
        *input = getch();
        g_object->onInputTriggered(*input);
    }
}


int main() {
    //Log::SetEnabled(true);
    Character *character = new Character(10, 20, 10, 8);
    Ataberk *ataberk = new Ataberk(30, 10, 9, 8);
    Mehmet *mehmet = new Mehmet(52, 10, 15, 8);
    Alara *alara = new Alara(80, 20, 12, 7);
    Selin *selin = new Selin(40, 40, 11, 11);

    Box *box1 = new Box(30, 30, 7, 3);
    Box *box2 = new Box(30, 40, 7, 3);

    CLIRenderer *renderer = new CLIRenderer();

    renderer->AttachObject(character);
    renderer->AttachObject(ataberk);
    renderer->AttachObject(mehmet);
    renderer->AttachObject(alara);
    renderer->AttachObject(selin);
    renderer->AttachObject(box1);
    renderer->AttachObject(box2);

    char input = '0';
    std::thread input_thread(getKeyboardInput, &input, renderer, character);
    input_thread.detach();
    while (input != 'q') {
        usleep(1000000 / 100);
        renderer->Render();
    }

    return 0;
}
