#include "lugar.h"
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <cstdlib>
#include <vector>
#include <sstream>
#include "Graph.h"

using namespace std;

string cargarArchivo(Graph<lugar *> &graphLugares,list<lugar *> &lugars,string nombrearch);
void imprimirLista(list<lugar *> lugars);
void imprimirGraph(Graph<lugar *>& lugars);
string imprimirlinea(int numchar, int longitud);
string imprimirMenu();
string imprimirGracias();
void cantidadSitios(Graph<lugar *> lugars,string tipo);
int cantidadTotal(Graph<lugar *> lugars);
void menuAyuda(string com);
void obtenerSitio(Graph<lugar *> lugars,double x,double y);
void crearSitio(Graph<lugar *> &graphLugares,list<lugar *> &lugars,string nombretemp,int tipotemp,double lattemp,double lontemp);
// void modificarSitio(Graph<lugar *> &graphLugares,list<lugar *> &lugars,string newname,int newtipo,double lat,double lon,double newlat,double newlon);
list<lugar *>::iterator obtenerSitio2(list<lugar *> &lugars,double x,double y);
// void eliminarSitio(Graph<lugar *> &graphLugares,list<lugar *> &lugars,double lat,double lon);

int main()
{

    list< lugar* > lugares;
    Graph<lugar*> graphlugares;
    string opcion,comando;
    getline( cin, opcion );
    while( opcion != "exit" || opcion != "fin" )
    {
        stringstream ss( opcion );

        ss >> comando;
        if( comando == "cargar" )
        {
            string file;
            ss >> file;
            cout << cargarArchivo(graphlugares, lugares, file );
        }
        else if( comando == "cantSitios" )
        {
            string tipo;
            ss >> tipo;
            if( tipo == "" )
                cout << "Cantidad Sitios: " << cantidadTotal(graphlugares) << endl;
            else
                cantidadSitios( graphlugares, tipo );
        }
        else if( comando == "obtenerSitio" )
        {
            double x,y;
            ss >> x >> y;
            obtenerSitio( graphlugares, x, y );
        }

        else if( comando == "crearSitio" )
        {
            string nombre;
            int tipo;
            double lat,lon;
            ss >> nombre >> tipo >> lat >> lon;
            crearSitio(graphlugares ,lugares, nombre, tipo, lat, lon );
        }
        else if( comando == "modificarSitio" )
        {
            double lon,lat,newlon,newlat;
            string nombre;
            int tipo;
            ss >> lon >> lat >> nombre >> tipo >> newlat >> newlon;
            // modificarSitio( lugares, nombre,  tipo, lat, lon, newlat, newlon );
        }
        else if( comando == "eliminarSitio" )
        {
            int lat, lon ;
            ss >> lat >> lon ;
            // eliminarSitio( lugares, lat, lon );
        }
        else if( comando == "ayuda" )
        {
            string com;
            ss >> com;
            menuAyuda( com );
        }
        else if( comando == "mostrarlista" )
        {
            imprimirLista(lugares);
        }
        else if(comando=="mostrargraph")
        {
            imprimirGraph( graphlugares);
        }
        else if( comando == "crearPuntoInfo" )
        {
          int n;
          ss >> n;
          vector< pair< double , double > > v;
          graphlugares.crearPuntoInfo( n , v );
          for( int i = 0 ; i < v.size() ; ++i )
          {
            printf("-\tPunto [%d] ubicado en (%lf, %lf).\n", i , v[i].first, v[i].second );
            // printf("%lf %lf\n", v[i].first, v[i].second );
          }
        }
        else if( comando == "buscarXUbicacion" )
        {
          double xMax,xMin,yMax,yMin;
          ss >> xMax >> yMax >> xMin >> yMin;
          vector< lugar* > v;
          graphlugares.buscarXUbicacion( xMax , yMax , xMin , yMin , v );
          for( int i = 0 ; i < (int)v.size() ; ++i )
          {
            printf("\t- %s de tipo %d, ubicado en (%lf,%lf).\n", v[i]->getNombre().c_str() , v[i]->getTipo() , v[i]->getLat() , v[i]->getLon() );
          }
          // cout << "sali" << endl;
        }
        else
        {
            cout << "Comando erroneo \n";
        }
        getline( cin, opcion );
    }
    cout<<imprimirGracias();


    return (0);
}


