#pragma once

#include <bfs.h>
#include <list>
#include <unordered_set>

typedef std::vector<node_t> ConnectedComponent;

class ConnectedComponentsFinder : protected BFS {
private:
  // unordered_set is generally O(1) for insertion, verification and erasing
  // However, it can be O(n) in the worst case. But as we are using integer keys,
  // it should be O(1) as long as the size of the intege  is less than the size of the hash.
  // For now i think it's a good approach but we may replace it with our own optimized set.
  std::unordered_set<node_t> remaining;
  virtual void discover(node_t);
  virtual void initialize();
  void makeComponent();
public:
  std::vector<ConnectedComponent*> connectedComponents;
  ConnectedComponentsFinder(Graph*);
};
