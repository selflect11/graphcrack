#pragma once

#include "graph.h"

class MatrixGraph : public Graph {
private:
	int * adjacencyMatrix;
	int nodeCount;
public:
  MatrixGraph(int);
  void addEdge(int, int);
  int getNodeCount();
  const std::list<int> getNeighbors(int);
  bool isNeighbor(int, int);
  int getDegree(int);
};
