#include "documento.h"
#include "linea.h"

#include <iostream>

int main() {
    // Documento *doc = leerDocumento("nopor_furro.txt");
    Documento *doc = leerDocumento("test.txt");
    imprimirDocumento(doc);

    Documento *d = doc;
    while (d) {
        eliminarPalabraPorValor(&d->linea, "se");
        d = d->prox;
    }

    std::cout << "\n--------------------------------------------\n" << std::endl;

    imprimirDocumento(doc);
    escribirDocumento(doc, "test_modificado.txt");
}

