#ifndef MEMBER_H
#define MEMBER_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Edge; //Forward Declaration
struct Vertex; //Forward Declaration

typedef struct Edge{
    struct Vertex* dst; //Destination vertex
    int weight; //Weight of edge
}EDGE;

typedef struct Vertex{
    int data;
    struct Edge** adjacents;
    int num_adjacent;
    int capacity;
}VERTEX;

/* 
Creates a weighted edge.
Parameters:
    dst: Pointer of destination vertex.
    weight: Weight of edge.
Returns:
    Edge pointer if succesful, NULL if an error occured.
*/
EDGE* Create_Edge(VERTEX* dst, int weight);

/* 
Frees the memory allocated dynamically of an edge.
Parameters:
    e: Pointer of an edge.
*/
void Free_Edge(EDGE* e);

/* 
Creates a vertex.
Parameters:
    data: The data inside the vertex.
Returns:
    Vertex pointer if succesful, NULL if an error occured.
*/
VERTEX* Create_Vertex(int data);

/* 
Adds an weighted edge from between two vertices.
Parameters:
    src: Pointer of source vertex.
    dst: Pointer of destination vertex.
    weight: Weight of edge.
    is_directed: A boolean indicating whether the edge is directed. If `true`, the
        edge is one-way (from `src` to `dst`). If `false`, an additional reverse edge
        is created (from `dst` to `src`).
Returns:
    0 if succesful, -1 if `src` or `dst` is NULL.
*/
int Add_Edge(VERTEX* src, VERTEX* dst, int weight, bool is_directed);

/* 
Frees the memory allocated dynamically of an vertex.
Parameters:
    v: Pointer of a vertex.
*/
void Free_Vertex(VERTEX* v);

#endif
