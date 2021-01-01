#include <iostream>
#include <vector>
#include <unistd.h>
#include <conio.h>
#include <thread>
#include <memory>
#include "engine/core/game_object.h"
#include "engine/scene/renderer.h"
#include "engine/scene/obj_converter.h"

int characterCount = 0;

class Hasan : public GameObject {
public:
    std::string tag_ = "Hasan";

    Hasan(int x, int y, int width, int height) : GameObject(x, y, width, height) {
    }

    std::vector<std::vector<std::string>> Draw() override {
        int height = transform_->GetHeight();
        int width = transform_->GetWidth();
        std::vector<std::vector<std::string>> obj_view(height, std::vector<std::string>(width, " "));
        obj_view[0][2] = "H";
        obj_view[0][3] = "A";
        obj_view[0][4] = "S";
        obj_view[0][5] = "A";
        obj_view[0][6] = "N";

        obj_view[1][3] = "[";
        obj_view[1][4] = "2";
        obj_view[1][5] = "3";
        obj_view[1][6] = "]";

        for (int i = 1; i < 8; i++)
            obj_view[2][i] = "-";

        obj_view[3][1] = "|";
        obj_view[3][4] = "|";
        obj_view[3][7] = "|";

        obj_view[4][1] = "|";
        obj_view[4][4] = "|";
        obj_view[4][7] = "|";

        obj_view[5][4] = "|";

        obj_view[6][2] = "/";
        obj_view[6][3] = "/";
        obj_view[6][5] = "\\";
        obj_view[6][6] = "\\";

        obj_view[7][0] = "_";
        obj_view[7][1] = "/";
        obj_view[7][2] = "/";
        obj_view[7][6] = "\\";
        obj_view[7][7] = "\\";
        obj_view[7][8] = "_";

        return obj_view;
    }


};
class Yasin : public GameObject {
public:
    std::string tag_ = "Hasan";

    Yasin(int x, int y, int width, int height) : GameObject(x, y, width, height) {
    }

    std::vector<std::vector<std::string>> Draw() override {
        int height = transform_->GetHeight();
        int width = transform_->GetWidth();
        std::vector<std::vector<std::string>> obj_view(height, std::vector<std::string>(width, " "));
        obj_view[0][2] = "Y";
        obj_view[0][3] = "A";
        obj_view[0][4] = "S";
        obj_view[0][5] = "I";
        obj_view[0][6] = "N";

        obj_view[1][3] = "[";
        obj_view[1][4] = "1";
        obj_view[1][5] = "7";
        obj_view[1][6] = "]";

        for (int i = 1; i < 8; i++)
            obj_view[2][i] = "-";

        obj_view[3][1] = "|";
        obj_view[3][4] = "|";
        obj_view[3][7] = "|";

        obj_view[4][1] = "|";
        obj_view[4][4] = "|";
        obj_view[4][7] = "|";

        obj_view[5][4] = "|";

        obj_view[6][2] = "/";
        obj_view[6][3] = "/";
        obj_view[6][5] = "\\";
        obj_view[6][6] = "\\";

        obj_view[7][0] = "_";
        obj_view[7][1] = "/";
        obj_view[7][2] = "/";
        obj_view[7][6] = "\\";
        obj_view[7][7] = "\\";
        obj_view[7][8] = "_";

        return obj_view;
    }


};
class Bayram : public GameObject {
public:
    std::string tag_ = "Hasan";

    Bayram(int x, int y, int width, int height) : GameObject(x, y, width, height) {
    }

    std::vector<std::vector<std::string>> Draw() override {
        int height = transform_->GetHeight();
        int width = transform_->GetWidth();
        std::vector<std::vector<std::string>> obj_view(height, std::vector<std::string>(width, " "));
        obj_view[0][2] = "B";
        obj_view[0][3] = "A";
        obj_view[0][4] = "Y";
        obj_view[0][5] = "R";
        obj_view[0][6] = "A";
        obj_view[0][7] = "M";

        obj_view[1][3] = "[";
        obj_view[1][4] = "7";
        obj_view[1][5] = "2";
        obj_view[1][6] = "]";

        for (int i = 1; i < 8; i++)
            obj_view[2][i] = "-";

        obj_view[3][1] = "|";
        obj_view[3][4] = "|";
        obj_view[3][7] = "|";

        obj_view[4][1] = "|";
        obj_view[4][4] = "|";
        obj_view[4][7] = "|";

        obj_view[5][4] = "|";

        obj_view[6][2] = "/";
        obj_view[6][3] = "/";
        obj_view[6][5] = "\\";
        obj_view[6][6] = "\\";

        obj_view[7][0] = "_";
        obj_view[7][1] = "/";
        obj_view[7][2] = "/";
        obj_view[7][6] = "\\";
        obj_view[7][7] = "\\";
        obj_view[7][8] = "_";

        return obj_view;
    }


};
class Can : public GameObject {
public:
    std::string tag_ = "Hasan";

    Can(int x, int y, int width, int height) : GameObject(x, y, width, height) {
    }

