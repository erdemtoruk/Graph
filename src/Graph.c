#include "Graph.h"

GRAPH* Create_Graph(){
    GRAPH* new_graph = (GRAPH*) malloc(sizeof(GRAPH));
    if(!new_graph){
        printf("Can not allocate space!\n");
        return NULL;
    }

    new_graph->num_vertices = 0;
    new_graph->capacity = 0;
    new_graph->vertices = NULL;

    return new_graph;
}

int Add_Vertex_to_Graph(GRAPH* g, int data){
    if(!g){
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

int Add_Edge_to_Graph(GRAPH* g, int src_data, int dst_data, int weight, bool is_directed){
    if(!g){
        printf("Graph not found!\n");
        return -1;
    }

    VERTEX* src = Find_Vertex(g, src_data);
    VERTEX* dst = Find_Vertex(g, dst_data);

    if(src && dst){
        if(Add_Edge(src, dst, weight, is_directed) == -1){
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

VERTEX* Find_Vertex(GRAPH* g, int data){
    if(!g){
        printf("Graph not found!\n");
        return NULL;
    }

    for (int i = 0; i < g->num_vertices; i++){
        if(g->vertices[i]->data == data)
            return g->vertices[i];
    }

    printf("Vertex not found in graph!\n");
    return NULL;    
}

void Free_Graph(GRAPH* g){
    for (int i = 0; i < g->num_vertices; i++){
        Free_Vertex(g->vertices[i]);
    }

    free(g->vertices);
    free(g);
}