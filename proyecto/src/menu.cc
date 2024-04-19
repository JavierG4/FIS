#include "menu.h"

bool MostrarMenu(bool sesioniniciada) {
  bool salir = false;
  int opcion;
  while (!salir && !sesioniniciada) {
    std::cout << "\nElija la opción que desee realizar:\n"
              << "(0) Salir\n"
              << "(1) Mostrar libros 📚\n"
              << "(2) Mostrar horarios 📅\n"
              << "(3) Iniciar sesión 👤\n"
              << "(4) Ayuda ❓";
    std::cout << std::endl;
    std::cin >> opcion;
    switch(opcion) {
      case 0:
        system("clear");
        salir = true;
        break;
      case 1: 
        system("clear");
        mostrar_todos_libros();
        break;
      case 2:
        system("clear");
        std::cout << std::endl;
        ver_horarios();
        break;
      case 3:
        system("clear");
        sesioniniciada = true;
        return sesioniniciada;
        break;
      case 4:
        system("clear");
        // Ayuda
        break;
      default: 
        system("clear");
        std::cout << "Ha introducido una opción no válida" << std::endl;
    }
  }
  return sesioniniciada;
}

void MenuRegistrado(Usuario& user, Horario horario) {
  bool salir = false;
  int opcion {0};
  while (!salir) {
    std::cout << "\nElija la opción que desee realizar:\n"
              << "(0) Salir\n"
              << "(1) Mostrar libros disponibles 📖\n"
              << "(2) Reservar libros 📝📕\n"
              << "(3) Mostrar horario aulas\n"
              << "(4) Reservar aulas 📝🪑\n"
              << "(5) Anular reserva de aula 🪑\n"
              << "(6) Devolver libro 📕\n"
              << "(7) Ver foro 🗣️";
    std::cout << std::endl;
    std::cin >> opcion;

    switch(opcion) {
      case 0:
        system("clear");
        salir = true;
        break;
      case 1: 
        system("clear");
        mostrar_libros_disponibles();
        break;
      case 2: {
        system("clear");
        string libro_reserva;
        cout << "Escribe el nombre del libro: ";
        cin >> libro_reserva;
        Libro reservado(libro_reserva);
        reservado.reservar_libro();
        break;
      }
      case 3:
        system("clear");
        std::cout << horario << std::endl;
        break;
      case 4:
        system("clear");
        reservar_aula(horario, user);
        break;
      case 5:
        system("clear");
        anular_reserva_aula(horario, user);
        break;
      case 6: { 
        system("clear");
        string libro_devolver;
        cout << "Escribe el nombre del libro: ";
        cin >> libro_devolver;
        Libro devuelto(libro_devolver);
        devuelto.devolver_libro();
        break;
      }
      case 7:
        system("clear");
        //MenuForo(user);
        break;
      default: 
        system("clear");
        std::cout << "Ha introducido una opción no válida" << std::endl;
    }
  }
}