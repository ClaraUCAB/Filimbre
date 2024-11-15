#include <iostream>

#include "linea.h"
#include "documento.h"
#include "listas.h"


int main() {
    // Documento *doc = leerDocumento("test.txt");
    Documento *doc = leerDocumento("nopor_furro.txt");
    imprimirDocumento(doc);

    std::cout << "hola diefo, no quieres teta?";
}


