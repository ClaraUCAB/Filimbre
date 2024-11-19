#include "interfaz.h"
#include "documento.h"


void imprimirMenuPrincipal() {
    std::cout << "     ______    ____    __     ____    __  ___    ____     ____     ______ \n    / ____/   /  _/   / /    /  _/   /  |/  /   / __ )   / __ \\   / ____/\n   / /_       / /    / /     / /    / /|_/ /   / __  |  / /_/ /  / __/   \n  / __/     _/ /    / /___ _/ /    / /  / /   / /_/ /  / _, _/  / /___   \n /_/       /___/   /_____//___/   /_/  /_/   /_____/  /_/ |_|  /_____/   \n";
    std::cout << "\n";
    std::cout << "Bienvenido al Editor de Texto Filimbre, escoja una opcion: \n";
    std::cout << "\n";
    std::cout << "1. Leer archivo\n";
    std::cout << "2. Mostrar archivo\n";
    std::cout << "3. Guardar archivo\n";
    std::cout << "4. Guardar archivo como\n";
    std::cout << "5. Lineas\n";
    std::cout << "6. Palabras\n";
    std::cout << "0. Salir\n";
}


void menuLeerArchivo() {

}


void menuGuardarArchivo(Documento *doc, std::string nombreArchivo) {
    if (doc != nullptr) {
        escribirDocumento(doc, nombreArchivo);

        std::cout << "Archivo guardado exitosamente.\n";
    } else {
        std::cout << "No hay documento cargado en memoria.\n";
    }
}


void menuGuardarArchivoComo(Documento *doc) {
    std::string entrada;

    if (doc != nullptr) {
        std::cout << "Indique el nuevo nombre del archivo: \n";
        std::getline(std::cin, entrada);

        escribirDocumento(doc, entrada); 
        std::cout << "Archivo guardado exitosamente bajo el nuevo nombre.\n";
    } else {
        std::cout << "No hay documento cargado en memoria.\n";
    }
}


void menuLineas() {
    std::cout << "1- Crear nueva linea \n";
    std::cout << "2- Insertar linea en posicion deseada \n";
    std::cout << "3- Mover linea de una posicion a otra \n";
    std::cout << "4- Eliminar linea deseada \n";
    std::cout << "0- Volver al menu anterior \n";
    std::cout << "\n";
    std::cout << "Elija una opcion \n";
    std::cout << "\n";
}


void menuPalabras(){
    std::cout << "1- Buscar palabra \n";
    std::cout << "2- Eliminar palabra de una linea deseada \n";
    std::cout << "3- Modificar palabra de una linea deseada \n";
    std::cout << "4- Sustituir palabra de una linea deseada \n";
    std::cout << "0- Volver al menu anterior \n";
    std::cout << "\n";
    std::cout << "Elija una opcion \n";
    std::cout << "\n";
}


bool preguntarSiNo() {
    std::string opcion;
    do {
        std::getline(std::cin, opcion);
        if (opcion == "si" || opcion == "s") {
            return true;
        }
        else if (opcion == "no" || opcion == "n") {
            return false;
        }
        else {
            std::cout << "responda con si o no \n";
        }
    } while (true);
}


int pedirEntero(const std::string &pregunta) {
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

