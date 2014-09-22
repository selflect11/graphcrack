#pragma once
#include <iostream>
#include <list_graph.h>
#include <matrix_graph.h>
#include <graph_text_factory.h>
#include <graph_statistics.h>

#define OK 0
#define ERR_WRONG_PARAMETERS 1
#define ERR_WRONG_FILE_FORMAT 2

class Program {
public:
  virtual int run(Graph *)=0;
  int exec(int, char**);

  template <typename G>
  Graph * loadGraph(char*);
};
