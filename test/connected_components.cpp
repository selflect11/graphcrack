#include <graph.h>
#include <connected_components_finder.h>
#include <list_graph.h>
#include <assert.h>
#include <iostream>
#include "fixtures/graphs.h"

int main(){
  std::vector<ConnectedComponent*>::iterator it;
  ListGraph graph = test_graph_not_connected<ListGraph>();
  std::cout << "Testing Connected Components" << std::endl;
  ConnectedComponentsFinder ccf(&graph);

  it = ccf.connectedComponents.begin();
  assert((*it)->size() == 1);
  it++;
  assert((*it)->size() == 2);
  it++;
  assert((*it)->size() == 3);
}
