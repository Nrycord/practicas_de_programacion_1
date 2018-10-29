#include <iostream> //entrada y salida de datos

using namespace std;

struct Empleados //crea la estructura de cada empleado
{
	
	char cod[5];
	string nombre;
	int edad;
	float salarioBase;
	float salarioLiquido;
	float isss;
	float afp;
	float renta;
	float totalPrestamo;
			
};

float calIsss(float salario); // calcula el isss

float calAfp(float salario); // calcula el afp

float calRenta(float salario, float isss, float afp); //calcula la renta

int cl(int clear); //verifica que un ingreso sea correcto

int main() //funcion principal
{
	int n;
	
	do{	
	cout << "Cuantos empleados tiene?" << endl;
	cin >> n; //ingresa el numero de empleados
	
	n = cl(n);
	system("cls");
	}while(n < 1);
	Empleados e[n]; //crea el arreglo con el numero de empleados seleccionados
	
	for(int i = 0; i < n ; i++)
	{ //pide llenar todos los campos de la estructura Empleados
		cout << "Ingrese el codigo del empleado: ";
		cin >> e[i].cod;

		cout << "Ingrese el nombre del empleado: ";
		cin >> e[i].nombre;
		
		do{
		cout << "Ingrese la edad del empleado: ";
		cin >> e[i].edad;
		e[i].edad = cl(e[i].edad);
		} while(e[i].edad < 1);
		
		do{
		cout << "Ingrese el salario base del empleado: ";
		cin >> e[i].salarioBase;
		e[i].salarioBase = cl(e[i].salarioBase);
		} while(e[i].salarioBase < 1);
		
		e[i].isss = calIsss(e[i].salarioBase);
		
		e[i].afp = calAfp(e[i].salarioBase);
		
		e[i].renta = calRenta(e[i].salarioBase,e[i].isss,e[i].afp);		
		
		int pres; //calcula el totol de cada prestamo
		float totpres = 0; //es la sumatoria de todos los prestamos
		float contador = 0; 
		int cp;
		
		do{
		cout << "La cantidad de prestamos del empleado: ";
		cin >> cp; //ingresa cuantos prestamos hay
		cp = cl(cp);
		}while(cp > 4 || cp < 0);
		
		while(contador + 1 <= cp)
		{//recorre el ciclo por cada prestamo
			
			do{
			cout << "Ingrese el monto del prestamo: ";
			cin >> pres;
			} while(pres < 1);
			
			if(e[i].salarioBase*0.2 > totpres)
			{ //evita que el prestamo pase del 20% del sueldo
			totpres += pres;
			}
			else
			{
				cout << "El prestamo excede su maximo del 20% de su salario. Su prestamo sera rechazado" << endl;
			}
		contador++;
		}
		e[i].totalPrestamo = totpres; 
		//asigna el total a pagar por los prestamos
		
		e[i].salarioLiquido = e[i].salarioBase - (e[i].isss + e[i].afp + e[i].renta + e[i].totalPrestamo);			
		//calcula el salario liquido del trabajador
	system("cls");
	}
	
	for(int i = 0; i < n ; i++)
	{//muestra todos los datos ingresados por el usuario
		cout << "Nombre: " << e[i].nombre << "\t";
	
		cout << "Codigo: " << e[i].cod << "\t";
		
		cout << "Edad: " << e[i].edad << endl;
		
		cout << "Salario base: " << e[i].salarioBase << endl;
		
		cout << "Isss: " << e[i].isss << endl;
		
		cout << "Afp: " << e[i].afp << endl;
		
		cout << "Renta: " << e[i].renta << endl;
		
		cout << "Prestamos: " << e[i].totalPrestamo << endl;
		
		cout << "Salario liquido: " << e[i].salarioLiquido << endl << endl;
	}
}

float calIsss(float salario)
{
	float isss;
	if(salario >= 600)
	{
		isss = 30;
	}
	else
	{
		isss = salario*0.03; //se descuenta el 3% al sueldo	
	}
	
	return isss;
}

float calAfp(float salario)
{
	float afp;
	afp = salario*0.0725; //se descuenta un 7.25%
	return afp;
}

float calRenta(float salario, float isss, float afp)
{
	float renta;
	float rsobre;
	float lim;
	
	lim = salario - (isss + afp);
	
	if(lim <= 472)
	{
		renta = 0;
	}
	else if(lim <= 895.24)
	{
		rsobre = lim - 472;
		renta = (rsobre * 0.10) + 17.67;
	}
	else if(lim <= 2038.10)
	{
		rsobre = lim - 895.24;
		renta = (rsobre * 0.20) + 60;
	}
	
	else if(lim > 2038.10)
	{
		rsobre = lim - 2038.10;
		renta = (rsobre * 0.30) + 288.57;
	}
	
	return renta;
	
}

int cl(int clear) //verifica si un dato erroneo fue ingresado y lo corrige
{
	if (cin.fail()) //si al ingresar los datos causo error entra al ciclo
    	{
			cin.clear(); // limpia la variable
        	cin.ignore(); // borra espacios y caracteres
        	cout << "Ingrese un numero valido." << endl;
        	system("pause"); // pausa el programa hasta que el usuario desee
        	
			clear = -1; 
			/*asigna el valor de clear a -1, de esa forma los ciclos se repiten
        			si clear entra al if*/
    	}
    return clear;//retorna la variable ya revisada y/o corregida
}
