#include "stdafx.h"
#include "NodoABB.h"
/*Constructor vacio de la clase
*/
template <class N>
NodoABB<N>::NodoABB()
{
}
/*Constructor de la clase
*/
template<class N>
NodoABB<N>::NodoABB(N dato)
{
	this->dato = dato;
	this->hijoIzq = nullptr;
	this->hijoDer = nullptr;

}
/*Metodo que retorna el hijo izquierdo
*/
template<class N>
NodoABB<N>* NodoABB<N>::getHijoIzq()
{
	return this->hijoIzq;
}
/*Metodo que retorna el hijo derecho
*/
template<class N>
NodoABB<N>* NodoABB<N>::getHijoDer()
{
	return this->hijoDer;
}
/*Metodo que retorna el dato del nodo
*/
template<class N>
N NodoABB<N>::getDato()
{
	return this->dato;
}
/*Metodo que cambia al hijo izquierdo por el dado por parametro
*/
template<class N>
void NodoABB<N>::setHijoIzq(NodoABB<N>* hijoIzquierdo)
{	
	this->hijoIzq = hijoIzquierdo;
	return;
}
/*Metodo que cambia al hijo derecho por el dado por parametro
*/
template<class N>
void NodoABB<N>::setHijoDer(NodoABB<N>* hijoDerecho)
{	
	this->hijoDer = hijoDerecho;
	return;
}
/*Metodo que cambia al dato del nodo por el dado por parametro
*/
template<class N>
void NodoABB<N>::setDato(N dato)
{
	this->dato = dato;
	return;
}
/*Agrega un dato al arbol
*/
template<class N>
void NodoABB<N>::agregar(N dato)
{	
	if (dato == this->dato) {
		cout << "El dato ya existe." << endl;
		return;
	}
	if (dato > this->dato) {
		if (this->hijoDer) {
			this->hijoDer->agregar(dato);
		}
		else {
			this->hijoDer = new NodoABB<N>(dato);
			cout << "Se agrego el dato al arbol" << endl;
		}
	}
	else {
		if (this->hijoIzq) {
			this->hijoIzq->agregar(dato);
		}
		else {
			this->hijoIzq = new NodoABB<N>(dato);
			cout << "Se agrego el dato al arbol" << endl;
		}
	}
}
/*Metodo que imprime en preorden
*/
template<class N>
void NodoABB<N>::preOrden()
{
	cout << dato << endl;
	if (this->hijoIzq) {
		this->hijoIzq->preOrden();
	}
	if (this->hijoDer) {
		this->hijoDer->preOrden();
	}

}
/*Metodo que imprime en inorden
*/
template<class N>
void NodoABB<N>::inOrden()
{
	if (this->hijoIzq) {
		this->hijoIzq->inOrden();
	}
	cout << dato << endl;

	if (this->hijoDer) {
		this->hijoDer->inOrden();
	}
}
/*Metodo que imprime en posorden
*/
template<class N>
void NodoABB<N>::posOrden()
{	
	if (this->hijoIzq) {
		this->hijoIzq->posOrden();
	}
	if (this->hijoDer) {
		this->hijoDer->posOrden();
	}
	cout << dato << endl;
}

/*Metodo que vacia el arbol
*/
template<class N>
void NodoABB<N>::vaciar()
{
	if (this->hijoIzq) {
		this->hijoIzq->vaciar();
	}
	if (this->hijoDer) {
		this->hijoDer->vaciar();
	}
	delete this->hijoDer;
	delete this->hijoIzq;
}
/*Metodo que devuelve el mayor de los 2 parametros dados
*/
template<class N>
N NodoABB<N>::mayor(N a, N b)
{	
	if (a < b) {
		return b;
	}
	if (a > b) {
		return a;
	}
	return a;
}

/*Destructor de la clase
*/
template <class N>
NodoABB<N>::~NodoABB()
{
}