void menuAyuda( string com )
{
    int c=0;
    if(com == "cargar" )
        c=1;
    else if(com == "cantSitios" )
        c=2;
    else if(com == "obtenerSitioxy" )
        c=3;
    else if(com == "crearStitio" )
        c=4;
    else if(com == "modificarSitioxy" )
        c=5;
    else if(com == "eliminarSitioxy" )
        c=6;
    else if(com == "fin" )
        c=7;

    switch(c)
    {
    case 1:
    {
        cout<<"para cargar archivo use el siguiente formato: cargar <nombre del archivo>"<<endl;
        break;
    }
    case 2:
    {
        cout<<"para saber la cantidad de sitios ingrese el siguiente formato:"<<endl;
        cout<<"cantSitios <el tipo de sitios de que se quieren contar>"<<endl;
        cout<<"o"<<endl;
        cout<<"canSitios T (para saber la cantidad total de sitios)"<<endl;
        break;
    }
    case 3:
    {
        cout<<"para saber que sitio esta ubicado en unas coordenadas especificas se sigue el siguiente formato:"<<endl;
        cout<<" obtenerSitioxy <insertar coordenada x> <insertar coordenada y> "<<endl;
        break;
    }
    case 4:
    {
        cout<<"para crear un nuevo sitio se utiliza el siguiente formato:"<<endl;
        cout<<"crearStitio <nombre> <tipo> <latitud> <longitud>"<<endl;
        break;
    }
    case 5:
    {
        cout<<"para modificar un sitioespecifico se debe utilizar el sigiente formato: "<<endl;
        cout<<"modificarSitioxy <latitud actual> <longitud acutal> <nuevo nombre> <nuevo tipo> <nueva latitud> <nueva longitud>"<<endl;
        break;
    }
    case 6:
    {
        cout<<"para eliminar un lugar especifico se utiliza el siguiente formato: "<<endl;
        cout<<"eliminarSitioxy <insetar coordenada x> <insertar coordenada y> "<<endl;
        break;
    }
    case 7:
    {
        cout<<"para salir del programa se utiliza el siguiente comando: "<<endl;
        cout<<"fin"<<endl;
        break;
    }
    default:
    {
        cout<<"el comando escrito no existe"<<endl;
        break;
    }

    }
}

void eliminarSitio(Graph<lugar *> &graphLugares,list<lugar *> &lugars,double lat,double lon)
{
    if(!lugars.empty())
    {
        list<lugar *>::iterator eliminado=obtenerSitio2(lugars,lat,lon);
        cout<<"El sitio "<<(*eliminado)->getNombre()<<" en las coordenadas ("<<(*eliminado)->getLat()<<","<<(*eliminado)->getLon()<<") ha sido eliminado."<<endl;
        lugars.erase(eliminado);
        // graphLugares.delNode(eliminado);
    }
    else
    {
        cout<<"No se han ingresado lugares."<<endl;
    }
}



string imprimirGracias()
{
    string gracias="";
    char esi = 201, esd = 187, eii = 200, eid = 188, lv = 186, lh = 205, id = 185,ii = 204;
    gracias=gracias
            +"\n "+ esi + imprimirlinea(205, 38) + esd + "\n"
            +" "+ lv + "\t\t\t\t\t" + lv + "\n"
            +" "+ lv + "      GRACIAS POR PREFERIRNOS.       \t" + lv + "\n"
            +" "+ lv + "\t\t\t\t\t" + lv + "\n"
            +" "+ eii + imprimirlinea(205, 38) + eid + "\n";
    return gracias;
}

void crearSitio(Graph<lugar *> &graphLugares,list<lugar *> &lugars,string nombretemp,int tipotemp,double lattemp,double lontemp)
{

    lugar *temp=new lugar(nombretemp, tipotemp, lattemp, lontemp);


    graphLugares.addNode(temp);
        lugars.push_back(temp);
    cout<<"El sitio de tipo "<<tipotemp<<" en ("<<lattemp<<","<<lontemp<<") ha sido creado."<<endl;

}

void obtenerSitio(Graph<lugar *> lugars,double x,double y)
{
    if(lugars.cantNodes()!=0)
    {
        double distancia;
        string nombre;
        int tipo;
        double lat;
        double lon;

            vector<lugar*> v;
         lugars.plane(v);

        for (vector<lugar*>::iterator it=v.begin();it!=v.end();it++)
        {
            if(it==v.begin())
            {
                distancia=(*it)->calcularDistanciaM(x,y);
                nombre=(*it)->getNombre();
                tipo=(*it)->getTipo();
                lat=(*it)->getLat();
                lon=(*it)->getLon();
            }
            else
            {
                if((*it)->calcularDistanciaM(x,y)<distancia)
                {
                    distancia=(*it)->calcularDistanciaM(x,y);
                    nombre=(*it)->getNombre();
                    tipo=(*it)->getTipo();
                    lat=(*it)->getLat();
                    lon=(*it)->getLon();
                }
            }
        }
        cout<<"El sitio turistico mas cercano se encuentra a "<<distancia<<" metros. Su nombre es "<<nombre<<", es de tipo "<<tipo<<" y se ubica en ("<<lat<<","<<lon<<").\n";

    }
    else
    {
        cout<<"No se han ingresado lugares."<<endl;
    }
}

