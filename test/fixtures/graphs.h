template<typename G> 
G test_graph_5(){
  G g(5);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(0,2);
	g.addEdge(2,3);
	g.addEdge(2,4);
	g.addEdge(3,4);
  return g;
}