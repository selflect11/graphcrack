#pragma once

#include <graph.h>
#include <spanning_tree.h>
#include <search_marking.h>

class GraphSearch {
protected:
  SearchMarking * marks;
  Graph * graph;
  virtual void initialize();
  virtual node_t getNextNode();
  virtual void finalize();
  virtual void discover(node_t);
  virtual bool hasDiscoveredNodes();
  virtual bool haveFather(node_t);
public:
  GraphSearch(Graph*);
  SpanningTree search(node_t);
};
