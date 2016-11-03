#ifndef GRAPH
#define GRAPH

#include <vector>
#include <vector>
#include "NodeGraph.h"

template <typename R>
class Graph
{
private:
  std::vector< NodeGraph<R>* > vectorN;
public:
  Graph():vectorN(std::vector< NodeGraph<R>* >()){};
  ~Graph();
  std::vector< NodeGraph<R>* > getList();
  bool addNode( R date );
  bool addArist( R dateOrigin, R dateToGo, int weight );

  NodeGraph< R >* findNode( R date );
  bool delNode( R date );
  bool delNode( NodeGraph<R>* n );
  bool delArist( R dateOrigin, R dateToGo );
  void BFS( NodeGraph<R>* n , std::vector< R >& v);
  void DFS( NodeGraph<R>* n, std::vector< R >& dfs);
  void DFS_C( NodeGraph<R>* n, std::vector< R >& dfs);
  void plane(  std::vector< R >& vplane);
  void allNode( bool s );
};

#include "Graph.hxx"

#endif
