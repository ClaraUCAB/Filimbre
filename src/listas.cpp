#include "listas.h"
#include <iostream>


// Inserta X al comienzo de la lista P
void insertarEnCabeza(Lista **p, int x) {
    Lista *t = new Lista;
    t->valor = x;

    t->prox = *p;
	*p = t;
}


// Inserta X al final de la lista P
void insertarEnCola(Lista *p, int x) {
    Lista *aux = p;

    Lista *t = new Lista;
    t->valor = x;
    t->prox = nullptr;

    // Cubrimos el caso de una lista vacia
    if (!aux) insertarEnCabeza(&p, x);

    // Vamos al penúltimo elemento de la lista
    else while (aux->prox) aux = aux->prox;

    aux->prox = t;
}


void buscarPorValor(Lista *p, int x) {

}


void buscarPorIndice(Lista *p, int n) {

}


// Elimina el elemento por dado por un índice N
void eliminarPorIndice(Lista **p, int n) {
    Lista *t = *p;

    while (t && n-->0) t = t->prox;
    if (!t) return;
}


// Elimina un elemento de la lista P dado un puntero K
void eliminarNodo(Lista **p, Lista *k) {
    Lista *t = *p;

    // TODO: Finish this
}


void imprimirLista(Lista *p){
	Lista *t = p;

	while (t) {
        std::cout << "->[" << t->valor << "]";
	    t = t->prox;
	}

    std::cout << "->NULL" << std::endl;
}

