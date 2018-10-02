//Programa creado por: Carlos Enrique Cordero Linares
//Carnet: CL18030


//codigo escencial 
#include <iostream> //Admite la entrada y salida de datos
#include <math.h>	//Agrega diversos procesos matematicos.
#include <windows.h> //utilizado para declarar las funciones de la biblioteca windows API.
#include <iomanip> //Permite utilizar el comando setpresicion
using namespace std;
//codigo escencial

				
int main ()
{

/*comando para asignar color de fondo y color a las letras,
 el 80 significa 8="color de fondo" 1="color de letras"*/
system("color 31");

				
int venta;//variable de la venta
				
float salario;//variable de la paga


	cout<<"Hola bienvenido/a."<<endl;

//ciclo para verificar si el numero ingresado es correcto
do
{

//peticion de la cantidad de ventas realizadas.
cout<<"Escriba la cantidad de ventas realizadas en el mes."<<endl;

//se asigna valor a la variable venta
cin>> venta;
				//cierre del ciclo
} while(venta < 0);


cout << setprecision(3)<<endl;//especifica cuantos decimales va a mostrar
cout << fixed<<endl;


if (venta >= 0 && venta <= 500000){
	
//se asigna valor al salario
	salario = 80.000; 
}


else if (venta >= 500001  && venta  <= 1000000){
	
//se asigna valor al salario
	salario = 160.000;
}
 
else if (venta >= 1000001  && venta <= 1500000){
	
//se asigna valor al salario
	salario = 320.000;
}
 
else if (venta >= 1500001  && venta <= 2500000){
	
//se asigna valor al salario
	salario = 450.000;
}
 
else if (venta >= 2500001  && venta <= 4000000){
	
//se asigna valor al salario
	salario = 500.000;
}
 
else if (venta > 4000000){
	
//se asigna valor al salario, usando la operacion vneta * 20 %
	salario = (venta * 0.20);
	
}
 
else {
	cout<<"No tendra pago"<<endl;
}

//imprimime el pago que debe recibir
cout<<"Su paga por la venta es de: "<<salario<<endl;
	

	Beep(725,300);  
	Beep(684,300);
	Beep(422,300); 
	
//detiene el programa momentameamente
system("pause");
return EXIT_SUCCESS; //termina la funcion principal
}
