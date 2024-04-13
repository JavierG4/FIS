#include "menu.h"
#include "usuario.h"
#include "horario.h"
#include "aulas.h"
#include "../library/libros.h"


bool MostrarMenu(bool sesioniniciada) {
  bool salir = false;
  int opcion {0};
  while (!salir && !sesioniniciada) {
    std::cout << std::endl << "¡Buenos días!" << std::endl << std::endl;
    std::cout << "Elija la opción que desee realizar:\n"
              << "(1) Mostrar libros 📚\n"
              << "(2) Mostrar libros disponibles 📖\n"
              << "(3) Mostrar horarios 📅\n"
              << "(4) Iniciar sesión 👤\n"
              << "(5) Ayuda ❓\n"
              << "(6) Salir";
    std::cout << std::endl;
    std::cin >> opcion;
    switch(opcion) {
      case 1:
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        sesioniniciada = true;
        return sesioniniciada;
        break;
      case 5:
        // Mostrar txt de Ayuda
        break;
      case 6:
        salir = true;
        break;
      default: 
        std::cout << "Ha introducido una opción no válida" << std::endl;
    }
  }
  return sesioniniciada;
}

bool MenuRegistrado(bool registradoaulaopt) {
  bool salir = false;
  int opcion {0};
  while (!salir) {
    std::cout << "Elija la opción que desee realizar:\n"
              << "(1) Reservar libros 📝📕\n"
              << "(2) Reservar aulas 📝🪑\n"
              << "(3) Anular reserva de aula 🪑\n"
              << "(4) Devolver libro 📕\n"
              << "(5) Ver foro 🗣️\n"
              << "(6) Salir";
    std::cout << std::endl;
    std::cin >> opcion;

    switch(opcion) {
      case 1: {
        std::string nombre_libro_reserva;
        std::cout << "Introduce el nombre del libro a reservar: " << std::endl;
        std::getline(std::cin, nombre_libro_reserva); // Use getline() to handle spaces

        if (nombre_libro_reserva.empty()) {
          std::cout << "Error: El nombre del libro no puede estar vacío." << std::endl;
          // Handle empty input error (e.g., prompt again, return to menu)
          break;
        }

        Libro libro(nombre_libro_reserva);
        libro.reservar_libro();
        break;
  }
        
      case 2:
        registradoaulaopt = true;
        return registradoaulaopt;
        break;
      case 3:
        registradoaulaopt = false; // Cancelar reserva
        return registradoaulaopt;
        break;
      case 4:
        break;
      case 5:
        // Mostrar txt de foro
        break;
      case 6:
        salir = true;
        break;
      default: 
        std::cout << "Ha introducido una opción no válida" << std::endl;
    }
  }
  return registradoaulaopt;
}