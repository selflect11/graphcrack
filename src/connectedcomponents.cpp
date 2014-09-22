#include <program.h>
#include <connected_components_finder.h>

class GraphStats : public Program {
public:
  virtual int run(Graph * graph){
    ConnectedComponentsFinder ccf(graph);
    std::cout << "No CC: " << ccf.connectedComponents.size() << std::endl;
    ConnectedComponent * bigger = ccf.connectedComponents.front();
    ConnectedComponent * smaller = ccf.connectedComponents.front();
    std::list<ConnectedComponent*>::iterator it;
    for(it = ccf.connectedComponents.begin(); it != ccf.connectedComponents.end(); it++) {
      if((*it)->size() > bigger->size()) {
        bigger = (*it);
      }
      if((*it)->size() < smaller->size()) {
        smaller = (*it);
      }
    }
    std::cout << "Biggest: " << bigger->size() << std::endl;
    std::cout << "Smallest: " << smaller->size() << std::endl;
    return OK;
  }
};

int main(int argc, char ** argv) {
  GraphStats prog;
  return prog.exec(argc, argv);
}
