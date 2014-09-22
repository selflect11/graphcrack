#include <dfs.h>
#include <search_marking.h>
#include <stack>

DFS::DFS(Graph* graph){
  this->graph = graph;
}

SpanningTree DFS::search(node_t start){
  // Search related
  std::stack<node_t> * stack;
  SearchMarking marks(this->graph->getNodeCount());
  SpanningTree st(this->graph->getNodeCount());

  // Helper variables
  node_t current;
  std::list<node_t> neighbors;
  std::list<node_t>::iterator it;

  marks.setAll(undiscovered);
  stack = new std::stack<node_t>();
  stack->push(start);

  while(!stack->empty()) {
    current = stack->top();
    stack->pop();
    if(marks.is(current, undiscovered)){
      marks.set(current,discovered);
      neighbors = this->graph->getNeighbors(current);
      for(it = neighbors.begin(); it != neighbors.end(); it++){
        if(marks.is(*it,undiscovered)){
          st.setFather(*it,current);
        }
        stack->push(*it);
      }
    }
  }
  delete stack;
  return st;
}
