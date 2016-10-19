#include "dijkstra.h"
#include "minprio.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "graphio.h"

struct node{
	int p;
	int vert;
	Handle ptr;
};
typedef struct node* Node;

int cmp(void* lhs, void* rhs){
        return ((Node)lhs)->p > ((Node)rhs)->p ? 1 : ((Node)lhs)->p < ((Node)rhs)->p ? -1 : 0;
}

void shortestPath(GraphInfo GI, int s){
	int n = GI->graph->numVerts;
	float d[n];
	//printf("%i\n", n);
	int pre[n];
	d[s] = 0.0;
	Handle* handles = malloc(n * sizeof(Handle));

	for(int i = 0; i < n; i++){
		handles[i] = (Handle)malloc(sizeof(struct handle));	
	}

	MinPrio qp = makeQueue(cmp, n);
	Node temp = (Node)malloc(sizeof(struct node));
	temp->vert = s;
	temp->p = 0;
	Handle temp1 = enqueue(qp, temp);
	*handles[s] = *temp1;
	((Node)handles[s]->content)->ptr = temp1;
	for(int i = 0; i < n; i++){
		pre[i] = -1;
		if(i != s){	
			d[i] = INFINITY;
			Node nodeTemp = (Node)malloc(sizeof(struct node));
			nodeTemp->vert = i;
			nodeTemp->p = i+1;
			Handle temp = enqueue(qp, nodeTemp);
			*handles[i] = *temp;
			((Node)handles[i]->content)->ptr = temp;
		}
	}
	
	while(nonempty(qp)){
		Node v = (Node)dequeueMin(qp);
		int* suc = successors(GI->graph, v->vert);
		int* start = suc;
		while(*suc != -1 && *suc != s){
			if(((d[v->vert] + edge(GI->graph, v->vert, *suc)) < d[*suc])){
				d[*suc] = (d[v->vert] + edge(GI->graph, v->vert, *suc));
				pre[*suc] = v->vert;
				Handle h = ((Handle)((Node)handles[*suc]->content)->ptr);
				((Node)h->content)->p = (v->p)-1;
				decreasedKey(qp, ((Handle)((Node)handles[*suc]->content)->ptr));
			}
			suc++;
		}
		free(start);
	}

	printf("Shortest paths from vertex %s\n", GI->vertnames[s]);
	for(int i = 0; i < n; i++){
		if(i != s && pre[i] >= 0){
			printf("to %s is %f via %s\n", GI->vertnames[i], d[i], GI->vertnames[pre[i]]);
		}
	}
	disposeQueue(qp);
	for(int i = 0; i < n; i++){
		free(handles[i]);
	}
	free(handles);
}

int main(){
	GraphInfo gi3 = readGraph("triangleMST.txt", MATRIX);
    shortestPath(gi3, 1);
	shortestPath(gi3, 0);
	GraphInfo gi = readGraph("LevitinPrim.txt", MATRIX);
	shortestPath(gi, 0);
	shortestPath(gi, 1);
	GraphInfo gi2 = readGraph("sixMST.txt", MATRIX);
	shortestPath(gi2, 2);
	shortestPath(gi2, 1);


}	

