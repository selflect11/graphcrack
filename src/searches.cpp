#include <program.h>
#include <ctime>
#include <bfs.h>
#include <dfs.h>
#include <string>

class Searches : public Program {
public:
  void run_search(string name, GraphSearch &search) {
    clock_t begin;
    clock_t end;
    double elapsed_secs;
    begin = clock();
    for(node_count_t i = 0; i < 10; i++){
      SpanningTree st = search.search(i);
      if(i < 5) {
        for(int j = 1; j < 6; j++) {
          std::cout << name << "(" << i << "): " << j*10 << " filho de " st.getFather(j*10) << std::endl;
        }
      }
    }
    end = clock();
    elapsed_secs = double(end-begin)/CLOCKS_PER_SEC;
    std::cout << "Tempo 10 " << name << ": " << elapsed_secs << std::endl;
  }
  virtual int run(Graph * graph){
    // Pause para medir
    BFS bfs(graph);
    DFS dfs(graph);

    this->run_search(bfs);
    this->run_search(dfs);

    return OK;
  }
};

int main(int argc, char ** argv) {
  Searches prog;
  return prog.exec(argc, argv);
}