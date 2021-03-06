

#ifndef LUGAR
#define LUGAR
#include <iostream>

//#define RADIOTIERRA 6378;

class lugar {
private:
  std::string nombre;
  int tipo;
  double lat;
  double lon;
  double latrad;
  double lonrad;

public:
    lugar();
  lugar(std::string nombre, int tipo, double lat, double lon);
  lugar( double lat ,double lon ): nombre("") , lat(lat) , lon(lon) {};
  ~lugar();
  std::string getNombre();
  int getTipo();
  double toRadian(double grados);
  double calcularDistanciaM(double latm,double lonm);

  void setNombre(std::string const aux);
  void setTipo(int const aux);
  void setLat(double const aux);
  void setLon(double const aux);


  double getLat();
  double getLon();

  bool operator<( const lugar &o )const;
};

#endif
#include "lugar.hxx"
