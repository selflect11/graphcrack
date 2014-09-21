#include <matrix_graph.h>

MatrixGraph::MatrixGraph(node_count_t n) {
		node_count_t i;
		this->adjacencyMatrix = new int[n*n];
		for(i = 0; i < n; i++){
			this->adjacencyMatrix[i] = 0;
		}
		this->nodeCount = n;
	};

void MatrixGraph::addEdge(node_t i, node_t j){
	this->adjacencyMatrix[i*this->getNodeCount()+j] = 1;
};

node_count_t MatrixGraph::getNodeCount() {
	return this->nodeCount;
};

const std::list<node_t> MatrixGraph::getNeighbors(node_t i){
	std::list<node_t> neighbors(this->getNodeCount());
	node_count_t j;
	for(j = 0; j < this->getNodeCount(); j++) {
		if(this->isNeighbor(i,j)) {
			neighbors.push_back(j);
		}
	}
	return neighbors;
};

bool MatrixGraph::isNeighbor(node_t i, node_t j) {
	return 
		this->adjacencyMatrix[i*this->getNodeCount() + j] > 0
		|| this->adjacencyMatrix[j*this->getNodeCount() + i] > 0;
};

int MatrixGraph::getDegree(node_t i){
	int degree = 0;
	node_count_t j;

	for(j = 0; j < this->getNodeCount(); j++){
		if(this->isNeighbor(i,j)) {
			degree++;
		}
	}

	return degree;
};
