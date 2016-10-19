#include "minprio.h"
#include <stdlib.h>
#include <stdio.h>

struct minprio {
    int arrsize;
    int numElts;
    Handle* arr;
    Comparator comp;
};


int cmp(double lhs, double rhs){
	return lhs > rhs ? 1 : lhs < rhs? -1 : 0;
}


MinPrio makeQueue(Comparator comp, int maxsize){
	MinPrio g = (MinPrio) malloc(sizeof(struct minprio));
	g->comp = comp;
        g->arrsize = maxsize + 1;
        g->numElts = 0;
	g->arr = (Handle*) malloc((maxsize + 1) * sizeof(Handle));
	for(int i = 0; i < (maxsize + 1); i++){
		*(g->arr + i) = (Handle) malloc(sizeof(struct handle));
	}
	return g;
}

void disposeQueue(MinPrio qp){
	for(int i = 0; i < qp->arrsize; i++){
		free(*(qp->arr + i));
		free(qp->arr + i);
	}
	free(qp);
}

void swap(MinPrio qp, int a, int b){
	Handle temp = *(qp->arr + a);
	*(qp->arr + a) = *(qp->arr + b);
	*(qp->arr + b) = temp;
	(*(qp->arr + a))->pos = a;
	(*(qp->arr + b))->pos = b;
}

Handle enqueue(MinPrio qp, void* item){
	(*(qp->arr + (++qp->numElts)))->content = item;
	(*(qp->arr + (qp->numElts)))->pos = qp->numElts;
	return *(qp->arr + (qp->numElts));
}

int nonempty(MinPrio qp){
	if(qp->numElts)
		return 1;
	return 0;
}

void shiftDown(MinPrio qp, int k){
	Handle v = *(qp->arr + k);
	int j;
	while(k < (qp->numElts/2)){
		j = 2*k;
		if(j < qp->numElts && (*(qp->arr + j))->pos > (*(qp->arr + (j+1)))->pos)
			++j;
		if(v->pos <= (*(qp->arr + j))->pos)
			break;
		swap(qp, k, j);
		k = j;
	}
	*(qp->arr + k) = v;
}

void* dequeueMin(MinPrio qp){
	Handle hand = *(qp->arr + 1);
	void* r = (hand->content);
	*(qp->arr + 1) = *(qp->arr + ((qp->numElts)++));
	shiftDown(qp, 1);	
	return r;
}

void decreasedKey(MinPrio qp, Handle hand){

}

int main(){
	MinPrio g = (MinPrio) malloc(sizeof(struct minprio));
        g->arrsize = 5 + 1;
        g->numElts = 0;
        g->arr = (Handle*) malloc((5 + 1) * sizeof(Handle));
        for(int i = 0; i < (5 + 1); i++){
                *(g->arr + i) = (Handle) malloc(sizeof(struct handle));
        }

	enqueue(g, NULL);
	enqueue(g, NULL);
	enqueue(g, NULL);
	enqueue(g, NULL);
	enqueue(g, NULL);
	dequeueMin(g);	
	

}
