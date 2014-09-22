#include <program.h>

class GraphStats : public Program {
public:
  virtual int run(Graph * graph){
    std::vector<float>::iterator it;
    GraphStatistics stats(graph);
    std::cout << "# n = " << stats.nodeCount << std::endl;
    std::cout << "# m = " << stats.edgeCount << std::endl;
    std::cout << "# d_medio = " << stats.averageDegree << std::endl;
    std::cout << "# d_max = " << stats.maxDegree << std::endl;
    for(it = stats.degreeDistribution.begin(); it != stats.degreeDistribution.end(); it++){
      std::cout << it - stats.degreeDistribution.begin() + 1 << " " << *it << std::endl;
    }
    return OK;
  }
};

int main(int argc, char ** argv) {
  GraphStats prog;
  return prog.exec(argc, argv);
}
