#ifndef GRAPH_H
#define GRAPH_H

#include "Vertex.h"


typedef struct Graph{

    VERTEX** Vertices;
    int num_vertices;
    int capacity;

} GRAPH;


#endif