#include <iostream>
#include <string>
#include "linea.h"
#include "documento.h"
#include "utils.h"


void interfazMenuPrincipal()
{
    std::cout << "     ______    ____    __     ____    __  ___    ____     ____     ______ \n    / ____/   /  _/   / /    /  _/   /  |/  /   / __ )   / __ \   / ____/\n   / /_       / /    / /     / /    / /|_/ /   / __  |  / /_/ /  / __/   \n  / __/     _/ /    / /___ _/ /    / /  / /   / /_/ /  / _, _/  / /___   \n /_/       /___/   /_____//___/   /_/  /_/   /_____/  /_/ |_|  /_____/   \n";
    std::cout << "Bienvenido al Editor de Texto Filimbre, escoja una opcion: \n";
    std::cout << "1. Leer archivo\n";
    std::cout << "2. Mostrar archivo\n";
    std::cout << "3. Guardar archivo\n";
    std::cout << "4. Guardar archivo como\n";
    std::cout << "5. Lineas\n";
    std::cout << "6. Palabras\n";
    std::cout << "0. Salir\n";
}

bool siNo(){
    std::string opcion;
    bool terminar=false;
    do {
        std::getline(std::cin, opcion);
        if (opcion == "si" || opcion == "s"){
            return true;
        }
        else if (opcion == "no" || opcion == "n"){
        return false;
        }
        else{
            std::cout << "responda con si o no \n";
        }
    } while (!terminar);
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
        clear();
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
            clear();
            if (doc != nullptr){
                std::cout << "se va a borrar el archivo en RAM, quiere continuar? [si/no]: \n";
                if(siNo()){
                    std::cout << "indique el nombre del archivo: \n";
                    std::getline(std::cin, entrada);
                    doc = leerDocumento(("./../"+entrada));
                    std::getline(std::cin, entrada);
                }
                else{
                    break;
                }
            }
            else{
                std::cout << "indique el nombre del archivo: \n";
                std::getline(std::cin, entrada);
                doc = leerDocumento(("./../"+entrada));
                std::getline(std::cin, entrada);
                break;
            }

        case 2:
            clear();
            imprimirDocumento(doc);
            std::getline(std::cin, entrada);
            break;

        case 3:
            clear();
            break;

        case 4:
            clear();
            break;

        case 5:
            clear();
            break;

        case 6:
            clear();
            Documento *leerDocumento();
            break;

        default:
            clear();
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