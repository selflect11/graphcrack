#pragma once

#include "graph.h"

class ListGraph : public Graph {
private:
	std::list<node_t> * adjacencyList;
	int nodeCount;
public:
  ListGraph(node_count_t);
  void addEdge(node_t, node_t);
  node_count_t getNodeCount();
  const std::list<node_t> getNeighbors(node_t);
  bool isNeighbor(node_t, node_t);
  int getDegree(node_t);
};
