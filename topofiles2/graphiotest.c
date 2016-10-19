/* some tests for graphio.c */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "graph.h"
#include "graphio.h"

int main() {
    GraphInfo gi; 

    gi = readGraph("statesContig.txt", LIST);
    // writeGraph(gi);

    int NCnum = vertexNum(gi, "AL");

    int* vsucc = successors(gi->graph, NCnum);
    printf("Successors of AL: ");
    for (int i = 0; vsucc[i] != -1; i++) 
        printf(" %s ", gi->vertnames[i]);
    printf("\n");

    return 0;
}
