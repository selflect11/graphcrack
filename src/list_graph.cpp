#include "list_graph.h"

ListGraph::ListGraph(int n){
	this->adjacencyList = new std::list<int>[n];
	this->nodeCount = n;
};
void ListGraph::addEdge(int i, int j){
	if(this->isNeighbor(i,j)) return;
	this->adjacencyList[i].push_back(j);
	this->adjacencyList[j].push_back(i);
};
int ListGraph::getNodeCount(){
	return this->nodeCount;
};
const std::list<int> ListGraph::getNeighbors(int){
	std::list<int> list;
	return list;
};
bool ListGraph::isNeighbor(int i, int j){
	std::list<int>::iterator it;
	for(it = this->adjacencyList[i].begin(); it != this->adjacencyList[i].end(); it++) {
		if((*it) == j) return true;
	}
	return false;
};
int ListGraph::getDegree(int i){
	return this->adjacencyList[i].size();
};