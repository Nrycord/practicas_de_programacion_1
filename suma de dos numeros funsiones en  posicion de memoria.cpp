//Programa creado por: Carlos Enrique Cordero Linares
//Carnet: CL18030


//codigo escencial 
#include <iostream> //Admite la entrada y salida de datos
#include <math.h>	//Agrega diversos procesos matematicos.
#include <windows.h> //utilizado para declarar las funciones de la biblioteca windows API.

using namespace std;
//codigo escencial

float sumar();
void pedirNumeros(); /*declaramos la funcion*/

int main (){
	
pedirNumeros();
system ("pause"); 
//se encuentra en la libreria iostream
return 0;

}

float sumar (float &x, float &y)
{
	cout << "x = "<< &x << endl;
	cout << "y = "<< &y << endl;
	
	return x+y;
}

void pedirNumeros()
{	float x;
	float y;
	float res;
	
	cout<<"Ingrese un numero"<<endl;
	cin >> x;
	cout<<"Ingrese un numero"<<endl;
	cin >> y;
	res=sumar(x,y);
	
	cout << "x = "<< &x << endl;
	cout << "y = "<< &y << endl;
	
	cout<<"El resultado es: "<<res<<endl;
	
}

