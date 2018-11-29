#include <iostream>//libreria para codigos base 
#include <conio.h> //agrega un sistema de entrada y salida por consola
#include <stdio.h>//manipula datos de entrada y salida
#include <stdlib.h> //prototipos de funciones, macros y otros
#include <math.h>//agrega operaciones matematicas y diversas formulas
#include <fstream>//para editar txt
#include<ctime>//agraga la hora
//Creado por: Carlos Enrique Cordero Linares. CL18030
using namespace std;


int fibo(int n);//ejecuta la funcion del fibonacci
float FuncionTaylor(int mynum);//ejecuta la funcion del taylor
int cl(int clear); //verifica que ningun dato dea ingresado erroneamente

enum eOpt { oERROR=-1, oINICIO, oTAYLOR, oFIBONACCI, oVERRESULTADOS, oSALIR, oTOTAL }; //menu 
char stmp[100];//captura la opcion
int contt = 1;//un contador para limitar cierto ciclo
int arr[20];//guarda los datos de la secuancia de fibonacci



int main()
{
    int opt = 0; //capturara la opcion tomada
    int n; //almacena el valor que se resolvera en el taylor
	int cont;//
	float result = -1; //almacena el resultado de resolver el taylor
	string ejer; //almacena el texto de que operacion es que se realizo
	bool z = false; //permite limitar el ciclo de escritura de archivo bajo ciertas condiciones
	time_t now = time(0);//crea una variable de tiempo
	struct tm *ltm = localtime(&now);//crea la estructura para almacenar el tiempo
	
do
{
system( "cls" );

cout << ( "========== MENU ==========\n" );
cout <<( "1 - Serie de Taylor ") << endl;
cout <<( "2 - Serie de Fibonacci ")<< endl;
cout <<( "3 - Ver resultados ")<< endl;
cout <<( "4 - Salir" )<< endl;
cout <<( "**\n" );
cout <<( "Ingresa tu opcion : " ); gets( stmp );
opt = atoi(stmp);//selecciona la opcion 

if ( opt <= oINICIO || opt >= oTOTAL )	//verificando opciones validas
{
	opt = oERROR;
}

switch ( opt )//Realiza una verificacion de que decidio el usuario
{
case oTAYLOR : //Si el usuario decide utilizar taylor
	z = true;//entra a un proceso, por ende va a escribirlo en el .txt
    ejer = "taylor";//asigna el tipo de proceso a taylor
    system( "cls" );
	printf( "========== Serie de Taylor ==========\n" );
	printf( "Ingresa un numero : " ); gets( stmp );
	n = atoi(stmp);//ingresa el numero por el cual se va a resolver
	result = FuncionTaylor(n); //efectua la funcion de taylor y almacena el resultado
    break;

case oFIBONACCI :
	z = true; //Si el usuario decide utilizar taylor
	ejer = "fibonacci";//asigna el tipo de proceso a taylor
    system( "cls" );
    cout << ( "========== Serie de Fibonacci ==========\n" );
    cout << "Ingrese el limite de la sucecion" << endl;
    cin >> n;
    fibo(n);//evalua el valor de la funcion fibonacci
    break;

case oVERRESULTADOS :
	system("reporte.txt");//abre el archivo del reporte para mostrar los resultados que hay almacenados
	z = false;//no entro a ningun proceso, no es necesario escribirlo en el txt
	break;

case oERROR :
	z = false;//no entro a ningun proceso, no es necesario escribirlo en el txt
	cout << ( "ingresa una de las opciones correctas..\n\n" ) << endl;
	cout << ( "*** PRESIONA <ENTER> PARA CONTINUAR ***" ); getchar();
	break;
};

if(z)//si se realizo una operacion (fibonacci o taylor)
{
	ofstream myfile;//crea el archivo de texto
	myfile.open ("reporte.txt",ios::out | ios::app); //ios::app permite 
	myfile << "1- reporte \t" << "2- " << ejer << "\t" << "3- " << n << "\t"; //imprime uno a uno los datos 
	//que se han almacenados en el archivo de texto
	
	if(result == -1) //verifica e inserta el resultado de fibonacci
	{
		myfile << "4- ";
		for(int k = 0; k < contt; k++)//el ciclo imprime la sucesion de datos del fibonacci
		{
			if(arr[k] != 0 || arr[k] != 1)
			{
				myfile << arr[k] << ", ";
			}		
		}
	}
	else//si aplica a taylor imprime el resultado que se almaceno
	{
		myfile << "4- " << result << " ";
	} 
	myfile << "5- " << ltm->tm_mday<<"/"<<1 + ltm->tm_mon<<"/"<<1900 + ltm->tm_year << endl; 
	//agrega la fecha actual
	myfile.close();//cierra el archivo y termina de editarlo
}

result = -1;//reinicia ciertas variables para que no afecten en le siguiente ciclo
n = 0;

}while ( opt != oSALIR );//mientras la opcion no sea salir repetira esto.

}




int fibo(int n)//resuelve el ejercicios de fibonacci
{
    int t1 = 0;//es el valor 1
	int t2 = 1;//es el valor 2
	int nextTerm = 0;//el el valor del termino siguiente
	
    cout << "Fibonacci Series: " << t1 << ", " << t2 << ", ";//imprime los dos datos inciales

    nextTerm = t1 + t2;

    while(nextTerm <= n)
    {
    	
		arr[contt] = nextTerm;//agrega el dato actual al arreglo
        cout << nextTerm << ", ";
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;
        contt++;//aumenta con cada ciclo, reprecenta el total de diitos que hay
        
    }
    cout << endl;
	system("pause");
    return 0;
}



float FuncionTaylor(int mynum) //ejecuta el ejercicio de taylor
{
double ans = 0;//almacena la respuesta 

if ( mynum <= 0 )//si el numero ingresado es menor de cero, entonces muestra un error
{
cout << ( " ERROR!!..\n");
cout << ( "%s no es ha sido valido..\n\n");
cout << ( "***PRESIONA <ENTER> PARA CONTINUAR" ); getchar();
cl(mynum);
}
double mydoble = 0;
double myfact = 1;

ans = 1 + mynum;
for ( int i=2; i<mynum; i++ )
{
mydoble = pow( (double) mynum, (double)i );
myfact = 1;
for ( int j=1; j<=i; j++ )
myfact *= j;

ans = ans + ( mydoble / myfact );
}

cout <<  "**\n" ;
printf("El resultado es : %0.4f\n\n",  ans);//imprime el resultado
cout << ( "***PRESIONA <ENTER> PARA CONTINUAR" ); getchar();

return ans;//retorna la respuesta una vez ha operado
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



/*
Links donde se inspiro este programa:

https://www.programiz.com/cpp-programming/examples/fibonacci-series
https://programacion.net/foros/c-c-plus/serie_de_taylor_343408
https://www.youtube.com/watch?v=v9ZZUa3eOEM
https://codescracker.com/cpp/program/cpp-program-print-date.htm
https://stackoverflow.com/questions/4108313/how-do-i-find-the-length-of-an-array
*/
