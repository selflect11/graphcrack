#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <list>
class Graph {
  public:
    virtual void addEdge(int, int)=0;
    virtual int getNodeCount()=0;
    virtual const std::list<int> getNeighbors(int)=0;
    virtual bool isNeighbor(int, int)=0;
    virtual int getDegree(int)=0;
};

#endif
