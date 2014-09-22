#include <spanning_tree.h>

SpanningTree::SpanningTree(node_count_t count){
  this->fathers = new node_t[count];
  for(node_count_t i = 0; i < count; i++){
    this->fathers[i] = -1;
  }
};

node_t SpanningTree::getFather(node_t node){
  return this->fathers[node];
};

void SpanningTree::setFather(node_t node_a, node_t node_b){
  this->fathers[node_a] = node_b;
};
