#include <graph_text_factory.h>
#include <matrix_graph.h>
#include <list_graph.h>
#include <fstream>

template <typename G>
G* GraphTextFactory<G>::graphFromFile(std::string path) {
  G* graph;
  unsigned long int count;
  unsigned long int nodeA;
  unsigned long int nodeB;
  std::ifstream file(path);

  // File not open, it will not initialize the graph
  if(file.good()){
    file >> count;
    graph = new G(count);
    while(file.good()){
      file >> nodeA;
      file >> nodeB;
      graph->addEdge(nodeA-1,nodeB-1);
    }
  }
  return graph;
}

template class GraphTextFactory<ListGraph>;
template class GraphTextFactory<MatrixGraph>;
