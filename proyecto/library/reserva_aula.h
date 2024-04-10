#include "horario.h"

#include <fstream>
#include <string>

#define STYLE_ITALIC  "\033[3m"
#define COLOR_RESET   "\033[0m"
#define BOLD     "\033[1m" 

void reservar_aula(Horario& horario) {
  std::cout << STYLE_ITALIC << BOLD << "HORARIO " << COLOR_RESET << std::endl;
  std::cout << horario << std::endl;
  std::vector<std::string> semana = {"lunes", "martes", "miércoles", "jueves", "viernes", "sábado", "domingo"};
  std::string dia_de_la_semana;
  int aula, sesion, dia = -1;
  std::cout << STYLE_ITALIC << BOLD << "RESERVA" << COLOR_RESET << std::endl;
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

  if (horario.get_estado(dia, aula, sesion)) {
    std::cout << "El aula seleccionada no está disponible." << std::endl;
  } else {
    horario.set_estado(dia, aula, sesion, true);
    std::cout << "Reserva realizada con éxito\n" 
              << "Aula " << aula << "\n"
              << "Día de la semana " << dia << "\n"
              << "Sesión " << (sesion == 0 ? "Mañana" : "Tarde") << "\n"
              << "Aforo máximo: 15 personas." << "\n"
              << "Recuerde: " << STYLE_ITALIC << "No está permitimo comer ni beber en las aulas" << COLOR_RESET << std::endl;

    std::ofstream archivo("reservas.txt", std::ios::app);
    if (archivo.is_open()) {
      archivo << "Reserva: " << "\n"
              << "Aula " << aula << "\n"
              << "Día " << semana[dia] << "\n"
              << "Sesión " << (sesion == 0 ? "mañana" : "tarde") << "\n"
              << "Aforo máximo: 15 personas." << "\n"
              << "Recuerde: No está permitimo comer ni beber en las aulas" << std::endl;
      archivo.close();
    } else {
      std::cout << "No se pudo abrir el archivo para guardar la reserva." << std::endl;
    }
  }
}
