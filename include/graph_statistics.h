#pragma once

#include <graph.h>

class GraphStatistics {
public:
  GraphStatistics(Graph);
  float averageDegree;
  std::vector<float> degreeDistribution;
  int nodeCount;
  int edgeCount;
}
