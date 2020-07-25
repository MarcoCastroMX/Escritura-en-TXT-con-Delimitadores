#include "A.h"
#include <iostream>
#include <sstream>
#include <fstream>

A::A()
{

}

A::A(string cadena,int llave, int arr[])
{
    this->cadena=cadena;
    this->llavePrimaria=llave;
    for(int i=0;i<5;i++){
        this->arreglo[i]=arr[i];
    }
}

int A::menuPrincipal(){
   int Opcion,Opcion2;
   cout<<"\t\tMENU PRINCIPAL\n\n1.-Agregar\n2.-Eliminar\n3.-Mostrar Todos\n4.-Salir\n"<<endl;
   cin>>Opcion;
   switch(Opcion){
        case 1:{
            cout<<"\t\tMENU PRINCIPAL\n\n1.-Agregar al Final\n2.-Agregar al Inicio\n"<<endl;
            cin>>Opcion2;
            if(Opcion2<0 || Opcion2>2){
                cout<<"\nOpcion No Valida\n"<<endl;
                return 0;
            }
            else if(Opcion2==1){
                return 11;

            }
            else if(Opcion2==2){
                return 12;
            }
            break;
        }
        case 2:{
            return 2;
        }
        case 3:{
            return 3;
        }
        case 4:{
            return 4;
        }
        default:{
            cout<<"\nOpcion No Valida\n"<<endl;
            return 0;
        }
   }
   return 0;
}

string A::ToFile()
{
    stringstream ss,llave;
    string s="";
    llave<<llavePrimaria;
    s=cadena+"|"+llave.str()+"|";
    int numero;
    for(int i=0;i<5;i++){
        numero=arreglo[i];
        ss<<numero<<",";
    }
    s+=ss.str();
    return s;
}

bool A::Compararllave(int llave)
{
    ifstream fin;
    stringstream ss;
    ss<<llave;
    fin.open("Archivo.txt");
    if (fin.is_open()){
            while(!fin.eof()){
                string cadena;
                fin>>cadena;
                string atributos[3];
                int contDelimitadores = 0;
                for(int i = 0; i < cadena.length(); i++){
                    if (cadena[i]=='|'){
                        contDelimitadores++;
                    }
                    else{
                        atributos[contDelimitadores]+=cadena[i];
                    }
                }
                if(ss.str()==atributos[1])
                    return true;
            }
            fin.close();
    }
    return false;
}

void A::MostrarTodos()
{
    ifstream fin;
    fin.open("Archivo.txt");
    if (fin.is_open()){
        while(!fin.eof()){
            string cadena;
            fin>>cadena;
            string atributos[3];
            int contDelimitadores = 0;
            for(int i = 0; i < cadena.length(); i++){
                if (cadena[i]=='|'){
                    contDelimitadores++;
                }
                else{
                    atributos[contDelimitadores]+=cadena[i];
                }
            }
            cout<<ToString(atributos[0],atributos[1],atributos[2])<<endl;
        }
        fin.close();
    }
}

string A::ToString(string nombre,string llave, string arreglo)
{
    string s;
    return s=nombre+" "+llave+" "+arreglo;
}
