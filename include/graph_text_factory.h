#pragma once

#include <graph.h>
#include <string>

template <typename G>
class GraphTextFactory {
public:
  G * graphFromFile(std::string);
};