    std::vector<std::vector<std::string>> Draw() override {
        int height = transform_->GetHeight();
        int width = transform_->GetWidth();
        std::vector<std::vector<std::string>> obj_view(height, std::vector<std::string>(width, " "));
        obj_view[0][3] = "C";
        obj_view[0][4] = "A";
        obj_view[0][5] = "N";

        obj_view[1][3] = "[";
        obj_view[1][4] = "0";
        obj_view[1][5] = "2";
        obj_view[1][6] = "]";

        for (int i = 1; i < 8; i++)
            obj_view[2][i] = "-";

        obj_view[3][1] = "|";
        obj_view[3][4] = "|";
        obj_view[3][7] = "|";

        obj_view[4][1] = "|";
        obj_view[4][4] = "|";
        obj_view[4][7] = "|";

        obj_view[5][4] = "|";

        obj_view[6][2] = "/";
        obj_view[6][3] = "/";
        obj_view[6][5] = "\\";
        obj_view[6][6] = "\\";

        obj_view[7][0] = "_";
        obj_view[7][1] = "/";
        obj_view[7][2] = "/";
        obj_view[7][6] = "\\";
        obj_view[7][7] = "\\";
        obj_view[7][8] = "_";

        return obj_view;
    }


};
class Bashir : public GameObject {
public:
    std::string tag_ = "Hasan";

    Bashir(int x, int y, int width, int height) : GameObject(x, y, width, height) {
    }

    std::vector<std::vector<std::string>> Draw() override {
        int height = transform_->GetHeight();
        int width = transform_->GetWidth();
        std::vector<std::vector<std::string>> obj_view(height, std::vector<std::string>(width, " "));
        obj_view[0][2] = "B";
        obj_view[0][3] = "A";
        obj_view[0][4] = "S";
        obj_view[0][5] = "H";
        obj_view[0][6] = "I";
        obj_view[0][7] = "R";

        obj_view[1][3] = "[";
        obj_view[1][4] = "0";
        obj_view[1][5] = "4";
        obj_view[1][6] = "]";

        for (int i = 1; i < 8; i++)
            obj_view[2][i] = "-";

        obj_view[3][1] = "|";
        obj_view[3][4] = "|";
        obj_view[3][7] = "|";

        obj_view[4][1] = "|";
        obj_view[4][4] = "|";
        obj_view[4][7] = "|";

        obj_view[5][4] = "|";

        obj_view[6][2] = "/";
        obj_view[6][3] = "/";
        obj_view[6][5] = "\\";
        obj_view[6][6] = "\\";

        obj_view[7][0] = "_";
        obj_view[7][1] = "/";
        obj_view[7][2] = "/";
        obj_view[7][6] = "\\";
        obj_view[7][7] = "\\";
        obj_view[7][8] = "_";

        return obj_view;
    }


};

class Character : public GameObject {
public:
    std::string tag_ = "Character";

    Character(int x, int y, int width, int height) : GameObject(x, y, width, height) {
    }

    std::vector<std::vector<std::string>> Draw() override {
        int height = transform_->GetHeight();
        int width = transform_->GetWidth();
        std::vector<std::vector<std::string>> obj_view(height, std::vector<std::string>(width, " "));
        Log::d(tag_, "expected rows= " + std::to_string(height) + ", columns= " + std::to_string(width) + "\n");
        obj_view[0][2] = "Y";
        obj_view[0][3] = "U";
        obj_view[0][4] = "K";
        obj_view[0][5] = "S";
        obj_view[0][6] = "E";
        obj_view[0][7] = "L";

        obj_view[1][3] = "[";
        obj_view[1][4] = "9";
        obj_view[1][5] = "9";
        obj_view[1][6] = "]";

        for (int i = 1; i < 8; i++)
            obj_view[2][i] = "-";

        obj_view[3][1] = "|";
        obj_view[3][4] = "|";
        obj_view[3][7] = "|";

        obj_view[4][1] = "|";
        obj_view[4][4] = "|";
        obj_view[4][7] = "|";

        obj_view[5][4] = "|";

        obj_view[6][2] = "/";
        obj_view[6][3] = "/";
        obj_view[6][5] = "\\";
        obj_view[6][6] = "\\";

        obj_view[7][0] = "_";
        obj_view[7][1] = "/";
        obj_view[7][2] = "/";
        obj_view[7][6] = "\\";
        obj_view[7][7] = "\\";
        obj_view[7][8] = "_";

        return obj_view;
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
    auto *character = new Character(10, 20, 9, 8);
    character->SetUuid("character");
    character->SetId(characterCount++);
    auto *hasan = new Hasan(30, 10, 9, 8);
    hasan->SetUuid("hasan");
    hasan->SetId(characterCount++);
    auto *yasin = new Yasin(40, 10, 9, 8);
    yasin->SetUuid("yasin");
    yasin->SetId(characterCount++);
    auto *bayram = new Bayram(10, 20, 9, 8);
    bayram->SetId(characterCount++);
    bayram->SetUuid("bayram");
    auto *can = new Can(50, 10, 9, 8);
    can->SetId(characterCount++);
    can->SetUuid("can");
    auto *bashir = new Bashir(10, 30, 9, 8);
    bashir->SetId(characterCount++);
    bashir->SetUuid("bashir");

    Box *box1 = new Box(30, 30, 7, 3);
    box1->SetUuid("box1");
    box1->SetId(characterCount++);
    Box *box2 = new Box(30, 40, 7, 3);
    box2->SetId(characterCount++);
    box2->SetUuid("box2");
    auto *renderer = new CLIRenderer();
    renderer->AttachObject(character);
    renderer->AttachObject(hasan);
    renderer->AttachObject(yasin);
    renderer->AttachObject(bayram);
    renderer->AttachObject(can);
    renderer->AttachObject(bashir);
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
