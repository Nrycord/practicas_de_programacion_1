#include <iostream>
#include<fstream>
#define ncarr 30
#define ncli 30
//Creado por: Carlos Enrique Cordero Linares. CL18030
using namespace std;

struct Cliente //nombra la estructura de los clientes
{
	string nombre;
	string apellido;
	string dui;
	string licencia;
	string carroR;
};

struct Auto //nombra la estructura de los autos
{
	string nombre;
	string chasis;
	int anio;
	float precioPorDia;

};

Auto carros[ncarr]; //el arreglo de carros
Cliente clientes[ncli]; //el arreglo de clientes
Auto carrosRent[ncarr]; //el arreglo de carros rentados

int cl(int clear);
int mostVehi(); //muestra los vehiculos disponibles
int agrecli(); //Agrega los clientes
int agrevehi(); //agrega vehiculos a la lista
int arrC(int pos, Auto car[ncarr]); //organiza el arreglo de los carros
int mostVehiRent(); //muestra todos los carros rentados
int mostcli();

int main(){
carros[0].nombre = "Toyota Corolla 1.8L";
carros[0].anio = 2018;
carros[0].chasis = "3G1J85CC2GS999589";
carros[0].precioPorDia = 50.5;
carros[1].nombre = "Mazda 6";
carros[1].anio = 2017;
carros[1].chasis = "4G1K85CC2GD923584";
carros[1].precioPorDia = 30.7;
carros[2].nombre = "Mitsubishi lancer AWD";
carros[2].anio = 2017;
carros[2].chasis = "4O1T85HJ2SJ63584";
carros[2].precioPorDia = 70.2;
    int menu;
    bool continuar = true;
    cout << "\n\n\n\n\n________________________________________________________________________________________________________________________" << endl;
    cout << "                                                   Bienvenido      "<< endl;
    cout << "                                          Renta de autos El Gato Motriz "<< endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cin.get();
    system("cls");
    do{ do{
    cout << "Que tramite desearia realizar?" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t___________________________" << endl;
    cout << "\t\t\t\t\t\t|1:Mostrar vehiculos.     |" << endl;
    cout << "\t\t\t\t\t\t---------------------------" << endl;
    cout << "\t\t\t\t\t\t___________________________" << endl;
    cout << "\t\t\t\t\t\t|2:Agregar cliente nuevo. |" << endl;
    cout << "\t\t\t\t\t\t---------------------------" << endl;
    cout << "\t\t\t\t\t\t___________________________" << endl;
    cout << "\t\t\t\t\t\t|3:Agregar vehiculo nuevo.|" << endl;
    cout << "\t\t\t\t\t\t---------------------------" << endl;
    cout << "\t\t\t\t\t\t___________________________" << endl;
    cout << "\t\t\t\t\t\t|4:Mostrar carros rentados|" << endl;
    cout << "\t\t\t\t\t\t---------------------------" << endl;
    cout << "\t\t\t\t\t\t___________________________" << endl;
    cout << "\t\t\t\t\t\t|5:salir                  |" << endl;
    cout << "\t\t\t\t\t\t---------------------------" << endl << "-->";
    cin >> menu;
    menu = cl(menu);
    }while(menu < 0 || menu > 5);
    switch(menu)
    {   case 1:
            mostVehi();
            system("pause");
            system("cls");
            break;
        case 2:
            agrecli();
            system("pause");
            system("cls");
            break;
        case 3:
            agrevehi();
            system("pause");
            system("cls");
            break;
        case 4:
            mostVehiRent();
            system("pause");
            system("cls");
            break;
        case 5:
            continuar = false;
            break;
    }}while(continuar == true);}
///////////////////////////////////////////////////////////////
int mostVehi()
{
    int mostrar;
    int rentar;
    int tiempo;
    float costo;

    for(int i = 0; i <= ncarr; i++)
    {
        if(!carros[i].nombre.empty() || carros[i].nombre != "")
        {
            cout << "Auto n " << i+1;
            cout << "; Nombre: " << carros[i].nombre << endl;


        do{
        cout << "Desearia tener mas informacion acerca de este auto? (1: si, 2: no)" << endl << "-->";
        cin >> mostrar;
        mostrar = cl(mostrar);
        }while(mostrar < 1 || mostrar > 2);

        if(mostrar == 1)
        {
            cout << "Chasis: " << carros[i].chasis << endl;
            cout << "Anio: " << carros[i].anio << endl << endl;

            do{
            cout << "Desearia rentar este vehiculo? (1: si, 2: no)" << endl<< "-->";
            cin >> rentar;
            rentar = cl(rentar);
            }while(rentar < 1 || rentar > 2);

            if(rentar == 1)
            {
                int n;
                //////////////////////////

                do{
                cout << "Seleccione un cliente o cree uno nuevo: " << endl;
                mostcli();
                cout << "Seleccione su numero de usuario, si no tiene uno precione 0:" << endl;
                do{
                cin >> n;
                n = cl(n);
                }while(n < 0);

                if(n == 0)
                {
                    agrecli();
                    cout << "Cliente agragado, por favor seleccione su numero de cliente." << endl;
                    cin.get();
                }}while(n == 0);

                clientes[n].carroR = carros[i].nombre;


                /////////////////////////////
                cout << "Ingrese por cuantos dias desearia rentarlo: "<< endl << "-->";
                cin >> tiempo;
                costo = tiempo * carros[i].precioPorDia;
                cout << "Debera pagar $" << costo << " por rentarlo " << tiempo << " dias." << endl;
                carrosRent[i].nombre = carros[i].nombre;
                carrosRent[i].chasis = carros[i].chasis;
                carrosRent[i].anio = carros[i].anio;
                carrosRent[i].precioPorDia = carros[i].precioPorDia;

                arrC(i,carros);
                break;
////////////////////////////////////////////////////////////////////////////////////////////////////////
//Buscar como borrar de ahi el carro
            }
        }
        }
    }
}

