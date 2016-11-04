
#include <vector>

#include <queue>
#include <iostream>
#include <algorithm>

template <typename R>
bool  Graph< R >::delNode( NodeGraph<R>* n )
{
  typename std::vector< NodeGraph< R > * >::iterator it;
  for( it  = this->vectorN.begin() ; it != this->vectorN.end() ; ++it )
  {
    (*it)->delArist(n);
  }
  return 1;
}

template <typename R>
Graph< R >::~Graph()
{
  typename std::vector< NodeGraph< R > * >::iterator it;
  for( it = this->vectorN.begin() ; it != this->vectorN.end() ; ++it )
    delNode( *it );
}

template <typename R>
std::vector< NodeGraph<R>*> Graph< R >:: getList()
{
  return this->vectorN;
}

template <typename R>
bool  Graph< R >::addNode( R date )
{
  if( findNode( date )  != NULL )
    return false;
  this->vectorN.push_back( new NodeGraph<R>(date) );
  return true;
}

template <typename R>
bool  Graph< R >::addArist( R dateOrigin, R dateToGo, int weight ){
    NodeGraph< R > *aux,*aux2;
    aux = aux2 = NULL;
    aux=findNode(dateOrigin);
    aux2=findNode(dateToGo);
    if( aux == NULL || aux2 == NULL )
      return 0;
    aux->addNode(aux2,weight);
    return 1;
}



template <typename R>
NodeGraph < R >* Graph< R >::findNode( R date )
{
  typename std::vector< NodeGraph< R > * >::iterator it;
  for( it = this->vectorN.begin() ; it != this->vectorN.end() ; ++it )
      if( (*it)->getDate() == date )
        return *it;
  return NULL;
}


template <typename R>
bool  Graph< R >::delNode( R date )
{
  NodeGraph<R> * aux = findNode( date );
  if( aux == NULL )
    return false;
  return delNode( aux );
}

template <typename R>
void Graph< R >::allNode( bool  s )
{
  typename std::vector< NodeGraph< R > * >::iterator it;
  for( it = this->vectorN.begin() ; it != this->vectorN.end() ; ++it )
      (*it)->setVisited( s );
}

template <typename R>
void  Graph< R >::BFS( NodeGraph<R>* n , std::vector< R >& v)
{
  if( n == NULL )
  {

    return ;
  }

  this->allNode( false );
  std::queue< NodeGraph<R>* > q;
  n->setVisited( true );
  q.push( n );
  while( !q.empty() )
  {

      NodeGraph<R>* now = q.front();

      q.pop();

      v.push_back( now->getDate() );


      for(int i=0;i<now->getVector().size();i++)
   {

        if(!(now->getVector()[i].first->getVisited()))
        {
          now->getVector()[i].first->setVisited( true );
          q.push( now->getVector()[i].first );
        }
      }
  }
}

template <typename R>
bool  Graph< R >::delArist( R dateOrigin, R dateToGo )
{
  NodeGraph< R > *aux,*aux2;
  aux = aux2 = NULL;
  aux=findNode(dateOrigin);
  aux2=findNode(dateToGo);
  if( aux == NULL || aux2 == NULL )
    return 0;
  return aux->delArist( aux2 );
}
template <typename R>
void  Graph< R >::DFS( NodeGraph<R>* n, std::vector< R >& dfs)
{
  this->allNode( false );
  n->setVisited(true);
  DFS_C( n, dfs);
}

