#include "graphAlgs.h"
#include <math.h>
#include <stdio.h>
float solve(float a,float b, float c){
	if(a != INFINITY){ return a; }
	else if(b != INFINITY && c != INFINITY) { return (b + c); }
	else{ return INFINITY; }
}

Graph transClose(Graph g){
	int size = g->numVerts;
	Graph f = makeGraph(g->numVerts, MATRIX);
	for (int src = 0; src < size; src++)
            for (int trg = 0; trg < size; trg++)
                *(f->adjM + (size*src) + trg) = 0; 
	
	for(int k = 0; k < size; k++)
		for(int i = 0; i < size; i++)
			for(int j = 0; j < size; j++){
				*(f->adjM + (size * i) + j) = solve(*(g->adjM + (size * i) + j), *(g->adjM + (size * i) + k), *(g->adjM + (size * k) + j));
			}
	return f;
}

Graph minSpanTree(Graph g){
	
}