int arrC(int pos, Auto car[ncarr])
{
    for(int i = 0; pos < car[i].nombre.length() ; i++)
    {
        car[pos].nombre = car[pos+1].nombre;
        car[pos].chasis = car[pos+1].chasis;
        car[pos].anio = car[pos+1].anio;
        car[pos].precioPorDia = car[pos+1].precioPorDia;
    pos++;
    } //arreglar la posicion de los autos una vez se renta uno

    car[pos].nombre = "";
    car[pos].chasis = "";
    car[pos].anio = 0;
    car[pos].precioPorDia = 0;
}

int agrecli()
{
    int conti;
    for(int i = 0; i <= ncli; i++)
    {
        if(clientes[i].nombre.empty() || clientes[i].nombre == "")
        {
        cout << "Ingrese su Nombre: " << endl << "-->";
        cin >> clientes[i].nombre;
        cout << "Ingrese su Apellido: " << endl << "-->";
        cin >> clientes[i].apellido;

        cout << "Ingrese su N de DUI: " << endl << "-->";
        cin >> clientes[i].dui;

        cout << "Ingrese su N de licencia: " << endl << "-->";
        cin >> clientes[i].licencia;

        cout << "Desea agregar otro cliente?(1: si, 2: no)" << endl;
        do{
            cin >> conti;
            conti = cl(conti);
        }while(conti < 1 || conti > 2);
        }

        if(conti == 2)
        {
            break;
        }
    }
    system("cls");
}


int agrevehi()
{
    int mas;
    for(int i = 0; i <= ncarr; i++)
    {
        if(carros[i].nombre.empty() || carros[i].nombre == "")
        {
        cout << "Ingrese el nombre del vehiculo: " << endl << "-->";
        cin >> carros[i].nombre;
        cout << "Ingrese el chasis del vehiculo: " << endl << "-->";
        cin >> carros[i].chasis;
        do{
        cout << "Ingrese el anio del vehiculo: " << endl << "-->";
        cin >> carros[i].anio;
        carros[i].anio = cl(carros[i].anio);
        }while(carros[i].anio < 1);
        cout << "Ingrese el precio por dia de renta del vehiculo: " << endl << "-->";
        cin >> carros[i].precioPorDia;

        cout << "Desea agregar otro vehiculo? (1: si, 2: no) " << endl << "-->";
        do{
        cin >> mas;
        mas = cl(mas);
        }while(mas < 1 || mas > 2);

        if(mas == 2)
        {
          break;
        }
        }
        /*else
            {
                cout << "Espacio ocupado" << endl;
            }*/
    }
    cout << "Vehiculo/s agregado exitosamente" << endl;
}

int mostVehiRent()
{

        for(int i = 0; i < ncarr; i++)
        {

            if(!carrosRent[i].nombre.empty() || carrosRent[i].nombre != "")
            {
                cout << "Auto n " << i+1 << endl;
                cout << "Nombre del auto rentado: " << carrosRent[i].nombre << endl;
                cout << "Chasis del auto rentado: " << carrosRent[i].chasis << endl;
                cout << "Anio del auto rentado: " << carrosRent[i].anio << endl << endl;
                /*for(int j = 0; j < ncarr; j++)
                {
                    if(clientes[j].carroR == carrosRent[i].nombre)
                    {
                        cout << "Rentado por: " << clientes[j].nombre << endl;
                    }
                }*/
            }
        }
}

int mostcli()
{
    for(int i = 0; i < ncarr; i++)
        {
            if(!clientes[i].nombre.empty() || clientes[i].nombre != "")
            {
                cout << "Cliente n " << i+1 << endl;
                cout << "Nombre: " << clientes[i].nombre << endl;
                cout << "Apellido: " << clientes[i].apellido << endl;
                cout << "DUI: " << clientes[i].dui << endl;
                cout << "Licencia: " << clientes[i].licencia << endl;
                /*cout << "Carro rentado: " ;
                clientes[i].carroR.empty()? cout << "No a rentado ningun auto"  << endl << endl : cout << clientes[i].carroR << endl  << endl;
            */}
        }
}

int cl(int clear) //verifica si un dato erroneo fue ingresado y lo corrige
{
	if (cin.fail()) //si al ingresar los datos causo error entra al ciclo
    	{
			cin.clear(); // limpia la variable
        	cin.ignore(); // borra espacios y caracteres
        	cout << "El numero ingresado no es correcto, por favor intentelo nuevamente." << endl;
        	system("pause"); // pausa el programa hasta que el usuario desee

			clear = -1;
			/*asigna el valor de clear a -1, de esa forma los ciclos se repiten
        			si clear entra al if*/
    	}
    return clear;//retorna la variable ya revisada y/o corregida
}
