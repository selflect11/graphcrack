#include <spanning_tree.h>

SpanningTree::SpanningTree(node_count_t count){
  this->fathers = new node_t[count];
  this->distances = new node_count_t[count];
  this->maxDistance = -1;
  for(node_count_t i = 0; i < count; i++){
    this->fathers[i] = -1;
    this->distances[i] = -1;
  }
};

node_t SpanningTree::getFather(node_t node){
  return this->fathers[node];
};

void SpanningTree::setFather(node_t node_a, node_t node_b){
  this->fathers[node_a] = node_b;
  if(node_b >= 0) {
    this->distances[node_a] = this->distances[node_b]+1;
    if(this->maxDistance == -1 || (this->distances[node_a] > this->distances[this->maxDistance])) {
      this->maxDistance = node_a;
    }
  }
};

node_count_t SpanningTree::getMaxDistance(){
  return this->distances[this->maxDistance];
};

SpanningTree::~SpanningTree(){
  delete this->distances;
  delete this->fathers;
};
