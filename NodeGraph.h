#ifndef NODEGRAPH
#define NODEGRAPH


#include <vector>


template <typename R>
class NodeGraph
{
private:
  R date;
  bool visited;
  std::vector< std::pair< NodeGraph< R >* , int > > vectorN;
public:
  NodeGraph ():  vectorN ( std::vector< std::pair< NodeGraph<R>* , int > >() ){};
  NodeGraph (const R dateL ): date(dateL) , vectorN ( std::vector< std::pair< NodeGraph<R>* , int > >() ){};
  ~NodeGraph();
  std::vector< std::pair< NodeGraph< R >* , int > > getVector();
  bool delArist(NodeGraph<R>* n);
  bool addNode( NodeGraph<R>* n , int weight );
  
  void setVisited( bool s );
  bool getVisited( );
  R getDate();

};
#include "NodeGraph.hxx"

#endif
