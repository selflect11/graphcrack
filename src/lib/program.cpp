#include <program.h>

int Program::exec(int argc, char ** argv){
  Graph * graph;
  if(argc < 2) {
    std::cout << "Usage: " << argv[0] << " [GRAPH_FILE] [REP]" << std::endl;
    std::cout << "REPresentations: (m = adjacency Matrix) (l = adjacency List)" << std::endl;
    return ERR_WRONG_PARAMETERS;
  }

  if(argc < 3 || argv[2][0] == 'l'){
    graph = this->loadGraph<ListGraph>(argv[1]);
  } else if (argv[2][0] == 'm'){
    graph = this->loadGraph<MatrixGraph>(argv[1]);
  } else {
    return ERR_WRONG_PARAMETERS;
  }

  if(!graph) return ERR_WRONG_FILE_FORMAT;

  return this->run(graph);
}

template <typename G>
Graph * Program::loadGraph(char* path){
  GraphTextFactory<G> factory;
  return factory.graphFromFile(path);
}
