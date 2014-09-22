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
      // Our representation starts at 0 index, so subtract 1 here
      if(nodeA && nodeB) {
        graph->addEdge(nodeA-1,nodeB-1);
      }
      nodeA = 0;
      nodeB = 0;
    }
    file.close();
  }
  return graph;
}

template class GraphTextFactory<ListGraph>;
template class GraphTextFactory<MatrixGraph>;
