#include "documento.h"
#include "linea.h"

int main() {
    // Documento *doc = leerDocumento("nopor_furro.txt");
    Documento *doc = leerDocumento("test.txt");
    imprimirDocumento(doc);

    Documento *d = doc;
    while (d) {
        eliminarPalabraPorValor(&d->linea, "los");
        d = d->prox;
    }

    imprimirDocumento(doc);
    escribirDocumento(doc, "test_modificado.txt");
}

