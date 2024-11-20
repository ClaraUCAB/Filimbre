#include "interfaz.h"
#include "documento.h"
#include "linea.h"
#include "utils.h"

#include <iostream>


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


void imprimirEnCuadro(std::string mensaje) {
    int len = mensaje.length();

    std::cout << "┏";
    for (int i = 0; i < len; i++) std::cout << "━";
    std::cout << "┓\n";

    std::cout << "┃ " << mensaje << " ┃\n";

    std::cout << "┗";
    for (int i = 0; i < len; i++) std::cout << "━";
    std::cout << "┛\n";
}


void menuLeerArchivo(Documento **doc) {
    std::string entrada;

    if (*doc != nullptr) {
        std::cout << "se va a borrar el archivo en RAM, quiere continuar? [si/no]: \n";
        if(!preguntarSiNo()) {
            return;
        }
    }

    std::cout << "indique el nombre del archivo: ";
    std::getline(std::cin, entrada);

    *doc = leerDocumento(entrada);

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


void menuLineas(Documento *doc) {
    Linea *linea = nullptr;

    clear();

    while (true) {
        std::cout << "Linea: ";
        imprimirLinea(linea);
        std::cout << "\n";

        std::cout << "1- Crear nueva linea \n";
        std::cout << "2- Insertar linea en posicion deseada \n";
        std::cout << "3- Mover linea de una posicion a otra \n";
        std::cout << "4- Eliminar linea deseada \n";
        std::cout << "0- Volver al menu anterior \n";
        std::cout << "\n";
        std::cout << "Elija una opcion \n";

        int opcion = pedirEntero(">>> ");
        std::cout << "\n";

        switch (opcion) {
            // Salir
            case 0:
                return;

            // Crear linea
            case 1:
                linea = submenuCrearLinea();
                pause();
                clear();
                break;

            // Insertar linea nueva
            case 2:
                clear();
                submenuInsertarLinea(doc, linea);
                linea = nullptr;
                clear();
                break;

            // Mover linea de una pos a otra
                pause();
            case 3:
                clear();
                pause();
                break;

            // Eliminar una linea
            case 4:
                clear();
                pause();
                break;

            default:
                clear();
                imprimirEnCuadro("Ingrese una opción válida");
                break;
        }
    }
}

void menuPalabras(Documento *doc) {
    Linea *linea = nullptr;

    clear();

    while (true) {
        std::cout << "Linea: ";
        imprimirLinea(linea);
        std::cout << "\n";

        std::cout << "1- Buscar palabra \n";
        std::cout << "2- Eliminar palabra de una linea deseada \n";
        std::cout << "3- Modificar palabra de una linea deseada \n";
        std::cout << "4- Sustituir palabra de una linea deseada \n";
        std::cout << "0- Volver al menu anterior \n";
        std::cout << "\n";
        std::cout << "Elija una opcion \n";

        int opcion = pedirEntero(">>> ");
        std::cout << "\n";

        switch (opcion) {
            // Salir
            case 0:
                return;

            // Imprimir lineas donde aparece una palabra
            case 1:
                pause();
                clear();
                break;

            // Insertar linea nueva
            case 2:
                clear();
                submenuInsertarLinea(doc, linea);
                linea = nullptr;
                clear();
                break;

            // Mover linea de una pos a otra
                pause();
            case 3:
                clear();
                pause();
                break;

            // Eliminar una linea
            case 4:
                clear();
                pause();
                break;

            default:
                clear();
                imprimirEnCuadro("Ingrese una opción válida");
                break;
        }
    }
}


Linea *submenuCrearLinea() {
    Linea *linea = new Linea;
    int cantidad = pedirEntero("Ingrese la cantidad de palabras: ");

    for (int i = 0; i < cantidad; i++) {
        std::string palabra;
        std::cin >> palabra;
        apendarPalabra(&linea, palabra);
    }

    return linea;
}


void submenuInsertarLinea(Documento *doc, Linea *linea) {
    if (!linea) {
        std::cout << "Tiene que crear una linea primero." << std::endl;
        pause();
        return;
    }

    int indice = pedirEntero("Ingrese el indice donde insertar: ");
    insertarLinea(&doc, linea, indice);
}


void submenuMoverLinea(Linea *linea, int i, int j) {

}


void submenuEliminarLinea(Linea *linea, int i) {

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
    std::cout << std::flush;
    
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


