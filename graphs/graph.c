#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "graph.h"

typedef struct adjList* AdjList;
typedef struct adjNode* AdjNode;

struct adjNode{
    float weight;
    int dest;
    AdjNode next;
};

struct adjList{
    int vertex;
    AdjNode head;  // pointer to head node of list
};

struct graph{
    int rep;
    int vertices;
    float** data;
    AdjList array;
};

AdjNode delNode(AdjNode t);

Graph makeGraph(int n, int rep) {
    Graph g = (Graph) malloc(sizeof(struct graph));
    g->rep = rep;
    g->vertices = n;
    if(rep){
        g->array = (AdjList) malloc(g->vertices * sizeof(struct adjList));
        for (int i = 0; i < g->vertices; i++) {
            g->array[i].vertex = i;
            g->array[i].head = NULL;
        }
    }
    else{
        g->data = (float**) malloc(sizeof(float*) * n);
        for (int i = 0; i < g->vertices; i++) {
            g->data[i] = (float*) malloc(g->vertices * sizeof(float));
        }
        for(int i = 0; i < g->vertices; i++){
            for(int j = 0; j < g->vertices; j++){
                g->data[i][j] = 0;
            }
        }

    }
    return g;
}

Graph cloneGraph(Graph G, int rep){
    Graph gNew = makeGraph(G->vertices, rep);
    if(rep){
        for(int i = 0; i < G->vertices; i++){
            for(int j = 0; j < G->vertices; j++){
                if(G->data[i][j] > 0){
                    addEdge(gNew, i, j, G->data[i][j]);
                }
            }
        }
    }
    else{
        for(int i = 0; i < G->vertices; i++) {
            AdjNode temp = G->array[i].head;
            while(temp){
                addEdge(gNew, i, temp->dest, temp->weight);
                temp = temp->next;
            }
        }
    }
    return gNew;
}

void disposeGraph(Graph G){
    if(!G->rep) {
        for (int i = 0; i < G->vertices; i++) {
            free(G->data[i]);
        }
        free(G->data);
    }
    else{
        for(int i = 0; i < G->vertices; i++){
            AdjNode current = G->array[i].head;
            AdjNode nxt;
            while(current){
                nxt = current->next;
                free(current);
                current = nxt;
            }
            G->array[i].head = NULL;
        }
    }
    free(G);
}

int numVerts(Graph G){
    return G->vertices;
}

int addEdge(Graph G, int source, int target, float w){
    if(source < 0 || source >= G->vertices || target < 0 || target >= G->vertices){
        return ERROR;
    }
    if(!G->rep){
        if(G->data[source][target] == 0) {
            G->data[source][target] = w;
            return OK;
        }
        return ERROR;
    }
    else {
        if(G->array[source].head == NULL){
            G->array[source].head = (AdjNode) malloc(sizeof(struct adjNode));
            G->array[source].head->dest = target;
            G->array[source].head->weight = w;
            G->array[source].head->next = NULL;
            return OK;
        }
        AdjNode temp = G->array[source].head;
        while(temp->next){
            if (temp->dest == target){
                return ERROR;
            }
            temp = temp->next;
        }
        if (temp->dest == target) {
            return ERROR;
        }

        temp->next = (AdjNode) malloc(sizeof(struct adjNode));
        temp->next->dest = target;
        temp->next->weight = w;
        temp->next->next = NULL;

        return OK;
    }
}

int delEdge(Graph G, int source, int target){
    if(source < 0 || source >= G->vertices || target < 0 || target >= G->vertices){
        return -1;
    }

    if(G->rep){
        AdjNode temp = G->array[source].head;
        AdjNode temp2 = NULL;
        if(temp->dest == target){
            temp2 = temp->next;
            G->array[source].head = temp2;
            free(temp);
            return OK;
        }
        else {
            temp2 = NULL;
            while (temp->next && !temp2) {
                if (temp->next->dest == target) {
                    temp2 = temp->next;
                    temp->next = temp->next->next;
                    free(temp2);
                    return OK;
                }
                temp = temp->next;
            }
        }

        return INFINITY;
    }
    else{
        if(!G->data[source][target]){ return ERROR; }
        else{
            G->data[source][target] = 0;
            return OK;
        }
    }
    return ERROR;
}

