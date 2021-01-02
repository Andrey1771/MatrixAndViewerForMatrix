#ifndef MAP_H
#define MAP_H
#include "matrix.h"
#include "utilities.h"
#include "room.h"

class Map
{
public:
    Map();
    Matrix tieldsMatrix;
    std::vector<Room> rooms;

};

#endif // MAP_H
