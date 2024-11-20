#include "interfaz.h"
#include "documento.h"
#include "linea.h"
#include "listas.h"
#include "utils.h"

#include <cctype>
#include <iostream>
#include <string>


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


void menuLeerArchivo(Documento **doc, std::string &ruta) {
    std::string entrada;

    if (*doc != nullptr) {
        std::cout << "El archivo actual se va a descartar. ¿Desea continuar? [Si/No]: ";
        if(!preguntarSiNo()) {
            return;
        }
    }

    std::cout << "Indique el nombre del archivo: ";
    std::getline(std::cin, entrada);

    *doc = leerDocumento(entrada);
    ruta = entrada;
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
        std::cout << "Indique el nuevo nombre del archivo: ";
        std::getline(std::cin, entrada);

        escribirDocumento(doc, entrada); 
        std::cout << "Archivo guardado exitosamente bajo el nuevo nombre.\n";
    } else {
        std::cout << "No hay documento cargado en memoria.\n";
    }
}


void menuLineas(Documento **doc) {
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
                submenuInsertarLinea(doc, linea);
                linea = nullptr;
                pause();
                clear();
                break;

            // Mover linea de una pos a otra
            case 3:
                submenuMoverLinea(doc);
                pause();
                clear();
                break;

            // Eliminar una linea
            case 4:
                submenuEliminarLinea(doc);
                pause();
                clear();
                break;

            default:
                clear();
                imprimirEnCuadro("Ingrese una opción válida");
                break;
        }
    }
}


Linea *submenuCrearLinea() {
    Linea *linea = nullptr;
    int cantidad = pedirEntero("Ingrese la cantidad de palabras: ");

    for (int i = 0; i < cantidad; i++) {
        std::string palabra;
        std::cin >> palabra;
        apendarPalabra(&linea, palabra);
    }

    return linea;
}


void submenuInsertarLinea(Documento **doc, Linea *linea) {
    if (lineaVacia(linea)) {
        std::cout << "Tiene que crear una linea primero." << std::endl;
        return;
    }

    int indice = pedirEntero("Ingrese el indice donde insertar: ");
    insertarLinea(doc, linea, indice);
    std::cout << "Línea insertada exitosamente." << std::endl;
}


void submenuMoverLinea(Documento **doc) {
    int nLineas = contarLineas(*doc);

    if (nLineas <= 1) {
        std::cout << "No hay nada que hacer." << std::endl;
        return;
    }

    int i = pedirEntero("Ingrese la línea que quiere mover: ") - 1;

    if (i < 0 || i >= nLineas) {
        std::cout << "La línea que quiere mover no existe." << std::endl;
        return;
    }

    int j = pedirEntero("Ingrese la posición de destino: ") - 1;

    if (j > nLineas) {
        std::cout << "La posición a la que quiere insertar no existe." << std::endl;
        return;
    }

    if (i == j) {
        std::cout << "El número de línea que quiere mover y la posición destino no pueden ser iguales." << std::endl;
        return;
    }

    moverLineaPorIndice(doc, i, j);
    std::cout << "Línea movida exitosamente." << std::endl;
}


void submenuEliminarLinea(Documento **doc) {
    if (documentoVacio(*doc)) {
        std::cout << "No hay nada que hacer." << std::endl;
        return;
    }

    int i = pedirEntero("Ingrese la línea que desea eliminar: ") - 1;

    //if (!buscarLineaPorIndice(*doc, i)) {     // Esto no funciona con líneas vacías ):
    if (i < 0 || i >= contarLineas(*doc)) {
        std::cout << "La línea que quiere eliminar no existe." << std::endl;
        return;
    }

    eliminarLineaPorIndice(doc, i);
    std::cout << "Línea eliminada exitosamente" << std::endl;
}


void menuPalabras(Documento **doc) {
    clear();

    int opcion = 1;
    while (opcion != 0){
        std::cout << "1- Buscar palabra \n";
        std::cout << "2- Eliminar palabra de una linea deseada \n";
        std::cout << "3- Modificar palabra de una linea deseada \n";
        std::cout << "4- Sustituir palabra de una linea deseada \n";
        std::cout << "0- Volver al menu anterior \n";
        std::cout << "\n";
        std::cout << "Elija una opcion \n";

        int opcion = pedirEntero(">>> ");
        std::cout << "\n";

        switch (opcion){
            // Salir
            case 0:
                return;

            // Buscar palabra
            case 1:
                submenuBuscarPalabra(*doc);
                pause();
                clear();
                break;

            // Eliminar palabra
            case 2:
                submenuEliminarPalabra(doc);
                pause();
                clear();
                break;

            // Modificar palabra
            case 3:
                submenuModificarPalabra(doc);
                pause();
                clear();
                break;

            // Sustituir palabra
            case 4:
                submenuSustituirPalabra(doc);
                pause();
                clear();
                break;

            default:
                clear();
                imprimirEnCuadro("Ingrese una opción válida");
                break;
        }
    }
}


