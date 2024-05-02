#include "menu.h"

void MostrarMenu(Horario horario) {
  bool salir = false;
  int opcion;
  Eventos nuevo_evento;
  while (!salir) {
    std::cout << GREEN << "\nElija la opción que desee realizar:\n" << RESET
              << "\t(0) Salir\n"
              << "\t(1) Mostrar libros 📚\n"
              << "\t(2) Ver eventos\n"
              << "\t(3) Mostrar horarios 📅\n"
              << "\t(4) Iniciar sesión / Registrarse 👤\n"
              << "\t(5) Ayuda ❓\n\t";
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
        nuevo_evento.mostrar();
        break;
      case 3:
        system("clear");
        std::cout << std::endl;
        ver_horarios();
        break;
      case 4: {
        system("clear");
        Usuario user;
        Seguridad seguridad;
        bool resultado = seguridad.MenuSeguridad(user);
        if (resultado) {
          // Usuario
          system("clear");
          std::cout << "Bienvenido/a " << user.get_username() << std::endl;
          imprimir_recordatorio(user);
          MenuRegistrado(user, horario, nuevo_evento);
        }
        break;
      }
      case 5:
        system("clear");
        UsuarioNoIdentificadoFAQ();
        break;
      default: 
        system("clear");
        std::cout << "Ha introducido una opción no válida" << std::endl;
    }
  }
}

void MenuRegistrado(Usuario& user, Horario horario, Eventos nuevo_evento) {
  int opcion;
  imprimir_recordatorio(user);
  while (opcion != 0) {
    std::cout << GREEN << "\nElija la opción que desee realizar:\n" << RESET
              << "\t(0) Salir\n"
              << "\t(1) Mostrar libros disponibles 📖\n"
              << "\t(2) Reservar libros 📝📕\n"
              << "\t(3) Apuntarse a un evento\n"
              << "\t(4) Mostrar horario aulas\n"
              << "\t(5) Reservar aulas 📝🪑\n"
              << "\t(6) Ver aulas reservadas\n"
              << "\t(7) Anular reserva de aula 🪑\n"
              << "\t(8) Devolver libro 📕\n"
              << "\t(9) Ver foro 🗣️\n"
              << "\t(10) Ayuda ❓\n\t";
    std::cin >> opcion;
    switch(opcion) {
      case 0:
        system("clear");
        return;
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
      case 3: {
        system("clear");
        nuevo_evento.mostrar();  
        if (nuevo_evento.apuntarse(user)) {
          std::cout << "Te has apuntado al evento" << std::endl;
        } else {
          std::cout << "No se ha podido apuntar al evento" << std::endl;
        }
        ver_eventos(user);
        // nuevo_evento.guardar_eventos();
        break;
      }
      case 4:
        system("clear");
        std::cout << horario << std::endl;
        break;
      case 5:
        system("clear");
        reservar_aula(horario, user);
        break;
      case 6:
        system("clear");
        ver_reservas_aulas(user);
        break;
      case 7:
        system("clear");
        anular_reserva_aula(horario, user);
        break;
      case 8: { 
        system("clear");
        string libro_devolver;
        cout << "Escribe el nombre del libro: ";
        cin >> libro_devolver;
        Libro devuelto(libro_devolver);
        devuelto.devolver_libro();
        break;
      }
      case 9:
        system("clear");
        MenuForo(user);
        break;

      case 10:
        system("clear");
        UsuarioIdentificadoFAQ();
        break;
      default: 
        system("clear");
        std::cout << "Ha introducido una opción no válida" << std::endl;
    }
  }
}