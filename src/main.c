#include <stdio.h>
#include "Graph.h"

int main(){

    GRAPH* gra = Create_Graph();
    Add_Vertex_to_Graph(gra, 1);
    Add_Vertex_to_Graph(gra, 2);
    Add_Vertex_to_Graph(gra, 3);
    Add_Vertex_to_Graph(gra, 4);

    Add_Edge_to_Graph(gra, 1, 3, 5, false);
    Add_Edge_to_Graph(gra, 1, 2, 3, false);
    Add_Edge_to_Graph(gra, 1, 4, 1, false);


    printf("%d\n", gra->vertices[1]->adjacents[0]->dst->data);
    printf("%d\n", gra->vertices[0]->num_adjacent);
    printf("%d\n", gra->vertices[1]->num_adjacent);
    
    Print_Adjacentlist(Find_Vertex(gra, 1));
    Print_Adjacentlist(Find_Vertex(gra, 2));
    Print_Adjacentlist(Find_Vertex(gra, 3));
    Print_Adjacentlist(Find_Vertex(gra, 4));

    return 0;
}