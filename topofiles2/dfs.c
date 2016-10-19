//
// Created by Michael Janvier on 3/7/16.
//
#include "dfs.h"
#include <stdlib.h>

#define WHITE 0
#define GREY 1
#define BLACK 2

typedef int* INT;

void dfsVisit(DFSinfo dfs, int vertex, int* count, int* color, int* fin);

DFSinfo DFS(Graph g){
    INT count = (INT) malloc(sizeof(int));
    INT fin = (INT) malloc(sizeof(int));
    *count = 0;
    *fin = numVerts(g);
    INT color = (int*) malloc(numVerts(g) * sizeof(int));
    DFSinfo dfs = (DFSinfo) malloc(sizeof(struct dfsinfo));
    dfs->graph = g;
    dfs->discover = (int*) malloc(numVerts(dfs->graph) * sizeof(int));
    dfs->finish = (int*) malloc(numVerts(dfs->graph) * sizeof(int));
    dfs->finorder = (int*) malloc((numVerts(dfs->graph) + 1) * sizeof(int));
    dfs->parent = (int*) malloc(numVerts(dfs->graph) * sizeof(int));
    dfs->parent[numVerts(dfs->graph)] = -1;
    for(int i = 0; i < numVerts(dfs->graph); i++){
        dfs->parent[i] = -1;
        dfs->finorder[i] = 0;
        dfs->finish[i] = 0;
        dfs->discover[i] = 0;
    	color[i] = 0;
	}
    for(int i = 0; i < numVerts(dfs->graph); i++) {
        if(color[i] == WHITE) {
            dfsVisit(dfs, i, count, color, fin);
        }
    }
    return dfs;
}

void dfsVisit(DFSinfo dfs, int vertex, int* count, int* color, int* fin){
    color[vertex] = GREY;
    (*count)++;
    dfs->discover[vertex] = *count;
    int* arr = successors(dfs->graph, vertex);
    while(*arr != -1){
        if(color[*arr] == WHITE){
            dfs->parent[vertex] = *arr;
            dfsVisit(dfs, *arr, count, color, fin);
        }
        arr++;
    }
    color[vertex] = BLACK;
    (*fin)--;
    dfs->finorder[*fin] = vertex;
    (*count)++;
    dfs->finish[vertex] = *count;
}
