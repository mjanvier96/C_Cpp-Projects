#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>

//Helper Functions
void g2AddEdges(Graph g);
int g2DelEdgeTest(Graph g);
float addEdgeWeights(Graph g);
void g3AddEdges(Graph g);
float g3AddEdgeWeights(Graph g);
void sort_arr(int* arr, int n);
int arr_cmp(int* a1, int* a2, int n);
int arr_len(int* a);
void check_len(int* a, int n);
void print_arr(int* arr, int n);

/*
 * Test main for CS182 Homework 3
 * Testing graph implementations
 *
 * Exit code == number of points earned
 *              for that test
 */
int main(int argc, char* argv[])
{
  assert(argc == 2);
  
  int res;
  int* results;
      
  Graph g1 = makeGraph(1, LIST);
  //Graph g1 has 1 vertex

  int test = atoi(argv[1]);

  switch (test)
  {
  case 0:
    res = numVerts(g1);
    //1 vertex
    if (res == 1)
      exit(2);
    else
      exit(0);
   
  case 1:
     res = addEdge(g1, 0, 1, 1.0);
     //Should return ERROR because no vertex 1
    if (res == ERROR)
      exit(1);
    else
      exit(0);

  case 2:
    res = edge(g1, 0, 1);
    //Target out of range, should return -1
    if (res == -1)
      exit(1);
    else
      exit(0);

  case 3:
    results = successors(g1, 0);
    //No successors
    if (results[0] == -1)
      exit(1);
    else
      exit(0);

  case 4:
    results = predecessors(g1, 0);
    //No predecessors
    if (results[0] == -1)
      exit(1);
    else
      exit(0);
    
  case 5:
    //1 point if it doesn't crash
    disposeGraph(g1);
    exit(1);

  default:
    break;
  }

  Graph g2 = makeGraph(4, MATRIX);

  switch (test)
  {
  case 6:
    res = numVerts(g2);
    if (res == 4)
      exit(2);
    else
      exit(0);

  case 7:
    g2AddEdges(g2);
    //Makes complete graph
    //Adds 12 edges with weight 1.0
    float weights = addEdgeWeights(g2);
    if (weights == 12.0)
      exit(4);
    else
      exit(0);
    
  default:
    break;
  }
  
  g2AddEdges(g2);
  /* If addEdge crashes
     can't continue with other tests */

  int ex0[4] = {-1, 1, 2, 3};
  int ex1[4] = {-1, 0, 2, 3};
  int ex2[4] = {-1, 0, 1, 3};
  int ex3[4] = {-1, 0, 1, 2};
  int* suc;
  int* pre;
  switch (test)
  {
  case 8:
    //Successors of g2 vertex 0
    //expected: {-1, 1, 2, 3}
    suc = successors(g2, 0);
    check_len(suc, 4); //exits 0 if wrong length
    sort_arr(suc, 4);
    //see if sorted array match
    if (arr_cmp(ex0, suc, 4))
      exit(1);
    else
      exit(0);

  case 9:
    //Successors of vertex 1
    //expected: {-1, 0, 2, 3}
    suc = successors(g2, 1);
    check_len(suc, 4);
    sort_arr(suc, 4);
    if (arr_cmp(ex1, suc, 4))
      exit(1);
    else
      exit(0);
    
  case 10:
    //Successors of vertex 2
    //expected: {-1, 0, 1, 3}
    suc = successors(g2, 2);
    check_len(suc, 4);
    sort_arr(suc, 4);
    if (arr_cmp(ex2, suc, 4))
      exit(1);
    else
      exit(0);

  case 11:
    //Successors of vertex 3
    //expected: {-1, 0, 1, 2}
    suc = successors(g2, 3);
    sort_arr(suc, 4);
    if (arr_cmp(ex3, suc, 4))
      exit(1);
    else
      exit(0);

  case 12:
    //Predecessors of vertex 0
    //expected: {-1, 1, 2, 3}
    pre = predecessors(g2,0);
    check_len(pre, 4);
    sort_arr(pre, 4);
    if (arr_cmp(ex0, pre, 4))
      exit(1);
    else
       exit(0);

  case 13:
    //Predecessors of vertex 1
    //expected: {-1, 0, 2, 3}
    pre = predecessors(g2, 1);
    sort_arr(pre, 4);
    if (arr_cmp(ex1, pre, 4))
      exit(1);
    else
      exit(0);

  case 14:
    //Predecessors of vertex 2
    //expected : {-1, 0, 1, 3}
    pre = predecessors(g2,2);
    check_len(pre, 4);
    sort_arr(pre, 4);
    if (arr_cmp(ex2, pre, 4))
      exit(1);
    else
      exit(0);

  case 15:
    //Predecessors of vertex 3
    //expected: {-1, 0, 1, 2}
    pre = predecessors(g2,3);
    check_len(pre, 4);
    sort_arr(pre, 4);
    if (arr_cmp(ex3, pre, 4))
      exit(1);
    else
      exit(0);

  case 16:
    //Test deleting some edges
    res = g2DelEdgeTest(g2);
    exit(res);

  default:
    break;
  }

  Graph g3 = makeGraph(5, LIST);

  switch (test)
  {
  case 17:
    res = numVerts(g3);
    if (res == 5)
      exit(1);
    else
      exit(0);
    
  case 18:
    g3AddEdges(g3);
    res = g3AddEdgeWeights(g3);
    if (res == 4)
      exit(1);
    else
      exit(0);

  default:
    break;
  }

  g3AddEdges(g3);

  int empty[1] = {-1};
  int s1[2] = {2, -1}; //successor of g3 vertex 1
  int s2[2] = {4, -1}; //successor of g3 vertex 2
  int s4[3] = {-1, 2, 3}; //successor of g3 vertex 4
  int p2[3] = {-1, 1, 4}; //predecessors of g3 vertex 2
  int p3[2] = {4, -1}; //predecessors of g3 vertex 3
  int p4[2] = {2, -1}; //predecessors of g3 vertex 4
  int* v;
  Graph g2clone;
  switch (test)
  {
  case 19:
    delEdge(g3, 4, 2);
    float e = edge(g3, 4, 2);
    if (e == INFINITY)
      exit(1);
    else
      exit(0);

  case 20:
    res = delEdge(g3, 0, 1);
    if (res == ERROR)
      exit(1);
    else
      exit(0);

  case 21:
    v = successors(g3, 0);
    check_len(v, 1);
    if (arr_cmp(empty, v, 1))
      exit(1);
    else
      exit(0);

  case 22:
    v = successors(g3, 1);
    check_len(v, 2);
    if (arr_cmp(s1, v, 2))
      exit(1);
    else
      exit(0);

  case 23:
    v = successors(g3, 2);
    check_len(v, 2);
    if (arr_cmp(s2, v, 2))
      exit(1);
    else
      exit(0);

  case 24:
    v = successors(g3, 3);
    check_len(v, 1);
    if (arr_cmp(empty, v, 1))
      exit(1);
    else
      exit(0);

  case 25:
    v = successors(g3, 4);
    check_len(v, 3);
    sort_arr(v,3);
    if (arr_cmp(s4, v, 3))
      exit(1);
    else
      exit(0);

  case 26:
    v = predecessors(g3, 0);
    check_len(v, 1);
    if (arr_cmp(empty, v, 1))
      exit(1);
    else
      exit(0);

  case 27:
    v = predecessors(g3, 1);
    check_len(v, 1);
    if (arr_cmp(empty, v, 1))
      exit(1);
    else
      exit(0);

  case 28:
    v = predecessors(g3, 2);
    check_len(v, 3);
    sort_arr(v, 3);
    if (arr_cmp(p2, v, 3))
      exit(1);
    else
      exit(0);

  case 29:
    v = predecessors(g3, 3);
    check_len(v, 2);
    if (arr_cmp(p3, v, 2))
      exit(1);
    else
      exit(0);

  case 30:
    v = predecessors(g3, 4);
    check_len(v, 2);
    if (arr_cmp(p4, v, 2))
      exit(1);
    else
      exit(0);

  case 31:
    g2clone = cloneGraph(g2, LIST);
    exit(1);

  default:
    break;    
  }

  g2clone = cloneGraph(g2, LIST);

  float weights;
  Graph g3clone;
  switch (test)
  {
  case 32:
    weights = addEdgeWeights(g2clone);
    if (weights == 12.0)
      exit(2);
    else
      exit(0);

  case 33:
    g3clone = cloneGraph(g3, MATRIX);
    exit(1);

  default:
    break;  
  }

  g3clone = cloneGraph(g3, MATRIX);

  switch (test)
  {
  case 34:
    weights = g3AddEdgeWeights(g3clone);
    if (weights == 4.0)
      exit(2);
    else
      exit(0);

  }

  disposeGraph(g1);
  disposeGraph(g2);
  disposeGraph(g3);
  disposeGraph(g2clone);
  disposeGraph(g3clone);
  g1 = NULL;
  g2 = NULL;
  g3 = NULL;
  g2clone = NULL;
  g3clone = NULL;
}


