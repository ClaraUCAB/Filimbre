#include <iostream>

#include "linea.h"
#include "documento.h"
#include "listas.h"
#include "utils.h"


int main() {
    clear();
    std::string name;
    std::cout << "Hello, what is your name?" << std::endl;
    std::cout << ">>> ";
    std::cin >> name;
    clear();

    std::cout << "Hello, " << name << "." << std::endl;
    pause();

    return 0;

    // Documento *doc = leerDocumento("nopor_furro.txt");
    Documento *doc = leerDocumento("test.txt");
    Documento *d;
    imprimirDocumento(doc);

    d = doc;
    eliminarPalabraPorValor(&d->linea, "los");

    d = doc;
    eliminarPalabraPorIndice(&d->prox->prox->prox->linea, 120);

    std::cout << "\n------------------------------------------------------\n";
    std::cout << std::endl;

    imprimirDocumento(doc);
    escribirDocumento(doc, "guardar_como.txt");
}