template <typename R>
void  Graph< R >::DFS_C( NodeGraph<R>* n, std::vector< R >& dfs)
{
   dfs.push_back(n->getDate());
  //  std::cout << "pase por " << n->getDate() << std::endl;
  //  typename std::vector< std::pair< NodeGraph< R >* , int > > :: iterator it;
  //  std::cout << "el tamano  es " << n->getList().size() << std::endl;
   int cont = 0 ;
   for(int i=0;i<n->getVector().size();i++)
   {

     if(!(n->getVector()[i].first->getVisited()))
     {
      //  std::cout << "pase" << std::endl;
       n->getVector()[i].first->setVisited(true);
       DFS_C(n->getVector()[i].first,dfs);
     }


   }


  /* for(  it = n->getList().begin() ; it != n->getList().end() ; ++it )
   {
     std::cout << "entre " << n->getList().size() << " and " << ++cont << std::endl;
    //  std::cout << (it!=n->getList().end()) << " " << std::endl;
    //  std::cout << "llegue aca con " << (*it).first->getDate() << " en " << n->getDate() << std::endl;
    //  std::cout << " y " << (it!=n->getList().end()) << " and " << (!(*it).first->getVisited()) << std::endl;
     if(!((*it).first->getVisited()))
     {
      //  std::cout << "pase" << std::endl;
       (*it).first->setVisited(true);
       DFS_C((*it).first,dfs);
     }
    //  std::cout << "llegue al final del for " << std::endl;
   }
  //  std::cout << "sali "<< std::endl;*/
}

template <typename R>
void  Graph< R >::plane(  std::vector< R >& vplane)
{

  for( int a=0;a<this->vectorN.size();a++)
  {
     vplane.push_back((this->vectorN[a])->getDate()  );
      }
}


template <typename R>
int  Graph< R >::cantNodes()
{
    return this->vectorN.size();
}

template <typename R>
void  Graph< R >::crearPuntoInfo( int n , std::vector< std::pair< double , double > > &v )
{
  v.clear();
  std::vector< std::pair< double , double > > ord( this->vectorN.size() );
  for( int i = 0 ; i < (int) this->vectorN.size() ; ++i )
  {
    ord[ i ].first = this->vectorN[i]->getDate()->getLat() ;
    ord[ i ].second = this->vectorN[i]->getDate()->getLon() ;
  }
  sort( ord.begin() , ord.end() );
  // for( int i = 0 ; i <  ord.size() ; ++i )
    // std::cout << ord[i].first << " " << ord[i].second << std::endl;
  int pos = 0;
  int cont = 0;
  int tam = ord.size();
  if( n > tam )
    n=tam;
  while( n && tam > 0 )
  {
    int lim = (( tam  )/n) ;
    if( lim == 1 )
      v.push_back( std::make_pair( ord[cont].first , ord[ cont ].second ) );
    else if ( lim != 0 )
    {
      double A=0;
      double x,y;
      x = y = 0;
      for( int i = 0 ; i  < lim-1 ; ++i)
      {
          double temp =( (ord[ cont + i ].second*ord[ cont + i +1 ].first) - (ord[ cont +i + 1 ].second * ord[ cont + i ].first ));
          // std::cout << "in "<< i << " = " << temp << std::endl;
          A += temp;
          x += (ord[ cont + i ].second + ord[ cont + i + 1].second)*temp;
          y += (ord[ cont + i ].first + ord[ cont + i + 1].first)*temp;
      }
      double temp =( (ord[ cont + lim -1  ].second*ord[ cont  ].first) - (ord[ cont ].second * ord[ cont +lim-1   ].first) );
      A += temp;
      x += (ord[ cont + lim -1 ].second + ord[ cont ].second)*temp;
      y += (ord[ cont + lim -1  ].first + ord[ cont ].first)*temp;
      // std::cout << "inul " << " = " << temp << std::endl;

      A /= 2;
      A = fabs(A);
      x /= 6*A;
      y /= 6*A;
      if( (ord[ cont ].second < 0 && x > 0 )|| (ord[ cont ].second > 0 && x < 0 ))
        x*=-1;
      if( (ord[ cont ].first < 0 && y > 0 )|| (ord[ cont ].first > 0 && y < 0 ))
        y*=-1;

      v.push_back( std::make_pair(y,x) );
      // std::cout <<" se metio " << A << " " << x << " "  << y << std::endl;
    }
    // std::cout << "estoy en " << cont << " faltan "<<  n  << " lim " << lim << " tam " << tam << std::endl;
    --n;
    tam -= lim;
    cont += lim;
    // std::cout << "salgo con "<< cont << " n " << n << " tam " << tam << std::endl;
  }

}