/***** HELPER FUNCTIONS *****/

void g2AddEdges(Graph g2)
{
  addEdge(g2, 0, 1, 1.0);
  addEdge(g2, 0, 2, 1.0);
  addEdge(g2, 0, 3, 1.0);
  addEdge(g2, 1, 0, 1.0);
  addEdge(g2, 1, 2, 1.0);
  addEdge(g2, 1, 3, 1.0);
  addEdge(g2, 2, 0, 1.0);
  addEdge(g2, 2, 1, 1.0);
  addEdge(g2, 2, 3, 1.0);
  addEdge(g2, 3, 0, 1.0);
  addEdge(g2, 3, 1, 1.0);
  addEdge(g2, 3, 2, 1.0);
}

void g3AddEdges(Graph g)
{
  addEdge(g, 1, 2, 1.0);
  addEdge(g, 2, 4, 1.0);
  addEdge(g, 4, 2, 1.0);
  addEdge(g, 4, 3, 1.0);
}

float addEdgeWeights(Graph g)
{
  float edge_weights = 0;
  edge_weights += edge(g, 0, 1);
  edge_weights += edge(g, 0, 2);
  edge_weights += edge(g, 0, 3);
  edge_weights += edge(g, 1, 0);
  edge_weights += edge(g, 1, 2);
  edge_weights += edge(g, 1, 3);
  edge_weights += edge(g, 2, 0);
  edge_weights += edge(g, 2, 1);
  edge_weights += edge(g, 2, 3);
  edge_weights += edge(g, 3, 0);
  edge_weights += edge(g, 3, 1);
  edge_weights += edge(g, 3, 2);
  return edge_weights;
}

