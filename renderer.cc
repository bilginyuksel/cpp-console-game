#include "renderer.h"

CLIRenderer :: CLIRenderer() {
  this->scene_max_x_ = 50;
  this->scene_max_y_ = 170;
  for(int i=0; i<50; i++) {
    std::vector<std::string> t(170, "");
    screen_scene_.push_back(t);
  }
}

CLIRenderer :: CLIRenderer(int scene_x, int scene_y) {
  this->scene_max_x_ = scene_x;
  this->scene_max_y_ = scene_y;
}

void CLIRenderer :: clearScene() {
  COORD cursor_position;
  cursor_position.X = 0;
  cursor_position.Y = 0;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor_position);
}

void CLIRenderer :: AttachObject(GameObject *g_object) {
  game_objects_.push_back(g_object);
}

std::string CLIRenderer :: getVisibleRegionPxData() {
  std::string scene;
  for(int i=0; i<scene_max_x_; i++) {
    for(int j=0; j<scene_max_y_; j++)
      scene += screen_scene_[i][j];
    scene += "\n";
  }
  return scene; 
}

void CLIRenderer :: Render() {
  checkCollision();
  // clearScene();
  draw();
  std::string screen = getVisibleRegionPxData();
  std::cout<<screen;
  // clearScene();
}

void CLIRenderer :: draw() {
  for(int i=0; i<scene_max_x_; i++)
    for(int j=0; j<scene_max_y_; j++)
      screen_scene_[i][j] = " ";

  for(GameObject *obj : game_objects_) {
    Transform *transform = obj->GetTransform();
    Position *position = transform -> GetPosition();
    int xs = position->GetX();
    int xe = position->GetX() + transform->GetWidth();
    int ys = position->GetY();
    int ye = position->GetY() + transform -> GetHeight();
    std::vector<std::vector<std::string>> obj_vw = obj->Draw();
    for(int i=xs; i<xe; i++)
      for(int j=ys; j<ye; j++)
        screen_scene_[i][j] = obj_vw[i-xs][j-ys];
  }
}


void CLIRenderer :: checkCollision() {
  for(int i=0;i<game_objects_.size(); i++) {
    Rect *current = game_objects_[i]->GetCollider()->GetRect();
    for(int j=i+1; j<game_objects_.size(); j++){
      GameObject *temp = game_objects_[j];
      bool isIntersected = current->Intersects(*(temp->GetCollider()->GetRect()));
      if(isIntersected) {
        log_.push_back("Collision, ");
        game_objects_[i]->OnCollision(*game_objects_[j]);
        game_objects_[j]->OnCollision(*game_objects_[i]);
      }
    }
  }
}