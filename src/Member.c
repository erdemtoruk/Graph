#include "Member.h"

VERTEX* Create_Vertex(int data){
    VERTEX* new_Vertex = (VERTEX*) malloc(sizeof(VERTEX));
    new_Vertex->data = data;
    new_Vertex->capacity = 0;
    new_Vertex->num_adjacent = 0;
    new_Vertex->adjacents = NULL;
    return new_Vertex;
}

void Add_Edge(VERTEX* src, VERTEX* dst, int weight){
    if(src == NULL || dst == NULL){
        printf("Vertex not found!\n");
        return;
    }

    if(src->num_adjacent >= src->capacity){
        src->capacity = (src->capacity == 0) ? 2 : 2 * src->capacity;
        EDGE** new_list = (EDGE**) realloc(src->adjacents, src->capacity * sizeof(EDGE*));
        src->adjacents = new_list;
    }
    src->adjacents[src->num_adjacent++] = Create_Edge(dst, weight);;
}

void Free_Vertex(VERTEX* v){
    for (int i = 0; i < v->num_adjacent; i++){
        Free_Edge(v->adjacents[i]);
    }
    free(v->adjacents);
    free(v);
}

EDGE* Create_Edge(VERTEX* dst, int weight){
    EDGE* new_edge = (EDGE*) malloc(sizeof(EDGE));
    new_edge->dst = dst;
    new_edge->weight = weight;

    return new_edge;
}

void Free_Edge(EDGE* e){
    e->dst = NULL;
    free(e);
}
