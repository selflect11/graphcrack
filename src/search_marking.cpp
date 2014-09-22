#include <search_marking.h>

SearchMarking::SearchMarking(node_count_t count){
  this->marks = new mark_t[count];
  this->count = count;
};

SearchMarking::~SearchMarking(){
  delete this->marks;
};

void SearchMarking::set(node_t node, mark_t mark){
  this->marks[node] = mark;
};

void SearchMarking::setAll(mark_t mark){
  for(node_count_t i = 0; i < this->count; i++){
    this->set(i, mark);
  }
}

bool SearchMarking::is(node_t node, mark_t mark){
  return this->marks[node] == mark;
};
