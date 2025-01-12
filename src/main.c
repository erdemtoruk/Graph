#include <stdio.h>
#include "Graph.h"

int main(){

    VERTEX* v1 = Create_Vertex(0);
    VERTEX* v2 = Create_Vertex(1);
    Add_Edge(v1, v2, 5);
    printf("%d\n", v1->adjacents[0]->weight);
    

    return 0;
}