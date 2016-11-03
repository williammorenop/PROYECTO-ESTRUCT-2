#include "lugar.h"
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <cstdlib>
#include <sstream>

using namespace std;

string cargarArchivo(list<lugar *> &lugars,string nombrearch);
void imprimirLista(list<lugar *> lugars);
string imprimirlinea(int numchar, int longitud);
string imprimirMenu();
string imprimirGracias();
void cantidadSitios(list<lugar *> lugars,string tipo);
int cantidadTotal(list<lugar *> lugars);

void obtenerSitio(list<lugar *> lugars,double x,double y);

void crearSitio(list<lugar *> &lugars,string nombretemp,int tipotemp,double lattemp,double lontemp);

void modificarSitio(list<lugar *> &lugars,string newname,int newtipo,double lat,double lon,double newlat,double newlon);
list<lugar *>::iterator obtenerSitio2(list<lugar *> &lugars,double x,double y);
void menuAyuda(string com);

void eliminarSitio(list<lugar *> &lugars,double lat,double lon);
int main()
{
  double x , y , xx , yy ;
  while( scanf("%lf %lf %lf %lf",&x,&y,&xx,&yy )!=EOF )
  {
    lugar *nn =new lugar ("n",1,xx,yy);

    printf("%lf \n", nn->calcularDistanciaM( x , y )  );
  }
    //
    // char* opcion= new char [100];
    // // lugar* a = new lugar("sda", 2, 2.2, 3.2);
    // //////////////////////////////////////////////
    // /*char u;
    // for (int a = 0; a < 300; a++) {
    //   u = a;
    //   cout << a << " -> " << u << endl;
    // }*/
    // /////////////////////////////////////////////
    // char* token;
    // //cout<<imprimirMenu()<<"\nComando:  ";
    //
    // cin.getline(opcion,100);
    //
    //
    // //cout<<opcion;
    //
    //
    // //system("PAUSE");
    // //imprimirLista(lugares);
    // while (strcmp(opcion,"fin")!=0)
    // {
    //     token= strtok(opcion," ");
    //     cout<<token;
    //     if(strcmp(token,"cargar")==0)
    //     {
    //         token=strtok(NULL," ");
    //
    //         cout<<cargarArchivo(lugares,token);
    //         //imprimirLista(lugares);
    //
    //     }
    //     if(strcmp(token,"cantSitios")==0)
    //     {
    //         token=strtok(NULL," ");
    //         if(strcmp(token,"T")==0||strcmp(token,"t")==0)
    //         {
    //             cout<<"Cantidad Sitios: "<<cantidadTotal(lugares)<<endl;
    //         }
    //         else
    //         {
    //             cantidadSitios(lugares,token);
    //         }
    //
    //
    //     }
    //     if(strcmp(token,"obtenerSitioxy")==0)
    //     {
    //         double x,y;
    //         token=strtok(NULL," ");
    //         x=atof(token);
    //         token=strtok(NULL," ");
    //         y=atof(token);
    //         //cout<<x<<" "<<y;
    //         obtenerSitio(lugares, x, y);
    //
    //     }
    //     if(strcmp(token,"crearStitio")==0)
    //     {
    //         string nombretemp (strtok(NULL, " "));
    //         int tipotemp= atoi(strtok(NULL," "));
    //         double lattemp = atof(strtok(NULL," ")) ;
    //         double lontemp= atof(strtok(NULL," ")) ;
    //         crearSitio(lugares,nombretemp,tipotemp,lattemp,lontemp);
    //
    //     }
    //     if(strcmp(token,"modificarSitioxy")==0)
    //     {
    //         double lon = atof(strtok(NULL," "));
    //         double lat = atof(strtok(NULL," "));
    //         string nuevonombre (strtok(NULL," "));
    //         int nuevotipo = atoi(strtok(NULL," "));
    //         double nuevalat = atof(strtok(NULL," "));
    //         double nuevalon = atof(strtok(NULL," "));
    //         modificarSitio(lugares,nuevonombre,nuevotipo,lat,lon,nuevalat,nuevalon);
    //
    //     }
    //    if(strcmp(token,"eliminarSitioxy")==0)
    //     {
    //         int latelim = atoi(strtok(NULL," "));
    //         int longelim = atoi(strtok(NULL," "));
    //         eliminarSitio( lugares,latelim,longelim);
    //
    //     }
    //     if(strcmp(token,"ayuda")==0){
    //         menuAyuda(strtok(NULL," "));
    //     }
    //     //else
    //
    //     //{
    //       //  cout<<(char)173<<"Comando incorrecto!."<<endl;
    //     //}
    //
    //     // system("PAUSE");
    //     // system("cls");
    //     //cout<<imprimirMenu()<<"\nComando:  ";
    //
    //     cin.getline(opcion,100);
    //
    // }
    //
    list< lugar* > lugares;
    string opcion,comando;
    getline( cin , opcion );
    while( opcion != "exit" || opcion != "fin" )
    {
      stringstream ss( opcion );

      ss >> comando;
      if( comando == "cargar" )
      {
        string file;
        ss >> file;
        cout << cargarArchivo( lugares , file );
      }
      else if( comando == "cantSitios" )
      {
        string tipo;
        ss >> tipo;
        if( tipo == "" )
          cout << "Cantidad Sitios: " << cantidadTotal(lugares) << endl;
        else
          cantidadSitios( lugares , tipo );
      }
      else if( comando == "obtenerSitio" )
      {
        double x,y;
        ss >> x >> y;
        obtenerSitio( lugares , x , y );
      }

      else if( comando == "crearSitio" )
      {
        string nombre;
        int tipo;
        double lat,lon;
        ss >> nombre >> tipo >> lat >> lon;
        crearSitio( lugares , nombre , tipo , lat , lon );
      }
      else if( comando == "modificarSitio" )
      {
        double lon,lat,newlon,newlat;
        string nombre;
        int tipo;
        ss >> lon >> lat >> nombre >> tipo >> newlat >> newlon;
        modificarSitio( lugares , nombre,  tipo , lat , lon , newlat, newlon );
      }
      else if( comando == "eliminarSitio" )
      {
        int lat , lon ;
        ss >> lat >> lon ;
        eliminarSitio( lugares , lat , lon );
      }
      else if( comando == "ayuda" )
      {
        string com;
        ss >> com;
        menuAyuda( com );
      }
      else
      {
        cout << "Comando erroeno \n";
      }
      getline( cin , opcion );
    }
    cout<<imprimirGracias();


    return (0);
}


