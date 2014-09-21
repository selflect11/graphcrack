#pragma once

#include <graph.h>

class SpanningTree {
private:
  node_t * fathers;
public:
  SpanningTree(node_count_t);
  node_t getFather(node_t);
  void setFather(node_t, node_t);
};
