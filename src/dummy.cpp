#include <program.h>
#include <ctime>
#include <bfs.h>
#include <dfs.h>
#include <string>

class Searches : public Program {
public:
  virtual int run(Graph * graph){
    return OK;
  }
};

int main(int argc, char ** argv) {
  Searches prog;
  return prog.exec(argc, argv);
}
