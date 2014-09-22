#pragma once

#include <graph.h>

class SpanningTree {
private:
  node_t * fathers;
  node_count_t * distances;
  node_t maxDistance;
public:
  SpanningTree(node_count_t);
  ~SpanningTree();
  node_t getFather(node_t);
  node_count_t getMaxDistance();
  void setFather(node_t, node_t);
};
