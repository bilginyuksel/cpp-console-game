#ifndef POSITION_
#define POSITION_

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

#endif