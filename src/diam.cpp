#include <program.h>
#include <thread>
#include <spanning_tree.h>
#include <bfs.h>
#define THREAD_COUNT 2

typedef std::thread* thread_p;
typedef SpanningTree* st_p;

void bfs(unsigned int id, unsigned int count, Graph * graph, node_count_t * max_ds){
  node_t i;
  std::cout << "Running thread #" << id << std::endl;
}

class GraphStats : public Program {
public:
  virtual int run(Graph * graph){
    node_count_t it;
    node_count_t max_d;
    node_count_t * max_ds;
    BFS bfs(graph);
    max_ds = new node_count_t[graph->getNodeCount()];

    for(it = 0; it < graph->getNodeCount(); it++){
      max_ds[it] = bfs.search(it).getMaxDistance();
    }
    
    max_d = 0;
    for(it = 1; it < graph->getNodeCount(); it++){
      if(max_ds[it] > max_d){
        max_d = max_ds[it];
      }
    }

    std::cout << "Graph Diameter is " << max_d << std::endl;

    return OK;
  }
};

int main(int argc, char ** argv) {
  GraphStats prog;
  return prog.exec(argc, argv);
}
