#pragma once
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
#include <iostream>
#include "ABB.h"
#include "ABB.cpp"
#include "NodoABB.h"
#include "NodoABB.cpp"
class Principal
{
public:
	void menuPrincipal();
	void subMenu1();
	void subMenu2();
	void agregarDatos();
	string tipo = "";
	void configuracion();
	void leerDatos();
	void eliminarDatos();
	Principal();
	~Principal();
private:
	ABB<int>* abbInt = new ABB<int>;
	ABB<string>* abbString = new ABB<string>;
	ABB<double>* abbDouble = new ABB<double>;
};

