//Programa creado por: Carlos Enrique Cordero Linares
//Carnet: CL18030


//codigo escencial 
#include <iostream> //Admite la entrada y salida de datos
#include <math.h>	//Agrega diversos procesos matematicos.
#include <windows.h> //utilizado para declarar las funciones de la biblioteca windows API.

using namespace std;
//codigo escencial

using namespace std;

int main (int argc, char *argv[])
{

int x;

int fact=1;
  
do{

cout<<"Escriba el numero que quiere sacar el factorial: "<<endl;
cin>>x;

}while (x < 0);

for (int i=1;i<=x;i++)
{
	
	fact=fact*i;
	
}

cout <<"El resultado es: "<<fact<<endl;

system("pause");
return EXIT_SUCCESS;

}

