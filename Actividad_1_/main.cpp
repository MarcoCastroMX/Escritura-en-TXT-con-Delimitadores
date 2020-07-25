#include <iostream>
#include <A.h>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    A a;
    int Opc,llave,numero;
    string cadena;
    int arr[5];
    ofstream fout;
    ifstream fin;
    stringstream ss;
    do{
        Opc=a.menuPrincipal();
        switch (Opc){
            case 11:{
                cout<<"\t\tMENU PRINCIPAL\n\nIngrese la Cadena:"<<endl;
                cin>>cadena;
                cout<<"Ingrese la Llave Primaria: "<<endl;
                cin>>llave;
                if(a.Compararllave(llave)){
                    cout<<"La Llave ya Existe"<<endl;
                    break;
                }
                for(int i=0;i<5;i++){
                    cout<<"Ingrese un numero para la pocision: "<<i<<endl;
                    cin>>numero;
                    arr[i]=numero;
                }
                A a(cadena,llave,arr);
                fout.open("Archivo.txt",ios::app);
                fout<<a.ToFile()<<endl;
                fout.close();
                break;
            }
            case 12:{
                string Contenido="",linea;
                cout<<"\t\tMENU PRINCIPAL\n\nIngrese la Cadena:"<<endl;
                cin>>cadena;
                cout<<"Ingrese la Llave Primaria: "<<endl;
                cin>>llave;
                if(a.Compararllave(llave)){
                    cout<<"La Llave ya Existe"<<endl;
                    break;
                }
                for(int i=0;i<5;i++){
                    cout<<"Ingrese un numero para la pocision: "<<i<<endl;
                    cin>>numero;
                    arr[i]=numero;
                }
                A a(cadena,llave,arr);
                fout.open("Archivo.txt",ios::app);
                fout.close();
                fout.open("Archivo2.txt",ios::app);
                fout<<a.ToFile()<<endl;
                fout.close();
                fin.open("Archivo.txt");
                while(!fin.eof()){
                    fin>>linea;
                    if(fin.eof())
                        break;
                    Contenido+=linea+"\n";
                }
                fin.close();
                fout.open("Archivo2.txt",ios::app);
                fout<<Contenido;
                fout.close();
                remove("Archivo.txt");
                rename("Archivo2.txt","Archivo.txt");
                break;
            }
            case 2:{
                cout<<"\t\tMENU PRINCIPAL\n\nIngrese Llave Principal: "<<endl;
                cin>>llave;
                if(!a.Compararllave(llave)){
                        cout<<"\nLlave Inexistente"<<endl;
                        break;
                }
                ss.str("");
                ss<<llave;
                fin.open("Archivo.txt");
                string texto="";
                if (fin.is_open()){
                        while(!fin.eof()){
                            string linea;
                            fin>>linea;
                            if(fin.eof())
                                break;
                            string atributos[3];
                            int contDelimitadores = 0;
                            for(int i = 0; i < linea.length(); i++){
                                if (linea[i]=='|'){
                                    contDelimitadores++;
                                }
                                else{
                                    atributos[contDelimitadores]+=linea[i];
                                }
                            }
                            if(ss.str()==atributos[1]){

                            }
                            else {
                                texto+=linea+"\n";
                            }
                        }
                        fin.close();
                }
                fout.open("Archivo2.txt",ios::app);
                fout<<texto<<endl;
                fout.close();
                remove("Archivo.txt");
                rename("Archivo2.txt","Archivo.txt");
                break;
            }
            case 3:{
                cout<<"\t\tMENU PRINCIPAL\n"<<endl;
                a.MostrarTodos();
            }

        }


    }while(Opc!=4);
}
