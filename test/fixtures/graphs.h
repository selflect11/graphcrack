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

template<typename G>
G test_graph_not_connected(){
  G g(6);
  g.addEdge(0,1);
  g.addEdge(1,2);
  g.addEdge(3,4);
  return g;
}

template<typename G>
G test_graph_dfs(){
  G g(8);
  g.addEdge(0,1);
  g.addEdge(1,2);
  g.addEdge(2,3);
  g.addEdge(0,4);
  g.addEdge(4,5);
  g.addEdge(5,6);
  g.addEdge(3,7);
  return g;
}
