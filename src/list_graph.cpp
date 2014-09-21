#include <list_graph.h>

ListGraph::ListGraph(node_count_t n){
	this->adjacencyList = new std::list<node_t>[n];
	this->nodeCount = n;
};
void ListGraph::addEdge(node_t i, node_t j){
	if(this->isNeighbor(i,j)) return;
	this->adjacencyList[i].push_back(j);
	this->adjacencyList[j].push_back(i);
};
node_count_t ListGraph::getNodeCount(){
	return this->nodeCount;
};
const std::list<node_t> ListGraph::getNeighbors(node_t){
	std::list<node_t> list;
	return list;
};
bool ListGraph::isNeighbor(node_t i, node_t j){
	std::list<node_t>::iterator it;
	for(it = this->adjacencyList[i].begin(); it != this->adjacencyList[i].end(); it++) {
		if((*it) == j) return true;
	}
	return false;
};
int ListGraph::getDegree(node_t i){
	return this->adjacencyList[i].size();
};
