#include "stdafx.h"
#include "Principal.h"
#include <ctime>


/*Este metodo es el que ejecuta el menu principal del programa
*/
void Principal::menuPrincipal() {

	bool menu = true;

	cout << "Bienvenido al menu principal" << endl;
	string opcion;
	while (menu) {  //While infinito que es usado para el menu principal

		cout << "Menu principal:" << endl;
		cout << "1.-Imprimir Arboles\n2.-Modificar Arboles\n3.-Configuracion\n4.-Salir" << endl;
		cin >> opcion;
		try
		{
			std::stoi(opcion);
		}
		catch (const std::exception&)
		{
			cout << "Error,no escribio un numero" << endl;
			continue;
		}
		int opcionDef = std::stoi(opcion);

		switch (opcionDef) //Menu
		{
		case 1:
			subMenu1();
			break;
		case 2:
			subMenu2();
			break;
		case 3:
			configuracion();

			break;
		case 4:
			cout << "Adios, Buena suerte!" << endl;
			return;
		default:
			cout << "Error, ingrese una opcion valida porfavor" << endl;
			break;
		}

	}
}
/*Metodo que ejectuta el submenu de imprimir arboles
*/
void Principal::subMenu1() {
	bool menu = true;
	clock_t inicio;
	long duracion;
	cout << "Usted escogio imprimir arboles..." << endl;
	string opcion;
	while (menu) { //While infinito que sera usado para el submenu

		cout << "Como quiere usted imprimir su arbol?" << endl;
		cout << "1.-Pre-Orden\n2.-In-Orden\n3.-Post-Orden\n4.-Por Nivel\n5.-Volver" << endl;
		cin >> opcion;
		try
		{
			std::stoi(opcion);
		}
		catch (const std::exception&)
		{
			cout << "Error,no escribio un numero" << endl;
			continue;
		}
		int opcionDef = std::stoi(opcion);

		switch (opcionDef) //Menu
		{
		case 1:		//Imprime en preorden, dependiendo del tipo de arbol
			cout << "ABB:" << endl;
			
			if (tipo == "int") {
				inicio = clock();
				abbInt->preOrden();
				duracion = clock() - inicio;
				cout << "Tiempo de impresion del arbol ABB: " << duracion << " unidades de tiempo" << endl;
			}
			if (tipo == "string") {
				inicio = clock();
				abbString->preOrden();
				duracion = clock() - inicio;
				cout << "Tiempo de impresion del arbol ABB: " << duracion << " unidades de tiempo" << endl;
			}
			if (tipo == "double") {
				inicio = clock();
				abbDouble->preOrden();
				duracion = clock() - inicio;
				cout << "Tiempo de impresion del arbol ABB: " << duracion << " unidades de tiempo" << endl;
			}

			break;
		case 2:			//Imprime en inorden, dependiendo del tipo de arbol
			cout << "ABB:" << endl;
			if (tipo == "int") {
				inicio = clock();
				abbInt->inOrden();
				duracion = clock() - inicio;
				cout << "Tiempo de impresion del arbol ABB: " << duracion << " unidades de tiempo" << endl;
			}
			if (tipo == "string") {
				inicio = clock();
				abbString->inOrden();
				duracion = clock() - inicio;
				cout << "Tiempo de impresion del arbol ABB: " << duracion << " unidades de tiempo" << endl;
			}
			if (tipo == "double") {
				inicio = clock();
				abbDouble->inOrden();
				duracion = clock() - inicio;
				cout << "Tiempo de impresion del arbol ABB: " << duracion << " unidades de tiempo" << endl;
			}
			break;
		case 3:			//Imprime en posorden, dependiendo del tipo de arbol
			cout << "ABB:" << endl;
			if (tipo == "int") {
				inicio = clock();
				abbInt->posOrden();
				duracion = clock() - inicio;
				cout << "Tiempo de impresion del arbol ABB: " << duracion << " unidades de tiempo" << endl;
			}
			if (tipo == "string") {
				inicio = clock();
				abbString->posOrden();
				duracion = clock() - inicio;
				cout << "Tiempo de impresion del arbol ABB: " << duracion << " unidades de tiempo" << endl;
			}
			if (tipo == "double") {
				inicio = clock();
				abbDouble->posOrden();
				duracion = clock() - inicio;
				cout << "Tiempo de impresion del arbol ABB: " << duracion << " unidades de tiempo" << endl;
			}
			break;
		case 4:			//Imprime en por nivel, dependiendo del tipo de arbol
			cout << "ABB:" << endl;
			if (tipo == "int") {
				inicio = clock();
				abbInt->imprimirNiveles(abbInt->getRaiz(), 0);
				duracion = clock() - inicio;
				cout << "Tiempo de impresion del arbol ABB: " << duracion << " unidades de tiempo" << endl;
			}
			if (tipo == "string") {
				inicio = clock();
				abbString->imprimirNiveles(abbString->getRaiz(), 0);
				duracion = clock() - inicio;
				cout << "Tiempo de impresion del arbol ABB: " << duracion << " unidades de tiempo" << endl;
			}
			if (tipo == "double") {
				inicio = clock();
				abbDouble->imprimirNiveles(abbDouble->getRaiz(), 0);
				duracion = clock() - inicio;
				cout << "Tiempo de impresion del arbol ABB: " << duracion << " unidades de tiempo" << endl;
			}
			
			break;
		case 5:
			cout << "Volviendo..." << endl;
			return;
		default:
			cout << "Error, ingrese una opcion valida porfavor" << endl;
			break;
		}

	}
}
/*Metodo que ejectuta el submenu de modificacion de arboles
*/
void Principal::subMenu2() {
	bool menu = true;
	cout << "Usted escogio modificar arboles..." << endl;
	string opcion;
	while (menu) { //While infinito que sera usado para el submenu

		cout << "Desea agregar, eliminar o vaciar el arbol?" << endl;
		cout << "1.-Agregar nodo\n2.-Eliminar nodo\n3.-Vaciar arboles\n4.-Volver" << endl;
		cin >> opcion;
		try
		{
			std::stoi(opcion);
		}
		catch (const std::exception&)
		{
			cout << "Error,no escribio un numero" << endl;
			continue;
		}
		int opcionDef = std::stoi(opcion);

		switch (opcionDef) //Menu
		{
		case 1:
			agregarDatos();

			break;
		case 2:
			eliminarDatos();

			break;
		case 3:
			abbInt->vaciar();
			abbDouble->vaciar();
			abbString->vaciar();
			cout << "Se han vaciado los arboles" << endl;
			break;
		case 4:
			cout << "Volviendo..." << endl;
			return;
		default:
			cout << "Error, ingrese una opcion valida porfavor" << endl;
			break;
		}
	
	}
}
/*Metodo que le pregunta al usuario que dato quiere agregar dependiendo del tipo de arbol
*/
void Principal::agregarDatos()
{	
	if (tipo == "int") {
		int opcion;
		cout << "Ingrese el dato que quiere agregar" << endl;
		cin >> (opcion);
		abbInt->agregarDato(opcion);
	}
	if (tipo == "string") {
		string opcion2;
		cout << "Ingrese el dato que quiere agregar" << endl;
		cin >> (opcion2);
		abbString->agregarDato(opcion2);
	}
	if (tipo == "double") {
		double opcion3;
		cout << "Ingrese el dato que quiere agregar" << endl;
		cin >> (opcion3);
		abbDouble->agregarDato(opcion3);
	}
	
	
}
/*Metodo que configura el tipo de dato de los arboles, cambiando este y vaciando los arboles cuando se cambian
*/
void Principal::configuracion()
{
	bool menu = true;
	cout << "Usted escogio configuracion" << endl;
	string opcion;
	while (menu) { //While infinito que sera usado para el submenu

		cout << "Que tipo de dato desea para los arboles?" << endl;
		cout << "1.-Int\n2.-Double\n3.-String\n4.-Volver" << endl;
		cin >> opcion;
		try
		{
			std::stoi(opcion);
		}
		catch (const std::exception&)
		{
			cout << "Error,no escribio un numero" << endl;
			continue;
		}
		int opcionDef = std::stoi(opcion);

		switch (opcionDef) //Menu
		{
		case 1:
			tipo = "int";
			abbInt->vaciar();
			abbDouble->vaciar();
			abbString->vaciar();
			cout << "Se a cambiado el tipo de datos de los arboles a enteros, ademas se han vaciado los arboles" << endl;

			break;
		case 2:
			tipo = "double";
			abbInt->vaciar();
			abbDouble->vaciar();
			abbString->vaciar();
			cout << "Se a cambiado el tipo de datos de los arboles a double, ademas se han vaciado los arboles" << endl;

			break;
		case 3:
			tipo = "string";
			abbInt->vaciar();
			abbDouble->vaciar();
			abbString->vaciar();
			cout << "Se a cambiado el tipo de datos de los arboles a strings, ademas se han vaciado los arboles" << endl;

			break;
		case 4:
			cout << "Volviendo..." << endl;
			return;
		default:
			cout << "Error, ingrese una opcion valida porfavor" << endl;
			break;
		}

	}
}
/*Metodo que lee el archivo .txt entregado
*/
void Principal::leerDatos()
{
	bool saber = false;
	ifstream archivo("datos.txt"); //Se abre el archivo que queremos leer
	string linea = "";
	while (!archivo.eof()) {
		getline(archivo, linea);
		string auxDato = "";
		int dato = 0;
		double datoDoble = 0;
		istringstream is(linea);
		getline(is, auxDato);
		try
		{	
			for (int i = 0; i < auxDato.length(); i++) {
				if (auxDato.at(i) == '.') {
					datoDoble = stod(auxDato);
					abbDouble->agregarDato(datoDoble);  //Se agrega el doble al arbol
					tipo = "double";
					saber = true;
					break;
				}
			}
			if (saber == true) { //si fue doble se reinicia el while hasta terminar de leer el archivo
				continue;
			}
			dato = stoi(auxDato);
			abbInt->agregarDato(dato);//Se agrega al arbol el dato entero si esque no va al catch
			tipo = "int";
			continue;
		}
		catch (const std::exception&)
		{
			abbString->agregarDato(auxDato); //se agrega en el arbol el string
			tipo = "string";
			continue;
			
		}
		
		
	}
	
	archivo.close();
}
/*Metodo que pregunta  el dato a eliminar, si no esta en el arbol da mensaje de que no esta
*/
void Principal::eliminarDatos()
{
	if (tipo == "int") {
		int opcion;
		cout << "Ingrese el dato que quiere eliminar" << endl;
		cin >> (opcion);
		abbInt->eliminarDato(opcion);
	}
	if (tipo == "string") {
		string opcion2;
		cout << "Ingrese el dato que quiere eliminar" << endl;
		cin >> (opcion2);
		abbString->eliminarDato(opcion2);
	}
	if (tipo == "double") {
		double opcion3;
		cout << "Ingrese el dato que quiere eliminar" << endl;
		cin >> (opcion3);
		abbDouble->eliminarDato(opcion3);
	}
}
/*Constructor de la clase
*/
Principal::Principal()
{
	leerDatos();
	menuPrincipal();
}

/*Destructor de la clase
*/
Principal::~Principal()
{
}
