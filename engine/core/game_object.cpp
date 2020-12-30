//
// Created by bilgi on 12/24/2020.
//

#include "game_object.h"

// GAME_OBJECT
const std::string GameObject :: GetUuid() {
    return uuid_;
}
const int GameObject :: GetId() {
    return id_;
}
const bool GameObject :: IsSolid() {
    return is_solid_;
}
void GameObject :: SetSolid(bool is_solid) {
    this->is_solid_ = is_solid;
}
void GameObject :: SetCollider(Collider* collider) {
    delete this->collider_;
    this->collider_ = collider;
}
Transform* GameObject :: GetTransform() {
    return transform_;
}
GameObject :: GameObject(int x, int y, int width, int height) {
    int left = x;
    int right = x+width;
    int bottom = y+height;
    int top = y;
    Rect *rect = new Rect(left, right, bottom, top);
    std::cout<<"left= "<<left<<", right= "<<right<<", top= "<<top<<", bottom= "<<bottom<<"\n";
    this->collider_ = new Collider(rect);
    this->transform_ = new Transform(x, y, width, height, rect);
    this->collider_->SetCenter(this->transform_->GetPosition());
}
void GameObject :: SetUuid(std::string uuid) {
    this->uuid_ = uuid;
}
bool GameObject :: OnCollision(GameObject& intersected_obj) {
    std::cout<<"Collision happened";
    return false;
}
Collider* GameObject :: GetCollider() {
    return collider_;
}
void GameObject :: Move(char inp) {
    if(inp == 'H')
        transform_->updateXY(-1, 0);
    else if(inp == 'P')
        transform_->updateXY(1, 0);
    else if(inp == 'M')
        transform_->updateXY(0, 1);
    else if(inp == 'K')
        transform_->updateXY(0, -1);
    int left = this->collider_->GetRect()->GetLeft();
    int bottom = this->collider_->GetRect()->GetBottom();
    int top = this->collider_->GetRect()->GetTop();
    int right = this->collider_->GetRect()->GetRight();
    // std::cout<<"{left:"<<left<<", right:"<<right<<", bottom:"<<bottom<<", top:"<<top<<"}\n";

}