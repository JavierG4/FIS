#include "aulas.h"

#include <fstream>
#include <string>
#include <filesystem>

#define STYLE_ITALIC  "\033[3m"
#define COLOR_RESET   "\033[0m"
#define BOLD     "\033[1m" 

void reservar_aula(Horario& horario) {
  std::cout << STYLE_ITALIC << BOLD << "HORARIO " << COLOR_RESET << std::endl;
  std::cout << horario << std::endl;
  std::vector<std::string> semana = {"lunes", "martes", "miercoles", "jueves", "viernes", "sabado", "domingo"};
  std::string dia_de_la_semana, nombre;
  int aula, sesion, dia = -1;
  std::cout << STYLE_ITALIC << BOLD << "RESERVA" << COLOR_RESET << std::endl;
  std::cout << "→ Nombre para la reserva: ";
  std::cin >> nombre;
  std::cout << "→ Seleccione el día para la reserva en minúsculas (lunes, martes, ...): ";
  std::cin >> dia_de_la_semana;
  for (int i = 0; i < semana.size(); i++) {
    if (semana[i] == dia_de_la_semana) {
      dia = i;
    }
  }
  if (dia == -1) {
    std::cerr << "El día seleccionado no es válido" << std::endl;
    return;
  }

  std::cout << "→ Seleccione el aula para la reserva (1-4): ";
  std::cin >> aula;
  if (aula < 1 || aula > 4) {
    std::cout << "La aula seleccionada no es válida" << std::endl;
    return; 
  }

  std::cout << "→ Seleccione la sesión para la reserva. Para ello, indique el número correspondiente (Mañana = 0 ó Tarde = 1): ";
  std::cin >> sesion;
  if (sesion < 0 || sesion > 1) {
    std::cout << "La sesión seleccionada no es válida" << std::endl;
    return; 
  }

  if (horario.get_estado(dia, aula, sesion) != "Libre") {
    std::cout << "El aula seleccionada no está disponible." << std::endl;
  } else {
    horario.set_estado(dia, aula, sesion, nombre);
    std::cout << "Reserva realizada con éxito\n"
              << "Nombre de la reserva: " << nombre << "\n"
              << "Aula: " << aula << "\n"
              << "Día de la semana: " << semana[dia] << "\n"
              << "Sesión: " << (sesion == 0 ? "Mañana" : "Tarde") << "\n"
              << "Aforo máximo: 15 personas." << "\n"
              << "Recuerde: " << STYLE_ITALIC << "No está permitimo comer ni beber en las aulas" << COLOR_RESET << std::endl;
    std::string ruta_reserva = "../base_de_datos/usuarios/" + nombre + "/" + "reserva_" + semana[dia] +  ".txt";
    std::ofstream archivo(ruta_reserva);
    if (archivo.is_open()) {
      archivo << "Nombre de la reserva: " << nombre << "\n"
              << "Aula: " << aula << "\n"
              << "Día: " << semana[dia] << "\n"
              << "Sesión: " << (sesion == 0 ? "mañana" : "tarde") << "\n";
      archivo.close();
    } else {
      std::cout << "No se pudo abrir el archivo para guardar la reserva." << std::endl;
    }
  }
}


void anular_reserva_aula(Horario& horario) {
  std::vector<std::string> semana = {"lunes", "martes", "miercoles", "jueves", "viernes", "sabado", "domingo"};
  std::string dia_de_la_semana, nombre;
  int aula, sesion, dia = -1;
  std::cout << STYLE_ITALIC << BOLD << "ANULAR RESERVA" << COLOR_RESET << std::endl;
  std::cout << "→ Nombre de la reserva: ";
  std::cin >> nombre;
  std::cout << "→ Seleccione el día para la reserva en minúsculas (lunes, martes, ...): ";
  std::cin >> dia_de_la_semana;
  for (int i = 0; i < semana.size(); i++) {
    if (semana[i] == dia_de_la_semana) {
      dia = i;
    }
  }
  if (dia == -1) {
    std::cerr << "El día seleccionado no es válido" << std::endl;
    return;
  }

  std::cout << "→ Seleccione el aula para la reserva (1-4): ";
  std::cin >> aula;
  if (aula < 1 || aula > 4) {
    std::cout << "La aula seleccionada no es válida" << std::endl;
    return; 
  }

  std::cout << "→ Seleccione la sesión para anular la reserva. Para ello, indique el número correspondiente (Mañana = 0 ó Tarde = 1): ";
  std::cin >> sesion;
  if (sesion < 0 || sesion > 1) {
    std::cout << "La sesión seleccionada no es válida" << std::endl;
    return; 
  }

  if (horario.get_estado(dia, aula, sesion) == "Libre") {
    std::cout << "El aula seleccionada se encuentra libre" << std::endl;
  } else if (horario.get_estado(dia, aula, sesion) == nombre) {
    std::string libre = "Libre";
    horario.set_estado(dia, aula, sesion, libre);
    std::string ruta_reserva = "../base_de_datos/usuarios/" + nombre + "/" + "reserva_" + semana[dia] +  ".txt";
    if (std::filesystem::exists(ruta_reserva)) {
      std::filesystem::remove(ruta_reserva);
    }
    std::cout << "La reserva se ha anulado" << std::endl;
  }
  std::cout << STYLE_ITALIC << BOLD << "HORARIO " << COLOR_RESET << std::endl;
  std::cout << horario << std::endl;
}
