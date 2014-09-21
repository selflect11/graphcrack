#include "../src/matrix_graph.h"
#include "../src/list_graph.h"
#include <assert.h>
#include <iostream>

void test_graph(Graph * g){
	g->addEdge(0,1);
	g->addEdge(0,2);
	g->addEdge(0,2);
	g->addEdge(2,3);
	g->addEdge(2,4);
	g->addEdge(3,4);

	assert(g->getDegree(2) == 3 && "Graph#getDegree()");
	assert(g->getNodeCount() == 5 && "Graph#getNodeCount()");
	assert(g->isNeighbor(0,1) && "Graph#isNeighbor() true");
	assert(!g->isNeighbor(0,3) && "Graph#isNeighbor() false");
}

void test_matrix_graph(){
	std::cout << "Test MatrixGraph" << std::endl;
	test_graph(new MatrixGraph(5));
}

void test_list_graph(){
	std::cout << "Test ListGraph" << std::endl;
	test_graph(new ListGraph(5));
}

int main(){
	test_matrix_graph();
	test_list_graph();
}