void submenuBuscarPalabra(Documento *doc) {
    std::string palabra;
    std::cout << "Ingrese la palabra que desea buscar: ";
    std::getline(std::cin, palabra);

    Lista *lineas = buscarPalabraEnDocumento(doc, palabra);

    if (listaVacia(lineas)) {
        std::cout << "La palabra no aparece en ninguna parte del documento." << std::endl;
        return;
    }

    Lista *t = lineas;

    if (contarLista(lineas) == 1)
        std::cout << "La palabra aparece en la línea " << lineas->valor+1 << std::endl;

    else {
        std::cout << "La palabra aparece en las líneas ";

        while (t && t->prox->prox) {
            std::cout << t->valor+1 << ", ";
            t = t->prox;
        }

        std::cout << t->valor+1 << " y " << t->prox->valor+1 << ".";
    }
}


void submenuEliminarPalabra(Documento **doc) {
    std::string palabra;
    std::cout << "Ingrese la palabra que quiere eliminar: ";
    std::getline(std::cin, palabra);

    int nLinea = pedirEntero("Ingrese la línea en la que está: ")-1;
    Linea *linea = buscarLineaPorIndice(*doc, nLinea);

    if (lineaVacia(linea)) {
        std::cout << "Esa línea no existe o está vacía." << std::endl;
        return;
    }

    if (!existePalabra(linea, palabra)) {
        std::cout << "La palabra '" << palabra << "' no existe en la línea dada." << std::endl;
        return;
    }

    eliminarPalabraPorValor(&linea, palabra);
    std::cout << "Palabra eliminada exitosamente." << std::endl;
}


void submenuModificarPalabra(Documento **doc) {
    std::string palabra;
    std::cout << "Ingrese la palabra que quiere modificar: ";
    std::getline(std::cin, palabra);

    int nLinea = pedirEntero("Ingrese la línea en la que está: ")-1;
    Linea *linea = buscarLineaPorIndice(*doc, nLinea);

    if (lineaVacia(linea)) {
        std::cout << "Esa línea no existe o está vacía." << std::endl;
        return;
    }

    if (!existePalabra(linea, palabra)) {
        std::cout << "La palabra '" << palabra << "' no existe en la línea dada." << std::endl;
        return;
    }

    std::string nueva;
    std::cout << "Ingrese la nueva palabra: ";
    std::getline(std::cin, nueva);

    Linea *l = linea;
    while (l) {
        if (l->palabra == palabra) {
            l->palabra = nueva;
            return;
        }

        l = l->prox;
    }

    std::cout << "Palabra modificada exitosamente" << std::endl;
}


void submenuSustituirPalabra(Documento **doc) {
    std::string palabra;
    std::cout << "Ingrese la palabra que quiere sustituir: ";
    std::getline(std::cin, palabra);

    int nLinea = pedirEntero("Ingrese la línea en la que está: ")-1;
    Linea *linea = buscarLineaPorIndice(*doc, nLinea);

    if (lineaVacia(linea)) {
        std::cout << "Esa línea no existe o está vacía." << std::endl;
        return;
    }

    if (!existePalabra(linea, palabra)) {
        std::cout << "La palabra '" << palabra << "' no existe en la línea dada." << std::endl;
        return;
    }

    std::string nueva;
    std::cout << "Ingrese la nueva palabra: ";
    std::getline(std::cin, nueva);

    sustituirPalabra(&linea, palabra, nueva);
    std::cout << "Todas las ocurrencias de '" << palabra << "' sustituidas por '" << nueva << "' exitosamente." << std::endl;
}


bool preguntarSiNo() {
    std::string opcion;
    do {
        std::getline(std::cin, opcion);
        if (opcion == "si" || opcion == "s" || opcion == "Si" || opcion == "sI") {
            return true;
        }
        else if (opcion == "no" || opcion == "n" || opcion == "No" || opcion == "nO") {
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

