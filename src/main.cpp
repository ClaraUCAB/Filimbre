#include <iostream>

#include "linea.h"
#include "documento.h"


int main() {
    // Documento *doc = leerDocumento("test.txt");
    Documento *doc = leerDocumento("nopor_furro.txt");
    imprimirDocumento(doc);
}


