#include <stdio.h>
#include "Graph.h"

int main(){

    GRAPH* gra = Create_Graph();
    Add_Vertex_to_Graph(gra, 1);
    Add_Vertex_to_Graph(gra, 2);
    Add_Edge_to_Graph(gra, 1, 2, 5, false);

    printf("%d\n", gra->vertices[1]->adjacents[0]->dst->data);
    printf("%d\n", gra->vertices[0]->num_adjacent);
    printf("%d\n", gra->vertices[1]->num_adjacent);
    
    return 0;
}