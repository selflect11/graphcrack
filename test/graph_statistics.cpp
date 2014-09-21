#include <graph_statistics.h>
#include <list_graph.h>
#include "fixtures/graphs.h"
#include <assert.h>
#include <iostream>

bool between(float f, float b, float e){
  return f > b && f < e;
}

void test_graph_statistics(){
  ListGraph graph = test_graph_5<ListGraph>();
  GraphStatistics stats(&graph);
  assert(stats.nodeCount == 5 && "GraphStatistics#nodeCount");
  assert(stats.edgeCount == 5 && "GraphStatistics#edgeCount");
  assert(between(stats.degreeDistribution[1], 0.19, 0.21) && "GraphStatistics#degreeDistribution[1]");
  assert(between(stats.degreeDistribution[2], 0.59, 0.61) && "GraphStatistics#degreeDistribution[2]");
  assert(between(stats.degreeDistribution[3], 0.19, 0.21) && "GraphStatistics#degreeDistribution[2]");
}

int main(){
  std::cout << "Testing GraphStatistics" << std::endl;
  test_graph_statistics();
}
