#include <graph_statistics.h>

GraphStatistics::GraphStatistics(Graph * graph){
  int i;
  int degree;
  float distribution;

  this->averageDegree = 0.0;
  this->edgeCount = 0;
  this->maxDegree = 0;

  this->nodeCount = graph->getNodeCount();
  this->degreeDistribution.resize(this->nodeCount);

  for(i = 0; i < this->nodeCount; i++){
    degree = graph->getDegree(i);
    if(degree > this->maxDegree){
      this->maxDegree = degree;
    }
    distribution = this->degreeDistribution.at(degree)+1.0/this->nodeCount;
    this->degreeDistribution.at(degree) = distribution;
    this->edgeCount += degree;
  }

  this->degreeDistribution.resize(this->maxDegree);
  
  this->edgeCount = this->edgeCount/2;

  for(i = 0; i < this->maxDegree; i++){
    this->averageDegree += this->degreeDistribution[i]*i;
  }
};
