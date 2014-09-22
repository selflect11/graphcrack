#include <dfs.h>

DFS::DFS(Graph* g) : GraphSearch(g) { };

void DFS::initialize(){
  this->stack = new std::stack<node_t>();
}

bool DFS::hasDiscoveredNodes(){
  return this->stack->size();
}

node_t DFS::getNextNode(){
  node_t current = this->stack->top();
  this->stack->pop();
  return current;
}

void DFS::discover(node_t node){
  this->stack->push(node);
}

void DFS::finalize() {
  delete this->stack;
}

bool DFS::haveFather(node_t node){
  return !this->marks->is(node, explored);
}
