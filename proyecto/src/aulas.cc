#include "aulas.h"

#include <fstream>
#include <string>
#include <filesystem>

#define STYLE_ITALIC  "\033[3m"
#define COLOR_RESET   "\033[0m"
#define BOLD     "\033[1m" 

/**
 * @brief función para reservar aulas
 * @param horario 
 */
void reservar_aula(Horario& horario,Usuario& usuario) {
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
    std::string ruta_reserva = "../base_de_datos/usuarios/" + usuario.get_username() + "/" + "reserva_" + nombre +  ".txt";
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

/**
 * @brief función para anular la reserva de aulas
 * @param horario 
 */
void anular_reserva_aula(Horario& horario,Usuario& usuario) {
  ver_reservas_aulas(usuario);
  std::string nombre;
  std::cout << STYLE_ITALIC << BOLD << "ANULAR RESERVA" << COLOR_RESET << std::endl;
  std::cout << "→ Nombre de la reserva: ";
  std::cin >> nombre;
  if (horario.buscar_reserva(nombre)) {
    std::string ruta_reserva = "../base_de_datos/usuarios/" + usuario.get_username() + "/" + "reserva_" + nombre +  ".txt";
    if (std::filesystem::exists(ruta_reserva)) {
      std::filesystem::remove(ruta_reserva);
    }
    std::cout << "La reserva se ha anulado" << std::endl;
  } else {
    std::cout << "No hay ninguna reserva con ese nombre" << std::endl;
  }
  std::cout << STYLE_ITALIC << BOLD << "HORARIO " << COLOR_RESET << std::endl;
  std::cout << horario << std::endl;
}
/**
 * @brief función para ver las reservas de un usuario
 * @param usuario 
 */
void ver_reservas_aulas(Usuario& usuario) {
  std::cout << STYLE_ITALIC << BOLD << "RESERVAS" << COLOR_RESET << std::endl;
  std::string ruta_reserva = "../base_de_datos/usuarios/" + usuario.get_username();
  for (const auto& entry : std::filesystem::directory_iterator(ruta_reserva)) {
    auto filename = entry.path().filename().string();
    if (filename.find("reserva") == 0)  {
      std::ifstream file(entry.path());
      if (file) { 
        std::string line;
        while (getline(file, line)) {
          std::cout << line << std::endl;
        }
      } else {
        std::cerr << "Error al abrir el archivo " << filename << std::endl;
      }
      file.close();
    }
  }
}

