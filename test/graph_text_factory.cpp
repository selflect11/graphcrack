#include <graph_text_factory.h>
#include <list_graph.h>
#include <assert.h>
#include <iostream>

int main(int argc, char ** argv){
  std::cout << "Testing reading graph" << std::endl;
  GraphTextFactory<ListGraph> factory;
  ListGraph * g = factory.graphFromFile("./test/fixtures/graph_test.txt");

  assert(g && "Graph initialized");
	assert(g->getDegree(1) == 3 && "Graph#getDegree()");
}
