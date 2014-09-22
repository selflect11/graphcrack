#pragma once

#include <graph.h>
#include <spanning_tree.h>

class BFS {
  Graph * graph;
public:
  BFS(Graph*);
  SpanningTree search(node_t);
};
