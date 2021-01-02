#ifndef UTILITIES_H
#define UTILITIES_H

struct XY
{
    int x, y;
    XY(int ax = 0, int ay = 0);
};

enum TypeRooms
{
    Start, Fight, Nothing, Story, Boss, Shop, Item, Challenge
};

class Utilities
{
public:
    Utilities();
};

#endif // UTILITIES_H