float g3AddEdgeWeights(Graph g)
{
  float edge_weights = 0;
  edge_weights += edge(g, 1, 2);
  edge_weights += edge(g, 2, 4);
  edge_weights += edge(g, 4, 2);
  edge_weights += edge(g, 4, 3);
  return edge_weights;
}

int g2DelEdgeTest(Graph g2)
{
  int res = 0;
  res += delEdge(g2, 1, 0);
  res += delEdge(g2, 2, 1);
  res += delEdge(g2, 3, 2);
  res += delEdge(g2, 0, 3);
  //If deletes not OK, res != 0
  if (res != 0)
    return 0;
  //No points

  //Now res == number of points
  //+1 for each edge that returns inf
  if (edge(g2, 1, 0) == INFINITY)
    res++;
  if (edge(g2, 2, 1) == INFINITY)
    res++;
  if (edge(g2, 3, 2) == INFINITY)
    res++;
  if (edge(g2, 0, 3) == INFINITY)
    res++;
  return res;
}

/* sort int array
   takes int arr and size of the array */
void sort_arr(int* arr, int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}
 
/* array compare
   returns 1 if same, 0 if not */
int arr_cmp(int* a1, int* a2, int n)
{
  int i;
  for (i = 0; i < n; i++)
    if (a1[i] != a2[i])
      return 0;
  return 1;
}

int arr_len(int* a)
{
  int len = 0;
  while (a && (*a != -1))
  {
    len++;
    a++;
  }
  return len+1; //counting -1 as part of length
}

void check_len(int* a, int n)
{
  if (arr_len(a) != n)
    exit(0);
}

/* print int array
   takes int array and size of the array */
void print_arr(int* arr, int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    printf("arr[%i]: %i\n", i, arr[i]);
  }
}
