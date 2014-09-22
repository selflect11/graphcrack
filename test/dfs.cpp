#include <graph.h>
#include <dfs.h>
#include <list_graph.h>
#include <assert.h>
#include "fixtures/graphs.h"

int main(){
  ListGraph graph = test_graph_5<ListGraph>();
  DFS dfs(&graph);
  assert(dfs.search(2).getFather(4) == 3 || dfs.search(2).getFather(3) == 4);
}
