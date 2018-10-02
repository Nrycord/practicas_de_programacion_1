//Programa creado por: Carlos Enrique Cordero Linares
//Carnet: CL18030


//codigo escencial 
#include <iostream> //Admite la entrada y salida de datos
#include <math.h>	//Agrega diversos procesos matematicos.
#include <windows.h> //utilizado para declarar las funciones de la biblioteca windows API.

using namespace std;
//codigo escencial

int factorial (int n)
{
//realiza el factorial de un número
if (n<0){
	return 0;
}
else if (n>1)

	return n*factorial (n-1);
return 1;
}

int main (int argc, char *argv[])
{
	cout<< factorial(3) <<endl;
	system("pause");
}

