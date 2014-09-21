#include <graph_statistics.h>

GraphStatistics::GraphStatistics(Graph * graph){
  int i;
  int degree;
  float distribution;

  this->averageDegree = 0.0;
  this->edgeCount = 0;

  this->nodeCount = graph->getNodeCount();

  for(i = 0; i < this->nodeCount; i++){
    degree = graph->getDegree(i);
    if(degree > this->degreeDistribution.size()){
      this->degreeDistribution.resize(degree+2);
    }
    distribution = this->degreeDistribution.at(degree) + 1.0/this->nodeCount;
    this->degreeDistribution.at(degree) = distribution;
    this->edgeCount += degree;
  }
  
  this->edgeCount = this->edgeCount/2;

  for(i = 0; i != this->degreeDistribution.size(); i++){
    this->averageDegree += this->degreeDistribution[i]*i;
  }
};
