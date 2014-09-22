#include <graph_search.h>

GraphSearch::GraphSearch(Graph* g) : graph(g) {
  this->marks = new SearchMarking(this->graph->getNodeCount());
  this->marks->setAll(undiscovered);
}

SpanningTree GraphSearch::search(node_t start){
  node_t current;
  SpanningTree spanningTree(this->graph->getNodeCount());
  std::list<node_t> neighbors;
  std::list<node_t>::iterator it;
  this->initialize();
  this->discover(start);
  this->marks->set(start,discovered);

  while(this->hasDiscoveredNodes()){
    current = this->getNextNode();
    if(!this->marks->is(current,explored)){
      neighbors = this->graph->getNeighbors(current);
      for(it = neighbors.begin(); it != neighbors.end(); it++){
        this->discover(*it);
        if(!this->haveFather(*it)){
          spanningTree.setFather(*it,current);
        }
        if(!this->marks->is(*it,explored)){
          this->marks->set(*it,discovered);
        }
      }
    } 
    this->marks->set(current,explored);
  }
  
  this->finalize();
  return spanningTree;
}

void GraphSearch::initialize(){
}

void GraphSearch::finalize(){
}

void GraphSearch::discover(node_t){
}

bool GraphSearch::hasDiscoveredNodes(){
  return false;
}

bool GraphSearch::haveFather(node_t node){
  return !this->marks->is(node, undiscovered);
}

node_t GraphSearch::getNextNode(){
  return 0;
}
