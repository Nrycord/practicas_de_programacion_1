#include <iostream> //ingreso y salida de datos

using namespace std;

//Creado por: Carlos Enrique Cordero Linares. CL18030

//verifica que el campo ingresado sea correcto
int cl(int clear); 

//limpia la pantalla
void l(); 

//Ingresa y reeplaza " _ " con "X" o "O" cambiando el arreglo original
char ingresaPosicion(string tic[3][3], int col, int fila,char turn, int coordx, int coordy);

//cambia el turno del jugador uno al dos y viceversa
char changeT(char turn);

//muestra el mensaje de quien es el ganador y ademas muestra el tablero una vez más
char ganar(string tic[3][3], int col, int fila, char turn); 


//funcion principal
int main() 
{
	
	//constantes que marcan la longitud de la matriz
	const int nFila = 3;
	const int nCol = 3;

	//crea la matriz la cual sera de 3x3 el cual representa el tablero del juego
	string tic[nFila][nCol];

	//la condicion cambia si un jugador enlista 3 en raya del mismo signo
	bool win = false; 	
	
	/*asigna el turno de cada jugador
			cada vez que uno pone un simbolo ("X" o "O") pasa al turno del siguiente jugador*/
	char turn; 
	
	//almacena la columna en la que se pondra el marcador
	int coordx; 
	
	//almacena la fila en la que se pondra el marcador
	int coordy; 
	
	for(int i = 0; i < 3; i++) 
	//recorre todas las columnas de la matriz
	{
		for(int j = 0; j < 3; j++)
		//recorre todas las filas de la matriz
		{
			tic[i][j] = " _ "; 
			/*asigna el valor de " _ " a todos los espacios de la matriz tic
					estos se cambaran a medida el programa avanza	*/
		}		
	}
	
	
	cout << "Bienvenido a Tic Tac Toe" << endl;
	
	//inicio de interfaz grafica

	do 
	/*este bloque se repetira hasta que win = true o
			en otras palabras que una de las condiciones de victoria se cumpla*/
	{ 
	
	cout << "						 X			" << endl; //señaliza el eje x
	cout << "	 			 0	   	 1 		 2 " << endl; 
	//muestra el valor de las columnas en el tablero
	
	cout << "			_________________________________________________" << endl;
	for(int i = 0; i < 3; i++)
	//recorre todas las columnas de la matriz
	{
		cout << "			|  ";
		for(int j = 0; j < 3; j++)
		//recorre todas las filas de la matriz
		{
			cout << "	" << tic[i][j]<< "	"; 
			//imprime el valor actual de cada espacio de la matriz	
		
		}
		cout << "|  " << i << endl; 
		//muestra el valor de las filas en el tablero
		
		cout << "			|						|" << endl;	
	}
	cout << "			-------------------------------------------------  Y" << endl;
	
	// fin de la interfaz grafica
	
	turn = changeT(turn); //cambia el turno del jugador
	
	//Señala de quien es el turno
	cout << "turno del jugador " << (turn == 'X')? "1":"2";  
	cout << ": " << endl; 
	
	do
	/*mientras el valor ingresado no se encuentre en el rango del tablero 
			no tomara ese dato, de esa forma se evitan errores*/
	{
	cout << "Ingrese la coordenada x: ";
	cin >> coordx; //ingresa la coordernada en x, (columna)
	
	/*verifica si un dato erroneo o invalido fue ingresado
			si es asi borra el dato ingresado y pide que se ingrese nuevamente*/
	coordx = cl(coordx); 
	
	
	}while(coordx < 0 || coordx > 2); 
	//fin de la verificacion de la coordenada x 
		
	do
	/*mientras no se encuentre en el rango del tablero 
			no tomara el dato de esa forma se evitan errores*/
	{
	cout << "Ingrese la coordenada y: ";
	cin >> coordy; //ingresa la coordernada en y, (fila)
	
	coordy = cl(coordy);
	/*verifica si un dato erroneo o invalido fue ingresado
			si es asi borra el dato ingresado y pide que se ingrese nuevamente*/
	
	}while(coordy < 0 || coordy > 2);
	//fin de la verificacion de coordenada y
	
	turn = ingresaPosicion(tic, nFila, nCol, turn, coordx, coordy);
	/*llama a la funcion ingresarPosicion y el resultado lo asigna a la variable turn
			este coloca el simbolo en el espacio indicado por las coordenadas que el jugador ingreso*/
	
	
for(int i = 0; i < 3; i++)//recorre todas las columnas
{
	
	if(tic[i][0] ==  tic[i][1] && tic[i][0] == tic[i][2] && tic[i][0] != " _ "
			&& tic[1][i] != " _ " && tic[2][i] != " _ ") 		
/*realiza la verificacion: si 3 del mismo signo estan en la misma columna 
		y estos son distintos de "  _ " entonces el jugador de quien puso el ultimo signo gana*/
	
	{
		win = true;//el booleano win se vuelve verdadero, y por ende deja de repetir el while
		
		//muestra si el jugador 1("X") o el jugador 2 ("O") ha ganado
		cout << "El jugador " << (turn == 'X')? "1":"2"; 
		cout << " ha ganado." << endl;
		
		ganar(tic,nCol,nFila,turn); //muestra al ganador llamando a la funcion ganar	
	}
	
	else if(tic[0][i] ==  tic[1][i] && tic[0][i] == tic[2][i] && tic[0][i] != " _ " 
			&& tic[1][i] != " _ " && tic[2][i] != " _ ")
/*realiza la verificacion: si 3 del mismo signo estan en la misma fila 
		y estos son distintos de "  _ " entonces el jugador de quien puso el ultimo signo gana*/

	{
		win = true;//el booleano win se vuelve verdadero, y por ende deja de repetir el while
		
		//muestra si el jugador 1("X") o el jugador 2 ("O") ha ganado
		cout << "El jugador " << (turn == 'X')? "1":"2"; 
		cout << " ha ganado." << endl;
		
		ganar(tic,nCol,nFila,turn); //muestra al ganador llamando a la funcion ganar
	}
	
	else if( (tic[0][0] ==  tic[1][1] && tic[0][0] == tic[2][2] && tic[0][0] != " _ ")
			|| (tic[0][2] == tic[1][1] && tic[0][2] == tic[2][0] && tic[0][2] != " _ ") )
/*realiza la verificacion: si 3 del mismo signo estan en diagonal 
		y estos son distintos de "  _ " entonces el jugador de quien puso el ultimo signo gana*/

	{
		win = true;//el booleano win se vuelve verdadero, y por ende deja de repetir el while
		
		//muestra si el jugador 1("X") o el jugador 2 ("O") ha ganado
		cout << "El jugador " << (turn == 'X')? "1":"2"; 
		cout << " ha ganado." << endl;
		
		ganar(tic,nCol,nFila,turn); //muestra al ganador llamando a la funcion ganar
	}
}
	
	if(tic[0][0] != " _ " && tic[0][1] != " _ " && tic[0][2] != " _ " &&
			tic[1][0] != " _ " && tic[1][1] != " _ " && tic[1][2] != " _ " &&
					tic[2][0] != " _ " && tic[2][1] != " _ " && tic[2][2] != " _ ")
/*si todas las casillas han sido ocupadas (todas son distintas de " _ ")
		entonces declara un empate*/

	{
		win = true;//cambia el valor de win a verdadero para acavar el ciclo while
		cout << "Es un empate." << endl;
		system("pause");
		ganar(tic,nCol,nFila,turn)

}
// fin de la interfaz grafica		

system("pause");
//pausa el sistema, dando un espacio entre ambos turnos de los jugadores

l();//limpia la pantalla
			
} while(win != true);
//una vez una de las condiciones para ganar se cumplen el ciclo deja de repetirse
}		

