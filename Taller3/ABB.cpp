#include "stdafx.h"
#include "ABB.h"
/*Constructor de la clase
*/
template<class N>
ABB<N>::ABB()
{	
	this->raiz = nullptr;
	this->actual = nullptr;
}
/*Metodo que retorna la raiz
*/
template<class N>
NodoABB<N>* ABB<N>::getRaiz()
{
	return this->raiz;
}
/*Metodo que agrega un dato si la raiz es nula, sino llama a otro metodo de la clase NodoABB
*/
template<class N>
void ABB<N>::agregarDato(N dato)
{	
	
	if (!this->raiz) {
		this->raiz = new NodoABB<N>(dato);
	}
	else {
		this->raiz->agregar(dato);
	}
}
/*Metodo que llama a otro metodo para imprimir por preorden
*/
template<class N>
void ABB<N>::preOrden()
{
	if (!this->raiz) {
		return;
	}
	this->raiz->preOrden();
}
/*Metodo que llama a otro metodo para imprimir por inorden
*/
template<class N>
void ABB<N>::inOrden()
{	
	if (!this->raiz) {
		return;
	}
	this->raiz->inOrden();
}
/*Metodo que llama a otro metodo para imprimir por posorden
*/
template<class N>
void ABB<N>::posOrden()
{	
	if (!this->raiz) {
		return;
	}
	this->raiz->posOrden();
}

/*Metodo que llama a otro metodo para vaciar el arbol
*/
template<class N>
void ABB<N>::vaciar()
{
	if (this->raiz) {
		this->raiz->vaciar();
	}
	delete this->raiz;
	this->raiz = nullptr;
}
/*Metodo que imprime el arbol con la raiz lo mas a la izquierda y desde ahi se genera un "arbol"
*/
template<class N>
void ABB<N>::imprimirNiveles(NodoABB<N>* raiz, int cero)
{
	if (!raiz) {
		return;
	}
	imprimirNiveles(raiz->getHijoDer(), cero + 1);
	for (int i = 0; i < cero; i++) {
		cout << "  ";
	}
	cout << raiz->getDato() << endl;
	imprimirNiveles(raiz->getHijoIzq(), cero + 1);

}
/*Metodo que elimina un dato dado por parametro
*/
template<class N>
void ABB<N>::eliminarDato(N dato)
{
	NodoABB<N>* padre = NULL;
	NodoABB<N>* nodo;
	N aux;

	this->actual = this->raiz;
	//Se busca el valor
	while (!vacio(this->actual)) {
		if (dato == this->actual->getDato()) {
			if (esHoja(this->actual)) {
				if (padre){//Comprobamos si tiene un padre
					if (padre->getHijoDer() == this->actual) {
						padre->setHijoDer(nullptr);
					}
					else if(padre->getHijoIzq() == this->actual){
						padre->setHijoIzq(nullptr);
					}
				}
				delete this->actual; //Borramos el nodo
				this->actual = NULL;
				cout << "Se elimino el dato del arbol" << endl;
				return;
			}
			else { //Llega aqui si el valor esta en un nodo no hoja
				padre = this->actual;

				if (this->actual->getHijoDer()) {
					nodo = this->actual->getHijoDer();
					while (nodo->getHijoIzq()) {
						padre = nodo;
						nodo = nodo->getHijoIzq();
					}
				}
				else {
					nodo = this->actual->getHijoIzq();
					while (nodo->getHijoDer()) {
						padre = nodo;
						nodo = nodo->getHijoDer();
					}
				}
				aux = this->actual->getDato();
				this->actual->setDato(nodo->getDato());
				nodo->setDato(aux);
				this->actual = nodo;
			}
		}
		else {
			padre = this->actual;
			if (dato > this->actual->getDato()) {
				this->actual = this->actual->getHijoDer();
			}
			else if(dato<this->actual->getDato()){
				this->actual = this->actual->getHijoIzq();
			}
		}
	}
	cout << "El valor no esta en el arbol" << endl; //Si no esta el nodo, mandamos un mensaje
}
/*Metodo que revisa si el nodo es null
*/
template<class N>
bool ABB<N>::vacio(NodoABB<N>* nodo)
{
	return nodo == NULL;
}
/*Metodo que revisa si el nodo es una hoja
*/
template<class N>
bool ABB<N>::esHoja(NodoABB<N>* nodo)
{
	return !nodo->getHijoDer() && !nodo->getHijoIzq();
}
/*Destructor de la clase
*/
template<class N>
ABB<N>::~ABB()
{
}
