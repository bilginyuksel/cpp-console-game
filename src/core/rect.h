#ifndef RECT_
#define RECT_

class Rect {
private:
    int left_;
    int right_;
    int bottom_;
    int top_;

public:
    Rect(int left, int top, int right, int bottom);

    const int GetLeft();
    const int GetRight();
    const int GetBottom();
    const int GetTop();

    void SetRect(int left, int top, int right, int bottom);

    const bool Intersects(const Rect&);
    // const bool Intersects(const Rect*);
    // const bool Intersects(const Rect);

    // const bool Contains(const Rect*);
    // const bool Contains(const Rect);
    const bool Contains(const Rect&);
    const bool Contains(int x, int y);
};


#endif