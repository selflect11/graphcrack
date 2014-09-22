#include <graph.h>
#include <dfs.h>
#include <list_graph.h>
#include <assert.h>
#include "fixtures/graphs.h"

void test_a(){
  ListGraph graph = test_graph_5<ListGraph>();
  DFS dfs(&graph);
  assert(dfs.search(2).getFather(4) == 3 || dfs.search(2).getFather(3) == 4);
}

void test_b(){
  ListGraph graph = test_graph_dfs<ListGraph>();
  DFS dfs(&graph);
  assert(dfs.search(0).getFather(1) == 2 || dfs.search(0).getFather(4) == 5);
}
int main(){
	test_a();
	test_b();
}