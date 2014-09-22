#pragma once

#include <list>

typedef long node_count_t;
typedef long node_t;

class Graph {
  public:
    virtual void addEdge(node_t, node_t)=0;
    virtual node_count_t getNodeCount()=0;
    virtual const std::list<node_t> getNeighbors(node_t)=0;
    virtual bool isNeighbor(node_t, node_t)=0;
    virtual int getDegree(node_t)=0;
};
