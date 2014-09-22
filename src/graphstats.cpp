#include <iostream>
#include <list_graph.h>
#include <matrix_graph.h>
#include <graph_text_factory.h>
#include <graph_statistics.h>

#define OK 0
#define ERR_WRONG_PARAMETERS 1
#define ERR_WRONG_FILE_FORMAT 2

int processStatistics(Graph * graph){
  std::vector<float>::iterator it;
  GraphStatistics stats(graph);
  std::cout << "# n = " << stats.nodeCount << std::endl;
  std::cout << "# m = " << stats.edgeCount << std::endl;
  std::cout << "# d_medio = " << stats.averageDegree << std::endl;
  std::cout << "# d_max = " << stats.maxDegree << std::endl;
  for(it = stats.degreeDistribution.begin(); it != stats.degreeDistribution.end(); it++){
    std::cout << it - stats.degreeDistribution.begin() + 1 << " " << *it << std::endl;
  }
  return OK;
}

template <typename G>
int processGraph(char* path){
  GraphTextFactory<G> factory;
  Graph * graph;
  graph = factory.graphFromFile(path);

  if(!graph) return ERR_WRONG_FILE_FORMAT;
  return processStatistics(graph);
}

int main(int argc, char ** argv) {
  if(argc < 2) {
    std::cout << "Usage: " << argv[0] << " [GRAPH_FILE] [REP]" << std::endl;
    std::cout << "REPresentations: (m = adjacency Matrix) (l = adjacency List)" << std::endl;
    return ERR_WRONG_PARAMETERS;
  }

  if(argc < 3 || argv[2][0] == 'l'){
    return processGraph<ListGraph>(argv[1]);
  } else if (argv[2][0] == 'm'){
    return processGraph<MatrixGraph>(argv[1]);
  }
  
  return ERR_WRONG_PARAMETERS;
}
