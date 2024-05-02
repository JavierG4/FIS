#include "faq.h"

void UsuarioNoIdentificadoFAQ() {
  int opcion;
  while (opcion != 0) {
    std::cout << GREEN << "\nElija el tema sobre el que desee consultar:\n" << RESET
              << "\t(0) Salir\n"
              << "\t(1) Registrarse 👤\n"
              << "\t(2) Libros 📚\n"
              << "\t(3) Eventos 📅\n"
              << "\t(4) Foro 🗣️";
    std::cout << std::endl;
    std::cin >> opcion;
    int pregunta;
    switch(opcion) {
      case 0:
        system("clear");
        return;
        break;
      case 1:
        system("clear");
        while (pregunta != 0) {
          std::cout << GREEN << "\nSeleccione la consulta:\n" << RESET
                    << "\t(0) Salir\n"
                    << "\t(1) ¿Qué información me piden para registrarme?\n";
          std::cin >> pregunta;
          if (pregunta == 1) {
            std::cout << "\nPara registrarse debe proporcionar:\n"
                      << "\t- Nombre de usuario\n\t- Contraseña\n\t- Correo electrónico\n"
                      << "\t- Nombre sin apellidos\n\t- Primer apellido\n";
          }
        }
        system("clear");
        break;
      case 2:
        system("clear");
        while (pregunta != 0) {
          std::cout << GREEN << "\nSeleccione la consulta:\n" << RESET
                    << "\t(0) Salir\n"
                    << "\t(1) ¿Cómo puedo reservar un libro?\n"
                    << "\t(2) ¿Qúe información me piden para reservar un libro?\n";
          std::cin >> pregunta;
          if (pregunta == 1) {
            std::cout << "\nPara reservar un libro debe:\n\t- Estar registrado en la plataforma\n"
                      << "Si tiene dudas a la hora de registrarse acceda puede acceder\n"
                      << "a la secciñon 'Registrarse' de la opción 'Ayuda'\n";
          } else {
            std::cout << "\nPara reservar un libro debe estar registrado y proporcionar :\n"
                      << "el nombre del libro\n";
          }
        }
        system("clear");
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


void UsuarioIdentificadoFAQ() {
    int opcion;
  while (opcion != 0) {
    std::cout << GREEN << "\nElija el tema sobre el que desee consultar:\n" << RESET
              << "\t(0) Salir\n"
              << "\t(1) Libros 📚\n"
              << "\t(2) Aulas de estudio\n"              
              << "\t(3) Eventos 📅\n"
              << "\t(4) Foro 🗣️";
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