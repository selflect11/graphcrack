#pragma once

#include <graph_search.h>
#include <queue>

class BFS : public GraphSearch {
  std::queue<node_t> * queue;
  virtual void initialize();
  virtual node_t getNextNode();
  virtual void finalize();
  virtual void discover(node_t);
  virtual bool hasDiscoveredNodes();
public:
  BFS(Graph*);
};
