#pragma once
#include <iostream>
#include <queue>
using namespace std;

template <class N>
class NodoABB
{
public:
	NodoABB();
	NodoABB(N dato);
	NodoABB<N>* getHijoIzq();
	NodoABB<N>* getHijoDer();
	N getDato();
	void setHijoIzq(NodoABB<N>* hijoIzquierdo);
	void setHijoDer(NodoABB<N>* hijoDerecho);
	void setDato(N dato);
	void agregar(N dato);
	void preOrden();
	void inOrden();
	void posOrden();
	void vaciar();
	N mayor(N a, N b);
	~NodoABB();
private:
	N dato;
	NodoABB<N>* hijoDer;
	NodoABB<N>* hijoIzq;
};

