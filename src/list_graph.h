#ifndef LIST_GRAPH_H
#define LIST_GRAPH_H

#include "graph.h"

class ListGraph : public Graph {
private:
	std::list<int> * adjacencyList;
	int nodeCount;
public:
  ListGraph(int);
  void addEdge(int, int);
  int getNodeCount();
  const std::list<int> getNeighbors(int);
  bool isNeighbor(int, int);
  int getDegree(int);
};

#endif