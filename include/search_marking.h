#pragma once

#include <graph.h>

enum mark_t { undiscovered, discovered, explored };
class SearchMarking {
public:
  void set(node_t,mark_t);
  void setAll(mark_t);
  bool is(node_t,mark_t);
  SearchMarking(node_count_t);
  ~SearchMarking();
private:
  mark_t * marks;
  node_count_t count;
};
