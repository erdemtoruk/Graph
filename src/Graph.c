#include "Graph.h"

GRAPH* Create_Graph(){
    GRAPH* new_graph = (GRAPH*) malloc(sizeof(GRAPH));
    if(new_graph == NULL){
        printf("Can not allocate space!\n");
        return NULL;
    }

    new_graph->num_vertices = 0;
    new_graph->capacity = 0;
    new_graph->vertices = NULL;

    return new_graph;
}

int Add_Vertex_to_Graph(GRAPH* g, int data){
    if(g == NULL){
        printf("Graph not found!\n");
        return -1;
    }

    for (int i = 0; i < g->num_vertices; i++){
        if(data == g->vertices[i]->data){
            printf("Node already exist!\n");
            return -1;
        }
    }

    if(g->num_vertices >= g->capacity){
        g->capacity = (g->capacity == 0) ? 2 : 2 * g->capacity;
        VERTEX** new_list = (VERTEX**) realloc(g->vertices, g->capacity * sizeof(VERTEX*));
        g->vertices = new_list;
    }
    g->vertices[g->num_vertices++] = Create_Vertex(data);
    return 0;
}

int Add_Edge_to_Graph(GRAPH* g, int src, int dst, int weight, bool is_directed){
    if(g == NULL){
        printf("Graph not found!\n");
        return -1;
    }

    int index1, index2;
    bool flag1 = false;
    bool flag2 = false;

    for (int i = 0; i < g->num_vertices; i++){
        if(src == g->vertices[i]->data){
            index1 = i;
            flag1 = true;
        }

        if(dst == g->vertices[i]->data){
            index2 = i;
            flag2 = true;
        }
    }

    if(flag1 && flag2){
        if(Add_Edge(g->vertices[index1], g->vertices[index2], weight, is_directed) == -1){
            printf("An error occured!\n");
            return -1;
        }
    }
    else{
        printf("Vertex not found!\n");
        return -1;
    }
    return 0;
}

void Free_Graph(GRAPH* g){
    for (int i = 0; i < g->num_vertices; i++){
        Free_Vertex(g->vertices[i]);
    }

    free(g->vertices);
    free(g);
}