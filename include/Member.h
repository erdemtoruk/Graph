#ifndef MEMBER_H
#define MEMBER_H

#include <stdlib.h>
#include <stdio.h>

struct Edge; //Forward Declaration
struct Vertex; //Forward Declaration

typedef struct Edge{
    struct Vertex* dst; //Destination Vertex
    int weight; //Weight of edge
}EDGE;

typedef struct Vertex{
    int data;
    struct Edge** adjacents;
    int num_adjacent;
    int capacity;
}VERTEX;

/* 

*/
EDGE* Create_Edge(VERTEX*, int);
/* 

*/
void Free_Edge(EDGE*);

/* 

*/
VERTEX* Create_Vertex(int);
/* 

*/
void Add_Edge(VERTEX*, VERTEX*, int);
/* 

*/
void Free_vertex(VERTEX*);

#endif
