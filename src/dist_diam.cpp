#include <program.h>
#include <thread>
#include <spanning_tree.h>
#include <bfs.h>
#define THREAD_COUNT 2

typedef std::thread* thread_p;
typedef SpanningTree* st_p;

void bfs(unsigned int id, unsigned int count, Graph * graph, node_count_t * max_ds){
  node_t i;
  BFS bfs(graph);
  std::cout << "Running thread #" << id << std::endl;
  for(i = 0; (count*i)+id < graph->getNodeCount(); i++){
    max_ds[count*i+id] = bfs.search(count*i+id).getMaxDistance();
  }
}

class GraphStats : public Program {
public:
  virtual int run(Graph * graph){
    unsigned int i;
    thread_p * threads;
    node_count_t it;
    node_count_t max_d;
    node_count_t * max_ds;
    unsigned int count = std::thread::hardware_concurrency(); 
    if(!count) count = THREAD_COUNT;
    std::cout << "Thread Number: " << count << std::endl;

    threads = new thread_p[count];
    max_ds = new node_count_t[graph->getNodeCount()];

    for(i=0; i < count; i++){
      threads[i] = new std::thread(bfs,i,count,graph,max_ds);
    }

    for(i=0; i < count; i++){
      threads[i]->join();
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
