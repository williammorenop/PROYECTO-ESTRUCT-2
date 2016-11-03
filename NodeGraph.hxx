#include "NodeGraph.h"

#include <vector>

template <typename R>
NodeGraph< R >::~NodeGraph(){};


template <typename R>
bool  NodeGraph< R >::delArist(NodeGraph< R >* n)
{
  typename std::vector< std::pair< NodeGraph< R >* , int > >::iterator it;
  for( it = this->vectorN.begin() ; it != this->vectorN.end() ; ++it )
    if( (*it).first == n )
    {
      this->vectorN.erase(it);
      return true;
    }
  return false;
}
template <typename R>
std::vector< std::pair< NodeGraph< R >* , int > > NodeGraph< R >::getVector()
{
  return this->vectorN;
}

template <typename R>
bool  NodeGraph< R >::addNode( NodeGraph<R>* n , int weight )
{
  typename std::vector< std::pair< NodeGraph< R >* , int > >::iterator it;
  for( it = this->vectorN.begin() ; it != this->vectorN.end() ; ++it )
    if( n == (*it).first)
      return false;
  this->vectorN.push_back( std::pair< NodeGraph< R >* , int >(n,weight) );
  return true;
}

template <typename R>
void  NodeGraph< R >::setVisited( bool s )
{
    this->visited = s;
}

template <typename R>
bool  NodeGraph< R >::getVisited( )
{
  return this->visited;
}

template <typename R>
R NodeGraph< R >::getDate()
{
  return this->date;
}
