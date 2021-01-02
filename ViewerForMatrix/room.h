#ifndef ROOM_H
#define ROOM_H
#include "matrix.h"
#include "utilities.h"

class Room
{
public:
    Room(XY aposOnMap, const Matrix &aroomMatrix);
    int numberConnections;
    Matrix roomMatrix;
    XY posOnMap;

};

#endif // ROOM_H
