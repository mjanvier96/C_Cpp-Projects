#include "graphAlgs.h"
#include <math.h>
#include <stdlib.h>

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
//      for(int i = 0; i < g->numVerts; i++)
//              printf("%i    ", *(par + i));

        Graph f = makeGraph(g->numVerts, LIST);

        for(int i = 0; i < g->numVerts; i++){
                addEdge(f, i, *(par + i), edge(g, i, *(par + i)));
                addEdge(f, *(par + i), i, edge(g, i, *(par + i)));
        }

        return f;
}


int main(){

}
