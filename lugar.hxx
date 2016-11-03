#ifndef LUGARHXX
#define LUGARHXX
#include "lugar.h"
#include <cmath>
#include <cstdio>
#define PI 3.1416




lugar::lugar(std::string nombre, int tipo, double lat, double lon) {
  this->nombre = nombre;
  this->tipo = tipo;
  this->lat = lat;
  this->lon = lon;
  this->latrad=toRadian(lat);
  this->lonrad=toRadian(lon);
}
lugar::~lugar(){};
std::string lugar::getNombre(){
return this->nombre;
}

int lugar::getTipo()
{
    return this->tipo;
}

double lugar::toRadian(double grados)
{
    return (((2)*PI)*grados)/360;
}

double lugar::getLat()
{

    return this->lat;
}

double lugar::getLon()
{

    return this->lon;
}

double lugar::calcularDistanciaM(double latm,double lonm)
{
    double diflat=toRadian(this->lat - latm);
    double diflon=toRadian(this->lon - lonm);
    double a=( sin(diflat/2)*sin(diflat/2) )+cos(toRadian(latm))*cos(latrad)
            *( sin(diflon/2)*sin(diflon/2) );
    double c = 2 * atan2( sqrt( a ) , sqrt( 1-a ) );
    double distanciaM=6371e3*c;
    // std::cout << "hola" << std::endl;
    // printf("diflat %lf diflon %lf a %lf c %lf\n",diflat , diflon , a , c );
    // double distanciaM=distanciaKm*1000;
    return distanciaM;
}

void lugar::setNombre(std::string const aux)
{
    this->nombre=aux;
}
void lugar::setTipo(int const aux)
{
    this->tipo=aux;
}
void lugar::setLat(double const aux)
{
    this->lat=aux;
}
void lugar::setLon(double const aux)
{
    this->lon=aux;
}
#endif
