//
// Created by bilgi on 12/24/2020.
//

#include "renderer.h"

CLIRenderer::CLIRenderer() {
    this->scene_max_x_ = 50;
    this->scene_max_y_ = 170;
    this->scene_max_visible_x_ = 170;
    this->scene_max_visible_y_ = 50;

    for (int i = 0; i < scene_max_visible_y_; i++) {
        std::vector<std::string> t(scene_max_visible_x_, "");
        screen_scene_.push_back(t);
    }
}

CLIRenderer::CLIRenderer(int scene_x, int scene_y) {
    this->scene_max_x_ = scene_x;
    this->scene_max_y_ = scene_y;
}

void CLIRenderer::clearScene() {
    COORD cursor_position;
    cursor_position.X = 0;
    cursor_position.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor_position);
}

void CLIRenderer::AttachObject(GameObject *g_object) {
    game_objects_.push_back(g_object);
}

std::string CLIRenderer::getVisibleRegionPxData() {
    std::string scene;
    for (int i = 0; i < scene_max_visible_y_; i++) {
        for (int j = 0; j < scene_max_visible_x_; j++)
            scene += screen_scene_[i][j];
        scene += "\n";
    }
    return scene;
}

void CLIRenderer::Render() {
    checkCollision();
    Log::d(tag, "Collision checked");
    clearScene();
    Log::d(tag, "Scene cleared");
    draw();
    Log::d(tag, "Draw function ran");
    std::string screen = getVisibleRegionPxData();
    Log::d(tag, "Get visible region px data.");
    std::cout << screen;
    clearScene();
}

void CLIRenderer::draw() {
    for (int i = 0; i < scene_max_visible_y_; i++)
        for (int j = 0; j < scene_max_visible_x_; j++)
            screen_scene_[i][j] = " ";

    for (GameObject *obj : game_objects_) {
//        Transform *transform = obj->GetTransform();
//        Position *position = transform->GetPosition();
//        int width = transform->GetWidth();
//        int height = transform->GetHeight();
//        int xs = position->GetX() - width/2;
//        int xe = position->GetX() + (width + 1)/2;
//        int ys = position->GetY() - height/2 ;
//        int ye = position->GetY() + (height + 1)/2;
        std::vector<std::vector<std::string>> obj_vw = obj->Draw();
//        Log::d(tag, "Obj draw function ran");
//        Log::d(tag,
//               "Before draw rows= " + std::to_string(obj_vw.size()) + ", columns= " + std::to_string(obj_vw[0].size()));
//        Log::d(tag, "Before draw xs= " + std::to_string(xs) + ", xe= " + std::to_string(xe));
//        Log::d(tag, "Before draw ys= " + std::to_string(ys) + ", ye= " + std::to_string(ye));
        int ys = obj->obj_border_rect_->GetTop();
        int ye = obj->obj_border_rect_->GetBottom();
        int xs = obj->obj_border_rect_->GetLeft();
        int xe = obj->obj_border_rect_->GetRight();
        for (int i = ys; i < ye; i++) {
            for (int j = xs; j < xe; j++) {
                screen_scene_[i][j] = obj_vw[i - ys][j - xs];
            }
        }
        Log::d(tag, "Object drawn to screen");
     //   drawCollider(obj);
    }
}


void CLIRenderer :: drawCollider(GameObject * const game_object) {
        Rect rect = *game_object->obj_border_rect_;
        int bot = rect.GetBottom();
        int top = rect.GetTop() - 1;
        int right = rect.GetRight();
        int left = rect.GetLeft() - 1;
        Log::d(tag, "uuid= " + game_object->GetUuid());
        Log::d(tag, "left= " + std::to_string(left) + ", right= " + std::to_string(right) +
                    ", top= " + std::to_string(top) + ", bottom= " + std::to_string(bot));
        for (int i = top; i <= bot; i++) {
            screen_scene_[i][left] = "|";
            screen_scene_[i][right] = "|";
        }
        for (int i = left; i <= right; i++) {
            screen_scene_[top][i] = "-";
            screen_scene_[bot][i] = "-";
        }
    
}

void CLIRenderer::checkCollision() {
    for (int i = 0; i < game_objects_.size(); i++) {
        Rect *current = game_objects_[i]->GetCollider()->GetRect();
        for (int j = i + 1; j < game_objects_.size(); j++) {
            GameObject *temp = game_objects_[j];
            bool isIntersected = current->Intersects(*(temp->GetCollider()->GetRect()));
            if (isIntersected) {
                Log::d(tag, "Collision happened!");
                game_objects_[i]->onCollisionInternal(*game_objects_[j]);
                game_objects_[j]->onCollisionInternal(*game_objects_[i]);
            }
        }
    }
}
