#include "faq.h"

void UsuarioNoIdentificadoFAQ() {
  int opcion;
  while (opcion != 0) {
    std::cout << GREEN << "\nElija el tema sobre el que desee consultar:\n" << RESET
              << "\t(0) Salir\n"
              << "\t(1) Registrarse 👤\n"
              << "\t(2) Libros 📚\n"
              << "\t(3) Eventos 📅\n"
              << "\t(4) Foro 🗣️\n\t";
    std::cin >> opcion;
    int pregunta = -1;
    switch(opcion) {
      case 0:
        system("clear");
        return;
        break;
      case 1:
        pregunta = -1;
        system("clear");
        while (pregunta != 0) {
          std::cout << GREEN << "\nSeleccione la consulta:\n" << RESET
                    << "\t(0) Salir\n"
                    << "\t(1) ¿Qué información me piden para registrarme?\n\t";
          std::cin >> pregunta;
          if (pregunta == 1) {
            std::cout << "\nPara registrarse debe proporcionar:\n"
                      << "\t- Nombre de usuario\n\t- Contraseña\n\t- Correo electrónico\n"
                      << "\t- Nombre sin apellidos\n\t- Primer apellido\n";
          } else {
            std::cout << "Ha introducido una opción no válida" << std::endl;
          }
        }
        system("clear");
        break;
      case 2:
        pregunta = -1;
        system("clear");
        while (pregunta != 0) {
          std::cout << GREEN << "\nSeleccione la consulta:\n" << RESET
                    << "\t(0) Salir\n"
                    << "\t(1) ¿Cómo puedo reservar un libro?\n"
                    << "\t(2) ¿Qúe información me piden para reservar un libro?\n\t";
          std::cin >> pregunta;
          if (pregunta == 1) {
            std::cout << "\nPara reservar un libro debe:\n\t- Estar registrado en la plataforma\n"
                      << "\nSi tiene dudas a la hora de registrarse puede acceder "
                      << "a la secciñon 'Registrarse' de la opción 'Ayuda'\n";
          } else if (pregunta == 2) {
            std::cout << "\nPara reservar un libro debe estar registrado y proporcionar "
                      << "el nombre del libro\n";
          } else {
            std::cout << "Ha introducido una opción no válida" << std::endl;
          } 
        }
        system("clear");
        break;
      case 3:
        pregunta = -1;
        system("clear");
        while (pregunta != 0) {
          std::cout << GREEN << "\nSeleccione la consulta:\n" << RESET
                    << "\t(0) Salir\n"
                    << "\t(1) ¿Cómo puedo apuntarme a un evento?\n\t";
          std::cin >> pregunta;
          if (pregunta == 1) {
            std::cout << "\nPara apuntarse a un evento debe:\n"
                      << "\t1º Debe estar registrado\n\t2º Proporcionar el nombre del evento\n";
          } else {
            std::cout << "Ha introducido una opción no válida" << std::endl;
          }
        }
        system("clear");
        break;
      case 4:
        pregunta = -1;
        system("clear");
        while (pregunta != 0) {
          std::cout << GREEN << "\nSeleccione la consulta:\n" << RESET
                    << "\t(0) Salir\n"
                    << "\t(1) ¿Cómo puedo acceder al foro?\n\t";
          std::cin >> pregunta;
          if (pregunta == 1) {
            std::cout << "\nPara acceder al foro debe:\n\t- Estar registrado en la plataforma\n"
                      << "\nSi tiene dudas a la hora de registrarse puede acceder "
                      << "a la secciñon 'Registrarse' de la opción 'Ayuda'\n"
                      << "\nUna vez registrado, si sigue teniendo dudas, puede acceder a la sección"
                      << " 'Foro' de la opción 'Ayuda'\n";
          } else {
            std::cout << "Ha introducido una opción no válida" << std::endl;
          }
        }
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
              << "\t(4) Foro 🗣️\n\t";
    std::cin >> opcion;
    int pregunta = -1;
    switch(opcion) {
      case 0:
        system("clear");
        return;
        break;
      case 1:
        pregunta = -1;
        system("clear");
        while (pregunta != 0) {
          std::cout << GREEN << "\nSeleccione la consulta:\n" << RESET
                    << "\t(0) Salir\n"
                    << "\t(1) ¿Qué información necesito para reservar un libro?\n"
                    << "\t(2) ¿Cómo devolver una reserva?\n"
                    << "\t(3) ¿Recibiría notificaciones cerca de la fecha de devolución?\n\t";
          std::cin >> pregunta;
          if (pregunta == 1) {
            std::cout << "\nPara reservar un libro debe:\n\t- Proporcionar el nombre del libro\n";
          } else if (pregunta == 2){
            std::cout << "\nPara devolver una reserva debe:\n\t- Proporcionar el nombre del libro\n";
          } else if (pregunta == 3) {
            std::cout << "\nNo recibirá notificaciones cerca de la fecha de devolución\n";
          } else {
            std::cout << "Ha introducido una opción no válida" << std::endl;  
          }
        }
        system("clear");
        break;
      case 2:
        pregunta = -1;
        system("clear");
        while (pregunta != 0) {
          std::cout << GREEN << "\nSeleccione la consulta:\n" << RESET
                    << "\t(0) Salir\n"
                    << "\t(1) ¿Qué información necesito para reservar un aula?\n"
                    << "\t(2) ¿Cómo anular la reserva de un aula?\n"
                    << "\t(3) ¿Recibiría notificaciones cerca de la fecha de la reserva del aula?\n\t";
          std::cin >> pregunta;
          if (pregunta == 1) {
            std::cout << "\nPara reservar un aula debe proporcionar:\n\t- Un nombre para la reserva\n"
                      << "\t- El día que desea reservar el aula\n"
                      << "\t- El aula (1, 2, 3, 4)\n"
                      << "\t- La sesión (mañana, tarde) \n";
          } else if (pregunta == 2) {
            std::cout << "\nPara anular la reserva de un aula debe:\n\t"
                      << "- El nombre de la reserva que desea anular\n";
          } else if (pregunta == 3) {
              std::cout << "\nSí recibiría una notificación el día previo a la reserva\n";
          } else {
            std::cout << "Ha introducido una opción no válida" << std::endl;
          } 
        }
        system("clear");
        break;
      case 3:
        pregunta = -1;
        system("clear");
        while (pregunta != 0) {
          std::cout << GREEN << "\nSeleccione la consulta:\n" << RESET
                    << "\t(0) Salir\n"
                    << "\t(1) ¿Recibiría notificaciones cerca de la fecha del evento al que me he apuntado?\n\t";
          std::cin >> pregunta;
          if (pregunta == 1) {
            std::cout << "\nNo recibirá notificaciones cerca de la fecha del evento\n";
          } else {
            std::cout << "Ha introducido una opción no válida" << std::endl;
          }
        }
        system("clear");
        break;
      case 4:
        pregunta = -1;
        system("clear");
        while (pregunta != 0) {
          std::cout << GREEN << "\nSeleccione la consulta:\n" << RESET
                    << "\t(0) Salir\n"
                    << "\t(1) ¿Cómo puedo dejar un comentario en el foro en una discusión existente?\n"
                    << "\t(2) ¿Cómo crear una discusión?\n\t";
          std::cin >> pregunta;
          if (pregunta == 1) {
            std::cout << "\nPara dejar un comentario en el foro debe:\n"
                      << "\t1º Acceda al foro\n\t2º Seleccione una discusión\n"
                      << "\t3º Seleccione 'Escribir mensaje'\n\t4º Escriba su mensaje\n";
          } else if (pregunta == 2) {
            std::cout << "\nPara dejar un comentario en el foro debe:\n"
                      << "\t1º Acceda al foro\n\t2º Seleccione 'Crear discusión'\n"
                      << "\t3º Introduzca el tema de la discusión\n";
          } else {
            std::cout << "Ha introducido una opción no válida" << std::endl;
          }
        }
        system("clear");
        break;
      default:
        system("clear");
        std::cout << "Ha introducido una opción no válida" << std::endl;
    }
  }
}