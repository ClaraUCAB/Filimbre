#include <iostream>
#include <string>
#include "linea.h"
#include "documento.h"

void interfazMenuPrincipal()
{
    std::cout << "Bienvenido al Editor de Texto Filimbre, escoja una opcion: \n";
    std::cout << "1. Leer archivo\n";
    std::cout << "2. Mostrar archivo\n";
    std::cout << "3. Guardar archivo\n";
    std::cout << "4. Guardar archivo como\n";
    std::cout << "5. Lineas\n";
    std::cout << "6. Palabras\n";
    std::cout << "0. Salir\n";
}

int pedirEntero(const std::string &pregunta)
{
    int numero = 0;
    bool termino = false;
    std::string entrada;
    std::cout << pregunta;

    do
    {
        std::getline(std::cin, entrada);
        try
        {
            numero = std::stoi(entrada);
            termino = true;
        }
        catch (const std::exception &e)
        {
            std::cerr << "ingrese un numero entero:" << std::endl;
            termino = false;
        }
        /* code */
    } while (!termino);
    return numero;
}

int main()
{
    int opcion = 1;
    std::string entrada;
    Documento *doc;
    do
    {
        system("clear");
        interfazMenuPrincipal();
        opcion = pedirEntero("");
        switch (opcion)
        {
        case 0:
            std::cout << "Gracias por usar Filimbre IDE, bye bye!"<<std::endl;
            std::getline(std::cin, entrada);
            std::exit(0);
            break;

        case 1:
            // leer el documento y si no existe abre uno en blanco.
            
            doc = leerDocumento("prueba.txt");
            imprimirDocumento(doc);
            break;

        case 2:
            break;

        case 3:
            break;

        case 4:
            break;

        case 5:
            break;

        case 6:
            
            Documento *leerDocumento();
            break;

        default:

            std::cout << "Ingrese una opcion valida\n";
            break;
        }
    } while (opcion != 0);
}

/*int main() {
    // Documento *doc = leerDocumento("test.txt");
    Documento *doc = leerDocumento("nopor_furro.txt");
    imprimirDocumento(doc);
} */