#include <bfs.h>
#include <search_marking.h>
#include <queue>

BFS::BFS(Graph* graph){
  this->graph = graph;
}

SpanningTree BFS::search(node_t start){
  // Search related
  std::queue<node_t> * queue;
  SearchMarking marks(this->graph->getNodeCount());
  SpanningTree st(this->graph->getNodeCount());

  // Helper variables
  node_t current;
  std::list<node_t> neighbors;
  std::list<node_t>::iterator it;

  marks.setAll(undiscovered);
  marks.set(start,discovered);
  queue = new std::queue<node_t>();
  queue->push(start);

  while(!queue->empty()) {
    current = queue->front();
    queue->pop();
    neighbors = this->graph->getNeighbors(current);
    for(it = neighbors.begin(); it != neighbors.end(); it++){
      if(marks.is(*it, undiscovered)){
        marks.set(*it,discovered);
        st.setFather(*it,current);
        queue->push(*it);
      }
    }
  }
  delete queue;
  return st;
}
