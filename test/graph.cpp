#include <matrix_graph.h>
#include <list_graph.h>
#include <assert.h>
#include <iostream>
#include "fixtures/graphs.h"

template<typename G>
void test_graph(){
  G g = test_graph_5<G>();
	assert(g.getDegree(2) == 3 && "Graph#getDegree()");
  assert(g.getNeighbors(2).size() == 3 && "Graph#getNeighbors()");
	assert(g.getNodeCount() == 5 && "Graph#getNodeCount()");
	assert(g.isNeighbor(0,1) && "Graph#isNeighbor() true");
	assert(!g.isNeighbor(0,3) && "Graph#isNeighbor() false");
}

int main(){
	std::cout << "Test MatrixGraph" << std::endl;
  test_graph<MatrixGraph>();
	std::cout << "Test ListGraph" << std::endl;
  test_graph<ListGraph>();
}
