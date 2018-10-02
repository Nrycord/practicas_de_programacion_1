//Programa creado por: Carlos Enrique Cordero Linares
//Carnet: CL18030


//codigo escencial 
#include <iostream> //Admite la entrada y salida de datos
#include <math.h>	//Agrega diversos procesos matematicos.
#include <windows.h> //utilizado para declarar las funciones de la biblioteca windows API.

using namespace std;
//codigo escencial

int main (int argc, char *argv[])
{

for (int i=1;i<=10;i++)
{				
cout<<endl<<("Tabla del ")<<i<<endl;

for (int j=1;j<=10;j++)

cout<<i<<"x"<<j<<"="<<i*j<<endl;

 }

system("pause");
return EXIT_SUCCESS;

}

