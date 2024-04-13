#include "horario.h"
#include <cassert>
#include <sstream>
#include <fstream>

#define COLOR_VIOLET  "\033[35m"
#define COLOR_CYAN    "\033[36m"
#define COLOR_RESET   "\033[0m"

/**
 * @brief constructor del objeto Horario
 */
Horario::Horario() {
  std::ifstream horario(ruta_fichero_);
  if (horario.is_open()) {
    std::string linea;
    while (std::getline(horario, linea)) {
      std::vector<std::string> dias;
      std::string sesion;
      std::istringstream line(linea);
      while (line >> sesion) {
        dias.push_back(sesion); 
      }
      horario_biblio_.push_back(dias); 
    }
  }
}

/**
 * @brief setter del estado del aula
 * @param dia 
 * @param aula 
 * @param sesion 
 * @param estado 
 */
void Horario::set_estado(int dia, int aula, int sesion, std::string estado) {
  horario_biblio_[dia][((aula - 1)* 2) + sesion] = estado;
}

/**
 * @brief getter del estado del aula
 * @param dia 
 * @param aula 
 * @param sesion 
 * @return std::string 
 */
std::string Horario::get_estado(int dia, int aula, int sesion) const {
  return horario_biblio_[dia][((aula - 1) * 2) + sesion]; 
}

/**
 * @brief operador de inserción
 * @param out 
 * @param horario 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& out, const Horario& horario) {
  std::vector<std::string> semana = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};
  for (int i = 0; i < semana.size(); i++) {
    out << COLOR_VIOLET << semana[i] << ":" << COLOR_RESET << std::endl;
    out <<  COLOR_CYAN << "  Mañana: " << COLOR_RESET << std::endl;
    for (int j = 1; j <= 4; j++) {
       out << "Aula " << j << ": ";
       if(horario.get_estado(i, j, 0) != "Libre") {
        out << "Ocupado";
       } else {
        out << horario.get_estado(i, j, 0);
       }
       if (j != 4) {
        out << " | ";
       }
    }
    out << std::endl;
    out << COLOR_CYAN <<  "  Tarde: " << COLOR_RESET << std::endl;
    for (int j = 1; j <= 4; j++) {
      out << "Aula " << j << ": ";
      if(horario.get_estado(i, j, 1) != "Libre") { 
        out << "Ocupado";
      } else {
        out << horario.get_estado(i, j, 1);
      }
      if (j != 4) {
        out << " | ";
      }
    }
    out << std::endl;
  }
  return out;
}

/**
 * @brief método para guardar la información de un horario en un fichero
 */
void Horario::guardar_horario() const {
  std::ofstream horario(ruta_fichero_); 
  if (horario.is_open()) {
    for (const auto& dia : horario_biblio_) {
      for (const auto& sesion : dia) {
        horario << sesion << " "; 
      }
      horario << std::endl;
    }
  }
}

bool Horario::buscar_reserva(const std::string& nombre) {
  for (auto& dia : horario_biblio_) {
    for (auto& sesion : dia) {
      if (sesion == nombre) {
        std::string libre = "Libre";
        sesion = libre;
        return true;
      }
    }
  }
  return false;
}