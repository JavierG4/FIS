#include "menu.h"
#include "usuario.h"
#include "horario.h"
#include "aulas.h"
#include "libros.h"
#include "info_biblio.h"
#include "discusion.h"
#include "foro.h"


bool MostrarMenu(bool sesioniniciada) {
  bool salir = false;
  int opcion {0};
  while (!salir && !sesioniniciada) {
    std::cout << "\nElija la opción que desee realizar:\n"
              << "(1) Mostrar libros 📚\n"
              << "(2) Mostrar horarios 📅\n"
              << "(3) Iniciar sesión 👤\n"
              << "(4) Ayuda ❓\n"
              << "(5) Salir";
    std::cout << std::endl;
    std::cin >> opcion;
    switch(opcion) {
      case 1: 
        mostrar_todos_libros();
        break;
      case 2:
        std::cout << std::endl;
        ver_horarios();
        break;
      case 3:
        sesioniniciada = true;
        return sesioniniciada;
        break;
      case 4:
        // Ayuda
        break;
      case 5:
        salir = true;
        break;
      default: 
        std::cout << "Ha introducido una opción no válida" << std::endl;
    }
  }
  return sesioniniciada;
}

bool MenuRegistrado(bool registradoaulaopt, Usuario& usuario) {
  bool salir = false;
  int opcion {0};
  while (!salir) {
    std::cout << "\nElija la opción que desee realizar:\n"
              << "(1) Mostrar libros disponibles 📖\n"
              << "(2) Reservar libros 📝📕\n"
              << "(3) Reservar aulas 📝🪑\n"
              << "(4) Anular reserva de aula 🪑\n"
              << "(5) Devolver libro 📕\n"
              << "(6) Ver foro 🗣️\n"
              << "(7) Salir";
    std::cout << std::endl;
    std::cin >> opcion;

    switch(opcion) {
      case 1: 
        mostrar_libros_disponibles();
        break;
      case 2: {
        string libro_reserva;
        cout << "Escribe el nombre del libro: ";
        cin >> libro_reserva;
        Libro reservado(libro_reserva);
        reservado.reservar_libro();
        break;
      }
      case 3:
        registradoaulaopt = true; // Reservar aula
        return registradoaulaopt;
        break;
      case 4:
        registradoaulaopt = false; // Anular reserva aula
        return registradoaulaopt;
        break;
      case 5: { 
        string libro_devolver;
        cout << "Escribe el nombre del libro: ";
        cin >> libro_devolver;
        Libro devuelto(libro_devolver);
        devuelto.devolver_libro();
        break;
      }
      case 6:
        MenuForo(usuario);
        break;
      case 7:
        salir = true;
        break;
      default: 
        std::cout << "Ha introducido una opción no válida" << std::endl;
    }
  }
  return registradoaulaopt;
}