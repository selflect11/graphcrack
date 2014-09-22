#include <connected_components_finder.h>

ConnectedComponentsFinder::ConnectedComponentsFinder(Graph * g) : BFS(g){
  for(node_count_t i = 0; i < this->graph->getNodeCount(); i++) {
    this->remaining.insert(i);
  }

  while(!this->remaining.empty()) {
    this->makeComponent();
    this->search(*this->remaining.begin());
  }
}

void ConnectedComponentsFinder::initialize(){
  //No-op - Avoid reseting markation
}

void ConnectedComponentsFinder::makeComponent(){
  this->connectedComponents.push_back(new ConnectedComponent());
}

void ConnectedComponentsFinder::discover(node_t node){
  BFS::discover(node);
  if(this->remaining.find(node) != this->remaining.end()){
    this->connectedComponents.back()->push_back(node);
    this->remaining.erase(node);
  }
}
