#include <bfs.h>

BFS::BFS(Graph* g) : GraphSearch(g) { };

void BFS::initialize(){
  this->vector = new std::vector<node_t>();
  this->idx = 0;
}

bool BFS::hasDiscoveredNodes(){
  return this->vector->size() - this->idx;
}

node_t BFS::getNextNode(){
  node_t current = this->vector->at(this->idx);
  this->idx++;
  return current;
}

void BFS::discover(node_t node){
  if(this->marks->is(node, undiscovered)){
    this->vector->push_back(node);
  }
}

void BFS::finalize() {
  delete this->vector;
}