list<lugar *>::iterator obtenerSitio2(list<lugar *> &lugars,double x,double y)
{
    double distancia;
    string nombre;
    int tipo;
    double lat;
    double lon;
    list<lugar *>::iterator aux;
    for (list<lugar *>::iterator it = lugars.begin(); it != lugars.end(); it++)
    {
        if(it==lugars.begin())
        {
            distancia=(*it)->calcularDistanciaM(x,y);
            aux=it;
        }
        else
        {
            if((*it)->calcularDistanciaM(x,y)<distancia)
            {
                aux=it;
            }
        }
    }
    return aux;
}

void cantidadSitios(Graph<lugar *> lugars,string tipo)
{
    int cont=0;
    int tipoint=atoi(tipo.c_str());


    for (int a=0;a<lugars.getList().size();a++)
    {
        if(lugars.getList()[a]->getDate()->getTipo()==tipoint)
        {
            cont++;
        }
    }
    if(cont==0)
    {
        cout <<"No hay sitios de tipo: "<<tipo<<"\n";
    }
    else
    {
        cout<<"Hay "<<cont<<" sitios de tipo "<<tipo<<"\n";
    }
}



int cantidadTotal(Graph<lugar *> lugars)
{
    return lugars.cantNodes();
}


string imprimirlinea(int numchar, int longitud)
{
    char m = numchar;
    string linea = "";
    for (int w = 0; w < longitud; w++)
    {
        linea += m;
    }
    return linea;
}
string cargarArchivo(Graph<lugar *> &graphLugares,list<lugar *> &lugars,string nombrearch)
{
    //http://www.cplusplus.com/forum/general/100714/
    ////////////////////////////////////////////////
    char *y = new char[nombrearch.length() /*+ 1*/];
    strcpy(y, nombrearch.c_str());
    ///////////////////////////////////////////////////
    ifstream archivo(y);
    char linea[100];
    if (archivo)
    {
        char *token;
        int cant, numtipos;

        archivo.getline(linea, sizeof(linea));

        //cout << linea << endl;
        token = strtok(linea, "\t");
        cant = atoi(token);
        token = strtok(NULL, "\t");
        numtipos = atoi(token);
        //cout<<numtipos<<"---"<<cant<<endl;
        // while (!archivo.eof())                        // WHILE O FOR CUALQUIERA

        for (int w = 0; w < cant; w++)
        {

            archivo.getline(linea, sizeof(linea));
            //cout << linea << endl;

            // NOMBRE
            token = strtok(linea, "\t");
            char nombre[10], tipo[10], lat[10], lon[10];
            int tipol;
            double latl, lonl;

            //  cout << "token: " << token << endl;
            strcpy(nombre, token);
            string nombrel(nombre);
            // cout << "cadena aux: " << nombrel << endl;
            // TIPO
            token = strtok(NULL, "\t");
            //  cout << "token: " << token << endl;
            strcpy(tipo, token);
            tipol = atoi(tipo);
            if (tipol < 0 && tipol > numtipos)
            {
                archivo.close();
                return "FALLO!\n";
            }
            // cout << "cadena aux: " << tipol << endl;
            // LAT
            token = strtok(NULL, "\t");
            //  cout << "token: " << token << endl;
            strcpy(lat, token);
            // IPORTANTE: double atof (const char* str);
            latl = atof(lat);
            // cout << "cadena aux: " << latl << endl;
            // lON
            token = strtok(NULL, "\t");
            // cout << "token: " << token << endl;
            strcpy(lon, token);
            lonl = atof(lon);
            // lonl=3.0035847;
            // cout<<endl;
            /* printf("%.7lf",lonl);
             cout<<endl;
             cout << "cadena aux: " << lonl << endl;*/

            lugar *temp=new lugar(nombrel, tipol, latl, lonl);
            graphLugares.addNode(temp);
            lugars.push_back(temp);
        }
    }
    else
    {
        archivo.close();
        return "FALLO. El archivo no existe.\n";
    }
    archivo.close();
    delete[] y;
    return "EXITO!\n";
}