float edge(Graph G, int source, int target){
    if(source < 0 || source >= G->vertices || target < 0 || target >= G->vertices){
        return (float) -1.0;
    }

    if(G->rep){
        AdjNode temp;

        if(G->array[source].head){ temp = G->array[source].head; }
        else{ return INFINITY; }

        while(temp){
            if(temp->dest == target){ return temp->weight; }
            temp = temp->next;
        }

        return INFINITY;
    }
    else{
        return G->data[source][target];
    }
}

int* successors(Graph G, int source){
    int* suc;
    int index = 0;
    int count = 0;
    if(G->rep){
        AdjNode temp = G->array[source].head;
        while(temp){
            count++;
            temp = temp->next;
        }
        suc = (int*) malloc((count + 1) * sizeof(int));
        temp = G->array[source].head;
        for(int i = 0; i < count; i++){
            suc[i] = temp->dest;
            temp = temp->next;
        }
    }
    else{
        for(int i = 0; i < G->vertices; i++){
            if(G->data[source][i] > 0){
                count++;
            }
        }
        suc = (int*) malloc((count + 1) * sizeof(int));
        for(int i = 0; index < count; i++){
            if(G->data[source][i] > 0){
                suc[index] = i;
                index++;
            }
        }
        suc[count] = -1;
    }
    printf("\nSuccessors of %i are   ", source);
    for(int i = 0; i < count; i++){
        int temp = suc[i];
        printf("   ->   %i", temp);
    }
    return suc;
}

int* predecessors(Graph G, int target){
    int* pre;
    int count = 0;
    if(G->rep){
        AdjNode temp;
        for(int i = 0; i < G->vertices; i++) {
            temp = G->array[i].head;
            while (temp) {
                if (temp->dest == target) {
                    count++;
                }
                temp = temp->next;
            }
        }
        pre = (int*) malloc((count + 1) * sizeof(int));
        count = 0;
        for(int i = 0; i < G->vertices; i++){
            temp = G->array[i].head;
            while(temp){
                if(temp->dest == target){
                    pre[count] = i;
                    count++;
                }
                temp = temp->next;
            }
        }
        pre[count + 1] = -1;
    }
    else{
        for(int i = 0; i < G->vertices; i++){
            if(G->data[i][target] > 0){
                count++;
            }
        }
        pre = (int*) malloc((count + 1) * sizeof(int));
        count = 0;
        for(int i = 0; i < G->vertices; i++){
            if(G->data[i][target] > 0){
                pre[count] = i;
                count++;
            }
        }
    }
    printf("\nPredecessors of %i are   ", target);
    for(int i = 0; i < count; i++){
        int temp = pre[i];
        printf("   ->   %i", temp);
    }
    return pre;
}

void printGraph(Graph G){
    if(G->rep){
        printf("\n\nAdjacency List");
        AdjNode temp;
        for(int i = 0; i < G->vertices; i++) {
            temp = G->array[i].head;
            printf("\n\nVertex %i has an edge to", i);
            while(temp){
                printf("   -> %i (%f)", temp->dest, temp->weight);
                if(temp){
                    temp = temp->next;
                }
            }
        }
    }
    else{
        printf("\nAdjacency Matrix");
        for(int i = 0; i < G->vertices; i++){
            printf("\n\nVertex %i has an edge to", i);
            for(int j = 0; j < G->vertices; j++){
                if(G->data[i][j] > 0) {
                    printf("   -> %i (%f)", j, G->data[i][j]);
                }
            }
        }
    }
}

int main1(){
    Graph g1 = makeGraph(5, MATRIX);
    addEdge(g1, 1, 2, 4.0);
    addEdge(g1, 1, 3, 1.0);
    addEdge(g1, 1, 4, 2.0);
    addEdge(g1, 0, 4, 1.0);
    addEdge(g1, 3, 1, 1.0);
    predecessors(g1, 4);
    int* t = successors(g1, 1);
    int i = 0;
    printf("\n\n");
    while(t[i] != -1){
        int temp = t[i];
        printf("   ->   %i", temp);
        i++;
    }
//    printGraph(g1);
//    delEdge(g1, 1, 4);
//    printGraph(g1);
//    delEdge(g1, 1, 3);
//    printGraph(g1);
//    printf("\n\nEdge of 3 to 1 is %f", edge(g1, 3, 1));
//    Graph g2 = cloneGraph(g1, LIST);
//    printGraph(g2);
//    disposeGraph(g1);
//    disposeGraph(g2);
    return 0;
}