/*se encarga de cambiar el " _ " por el signo correspondiente ("X" o "Y")
		dependiendo de quien sea el turno*/
char ingresaPosicion(string tic[3][3], int col, int fila,char turn, int coordx, int coordy) 
{
	
if(turn == 'X')//si es turno del jugador 1 ("X")
{
	for(int i = 0; i < 3; i++)//recorre todas las columnas
	{
	for(int j = 0; j < 3; j++) // recorre todas las filas
	{
		if(i == coordy && j == coordx) 
		//si la posicion ingresada coincide con el valor de la matriz en la que esta el ciclo for
		{
			if(tic[i][j] != " _ ") 
			/*si el valor de la matriz actual es distinto de " _ " significa
					que ya fue colocado un signo ("X" o "O") anteriormente*/
			{
				cout << "Intente otra coordenada" << endl; 
				//muestra la cadena de texto al usuario
				
				turn = 'O'; //reinicia el turno del jugador para que coloque otra posicion
			}
			
			else
			//si ese espacio no ha sido utilizado por un jugador entonces cambia el valor a X
			{
				tic[i][j] = " X ";
			}
		}	
	}
	}
}

else if(turn == 'O') //si es turno del jugador 2 ("O")
{
	for(int i = 0; i < 3; i++) //recorre todas las columnas
	{
	for(int j = 0; j < 3; j++) //recorre todas las filas
	{
		if(i == coordy && j == coordx)
		{
			if(tic[i][j] != " _ ")
			/*si el valor de la matriz actual es distinto de " _ " significa
					que ya fue colocado un signo ("X" o "O") anteriormente*/
			{
				cout << "Esa casilla ya esta ocupada" << endl; 
				//muestra la cadena de texto al usuario		
									
				turn = 'X'; 
				//reinicia el turno del jugador para que coloque otra posicion
				
			}
			
			else
			//si ese espacio no ha sido utilizado por un jugador entonces cambia el valor a O
			{
				tic[i][j] = " O ";
			}	
		}	
	}
	}
}
	return turn;
	/*retorna el valor de la variable turno
			la cual asigna de quien sera el turno que sigue*/
}

