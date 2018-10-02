//Programa creado por: Carlos Enrique Cordero Linares
//Carnet: CL18030


//codigo escencial 
#include <iostream> //Admite la entrada y salida de datos
#include <math.h>	//Agrega diversos procesos matematicos.
#include <windows.h> //utilizado para declarar las funciones de la biblioteca windows API.

using namespace std;
//codigo escencial

void l(); //declara la funcion l

int sumar (int a,int aux);
int pedirNumSumar();

int main ()
{	int n=1; //contador
	int vn; //su valor cambiara de 2 a 4
	int suma=0; //acumulador
	int aux; // intercambio de valores

do {
 	l();
cout << "cuantos numeros quiere sumar [2-4]: ";
cin>>vn;
/*vn<=pedirNumSumar;*/
}while (vn<2 || vn>4);

while(n<=vn) {
	l();
	cout << "Ingrese el numero "<<n<<endl;
	cin>>aux;
	suma = sumar(suma,aux);
	n++;	
}

 l();
cout << "La suma es de: "<<suma<<endl;

system("pause");
}

void l() 
{ //implimentacion de la funcion l
	system ("cls");
	cout<<"-----------------"<<endl;
	cout<<"-----------------"<<endl;
}
 

 
int sumar (int a,int aux)
//realiza la suma de dos numeros
{	
	return a+aux;
}


