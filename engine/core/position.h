//
// Created by bilgi on 12/24/2020.
//

#ifndef CLIENGINEDEMO_POSITION_H
#define CLIENGINEDEMO_POSITION_H

class Position {
private:
    int x_;
    int y_;
    friend class Transform;
public:
    Position(int x, int y);
    // Create a new copy position from position pointer.
    Position(Position*);
    int GetY() const;
    int GetX() const;
};

#endif //CLIENGINEDEMO_POSITION_H
