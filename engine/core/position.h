//
// Created by bilgi on 12/24/2020.
//

#ifndef CLIENGINEDEMO_POSITION_H
#define CLIENGINEDEMO_POSITION_H

class Position {
private:
    int x_;
    int y_;

public:

    Position(int x, int y);
    void SetX(int x);
    void SetY(int y);
    const int GetY();
    const int GetX();
};

#endif //CLIENGINEDEMO_POSITION_H
