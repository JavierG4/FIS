#include "horario.h"
#include <cassert>

#define COLOR_VIOLET  "\033[35m"
#define COLOR_CYAN    "\033[36m"
#define COLOR_RESET   "\033[0m"

//constructor
Horario::Horario() : horario_biblio_(7, std::vector<bool>(8, false)) {}
//setter
void Horario::set_estado(int dia, int aula, int sesion, bool estado) {
  assert (dia >= 0 && dia < 7 && aula >= 1 && aula <= 4 && sesion >= 0 && sesion <= 1);
  horario_biblio_[dia][((aula - 1)) + sesion] = estado;
}
//getter
bool Horario::get_estado(int dia, int aula, int sesion) const {
  return horario_biblio_[dia][((aula - 1)) + sesion]; 
}
//imprimir
std::ostream& operator<<(std::ostream& out, const Horario& horario) {
  std::vector<std::string> semana = {"Lunes", "Martes", "Miércoles", "Jueves", "Viernes", "Sábado", "Domingo"};
  for (int i = 0; i < semana.size(); i++) {
    out << COLOR_VIOLET << semana[i] << ":" << COLOR_RESET << std::endl;
    out <<  COLOR_CYAN << "  Mañana: " << COLOR_RESET << std::endl;
    for (int j = 1; j <= 4; j++) {
       out << "Aula " << j << ": " << (horario.get_estado(i, j, 0) ? "Ocupada " : "Libre ");
       if (j != 4) {
        out << " | ";
       }
    }
    out << std::endl;
    out << COLOR_CYAN <<  "  Tarde: " << COLOR_RESET << std::endl;
    for (int j = 1; j <= 4; j++) {
    out << "Aula " << j << ": " << (horario.get_estado(i, j, 1) ? "Ocupada " : "Libre ");
      if (j != 4) {
        out << " | ";
       }
    }
    out << std::endl;
  }
  return out;
}
