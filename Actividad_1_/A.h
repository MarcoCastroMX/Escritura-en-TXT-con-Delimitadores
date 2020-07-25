#ifndef A_H
#define A_H
#include <string>

using namespace std;

class A
{
private:
    string cadena;
    int llavePrimaria;
    int arreglo[5];
public:
    A();
    A(string,int,int arreglo[]);
    int menuPrincipal();
    string ToFile();
    bool Compararllave(int);
    void MostrarTodos();
    string ToString(string, string, string);
};

#endif // A_H
