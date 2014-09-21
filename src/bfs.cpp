#include <bfs.h>
#include <queue>

BFS::BFS(Graph* graph){
  this->graph = graph;
}

SpanningTree BFS::search(node_t start){
  node_t current;
  std::queue<node_t> * queue;
  std::list<node_t> neighbors;
  std::list<node_t>::iterator it;
  SpanningTree st(this->graph->getNodeCount());


  queue = new std::queue<node_t>();
  this->marks = new mark_t[this->graph->getNodeCount()];
  this->mark_all_as(undiscovered);
  this->marks[start] = discovered;
  queue->push(start);

  while(!queue->empty()) {
    current = queue->front();
    queue->pop();
    neighbors = this->graph->getNeighbors(current);
    for(it = neighbors.begin(); it != neighbors.end(); it++){
      if(marks[*it] == undiscovered){
        marks[*it] = discovered;
        st.setFather(*it,current);
        queue->push(*it);
      }
    }
  }
  delete queue;
  return st;
}

void BFS::mark_all_as(mark_t mark){
  for(node_count_t i = 0; i < this->graph->getNodeCount(); i++){
    marks[i] = mark;
  }
}
