#include <iostream>
#include <vector>
#include <unistd.h>


class GameObject {
public:
	const int up = 1;
	const int down = 2;
	const int left = 3;
	const int right = 4;

	int width_;
	int height_;
	int x_;
	int y_;

public:
	GameObject(int x, int y, int width, int height);
	void Move(int c);
	std::vector<std::vector<std::string>> Draw();
};

GameObject :: GameObject(int x, int y, int width, int height) {
	x_ = x;
	y_ = y;
	width_ = width;
	height_ = height;
}


std::vector<std::vector<std::string>> GameObject :: Draw() {
	std::vector<std::vector<std::string>> obj_view(y_+height_, std::vector<std::string>(x_ + width_, " "));

	obj_view[0][2] = "0";	
	obj_view[0][3] = "0";	
	obj_view[0][4] = "0";	
	obj_view[1][2] = "0";	
	obj_view[1][3] = "0";	
	obj_view[1][4] = "0";

	for(int i=0;i<7;i++)
		obj_view[2][i] = "*";

	obj_view[3][0] = "*";	
	obj_view[3][3] = "*";	
	obj_view[3][6] = "*";
	
	obj_view[4][0] = "*";	
	obj_view[4][3] = "*";	
	obj_view[4][6] = "*";	
	
	obj_view[5][3] = "*";	
	
	obj_view[6][1] = "*";	
	obj_view[6][2] = "*";	
	obj_view[6][4] = "*";	
	obj_view[6][5] = "*";

	obj_view[7][1] = "*";	
	obj_view[7][5] = "*";	

	/*
      000
	  000
	*******
	*  *  *
	*  *  *
	   *
	 ** **
	 *   *
	// 7, 8
*/
	return obj_view;
}

void GameObject :: Move(int c) {
	if(c == up)
		y_--;
	else if(c == down)
		y_++;
	else if(c == right)
		x_++;
	else if(c == left)
		x_--;
}

class CLIRenderer {
private:
	int screen_max_x_;
	int screen_max_y_;
	std::vector<std::vector<std::string>> screen_scene_;
	std::vector<GameObject*> game_objects_;

	void clearScreen();
	void fillScreenScene();
	std::string getVisibleRegionPixelData(); 
public:
	CLIRenderer(int, int);
	void Render(); 
	void AttachObject(GameObject*);
	void DrawObjects();
};


void CLIRenderer :: fillScreenScene() {
	for(int i=0; i<screen_max_x_; i++) {
		std::vector<std::string> tmp;
		for(int j=0; j<screen_max_y_; j++) {
			tmp.push_back(" ");
		} screen_scene_.push_back(tmp);
	}	
}

void CLIRenderer :: DrawObjects() {
	for(int i=0; i<screen_max_x_; i++)
		for(int j=0;j<screen_max_y_; j++)
			screen_scene_[i][j] = " ";
	
	for(auto *obj : game_objects_) {
		int xs = obj->x_;
		int xe = obj->x_ + obj->width_;
		int ys = obj->y_;
		int ye = obj->y_ + obj->height_;
		std::vector<std::vector<std::string>> obj_vw = obj->Draw();
		for(int i=xs; i<xe; i++)
			for(int j=ys;j<ye;j++)
				screen_scene_[i][j] = obj_vw[i-xs][j-ys];
		
	}
	
}

CLIRenderer :: CLIRenderer(int max_x = 50, int max_y = 170) {
	this->screen_max_x_ = max_x;
	this->screen_max_y_ = max_y;
	this->fillScreenScene();
}

void CLIRenderer :: clearScreen() {
	system("clear");
}

std::string CLIRenderer :: getVisibleRegionPixelData() {
	std::string screen_;
	for(int i=0; i<screen_max_x_; i++) {
		for(int j=0; j<screen_max_y_; j++) {
			screen_ += screen_scene_[i][j] ;
		} screen_ += "\n"; 
	}	
	return screen_;
}

void CLIRenderer :: Render() {
	clearScreen();
	// default ubuntu terminal font and size
	// full page
	DrawObjects();
	std::string screen_ = getVisibleRegionPixelData();
	std::cout<<screen_<<std::flush;
}


void CLIRenderer :: AttachObject(GameObject *g_object) {
	// render these piece of shit
	game_objects_.push_back(g_object);	

	// update screen with that information
	int x_start = g_object->x_;
	int x_end = g_object->x_ + g_object->width_;
	int y_start = g_object->y_;
	int y_end = g_object->y_ + g_object->height_;
	for(int i = x_start; i<x_end; i++) {
		for(int j= y_start; j<y_end; j++){
			screen_scene_[i][j] = "*";	
		}
	}
}

int main(){
	CLIRenderer *renderer = new CLIRenderer;
	GameObject *g_object = new GameObject(10, 20, 7, 8);
	renderer->AttachObject(g_object);
	int d = -1;
	while(d!= 0) {
		std::cin >> d;
		g_object->Move(d);
		renderer->Render();
	}	
	return 0;
}
