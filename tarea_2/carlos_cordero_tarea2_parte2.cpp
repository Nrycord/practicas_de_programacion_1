#include <iostream> //ingreso y salida de datos
#include <windows.h> //efectos de la consola
#include <iomanip> //incluye la precision de decimales

using namespace std;

//Creado por: Carlos Enrique Cordero Linares. CL18030

int clear(int clear); //verifica que el campo ingresado sea correcto

void l(); //limpia la pantalla

int main() //funcion principal
{

	int sodap; //total de soda producida a diario
	int jugop; //total de jugo producida a diario
	int producto; //selecciona que producto se va a calcular
	int totalAgua; //almacena el total de agua que se usara
	int totalAzucar; //almacena el total de azucar que se usara
	int continuar; //permite repetir el proceso luego de hacer una operacion
	
do
{	
	do //repite el ciclo hasta que se ingrese un dato correcto
	{
	cout << "Que producto desea calcular (1 = soda, 2 = jugo, 3 = salir)" << endl;
	//crea las opciones de que proceso se desea hacer
	cin >> producto;
	
	if(producto < 1 || producto > 3)
	{
		cout << "Ingrese un numero dentro del rango mostrado." << endl;
		system("pause");
		l();
	}
	
	clear(producto);//evalua si el dato ingresado es correcto y lo corrige
	
	
	} while(producto < 1 || producto > 3);
	
	//divide el proceso en 3 posibilidades dependiendo de lo que el usuario seleccione
	switch(producto)
	{
		//si selecciono soda
		case 1:
			do //verifica que no de ningun error al ingresar el dato
			{
			
			cout << "Ingrese la produccion diaria de soda: ";
			cin >> sodap;
			clear(sodap);//evalua si el dato ingresado es correcto y lo corrige
			
			} while(sodap < 1);
			
			totalAgua = 600 * sodap; //calcula cuanta agua se necesitara
			totalAzucar = 700 * sodap; //calcula cuanta azucar se necesitara
			
			cout << "El total de produccion de soda sera de: " << sodap << " Unidades"  << endl;
			break; //sale del switch
		
		//si selecciono jugo
		case 2:
			do //verifica que no de ningun error al ingresar el dato
			{

			cout << "Ingrese la produccion diaria de jugo: ";
			cin >> jugop;
			clear(jugop);//evalua si el dato ingresado es correcto y lo corrige
			
			} while(jugop < 1);
			
			totalAgua = 600 * jugop; //calcula cuanta agua se necesitara
			totalAzucar = 700 * jugop; //calcula cuanta azucar se necesitara
			cout << "El total de produccion de jugo sera de: " << jugop << " Unidades" << endl;
			break; //sale de el switch
		
		//si selecciono salir del programa
		case 3:
			
			cout << "Gracias por su preferencia, que tenga un lindo dia." << endl;
			system("pause");
			return 0;//termina el programa
	}
	
	//muestra el resultado final
	cout << "El total de agua requerida sera de: " << totalAgua << " ml" << endl; 
	cout << "El total de azucar requerida sera de: " << totalAzucar << " ml"<< endl;
	system("pause");
	l();
	
	do //verifica que no de ningun error al ingresar el dato
	{
	
	cout << "Desea repetir el proceso? (1 = Si, 2 = No)" << endl;
	cin >> continuar;
	clear(continuar);
	
	} while(continuar < 1 || continuar > 2);
	
} while(continuar == 1);//mientras el valor de continuar sea 1, el proceso se repetira infinitamente


cout << "Gracias por su preferencia, que tenga un lindo dia." << endl;
return 0;
}

void l()
{
	system("cls");	
	cout << "--------------------------------------------" << endl;
}

int clear(int clear)
{
	if (cin.fail() || clear <= 0)
    	{
			cin.clear(); // limpia la variable
        	cin.ignore();
        	cout << "Ingrese un numero valido." << endl;
        	system("pause");
        	
    	}
    l();
    return clear;
}
