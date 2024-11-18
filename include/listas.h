#ifndef LISTAS_H_
#define LISTAS_H_


struct Lista {
    int valor;
    Lista *prox;
};

void insertarEnCabeza(Lista **p, int x);
void insertarEnCola(Lista **p, int x);

void buscarPorValor(Lista *p, int x);
void buscarPorIndice(Lista *p, int n);

void eliminarPorIndice(Lista **p, int n);
void eliminarNodo(Lista **p, Lista *k);

void imprimirLista(Lista *p);


#endif  // LISTAS_H_
