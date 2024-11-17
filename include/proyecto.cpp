#include "documento.h"
#include "linea.h"
#include "listas.h"
#include <iostream>
#include <string>

void interfazMenuPrincipal() {
  std::cout << "Bienvenido al Editor de Texto Filimbre, escoja una opcion: \n";
  std::cout << "1. Leer archivo\n";
  std::cout << "2. Mostrar archivo\n";
  std::cout << "3. Guardar archivo\n";
  std::cout << "4. Guardar archivo como\n";
  std::cout << "5. Lineas\n";
  std::cout << "6. Palabras\n";
}



int main() {
  int opcion;
  interfazMenuPrincipal();
  std::cin >> opcion;

}
