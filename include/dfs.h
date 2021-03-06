#pragma once

#include <graph_search.h>
#include <stack>

class DFS : public GraphSearch {
  std::stack<node_t> * stack;
  virtual void initialize();
  virtual node_t getNextNode();
  virtual void finalize();
  virtual void discover(node_t);
  virtual bool hasDiscoveredNodes();
  virtual bool haveFather(node_t);
public:
  DFS(Graph*);
};
