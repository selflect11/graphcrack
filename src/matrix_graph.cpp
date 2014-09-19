#include "matrix_graph.h"

MatrixGraph::MatrixGraph(int n) {
		int i;
		this->adjacencyMatrix = new int[n*n];
		for(i = 0; i < n; i++){
			this->adjacencyMatrix[i] = 0;
		}
		this->nodeCount = n;
	};

void MatrixGraph::addEdge(int i, int j){
	this->adjacencyMatrix[i*this->getNodeCount()+j] = 1;
};

int MatrixGraph::getNodeCount() {
	return this->nodeCount;
};

const std::list<int> MatrixGraph::getNeighbors(int i){
	std::list<int> neighbors(this->getNodeCount());
	int j;
	for(j = 0; j < this->getNodeCount(); j++) {
		if(this->isNeighbor(i,j)) {
			neighbors.push_back(j);
		}
	}
	return neighbors;
};

bool MatrixGraph::isNeighbor(int i, int j) {
	return 
		this->adjacencyMatrix[i*this->getNodeCount() + j] > 0
		|| this->adjacencyMatrix[j*this->getNodeCount() + i] > 0;
};

int MatrixGraph::getDegree(int i){
	int degree = 0;
	int j;

	for(j = 0; j < this->getNodeCount(); j++){
		if(this->isNeighbor(i,j)) {
			degree++;
		}
	}

	return degree;
};