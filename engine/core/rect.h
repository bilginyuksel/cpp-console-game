//
// Created by bilgi on 12/24/2020.
//

#ifndef CLIENGINEDEMO_RECT_H
#define CLIENGINEDEMO_RECT_H

class Rect {
private:

    int left_;
    int right_;
    int bottom_;
    int top_;

public:
    Rect(int left, int top, int right, int bottom);
    Rect();

    int GetLeft() const;
    int GetRight() const;
    int GetBottom() const;
    int GetTop() const;

   // void SetRect(int left, int top, int right, int bottom);
    void SetLeft(int left);
    void SetRight(int right);
    void SetTop(int top);
    void SetBottom(int bottom);

    bool Intersects(const Rect&) const;
    // const bool Intersects(const Rect*);
    // const bool Intersects(const Rect);

    // const bool Contains(const Rect*);
    // const bool Contains(const Rect);
    bool Contains(const Rect&) const;
    bool Contains(int x, int y) const;
};


#endif //CLIENGINEDEMO_RECT_H
