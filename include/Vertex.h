#ifndef VERTEX_H
#define VERTEX_H

#include "Edge.h"

typedef struct Vertex{

    void* data;
    EDGE** adjacents;
    int num_adjacent;
    int capacity;

} VERTEX;

#endif