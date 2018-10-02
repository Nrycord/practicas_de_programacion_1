//Programa creado por: Carlos Enrique Cordero Linares
//Carnet: CL18030


//codigo escencial 
#include <iostream> //Admite la entrada y salida de datos
#include <math.h>	//Agrega diversos procesos matematicos.
#include <windows.h> //utilizado para declarar las funciones de la biblioteca windows API.

using namespace std;
//codigo escencial

int main (int argc, char *argv[]){
	/*char x[4][4];
	
	
	for(int i=0; i<=2; i++)
	{
		for(int j=2; j>=0; j--)
		{
	
			x[i][j]='x';
	
		}
	}
	
		for(int i=0; i<=3; i++)
	{
		x[i][1]=3;
		
		if(i=3){
				x[3][2]=3;
				x[3][3]=3;			
		}	
	}*/
	
	
		char x[4][4];
	
	for(int i=0; i<=2; i++)
	{
		for(int j=2; j>=0; j--)
	{	
		if(i=3){
				x[i][j]=1;			
		}
		else{
			x[i][j]=0;
		}
			
	for(int i=0; i<=3; i++)
	{
		for(int j=0; j<=3; j++)
		{
	
			cout<<x[i][j]<<"______";
	
		}
		cout<<endl;
	}
	

system("pause");
return 0;

}

}
