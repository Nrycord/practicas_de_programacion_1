//Programa creado por: Carlos Enrique Cordero Linares
//Carnet: CL18030


//codigo escencial 
#include <iostream> //Admite la entrada y salida de datos
#include <math.h>	//Agrega diversos procesos matematicos.
#include <windows.h> //utilizado para declarar las funciones de la biblioteca windows API.

using namespace std;
//codigo escencial

int main (int argc, char *argv[]){

	int mat [5][5]; //declaramos una matriz
	int mat2 [5][5];
	int mat3 [5][5];
	
	//ciclo, contador,termial, incremento 
	for (int fila = 0; fila<5; fila++){ //ciclo for
		for (int col=0; col<5; col++){
			mat [fila][col] = 0;	
			
			if(fila == 4 || col == 2){
			mat2 [fila][2] = 0;
			mat2 [4][col] = 0;			
			}

			else{
				
			mat2[fila][col] = 1;
			}
			
			
			mat3 [fila][col] = mat [fila][col] + mat2 [fila][col];
					
		}
		
	}

	for (int fila = 0; fila<5; fila++){ //ciclo for
		for (int col=0; col<5; col++){
			cout<<mat3[fila][col]<<"\t";
		}		
		cout<<endl;
	}
system("pause");
return EXIT_SUCCESS;

}
