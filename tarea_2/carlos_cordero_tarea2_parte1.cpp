#include <iostream> //ingreso y salida de datos
#include <windows.h> //efectos de la consola
#include <iomanip> //incluye la precision de decimales

using namespace std;

//Creado por: Carlos Enrique Cordero Linares. CL18030

int cl(int clear); //verifica que el campo ingresado sea correcto
void l(); //limpia la pantalla

int main() //funcion principal
{
	int totalLlamada; //total de llamadas
	int minuto; //la longitud de la llamada
	float costo; //cuanto cuesta la llamada
	float cTotal; //costo total de todas las llamadas
	
	//verifica que no de ningun error al ingresar el dato
	do
	{
		//ingresa el total de llamadas
		cout << "Ingrese cuantas llamadas ha realizado: " << endl;
		cin >> totalLlamada;
		cl(totalLlamada);
		
		l();
    		
	}while(totalLlamada < 1); 
	
	//enlista el costo por cada llamada
	float llamadas[totalLlamada] = {0};
	
	//pide el ingreso de la duracion de cada llamada de acuerdo al numero de llamadas que realizo
	for(int i = 0 ; i < totalLlamada ; i++)
	{
		//evita que el ingreso de un error
		do
		{
		
		cout << "Ingrese la duracion de la llamada N " << i+1 << ": " << endl;
		cin >> minuto;
		cl(minuto);
		
		} while(minuto < 1);
		
		//asigna el costo segun la duracion de la llamada
		if(minuto >= 1 && minuto <= 10)
		{
			costo = /*minuto * */ 0.05;
		}
		else if(minuto > 10 && minuto <= 15)
		{
			costo = /*minuto * */ 0.08;
		}
		else
		{
			costo = /*minuto * */ 0.10;
		}
		
		//saca la suma de todos los costos de todas las llamadas
		cTotal = cTotal + costo;
		
		//enlista cada costo a una posicion en el arreglo llamadas
		llamadas[i] = costo;
						
	}
	l();
	
	//imprime el costo de todas las llamadas
	for(int i = 0 ; i < totalLlamada ; i++)
	{
	cout << "El costo de la llamada numero " << i+1 << " es de: $" << setprecision(3) << llamadas[i] << endl;
	}
	//imprime el total a pagar
	cout << "El total a pagar sera de: $" << setprecision(3) << cTotal << endl;
}

void l()
{
	system("cls");
}

int cl(int clear)
{
	if (cin.fail() || clear <= 0)
    	{
			cin.clear(); // limpia la variable
        	cin.ignore(); // borra espacios y caracteres
        	cout << "Ingrese un numero valido." << endl;
        	system("pause"); // pausa el programa hasta que el usuario desee
    	}
    return clear;//retorna la variable ya revisada
}
