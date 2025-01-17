#ifndef GRAPH_H
#define GRAPH_H

#include "Member.h"

typedef struct Graph{

    VERTEX** vertices;
    int num_vertices;
    int capacity;

} GRAPH;

/*
Creates a graph.
Returns:
    Graph pointer ifsuccesful, NULL if an error occured.
*/
GRAPH* Create_Graph();

/*
Adds vertex to graph.
Parameters:
    g: Pointer of a graph.
    data: The integer value inside the vertex.
Returns:
    0 if succesful, -1 if `g` is NULL or a node exist with a given `data`.
*/
int Add_Vertex_to_Graph(GRAPH* g, int data);

/*
Adds edge to graph.
Parameters:
    g: Pointer of a graph.
    src_data: The integer value in the source vertex.
    dst_data: The integer value in the destination vertex.
    weight: The weight of a edge.
    is_directed: A boolean indicating whether the edge is directed. If `true`, the
        edge is one-way (from `src` to `dst`). If `false`, an additional reverse edge
        is created (from `dst` to `src`).
Returns:
    0 if succesful, -1 if `g` is NULL or vertices with data `src` or `dst` not found.
*/
int Add_Edge_to_Graph(GRAPH* g, int src_data, int dst_data, int weight, bool is_directed);

/*
Find vertex in graph according to data
Parameters:
    g: Pointer of graph.
    data: The integer value inside the vertex.
Returns:
    Corresponding vertex pointer if succesful, NULL if `g` is NULL or vertex with `data` not found.
*/
VERTEX* Find_Vertex(GRAPH* g, int data);

/* 
Frees the memory allocated dynamically of a graph.
Parameters:
    g: Pointer of a graph.
*/
void Free_Graph(GRAPH* g);

#endif
