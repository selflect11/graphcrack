#pragma once

#include <graph.h>
#include <spanning_tree.h>

class DFS {
  Graph * graph;
public:
  DFS(Graph*);
  SpanningTree search(node_t);
};
