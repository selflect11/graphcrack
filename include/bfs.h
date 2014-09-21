#pragma once

#include <graph.h>
#include <spanning_tree.h>

enum mark_t { undiscovered, discovered, explored };

class BFS {
  Graph * graph;
  mark_t * marks;
  void mark(node_t, mark_t);
  void mark_all_as(mark_t);
public:
  BFS(Graph*);
  SpanningTree search(node_t);
};
