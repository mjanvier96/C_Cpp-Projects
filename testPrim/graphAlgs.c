#include "graphAlgs.h"
#include <math.h>
#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

Graph minSpanTree(Graph g){
	float *queue = (float*) malloc(g->numVerts * sizeof(float));
	int *par = (int*) malloc(g->numVerts * sizeof(int));
	for(int i = 0; i < g->numVerts; i++){
		*(queue + i) = INFINITY;
		*(par + i) = -1;
	}
	*queue = 0.0;
	*par = 0;

	int x, y;
	
	for(int k = 1; k < g->numVerts; k++){
		x = y = 0;
		for(int i = 0; i < g->numVerts; i++)
			for(int j = 0; j < g->numVerts; j++){
				if((*(queue + i) != INFINITY) && (*(queue + j) == INFINITY) && 
					edge(g, i, j) < edge(g, x, y)){
					x = i;
					y = j;
				}
			}
		*(par + y) = x;
		*(queue + y) = edge(g, x, y);
	}
//	for(int i = 0; i < g->numVerts; i++)
//		printf("%i    ", *(par + i));

	Graph f = makeGraph(g->numVerts, LIST);
	
	for(int i = 0; i < g->numVerts; i++){
		addEdge(f, i, *(par + i), edge(g, i, *(par + i)));
		addEdge(f, *(par + i), i, edge(g, i, *(par + i)));
	}

	return f;
}