void l()//limpia la pantalla
{
	system("cls");
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

char changeT(char turn) //cambia el turno cada vez que el ciclo while(win != true) se repite
{
	if (turn=='X')//si es el turno del jugador 1
	{
	turn = 'O'; //el turno sera ahora del jugador 2
	} 
	
	else 
	{
	turn='X'; //de otra forma el turno sera del jugador 1
	}
	return turn; //retorna el valor cambiado de turn
}

char ganar(string tic[3][3], int col, int fila, char turn) 
/*esta funcion se activa cuando una condicion para ganar se cumple
la funcion muestra el jugador que ha ganado y muestra el tablero una ultima vez */

{
	l();
	

		
		//inicio de la interfaz grafica

cout << "						 X			" << endl; 
//señaliza el eje x

cout << "	 			 0	   	 1 		 2 " << endl; 
//muestra el valor de las columnas en el tablero

cout << "			_________________________________________________" << endl;
for(int i = 0; i < 3; i++)
//recorre todas las columnas de la matriz
{
	cout << "			|  ";
	for(int j = 0; j < 3; j++)
	//recorre todas las filas de la matriz
	{
		cout << "	" << tic[i][j]<< "	"; 
		//imprime el valor actual de cada espacio de la matriz	
	}
	cout << "|  " << i << endl; 
	//muestra el valor de las filas en el tablero
	
	cout << "			|						|" << endl;	
}
cout << "			-------------------------------------------------  Y" << endl;

// fin de la interfaz grafica	

}

/* Referencia bibliografica.
Como pasar una matriz entre funciones: https://youtu.be/wYEa0z97yGE

Idea para funcion de cambiar turno e ideas generales: 
https://www.lawebdelprogramador.com/foros/Dev-C/100917-Un-ejemplo-del-juego-Gato.html}

*/
