#include "info_biblio.h"

#include <iostream>

#define COLOR_CYAN    "\033[36m"
#define COLOR_ROJO "\033[31m"
#define COLOR_RESET   "\033[0m"

/**
 * @brief muestra información sobre la biblioteca
 */
void get_informacion() {
  std::cout << "📖 Biblioteca" << std::endl;
  std::cout << "📍 San Cristóbal de La Laguna" << std::endl;
  std::cout << "📞 922 421 686" << std::endl;
}
/**
 * @brief muestra los horarios de la biblioteca 
 */
void ver_horarios() {
  std::cout << "🗓️  Lunes " << COLOR_CYAN << "(9:00 - 15:00)" << COLOR_RESET << std::endl;
  std::cout << "🗓️  Martes " << COLOR_CYAN << "(9:00 - 17:00)" << COLOR_RESET << std::endl;
  std::cout << "🗓️  Miércoles " << COLOR_CYAN << "(9:00 - 17:00)" << COLOR_RESET << std::endl;
  std::cout << "🗓️  Jueves " << COLOR_CYAN << "(9:00 - 17:00)" << COLOR_RESET << std::endl;
  std::cout << "🗓️  Viernes " << COLOR_CYAN << "(9:00 - 15:00)" << COLOR_RESET << std::endl;
  std::cout << "🗓️  Sábado " << COLOR_ROJO <<"Cerrado" << COLOR_RESET << std::endl;
  std::cout << "🗓️  Domingo " << COLOR_ROJO <<  "Cerrado" << COLOR_RESET << std::endl;
}