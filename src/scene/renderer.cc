#include "renderer.h"

CLIRenderer :: CLIRenderer() {
  this->scene_max_x_ = 50;
  this->scene_max_y_ = 170;
  this->scene_max_visible_x_ = 170;
	this->scene_max_visible_y_ = 50;

	for(int i=0; i<scene_max_visible_y_; i++) {
    std::vector<std::string> t(scene_max_visible_x_, "");
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
  for(int i=0; i<scene_max_visible_y_; i++) {
    for(int j=0; j<scene_max_visible_x_; j++)
      scene += screen_scene_[i][j];
    scene += "\n";
  }
  return scene; 
}

void CLIRenderer :: Render() {
 checkCollision();
	// std::cout<<"Collision checked\n";
 	clearScene();
	// std::cout<<"Scene cleared.\n";
  draw();
	// std::cout<<"Draw function ran.\n";
  std::string screen = getVisibleRegionPxData();
	// std::cout<<"Get visible region px data..\n";
  std::cout<<screen;
  clearScene();
}

void CLIRenderer :: draw() {
  for(int i=0; i<scene_max_visible_y_; i++)
    for(int j=0; j<scene_max_visible_x_; j++)
      screen_scene_[i][j] = " ";

  for(GameObject *obj : game_objects_) {
    Transform *transform = obj->GetTransform();
    Position *position = transform -> GetPosition();
    int xs = position->GetX();
    int xe = position->GetX() + transform->GetWidth();
    int ys = position->GetY();
    int ye = position->GetY() + transform -> GetHeight();
    std::vector<std::vector<std::string>> obj_vw = obj->Draw();
    // std::cout<<"Obj draw function ran\n";
    // std::cout<<"Before Draw rows= "<<obj_vw.size()<<", columns= "<<obj_vw[0].size()<<"\n";
   	// std::cout<<"Before Draw xs= "<<xs<<", xe= "<<xe<<"\n";
    // std::cout<<"Before Draw ys= "<<ys<<", ye= "<<ye<<"\n";
    for(int i=ys; i<ye; i++) { 
      for(int j=xs; j<xe; j++) {
        // std::cout<<", i= "<<j-xs<<", j= "<<i-ys<<"\n";
        // std::cout<<"obj_vw[i][j]= "<<obj_vw[i-ys][j-xs]<<"\n";
        screen_scene_[j][i] = obj_vw[i-ys][j-xs];
			}
		}
		// std::cout<<"Obj drawed to screen\n";
		// draw collider
   Rect *r = obj->GetCollider()->GetRect();
   int bot = r->GetBottom();
   int top = r->GetTop();
   int right = r->GetRight();
   int left = r->GetLeft();
   for(int i=top; i<bot; i++)  {
     screen_scene_[i][right+1] = "|";
     screen_scene_[i][left-1] = "|";
   }
   for(int i=left; i<right+1; i++) {
     screen_scene_[top-1][i] = "-";
     screen_scene_[bot][i] = "-";
   }
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
