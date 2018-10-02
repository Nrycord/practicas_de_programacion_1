//codigos escenciales, no editar.
#include <iostream> //entrada y salida de datos ademas de ciertos codigos básicos
using namespace std;
//codigos escenciales, no editar.

//Programa elaborado por: Carlos Enrique Cordero Linares (CL18030).

int main () //crea la funcion principal.
{
	int sacos;//los sacos que se van a comprar.
	float compra; //cuanto sale por todos los sacos.
	float descuentoTotal; //que descuento se le aplica.
	float total; //cuanto pagara al final.
	
	cout << "Bienvendos a Mi cafesito, sera un gusto sevirle."<< endl 
	<< "Cuantos sacos comprara? (50$ por saco de cafe)" << endl;
	
	cin >> sacos; //ingresa que tantos sacos comprara.
	
	compra = sacos * 50; //saca el total en dolares de sacos.
	
	
//verifica que descuento se le va a aplicar, dependiendo de lo que salga por todos los sacos.
	if (sacos >= 300 )
	{
		descuentoTotal = compra * 0.25; //aplica al 25%
	}
	else if (sacos > 250)
	{
		descuentoTotal = compra * 0.20; //aplica al 20%
	}
	else if (sacos > 200)
	{
		descuentoTotal = compra * 0.15; //aplica al 15%
	}
	else if (sacos > 100)
	{
		descuentoTotal = compra * 0.10; //aplica al 10%
	}
	else 
	{
		descuentoTotal = 0; //aplica al 0%
	}
	
	total = compra - descuentoTotal + (compra * 0.13); //saca cuanto debe pagar al final.
	//restandole el desucento y sumandole el iva.
	system("cls");
	cout <<"El total a pagar sera de: $"<<total<< endl << endl;
	cout <<"Gracias por preferirnos." << endl << "Que pase un lindo dia"; //termina el programa
	
	return 0;//termina el programa
} 
