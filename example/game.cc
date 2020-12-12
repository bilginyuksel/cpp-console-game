#include <iostream>
#include <vector>
#include <unistd.h>
#include <future>
#include <conio.h>
#include <thread>
#include <memory>
#include "../game_object.h"
#include "../renderer.h"

class Character : public GameObject {
public:
  Character(int x, int y, int width, int height) : GameObject(x, y, width, height) {
  }
  std::vector<std::vector<std::string>> Draw()
  {
    int height = transform_->GetHeight();
    int width = transform_->GetWidth();
    Position *pos = transform_->GetPosition();
    int y = pos->GetY();
    int x = pos->GetX();
    std::vector<std::vector<std::string>> obj_view(y + height, std::vector<std::string>(x + width, " "));

    obj_view[0][3] = "[";
    obj_view[0][4] = "5";
    obj_view[0][5] = "]";

    for (int i = 1; i < 8; i++)
      obj_view[1][i] = "-";

    obj_view[2][1] = "|";
    obj_view[2][4] = "|";
    obj_view[2][7] = "|";

    obj_view[3][1] = "|";
    obj_view[3][4] = "|";
    obj_view[3][7] = "|";

    obj_view[4][4] = "|";

    obj_view[5][2] = "/";
    obj_view[5][3] = "/";
    obj_view[5][5] = "\\";
    obj_view[5][6] = "\\";

    obj_view[6][0] = "_";
    obj_view[6][1] = "/";
    obj_view[6][2] = "/";
    obj_view[6][6] = "\\";
    obj_view[6][7] = "\\";
    obj_view[6][8] = "_";

    return obj_view;
  }

  bool OnCollision(GameObject &o) {
    std::cout<<"Collision happened character";
    return false;
  }
};

class Box : public GameObject {
public:
  Box(int x, int y, int w, int h) : GameObject(x, y, w, h){}
  std::vector<std::vector<std::string>> Draw() {
    int height = transform_->GetHeight();
    int width = transform_->GetWidth();
    Position *pos = transform_->GetPosition();
    int y = pos->GetY();
    int x = pos->GetX();
    std::vector<std::vector<std::string>> obj_vw(y + height, std::vector<std::string>(x + width, " "));

    for(int i=1; i<=5;i++)
      obj_vw[0][i] = "_";
    obj_vw[1][0] = "|";
    for(int i=1;i<=5;i++)
      obj_vw[1][i] = "0";
    obj_vw[1][6] = "|";

    obj_vw[2][0] = "|";
    obj_vw[2][6] = "|";
    for(int i=1;i<=5;i++)
      obj_vw[2][i] = "_";
    /*
       _____
      |00000|
      |_____|
    */
   return obj_vw;
  }
   bool OnCollision(GameObject &o) {
    std::cout<<"Collision happened box";
    return false;
  }
};

void getKeyboardInput(char *input, CLIRenderer *renderer, GameObject* g_object) {
  while(*input != 'q') {
		*input = getch();
		g_object->Move(*input);
	}
}

int main()
{
  Character *character = new Character(10, 20, 8, 9);
  Box *box1 = new Box(30,50, 3, 7);
  Box *box2 = new Box(40,50, 3, 7);
  CLIRenderer *renderer = new CLIRenderer();
  renderer->AttachObject(character);
  renderer->AttachObject(box1);
  renderer->AttachObject(box2);

  char input = '0';
  std::thread input_thread(getKeyboardInput, &input, renderer, character);
  input_thread.detach();
  while(input != 'q') {
    usleep(1000000/100);
    renderer->Render();
  }

  for(int i=0; i<renderer->log_.size();i++)
    std::cout<<renderer->log_[i]<<"\n";
  return 0;
}