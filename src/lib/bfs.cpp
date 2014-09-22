#include <bfs.h>

BFS::BFS(Graph* g) : GraphSearch(g) { };

void BFS::initialize(){
  this->queue = new std::queue<node_t>();
}

bool BFS::hasDiscoveredNodes(){
  return this->queue->size();
}

node_t BFS::getNextNode(){
  node_t current = this->queue->front();
  this->queue->pop();
  return current;
}

void BFS::discover(node_t node){
  if(this->marks->is(node, undiscovered)){
    this->queue->push(node);
  }
}

void BFS::finalize() {
  delete this->queue;
}
