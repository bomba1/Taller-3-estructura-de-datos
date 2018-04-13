#pragma once
#include "NodoABB.h"
template <class N>
class ABB
{
public:
	ABB();
	NodoABB<N>* getRaiz();
	void agregarDato(N dato);
	void preOrden();
	void inOrden();
	void posOrden();
	void vaciar();
	void imprimirNiveles(NodoABB<N>* raiz,int cero);
	void eliminarDato(N dato);
	bool vacio(NodoABB<N>* nodo);
	bool esHoja(NodoABB<N>* nodo);
	~ABB();
private:
	NodoABB<N>* raiz;
	NodoABB<N>* actual;
};

