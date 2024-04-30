#include "faq.h"

void UsuarioNoIdentificadoFAQ() {
  int opcion;
  while (opcion != 0) {
    std::cout << "\nElija el tema sobre el que desee consultar:\n"
              << "(0) Salir\n"
              << "(1) Registrarse 👤\n"
              << "(2) Libros 📚\n"
              << "(3) Eventos 📅\n"
              << "(4) Foro 🗣️";
    std::cout << std::endl;
    std::cin >> opcion;
    switch(opcion) {
      case 0:
        system("clear");
        return;
        break;
      case 1:
        system("clear");
        break;
      case 2:
        system("clear");
        break;
      case 3:
        system("clear");
        break;
      case 4:
        system("clear");
        break;
      default:
        system("clear");
        std::cout << "Ha introducido una opción no válida" << std::endl;
    }
  }
}


void UsuarioIdentificadoFAQ(Usuario&) {
    int opcion;
  while (opcion != 0) {
    std::cout << "\nElija el tema sobre el que desee consultar:\n"
              << "(0) Salir\n"
              << "(1) Libros 📚\n"
              << "(2) Aulas de estudio\n"              
              << "(3) Eventos 📅\n"
              << "(4) Foro 🗣️";
    std::cout << std::endl;
    std::cin >> opcion;
    switch(opcion) {
      case 0:
        system("clear");
        return;
        break;
      case 1:
        system("clear");
        break;
      case 2:
        system("clear");
        break;
      case 3:
        system("clear");
        break;
      case 4:
        system("clear");
        break;
      default:
        system("clear");
        std::cout << "Ha introducido una opción no válida" << std::endl;
    }
  }
}