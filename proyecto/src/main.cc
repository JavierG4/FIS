#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <utility>

#include "menu.h"

#include "seguridad.h"
#include "usuario.h"

#include "horario.h"
#include "aulas.h"
#include "info_biblio.h"

int main() {
  std::cout << std::endl;
  // Información de la biblioteca
  get_informacion();
  // Menú
  bool sesioniniciada = false;
  bool registradoaulaopt = false;
  Horario horario;
  if (MostrarMenu(sesioniniciada)) {
    // Seguridad
    Usuario user;
    Seguridad seguridad;
    bool resultado = seguridad.MenuSeguridad(user);
    if (!resultado) {
      std::cout << "Error de inicio" << std::endl;
    } else {
      // Usuario
      std::cout << "Bienvenido " << user.get_username() << std::endl;
      std::cout << user << std::endl; 
      // Reservar aulas
      if (MenuRegistrado(registradoaulaopt) == true) {
        reservar_aula(horario, user);
        // Mostrar horario
        std::cout << horario << std::endl;
      } else {
        anular_reserva_aula(horario, user);
      }
    }
  }
  //guardar horario, hacer siempre antes de que acabe el programa
  horario.guardar_horario();

  return 0;
}