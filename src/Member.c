#include "Member.h"

VERTEX* Create_Vertex(int data){
    VERTEX* new_vertex = (VERTEX*) malloc(sizeof(VERTEX));
    if(new_vertex == NULL){
        printf("Can not allocate space!\n");
        return NULL;
    }
    new_vertex->data = data;
    new_vertex->capacity = 0;
    new_vertex->num_adjacent = 0;
    new_vertex->adjacents = NULL;
    return new_vertex;
}

int Add_Edge(VERTEX* src, VERTEX* dst, int weight, bool is_directed){
    if(src == NULL || dst == NULL){
        printf("Vertex not found!\n");
        return -1;
    }

    if(src->num_adjacent >= src->capacity){
        src->capacity = (src->capacity == 0) ? 2 : 2 * src->capacity;
        EDGE** new_list = (EDGE**) realloc(src->adjacents, src->capacity * sizeof(EDGE*));
        src->adjacents = new_list;
    }
    src->adjacents[src->num_adjacent++] = Create_Edge(dst, weight);

    if(!is_directed){
        Add_Edge(dst, src, weight, true);
    }

    return 0;
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
    if(new_edge == NULL){
        printf("Can not allocate space!\n");
        return NULL;
    }
    new_edge->dst = dst;
    new_edge->weight = weight;
    return new_edge;
}

void Free_Edge(EDGE* e){
    e->dst = NULL;
    free(e);
}
