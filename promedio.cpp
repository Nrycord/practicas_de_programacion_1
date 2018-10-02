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
//variables utilizadas.
float notas [5];
float suma=0;
float promedio;


for (int i=0;i<=4;i++)

do
{
//Pide las notas
	cout <<"Ingrese la nota: "<<i+1<<endl;
				//Adquiere un valor.
	cin>>notas[i];
	
//suma todas las notas en una sola variable.
	suma=suma+notas[i]; 
	
}	while (notas[i] < 0);//mientras las notas sean mayores a 0 repetira el ciclo

//saca el promedio.
promedio=suma/5;

cout<<"Sus notas son: "<<endl;

//Imprime las notas una a una.
cout<<"N1: "<<notas[0]<<endl;
cout<<"N2: "<<notas[1]<<endl;
cout<<"N3: "<<notas[2]<<endl;
cout<<"N4: "<<notas[3]<<endl;
cout<<"N5: "<<notas[4]<<endl;

//Imprime el promedio.
cout<<"El promedio es de: "<<promedio<<endl;

return 0;

}
