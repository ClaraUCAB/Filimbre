#include "documento.h"
#include "linea.h"
#include "utils.h"

#include <iostream>


bool documentoVacio(Documento *doc) {
    return doc == nullptr;
}


int contarLineas(Documento *doc) {
    Documento *d = doc;
    int lineas = 0;

    while (d) {
        lineas++;
        d = d->prox;
    }

    return lineas;
}


// Esta función busca una palabra en cada linea
Lista *buscarPalabraEnDocumento(Documento *doc, std::string palabra) {
    Lista *lineas = nullptr;
    Documento *d = doc;
    int indice = 0;

    while (d) {
        Linea *l = d->linea;

        if (existePalabra(l, palabra)) {
            insertarEnCola(&lineas, indice);
        }

        indice++;
        d = d->prox;
    }

    return lineas;
}


Linea *buscarLineaPorIndice(Documento *doc, int i) {
    if (!doc)
        return nullptr;

    if (i < 0)
        return nullptr;

    Documento *d = doc;
    int j = 0;

    while (d && j++ < i) d = d->prox;
    return j > i ? d->linea : nullptr;
}


void insertarLinea(Documento **doc, Linea *linea, int n) {
    if (!doc || n < 0 || n-1 > contarLineas(*doc)) {
        apendarLinea(doc, linea);
        return;
    }

    Documento *nuevoDoc = new Documento;
    nuevoDoc->linea = linea;

    if (n == 0) {
        // Insertamos por cabeza
        nuevoDoc->prox = *doc;
        *doc = nuevoDoc;
        return;
    }

    Documento *d = *doc, *aux;
    int i = 2;

    while (d->prox && i++ < n) d = d->prox;
    aux = d->prox;
    d->prox = nuevoDoc;
    nuevoDoc->prox = aux;
}


void apendarLinea(Documento **doc, Linea *linea) {
    Documento *nuevoDoc = new Documento;
    nuevoDoc->linea = linea;
    nuevoDoc->prox = nullptr;

    if (documentoVacio(*doc)) {
        *doc = nuevoDoc;
        return;
    }

    Documento *d = *doc;
    while (d->prox) d = d->prox;
    d->prox = nuevoDoc;
}


void eliminarLinea(Documento **doc, Linea *linea) {
    Documento *d = *doc;
    int i = 0;

    while (d) {
        if (d->linea == linea) {
            eliminarLineaPorIndice(doc, i);
            return;
        }

        i++;
    }
}


void eliminarLineaPorIndice(Documento **doc, int n) {
    if (documentoVacio(*doc))
        return;

    Documento *d = *doc, *aux;

    if (n == 0) {
        *doc = d->prox;
        delete d;
        return;
    }

    // Nos paramos en el elemento
    // antes del que queremos borrar
    while (d->prox && n-->1) d = d->prox;

    if (n == 0) {
        aux = d->prox;
        d->prox = aux->prox;
        delete aux;
    }
}


void vaciarDocumento(Documento **doc) {
    Documento *d = *doc;

    while (d) {
        *doc = d->prox;
        delete d;
        d = *doc;
    }
}


void moverLineaPorIndice(Documento **doc, int i, int j) {
    Linea *linea = buscarLineaPorIndice(*doc, i);

    // if (lineaVacia(linea))
    if (i < 0 || i >= contarLineas(*doc))
        return;

    Documento *d = *doc, *aux;

    if (i == 0) {
        *doc = d->prox;
        insertarLinea(doc, linea, ++j);
        delete d;
        return;
    }

    // Nos paramos en el indice antes
    for (int a = 0; a < i-1; a++)
        d = d->prox;

    aux = d->prox;
    d->prox = aux->prox;
    delete aux;

    insertarLinea(doc, linea, ++j);
}


Documento *leerDocumento(std::string ruta) {
    // Tratamos de abrir el archivo
    FILE *fp = fopen(ruta.c_str(), "r");

    // Comprobamos si el archivo fue abierto exitosamente
    // Si no, devolvemos un documento vacio.
    if (!fp)
        return nullptr;

    // HACK: Encontrar una mejor manera de hacer esto
    Documento *doc = nullptr;
    Linea **linea = nullptr;
    // std::string palabra;
    char buffer[9999];
    std::string palabra;
    
    while (fgets(buffer, 9999, fp)) {
        // Convertimos la linea en un std::string
        // También la limpiamos
        palabra = buffer;
        palabra = palabra.substr(0, palabra.find("\n"));

        // Fin de linea
        if (palabra == "<fl>") {
            // Apendamos la linea como está al
            // documento e iniciamos una nueva
            apendarLinea(&doc, linea ? *linea : nullptr);
            linea = nullptr;
        }

        // Fin del documento
        else if (palabra == "<fd>") {
            // Devolvemos el documento tal como está
            fclose(fp);
            return doc;
        }

        // Palabra normal
        else {
            // Comprobamos si estamos trabajando en una
            // nueva linea o en una ya existente
            if (linea == nullptr) {
                // Creamos una nueva linea
                Linea *temp = nullptr;
                linea = &temp;
            }

            // Apendamos la palabra a la linea actual
            apendarPalabra(linea, palabra);
        }
    }

    // Por si acaso el archivo no contiene un <fd>
    fclose(fp);
    return doc;
}


void escribirDocumento(Documento *doc, std::string ruta) {
    // Tratamos de abrir el archivo
    FILE *fp = fopen(ruta.c_str(), "w");

    // Comprobamos si el archivo fue abierto exitosamente
    if (!fp)
        return;

    Documento *d = doc;
    while (d) {
        Linea *l = d->linea;

        while (l) {
            fputs(l->palabra.c_str(), fp);
            fputs("\n", fp);
            l = l->prox;
        }

        fputs("<fl>\n", fp);
        d = d->prox;
    }

    fputs("<fd>\n", fp);
    fclose(fp);
}


void imprimirDocumento(Documento *doc) {
    Documento *d = doc;
    int nLinea = 1;

    int margen = digitos(contarLineas(doc));

    while (d) {
        if (nLinea % 26 == 0) {
            pause();
            std::cout << std::endl;
        }

        int m = margen - digitos(nLinea) + 1;
        imprimirLineaNumerada(d->linea, nLinea++, m);
        d = d->prox;
    }
}