void imprimirLista(list<lugar *> lugars)
{
    for (list<lugar *>::iterator it = lugars.begin(); it != lugars.end(); it++)
    {
        cout << "-->" << (*it)->getNombre() << "tipo" << (*it)->getTipo()<<endl;

    }
}
void imprimirGraph(Graph<lugar *>& lugars)
{
    vector<lugar*> v;
    lugars.plane(v);

    for(int a=0; a<v.size(); a++)
    {
        cout<<v[a]->getNombre()<<endl;
    }

}

void puntosNONESESO(Graph<lugar *>& lugars, int x, int y)
{
    vector<lugar*> lugaresNO;
    vector<lugar*> lugaresNE;
    vector<lugar*> lugaresSO;
    vector<lugar*> lugaresSE;

    vector<lugar*> v;
    lugars.plane(v);

    for(int w=0; w<v.size(); w++)
    {
      lugaresNO.clear();
       lugaresNE.clear();
       lugaresSO.clear();
       lugaresSE.clear();
      for(int a=0; a<v.size(); a++)
        {

            if(v[a]->getLat() < v[w]->getLat() && v[a]->getLon() < v[w]->getLon())
            {
                lugaresNO.push_back(v[a]);
            }
            else if(v[a]->getLat() > v[w]->getLat() && v[a]->getLon() < v[w]->getLon())
            {
                lugaresNE.push_back(v[a]);
            }
            else if(v[a]->getLat() <v[w]->getLat() && v[a]->getLon() > v[w]->getLon())
            {
                lugaresSO.push_back(v[a]);
            }
            else if(v[a]->getLat() > v[w]->getLat() && v[a]->getLon() > v[w]->getLon())
            {
                lugaresSE.push_back(v[a]);
            }
        }
        lugar* menor=new lugar();
        menor->setNombre("NO HAY");
        double distanciamenor=-1;
        for(int b=0;b<lugaresNO.size();b++)
        {
            if(b==0)
            {
                menor=lugaresNO[b];
                distanciamenor=v[w]->calcularDistanciaM(lugaresNO[b]->getLat(),lugaresNO[b]->getLon());
            }
            else if((v[w]->calcularDistanciaM(lugaresNO[b]->getLat(),lugaresNO[b]->getLon()))<distanciamenor)
            {
                menor=lugaresNO[b];
                distanciamenor=(v[w]->calcularDistanciaM(lugaresNO[b]->getLat(),lugaresNO[b]->getLon()));
            }
        }
        lugars.addArist(v[w],menor,distanciamenor);
        menor->setNombre("NO HAY");
        distanciamenor=-1;
      for(int b=0;b<lugaresNE.size();b++)
        {
            if(b==0)
            {
                menor=lugaresNE[b];
                distanciamenor=v[w]->calcularDistanciaM(lugaresNE[b]->getLat(),lugaresNE[b]->getLon());
            }
            else if((v[w]->calcularDistanciaM(lugaresNE[b]->getLat(),lugaresNE[b]->getLon()))<distanciamenor)
            {
                menor=lugaresNE[b];
                distanciamenor=(v[w]->calcularDistanciaM(lugaresNE[b]->getLat(),lugaresNE[b]->getLon()));
            }
        }
        lugars.addArist(v[w],menor,distanciamenor);
        menor->setNombre("NO HAY");
        distanciamenor=-1;
         for(int b=0;b<lugaresSO.size();b++)
        {
            if(b==0)
            {
                menor=lugaresSO[b];
                distanciamenor=v[w]->calcularDistanciaM(lugaresSO[b]->getLat(),lugaresSO[b]->getLon());
            }
            else if((v[w]->calcularDistanciaM(lugaresSO[b]->getLat(),lugaresSO[b]->getLon()))<distanciamenor)
            {
                menor=lugaresSO[b];
                distanciamenor=(v[w]->calcularDistanciaM(lugaresSO[b]->getLat(),lugaresSO[b]->getLon()));
            }
        }
        lugars.addArist(v[w],menor,distanciamenor);
        menor->setNombre("NO HAY");
        distanciamenor=-1;
         for(int b=0;b<lugaresSE.size();b++)
        {
            if(b==0)
            {
                menor=lugaresSE[b];
                distanciamenor=v[w]->calcularDistanciaM(lugaresSE[b]->getLat(),lugaresSE[b]->getLon());
            }
            else if((v[w]->calcularDistanciaM(lugaresSE[b]->getLat(),lugaresSE[b]->getLon()))<distanciamenor)
            {
                menor=lugaresSE[b];
                distanciamenor=(v[w]->calcularDistanciaM(lugaresSE[b]->getLat(),lugaresSE[b]->getLon()));
            }
        }




    }


}
