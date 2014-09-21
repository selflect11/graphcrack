#include <graph.h>
#include <bfs.h>
#include <list_graph.h>
#include <assert.h>
#include "fixtures/graphs.h"

int main(){
  ListGraph graph = test_graph_5<ListGraph>();
  BFS bfs(&graph);
  assert(bfs.search(2).getFather(4) == 2);
}
