#pragma once

#include <graph_search.h>
#include <vector>

class BFS : public GraphSearch {
protected:
  std::vector<node_t> * vector;
  int idx;
  virtual void initialize();
  virtual node_t getNextNode();
  virtual void finalize();
  virtual void discover(node_t);
  virtual bool hasDiscoveredNodes();
public:
  BFS(Graph*);
};
