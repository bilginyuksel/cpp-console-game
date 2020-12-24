#include <iostream>
#include <vector>
#include <unistd.h>
#include <conio.h>
#include <thread>
#include <memory>
#include "engine/core/game_object.h"
#include "engine/scene/renderer.h"


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
        obj_view[0][1] = "Y";
        obj_view[0][2] = "U";
        obj_view[0][3] = "K";
        obj_view[0][4] = "S";
        obj_view[0][5] = "E";
        obj_view[0][6] = "L";

        obj_view[1][3] = "[";
        obj_view[1][4] = "5";
        obj_view[1][5] = "]";

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

    bool OnCollision(GameObject &o) override {
        int left = this->collider_->GetRect()->GetLeft();
        int bottom = this->collider_->GetRect()->GetBottom();
        int top = this->collider_->GetRect()->GetTop();
        int right = this->collider_->GetRect()->GetRight();
        std::cout << "Character{left:" << left << ", bottom:" << bottom << ", top:" << top << ", right:" << right
                  << "}\n";
        return false;
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
        return obj_vw;
    }

    bool OnCollision(GameObject &o) override {
        int left = this->collider_->GetRect()->GetLeft();
        int bottom = this->collider_->GetRect()->GetBottom();
        int top = this->collider_->GetRect()->GetTop();
        int right = this->collider_->GetRect()->GetRight();
        Log::d(tag_, "Box{left:" + std::to_string(left) + ", bottom:" + std::to_string(bottom) +
                     ", top:" + std::to_string(top) + ", right:" + std::to_string(right) + "}\n");
        return false;
    }
};

void getKeyboardInput(char *input, CLIRenderer *renderer, GameObject *g_object) {
    while (*input != 'q') {
        *input = getch();
        g_object->Move(*input);
    }
}

int main() {
    Log::SetEnabled(true);
    Character *character = new Character(10, 20, 9, 8);
    character->SetUuid("character");
    Box *box1 = new Box(30, 30, 7, 3);
    box1->SetUuid("box1");
    Box *box2 = new Box(30, 40, 7, 3);
    box2->SetUuid("box2");
    CLIRenderer *renderer = new CLIRenderer();
    renderer->AttachObject(character);
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