void menuAyuda( string com ){
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

    switch(c){
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

void eliminarSitio(list<lugar *> &lugars,double lat,double lon)
{
    if(!lugars.empty())
    {
        list<lugar *>::iterator eliminado=obtenerSitio2(lugars,lat,lon);
        cout<<"El sitio "<<(*eliminado)->getNombre()<<" en las coordenadas ("<<(*eliminado)->getLat()<<","<<(*eliminado)->getLon()<<") ha sido eliminado."<<endl;
        lugars.erase(eliminado);
    }
    else
    {
        cout<<"No se han ingresado lugares."<<endl;
    }



}

void modificarSitio(list<lugar *> &lugars,string newname,int newtipo,double lat,double lon,double newlat,double newlon)
{
    if(!lugars.empty())
    {
        list<lugar*>::iterator elmodificado =obtenerSitio2(lugars,lat,lon);
        cout<< "La informacion del Sitio "<< (*elmodificado)->getNombre();
        (*elmodificado)->setNombre(newname);
        (*elmodificado)->setTipo(newtipo);
        (*elmodificado)->setLat(newlat);
        (*elmodificado)->setLon(newlon);

        cout<<" se ha actualizado a: "<<newname<<" de tipo "<<newtipo<<", con coordenadas ("<<newlat<<","<<newlon<<")."<<endl ;
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

void crearSitio(list<lugar *> &lugars,string nombretemp,int tipotemp,double lattemp,double lontemp)
{
    lugars.push_back(new lugar(nombretemp,tipotemp,lattemp,lontemp));
    cout<<"El sitio de tipo "<<tipotemp<<" en ("<<lattemp<<","<<lontemp<<") ha sido creado."<<endl;

}

void obtenerSitio(list<lugar *> lugars,double x,double y)
{
    if(!lugars.empty())
    {
        double distancia;
        string nombre;
        int tipo;
        double lat;
        double lon;
        for (list<lugar *>::iterator it = lugars.begin(); it != lugars.end(); it++)
        {
            if(it==lugars.begin())
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

void cantidadSitios(list<lugar *> lugars,string tipo)
{
    int cont=0;
    int tipoint=atoi(tipo.c_str());
    for (list<lugar *>::iterator it = lugars.begin(); it != lugars.end(); it++)
    {
        if((*it)->getTipo()==tipoint)
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
int cantidadTotal(list<lugar *> lugars)
{
    return lugars.size();
}

string imprimirMenu()
{
    string menu="";
    char esi = 201, esd = 187, eii = 200, eid = 188, lv = 186, lh = 205, id = 185,ii = 204;
    menu=menu
         +" "+ esi + imprimirlinea(205, 38) + esd + "\n"
         +" "+ lv + "\t\t\t\t\t" + lv + "\n"
         +" "+ lv + "\t           MENU       \t\t" + lv + "\n"
         +" "+ lv + "\t\t\t\t\t" + lv + "\n"
         +" "+ ii + imprimirlinea(205, 38) + id + "\n"
         +" "+ lv + "  Comando 1: cargar. (Carga Archivo) \t\t\t" + lv + "\n"
         +" "+ lv + "  Comando 2: cantSitios (Cantidad de Sitios) \t" + lv + "\n"
         +" "+ lv + "  Comando 3: obtenerSitiosxy (Obtener Sitio) \t\t" + lv + "\n"
         +" "+ lv + "  Comando 4: crearSitio (Crear Sitio) \t\t" + lv + "\n"
         +" "+ lv + "  Comando 5: modificarSitioxy (Modificar Sitio) \t\t" + lv + "\n"
         +" "+ lv + "  Comando 6: eliminarSitioxy (Eliminar Sitio) \t\t" + lv + "\n"
         +" "+ lv + "  Comando 7: fin (Salir) \t\t\t" + lv + "\n"
         +" "+ eii + imprimirlinea(205, 38) + eid + "\n";
    return menu;
    /*char esi = 201, esd = 187, eii = 200, eid = 188, lv = 186, lh = 205, id = 185,ii = 204;
    cout <<" "<< esi << imprimirlinea(205, 38) << esd << endl
         <<" "<< lv << "\t\t\t\t\t" << lv << endl
         <<" "<< lv << "\t           MENU       \t\t" << lv << endl
         <<" "<< lv << "\t\t\t\t\t" << lv << endl
         <<" "<< ii << imprimirlinea(205, 38) << id << endl
         <<" "<< lv << "  Opcion 1: Cargar. \t\t\t" << lv << endl
         <<" "<< lv << "  Opcion 2: Cantidad de Sitios. \t" << lv << endl
         <<" "<< lv << "  Opcion 3: Obtener Sitio. \t\t" << lv << endl
         <<" "<< lv << "  Opcion 4: Crear Sitio. \t\t" << lv << endl
         <<" "<< lv << "  Opcion 5: Modificar Sitio. \t\t" << lv << endl
         <<" "<< lv << "  Opcion 6: Eliminar Sitio. \t\t" << lv << endl
         <<" "<< eii << imprimirlinea(205, 38) << eid << endl;*/
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
string cargarArchivo(list<lugar *> &lugars,string nombrearch)
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
            lugars.push_back(new lugar(nombrel, tipol, latl, lonl));
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
