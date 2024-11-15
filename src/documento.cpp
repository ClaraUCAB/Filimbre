#include "documento.h"


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


int digitos(int n) {
    int d = 1;
    while ((n = n / 10) > 0) d++;
    return d;
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


Documento *leerDocumento(std::string ruta) {
    // Tratamos de abrir el archivo
    std::ifstream file(ruta);

    // Comprobamos si el archivo fue abierto exitosamente
    // Si no, devolvemos un documento vacio.
    if (!file.is_open())
        return nullptr;

    Documento *doc = nullptr;
    Linea **linea = nullptr;
    std::string palabra;
    
    while (std::getline(file, palabra)) {
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
            file.close();
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
    file.close();
    return doc;
}


void escribirDocumento(Documento *doc, std::string ruta) {
    // Tratamos de abrir el archivo
    std::ofstream file(ruta);

    // Comprobamos si el archivo fue abierto exitosamente
    if (!file.is_open())
        return;

    Documento *d = doc;
    while (d) {
        Linea *l = d->linea;

        while (l) {
            file << l->palabra << std::endl;
            l = l->prox;
        }

        file << "<fl>" << std::endl;
        d = d->prox;
    }

    file << "<fd>" << std::endl;
}


void imprimirDocumento(Documento *doc) {
    Documento *d = doc;
    int nLinea = 1;

    int margen = digitos(contarLineas(doc));

    while (d) {
        int m = margen - digitos(nLinea) + 1;
        imprimirLineaNumerada(d->linea, nLinea++, m);
        d = d->prox;
    }
}

